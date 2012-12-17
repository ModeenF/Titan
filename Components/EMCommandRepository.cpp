#include "CommandIDs.h" // FIXME: Application file in the framework = bad
#include "EMCommand.h"
#include "EMCommandRepository.h"

EMCommandRepository* EMCommandRepository::m_opInstance = NULL;

EMCommandRepository::EMCommandRepository()
	:
//	m_opCommands(NULL),
//	m_opRedoCommand(NULL),
	m_vKeyReleased(false)
{
	//m_opCommands = new map<uint32, EMCommand*>();
	for(uint32 vIndex = 0; vIndex < MAX_NR_COMMANDS; vIndex++)
		m_opCommands[vIndex] = NULL;
}

EMCommandRepository::~EMCommandRepository()
{
/*
	EMCommand* opCommand;
	list<EMCommand*>::iterator oReleaseKeyIterator = m_oReleaseKeyCommands.begin();
	while(oReleaseKeyIterator != m_oReleaseKeyCommands.end())
	{
		opCommand = *oReleaseKeyIterator;
		oReleaseKeyIterator++;
		delete opCommand;
	}
	map<uint32, EMCommand*>::iterator oCommandIterator = m_opCommands -> begin();
	while(oCommandIterator != m_opCommands -> end())
	{
		opCommand = (*oCommandIterator).second;
		oCommandIterator++;
		delete opCommand;
	}
	delete m_opCommands;
*/
	for(uint32 vIndex = 0; vIndex < MAX_NR_COMMANDS; vIndex++)
		if(m_opCommands[vIndex] != NULL)
			delete m_opCommands[vIndex];

}

bool EMCommandRepository::AddCommand(EMCommand* p_opCommand, uint32 id)
{
/*
	if(m_opCommands -> find(id) != m_opCommands -> end())
		return false; // The ID already exists
	(*m_opCommands)[id] = p_opCommand;
*/
	if(m_opCommands[id] != NULL)
		return false;

	m_opCommands[id] = p_opCommand;

	return true;
}

void EMCommandRepository::ClearUndoStack()
{
	EMCommand* opCommand;

	list<EMCommand*>::iterator oIterator = fUndoStack.begin();

	while(oIterator != fUndoStack.end())
	{
		opCommand = *oIterator;
		oIterator++;
		delete opCommand;
	}

	fUndoStack.clear();
}

bool EMCommandRepository::CommandExists(uint32 p_vCommandID)
{
	return m_opCommands[p_vCommandID] != NULL;
/*
	if(m_opCommands -> find(p_vCommandID) == m_opCommands -> end())
		return false;
	return true;
*/
}

bool EMCommandRepository::ExecuteCommand(uint32 id)
{
	ExecuteCommandBody(id, NULL, NULL, NULL, false, false);
	return true;
}

void* EMCommandRepository::ExecuteCommand(uint32 id, void* one, void* two, void* three)
{
	return ExecuteCommandBody(id, one, two, three, false, false);
}

void* EMCommandRepository::ExecuteCommandBody(uint32 id, void* one, void* two, void* three, bool p_vPreventUndo, bool p_vTriggeredByBinding)
{
	//if(m_opCommands -> find(id) == m_opCommands -> end())
	if(m_opCommands[id] == NULL)
	{
		char vOutput[256];
		sprintf(vOutput, "The command with ID %d does not exist", id);
		EMDebugger(vOutput); // FIXME: Temporary
		return NULL; // The ID does not exist
	}

	EMCommand* opCommand = m_opCommands[id];//(*m_opCommands)[id];
	m_vKeyReleased = false;
	m_vTriggeredByBinding = p_vTriggeredByBinding;

	void* upResult;
	if(opCommand -> RequiresParameters())
	{
		try
		{
			upResult = opCommand -> ExecuteE(one, two, three);
		}
		catch(...)
		{
			// Send exception to EMExceptionHandler
			char vOutput[256];
			sprintf(vOutput, "A command with ID %d \"%s\" threw an exception", id, opCommand -> GetShortDescription());
			EMDebugger(vOutput); // FIXME: Temporary
		}
	}
	else
	{
		try
		{
			opCommand -> ExecuteE();
		}
		catch(...)
		{
			// Send exception to EMExceptionHandler
			char vOutput[256];
			sprintf(vOutput, "A command with ID %d \"%s\" threw an exception", id, opCommand -> GetShortDescription());
			EMDebugger(vOutput); // FIXME: Temporary
		}
	}

	if(opCommand/*(*m_opCommands)[id]*/ -> TriggerOnKeyRelease())
	{
		m_oReleaseKeyCommands.push_back(opCommand/*(*m_opCommands)[id]*/);
		m_oReleaseKeyCommands.unique();
	}

	if(opCommand -> IsUndoable() && !p_vPreventUndo)
	{
		if(opCommand -> GetShortDescription() != NULL)
			eo << "Command with ID " << id << " \"" << (const char*) opCommand -> GetShortDescription() << "\" is pushed onto the undo stack" << ef;
		EMCommand* opCommandClone = opCommand/*(*m_opCommands)[id]*/ -> CloneAndClear();
		ExecuteCommand(COMMAND_SET_UNDO_TEXTS, opCommandClone, NULL);
		fUndoStack.push_back(opCommandClone);
	}

	if(opCommand -> RequiresParameters())
		return upResult;
	else
		return NULL;
}

void* EMCommandRepository::ExecuteCommandNoUndo(uint32 id, void* one,
			void* two, void* three)
{
	return ExecuteCommandBody(id, one, two, three, true, false);
}


bool EMCommandRepository::ExecuteTriggeredCommand(uint32 id)
{
	ExecuteCommandBody(id, NULL, NULL, NULL, false, true);

	return true;
}


EMCommand* EMCommandRepository::GetUndoClone(uint32 id)
{
	//if(m_opCommands -> find(id) == m_opCommands -> end())
	if(m_opCommands[id] == NULL)
	{
//		emerr << "Failed to execute command with ID: " << id << endl;
		EMDebugger("The command does not exist");
		return NULL; // The ID does not exist
	}
	return m_opCommands[id] -> CloneAndClear();
}


list<EMCommand*>* EMCommandRepository::GetUndoStack()
{
	return &fUndoStack;
}



EMCommandRepository* EMCommandRepository::Instance()
{
	if(m_opInstance != NULL)
		return m_opInstance;

	m_opInstance = new EMCommandRepository();
	return m_opInstance;
}

bool EMCommandRepository::KeyReleased()
{
	return m_vKeyReleased;
}

void EMCommandRepository::Redo()
{
/*
	if(m_opRedoCommand != NULL)
	{
		try
		{
			m_opRedoCommand -> RedoE();
		}
		catch(...)
		{
			// Send exception to EMExceptionHandler
		}
		delete m_opRedoCommand;
		m_opRedoCommand = NULL;
	}
*/
}

bool EMCommandRepository::RequiresParameters(uint32 id)
{
	return m_opCommands[id] -> RequiresParameters();
}

void EMCommandRepository::SetKeyReleased()
{
	m_vKeyReleased = true;
	m_vTriggeredByBinding = true;

	list<EMCommand*>::iterator oIterator = m_oReleaseKeyCommands.begin();
	while(oIterator != m_oReleaseKeyCommands.end())
	{
		try
		{
			(*oIterator) -> ExecuteE();
		}
		catch(...)
		{
			// Send exception to EMExceptionHandler
		}
		oIterator++;
	}
	m_oReleaseKeyCommands.clear();
}


// Returns true if the last executed command (or currently executing
// command was/is triggered by a key or a MIDI message
bool EMCommandRepository::TriggeredByBinding()
{
	return m_vTriggeredByBinding;
}


void EMCommandRepository::Undo()
{
	EMCommand* opCommand = fUndoStack.back();
	fUndoStack.pop_back();
	try
	{
		opCommand -> UndoE();
	}
	catch(...)
	{
		// Send exception to EMExceptionHandler
		char vOutput[256];
		sprintf(vOutput, "A command \"%s\" threw an exception when undoed", opCommand -> GetShortDescription());
		EMDebugger(vOutput); // FIXME: Temporary
	}

	if(fUndoStack.size() > 0)
		ExecuteCommand(COMMAND_SET_UNDO_TEXTS, fUndoStack.back(), opCommand);
	else
		ExecuteCommand(COMMAND_SET_UNDO_TEXTS, NULL, opCommand);
/*
	if(m_opRedoCommand != NULL)
		delete m_opRedoCommand; // The redo stack only contains one item
	m_opRedoCommand = opCommand;
*/
	delete opCommand;
}


