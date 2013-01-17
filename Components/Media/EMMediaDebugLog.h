#ifndef __EM_MEDIA_DEBUG_LOG
#define __EM_MEDIA_DEBUG_LOG

#include "EMGlobals.h"

#include <fstream>
#include <Locker.h>

class EMMediaDebugLog {
public:
	explicit				EMMediaDebugLog();
							~EMMediaDebugLog();

			void operator	<<(const char*);
			void			Log(const char*);

private:
			BLocker			fLock;
			ofstream* 		fLogFile;
};

extern "C"	EMMediaDebugLog*	gMediaDebugLog;

#endif
