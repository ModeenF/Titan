#pragma warning(disable : 4786) // Skips boring debug truncate warning
#pragma warning(disable : 4275) // Skips "...needs to have dll-interface..."
#pragma warning(disable : 4251) // Skips "...needs to have dll-interface..."

#ifndef DEBUG_VERSION
#define DISABLE_OUTPUT
#endif

#include "EMDebugOutput.h"

#include "EMApplication.h"
#include "EMDebug_LibraryVersion.h"
// Since EMGlobals.h" isn't included in the header, it's included here instead
#include "EMGlobals.h"

#include <fstream>

static EMDebugOutput eo;

const char* LOG_FILE_NAME = "\\titan.log";

#ifndef __EXPORT_EM_DEBUG_LIBRARY
#define __EXPORT_EM_DEBUG_LIBRARY

EMDebugOutput::EMDebugOutput() :
m_vWindowCreated(false)
{
	eo << "DebugOutput Library v0.1Win, Build " << __EMDebug_LibraryVersion << " by " << __EMDebug_LibraryVersion_Owner << " (C) Elegant Media AB 2000-2001" << ef;
}

EMDebugOutput::~EMDebugOutput()
{
}

EMDebugOutput& EMDebugOutput::operator<<(short p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(const char* p_vpInput)
{
	if(p_vpInput[0] == '*')
	{
		if(strcmp(p_vpInput, "*DISABLE_DEBUG_WINDOW") == 0)
			m_vDebugIsActive = false;
		else if(strcmp(p_vpInput, "*ENABLE_DEBUG_WINDOW") == 0)
			m_vDebugIsActive = true;

		if(strcmp(p_vpInput, "*DISABLE_DEBUG_LOG") == 0)
			m_vWriteDebugLog = false;
		else if(strcmp(p_vpInput, "*ENABLE_DEBUG_LOG") == 0)
			m_vWriteDebugLog = true;

		return (*this);
	}

	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vpInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += string(p_vpInput);
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(unsigned short p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(int p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(unsigned int p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(long p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(unsigned long p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream* o = NULL; //TEMP, Doesn't do anything
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(float p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(double p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << p_vInput;
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << p_vInput;

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(int64 p_vInput)
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << static_cast<long>(p_vInput);
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	ostringstream oOutputStream;
	oOutputStream << double(p_vInput);

	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	m_oOutputString += oOutputStream.str();
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);
	return (*this);
}

EMDebugOutput& EMDebugOutput::operator<<(EMDebugOutput& (*p_opFunction)(EMDebugOutput&))
{
	return p_opFunction(*this);
}

EMDebugOutput& EMDebugOutput::EMFlush()
{
	if(m_vWriteDebugLog)
	{
		ofstream oOutStream(LOG_FILE_NAME, std::ios::out | std::ios::app);
		oOutStream << '\n';
	}

	if(!m_vDebugIsActive)
		return (*this);
//#ifdef DISABLE_OUTPUT
//return (*this);
//#endif
	if(!m_vWindowCreated)
		CreateDebugWindow();
	long vDummy;
	WaitForSingleObject(m_vLocalStringSemaphore, INFINITE);
	OutputString(m_oOutputString);
	m_oOutputString = "";
	ReleaseSemaphore(m_vLocalStringSemaphore, 1, &vDummy);

	return (*this);
}

void EMDebugOutput::OutputString(string p_oString)
{
	cout << p_oString;
}

LRESULT CALLBACK DebugWindowProcedure(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

void EMDebugOutput::CreateDebugWindow()
{
	// If BeOS, the default terminal window is used instead of a dedicated debug window
	m_vWindowCreated = true;
}


//Enters debugger and prints out a message (if supported by the platform)
EM_DEBUG_LIBRARY_DECLSPECIFIER void EMDebugger(const char* p_vpMessage)
{
#ifdef EM_DEBUG
	emerr << (char*) p_vpMessage << endl;
	debugger(p_vpMessage);
#endif //EM_DEBUG
}

EM_DEBUG_LIBRARY_DECLSPECIFIER EMDebugOutput& ef(EMDebugOutput& p_oStream)
{
	return p_oStream.EMFlush();
}

#endif //__EXPORT_EM_DEBUG_LIBRARY
