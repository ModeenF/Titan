/*******************************************************
* Creator: Martin Rudefelt
* Portability: non-native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_VIEW
#define __EM_VIEW

#include "EMGUIComponent.h"
#include "EMGUIGlobals.h"
#include "EMMouseCursor.h"
#include "EMRect.h"

class EMBitmap;

class EMView : public EMGUIComponent
{
public:
	virtual 				~EMView();

	virtual void			AddChild(EMGUIComponent* View) = 0;
	virtual void 			AssertWindowLocked() const = 0;
	virtual void 			BeginPaint() = 0;
	virtual EMRect 			Bounds() const = 0;

	virtual void 			CalculateStringHeight(const char* string,
								int32 &ascent, int32 &descent) = 0;
	virtual int32 			CalculateStringWidth(const char* string) = 0;
	virtual void 			ConstrainClippingRect(EMRect rect) = 0;
	virtual void 			ConvertToScreenCoordinates(int32 &x, int32 &y) = 0;

	virtual void 			DrawAndUnlockBuffer(EMRect updateRect) = 0;

	virtual void 			DrawBitmap(const EMBitmap* bitmap) = 0;
	virtual void 			DrawBitmap(const EMBitmap* bitmap, int32 x,
								int32 y) = 0;
	virtual void 			DrawBitmap(const EMBitmap* bitmap, EMRect source,
								EMRect Destination) = 0;

	virtual void 			DrawBuffer(EMRect updateRect) = 0;
	virtual void 			DrawString(int32 x, int32 y, const char* text) = 0;
	virtual void 			EnableDoubleBuffering(bool enabled) = 0;
	virtual void 			EndPaint() = 0;

	virtual void 			FillRect(EMRect rect) = 0;
	virtual EMRect 			GetClippingRect() const = 0;
	virtual EMView* 		GetLastMouseDownView() = 0;
	virtual void 			GetMouse(int32 &x, int32 &y, bool &buttonOne,
								bool &buttonTwo, bool &buttonThree) const = 0;
	virtual void 			GetScreenInfo(int32* width, int32* height,
								int32* bitDepth) = 0;
	virtual void 			Invalidate(EMRect rect) = 0;
	virtual bool			IsDoubleBuffered() = 0;
	virtual bool			IsHidden() = 0;
	virtual bool			IsPainting() = 0;
	virtual bool			LockBuffer() = 0;
	virtual bool			LockWindow() = 0;
	virtual void 			ReceiveAllMouseEvents(bool receiveAll) = 0;
	virtual bool			RemoveChild(EMGUIComponent* View) = 0;
	virtual void 			ScrollBy(int32 x, int32 y) = 0;
	virtual void 			ScrollTo(int32 x, int32 y) = 0;


	virtual void 			SetDefaultColor() = 0;
	virtual void 			SetDrawingMode(EMDrawingMode Mode) = 0;
	virtual void 			SetFont(EMFont Font) = 0;

	virtual void 			SetHighColor(const EMColor Color) = 0;
	virtual void 			SetLowColor(const EMColor Color) = 0;
	virtual void 			SetMouseCursor(EMMouseCursorType p_eType, bool AlwaysSucceed = false) = 0;

	virtual void 			SetViewColor(const EMColor Color) = 0;
	virtual void 			StrokeLine(int32 X1, int32 Y1, int32 X2, int32 Y2) = 0;
	virtual void 			StrokeRect(EMRect Rect) = 0;
	virtual void 			Sync() = 0;
	virtual void 			UpdateBufferFrame() = 0;
	virtual bool			WindowIsLocked() = 0;
	virtual void 			UnlockBuffer() = 0;
	virtual void 			UnlockWindow() = 0;

protected:
	EMView();
};

#endif
