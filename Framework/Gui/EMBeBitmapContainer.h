/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_BITMAP_CONTAINER
#define __EM_BE_BITMAP_CONTAINER

#include "EMBitmap.h"
#include "EMGUIGlobals.h"
#include "EMRect.h"

class BBitmap;

class EMBeBitmapContainer : public EMBitmap
{
public:
							EMBeBitmapContainer(const EMBitmap*);
							EMBeBitmapContainer(const void* nativeBitmap);
	virtual 				~EMBeBitmapContainer();

			EMRect			Bounds() const;
			void* 			GetBits();
			EMColorSpace 	GetColorSpace() const;
			void* 			GetNativeBitmap() const;
			int32 			GetSize() const;

private:
			BBitmap* 		fNativeBitmap;
};

#endif

