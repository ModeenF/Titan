#include "EMGlobals.h"

#include "EMBufferRepository.h"
#include "EMBeBufferRepository.h"
#include "EMMediaIDManager.h"

EMBufferRepository* EMBufferRepository::m_opInstance = NULL;

EMBufferRepository* EMBufferRepository::Instance()
{
	if(m_opInstance == NULL)
		m_opInstance = EM_new EMBeBufferRepository();
	return m_opInstance;
}

void EMBufferRepository::Delete() //Deleted by MediaEngine
{
	delete m_opInstance;
	m_opInstance = NULL;
}

EMBufferRepository::EMBufferRepository()
	:	m_vAudioIsInitialized(false),
		m_vVideoIsInitialized(false)
{
	m_vID = EMMediaIDManager::MakeID();
}

EMBufferRepository::~EMBufferRepository()
{
}

int32 EMBufferRepository::GetID() const
{
	return m_vID;
}
