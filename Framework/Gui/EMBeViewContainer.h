/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_VIEW_CONTAINER
#define __EM_BE_VIEW_CONTAINER

#include "EMRect.h"
#include "EMView.h"

#include <memory>

class EMBeView;
class EMBitmap;
class EMListener;

class BBitmap;

class EMBeViewContainer : public EMView
{
public:
							EMBeViewContainer(EMRect,
									uint32 resizeMode, bool doubleBuffered);
							~EMBeViewContainer();

			void			AddChild(EMGUIComponent*);
			void 			AssertWindowLocked() const;
			EMRect 			Bounds() const;

			void			BeginPaint();
			void			EndPaint();
			bool			IsPainting();

			void			GetScreenInfo(int32 *, int32 *, int32 *);

			void 			CalculateStringHeight(const char*, int32& ascent,
									int32& descent);

			int32 			CalculateStringWidth(const char*);

			void 			ConstrainClippingRect(EMRect);
			void 			ConvertToScreenCoordinates(int32 &x, int32 &y);

			void 			DrawAndUnlockBuffer(EMRect);

			void 			DrawBitmap(const EMBitmap*);
			void 			DrawBitmap(const EMBitmap*, int32 x, int32 y);
			void 			DrawBitmap(const EMBitmap*, EMRect source,
									EMRect destination);

			void 			DrawBuffer(EMRect);

			void 			DrawString(int32 x, int32 y, const char*);

			void 			EnableDoubleBuffering(bool);

			void 			FillRect(EMRect);

			EMRect			Frame() const;
			EMRect 			GetClippingRect() const;

			EMView* 		GetLastMouseDownView();

			void 			GetMouse(int32 &x, int32 &y, bool &buttonOne,
								bool &buttonTwo, bool &buttonThree) const;

			void* 			GetNativeView() const;

			void 			Hide();
			bool 			IsHidden();

			void 			Invalidate(EMRect);

			bool 			IsDoubleBuffered();

			bool 			LockBuffer();
			bool 			LockWindow();

			void 			UnlockBuffer();
			void 			UnlockWindow();

			void 			ReceiveAllMouseEvents(bool);

			bool 			RemoveChild(EMGUIComponent*);

			void 			ScrollBy(int32 x, int32 y);
			void 			ScrollTo(int32 x, int32 y);

			void 			SetBitmap(EMBitmap*);

			void 			SetDrawingMode(EMDrawingMode);

			void 			SetFont(EMFont);
			void 			SetFrame(EMRect);

			void			SetDefaultColor();
			void 			SetHighColor(EMColor);
			void 			SetLowColor(EMColor);
			void 			SetViewColor(EMColor);

			void			SetMouseCursor(EMMouseCursorType, bool = false);

			void 			Show();

			void 			StrokeLine(int32 x1, int32 y1, int32 x2, int32 y2);

			void 			StrokeRect(EMRect);

			void 			Sync();
			void 			UpdateBufferFrame();

			bool 			WindowIsLocked();

private:
			EMBeView* 		m_opDrawView;
			EMBeView* 		m_opPlainView;
			float 			M_vBufferScrollOffsetX;
			float 			m_vBufferScrollOffsetY;
	static	BBitmap* 		m_opBuffer;
	static	EMBeView* 		m_opBufferView;

			bool 			m_vIsDoubleBuffered;
	static 	int 			m_vExistingDoubleBufferedViews;
};

#endif
