#include "EMMediaDebugLog.h"

#include <fstream>
#include <string>
#include <time.h>

#include <Autolock.h>

#define EM_MEDIA_LOG_FILENAME "\\zZ-TitanMediaSystem-Zz.log"


EMMediaDebugLog* gMediaDebugLog = new EMMediaDebugLog();


EMMediaDebugLog::EMMediaDebugLog()
{
#	ifdef _DEBUG
		fLogFile = EM_new ofstream(EM_MEDIA_LOG_FILENAME, ios::out
			| ios::trunc);

		(*fLogFile) << "Date / time stamp\t\tThread ID\tDebug text" << endl;
		(*fLogFile) << "------------------------------------------------------"
					<< "----------------------------------------" << endl;
		fLogFile->close();
#	endif
}

EMMediaDebugLog::~EMMediaDebugLog()
{
#	ifdef _DEBUG
		BAutolock _(fLock);
		fLogFile -> close();
		delete fLogFile;
#	endif
}

void EMMediaDebugLog::operator<<(const char* _string)
{
#	ifdef _DEBUG
		Log(_string);
#	endif
}

void EMMediaDebugLog::Log(const char* _string)
{
	// TODO: clean up this ugliness...
#	ifdef _DEBUG
		BAutolock _(fLock);
		time_t now;
		tm when;
		time( &now );
		when = *localtime(&now);
		string oNow(asctime(&when));

		fLogFile -> open(EM_MEDIA_LOG_FILENAME, ios::out | ios::app);

		char* vpStr = new char[oNow.length()];
		memcpy(vpStr, oNow.c_str(), oNow.length() -1);
		vpStr[oNow.length() -1] = '\0';
		oNow = vpStr;

		uint32 vCurrentThreadID = (uint32) GetCurrentThreadId();

		(*fLogFile) << oNow.c_str() << "\t" << vCurrentThreadID << "\t"
			<< flush;
		(*fLogFile) << _string << endl;
		fLogFile -> close();
#	endif
}

