#include "EMBeBitmapContainer.h"


#include <Bitmap.h>
#include <Rect.h>

EMBeBitmapContainer::EMBeBitmapContainer(const EMBitmap* bitmap) :
fNativeBitmap(static_cast<BBitmap*>(bitmap -> GetNativeBitmap()))
{
}

EMBeBitmapContainer::EMBeBitmapContainer(const void* nativeBitmap) :
fNativeBitmap(static_cast<BBitmap*>(nativeBitmap))
{
}

EMBeBitmapContainer::~EMBeBitmapContainer()
{
	delete fNativeBitmap;
}

EMRect EMBeBitmapContainer::Bounds() const
{
	BRect oRect = fNativeBitmap -> Bounds();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}

void* EMBeBitmapContainer::GetBits()
{
	return fNativeBitmap -> Bits();
}

// This method has no support for big-endian colorspaces (yet)
EMColorSpace EMBeBitmapContainer::GetColorSpace() const
{
	color_space eSpace = fNativeBitmap -> ColorSpace();
	switch(eSpace)
	{
	case B_GRAY1:
		return EM_LE_GRAY1;
	case B_GRAY8:
		return EM_LE_GRAY8;
	case B_CMAP8:
		return EM_LE_CMAP8;
	case B_RGB15:
		return EM_LE_RGB15;
	case B_RGBA15:
		return EM_LE_RGBA15;
	case B_RGB16:
		return EM_LE_16;
	case B_RGB32:
		return EM_LE_32;
	default:
		return EM_COLORSPACE_UNKNOWN;
	}
}

void* EMBeBitmapContainer::GetNativeBitmap() const
{
	return fNativeBitmap;
}

int32 EMBeBitmapContainer::GetSize() const
{
	return fNativeBitmap -> BitsLength();
}

