/*******************************************************
* Creator: Martin Rudefelt
* Component: none
* Portability: non-native
*-------------------------------------------------------
* This file contains some global typedefs used by many
* parts of the system.
* The typedefs that should be supported by including
* this file are:
* int8, uint8, int16, uint16, int32, uint32,
* int64, uint64, NULL, bool, true, false, (status_t?),
* char, uchar
* It also containes #define:s that should be global and
* other useful stuff.
* All headers must include this file!
*******************************************************/

#ifndef __EM_GLOBALS
#define __EM_GLOBALS

/*************************************************************************/
// Misc stuff
/*************************************************************************/

#define EM_BIG_ENDIAN // Used by x86 architectures


#define PLATFORM_BEOS

/*************************************************************************/
// End of misc stuff
/*************************************************************************/

#include <SupportDefs.h>  // many nice BeOS typedefs

#ifndef UINT32_MAX
#	define UINT32_MAX 0xFFFFFFFFLL
#endif
#ifndef UINT64_MAX
#	define UINT64_MAX 0xFFFFFFFFFFFFFFFFLL
#endif
#ifndef INT32_MAX
#	define INT32_MAX 0x7FFFFFFFFLL
#endif
#ifndef INT32_MAX
#	define INT64_MAX 0x7FFFFFFFFFFFFFFFFLL
#endif

#define EM_FILE_SEPARATOR "/"

#define emerr	cout << "ERROR: "


#define EM_DEBUG // If debug code should be used

#ifdef EM_DEBUG
#	include <Debug.h>
#	define EM_new new
#else
#	define EM_new new
#endif


#include <new> // Needed for bad_alloc exception handling

#include "../../Components/EMDebugOutput.h"
	// This one needs to be included last in the file

#endif // __EM_GLOBALS
