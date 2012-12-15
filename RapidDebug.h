#ifndef TEMP_RAPID_DEBUG_H
#define TEMP_RAPID_DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <String.h>


extern "C" FILE*	_ddfl;

#define ENABLE_LOGGING	1
#define ENABLE_TRACING	1

#if ENABLE_LOGGING
#	define _LOG(Y...)	fprintf(_ddfl, Y); ::fflush(_ddfl);
#else
#	define _LOGF(Y...)
#endif


#if ENABLE_TRACING
#	define	TRACE(X...)	printf(X);
#else
#	define	TRACE(X...)
#endif

#define ERROR(X...) fprintf(stderr, X);


#endif	// TEMP_RAPID_DEBUG_H


