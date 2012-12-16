#include "EMBeViewContainer.h"

#ifdef PLATFORM_BEOS

#include "EMBeView.h"
#include "EMBitmap.h"
#include "EMGUIComponent.h"
#include "EMGUIGlobals.h"
#include "EMListener.h"

#include <Bitmap.h>
#include <Font.h>
#include <Region.h>
#include <View.h>
#include <Window.h>
#include <Point.h>

BBitmap* EMBeViewContainer::fBuffer = NULL;
EMBeView* EMBeViewContainer::fBufferView = NULL;
int EMBeViewContainer::fExistingDoubleBufferedViews = 0;

EMBeViewContainer::EMBeViewContainer(const EMRect frame, uint32 resizeMode,
	bool doubleBuffered)
	:
	fPlainView(new EMBeView(this, BRect(frame.m_vLeft,
			frame.m_vTop, frame.m_vRight, frame.m_vBottom),
			0, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE)),
	fBufferScrollOffsetX(0),
	fBufferScrollOffsetY(0),
	fDoubleBuffered(doubleBuffered)
{
	uint32 vResizingMode = 0;

	if((resizeMode & EM_FOLLOW_LEFT) == EM_FOLLOW_LEFT)
		vResizingMode = vResizingMode | B_FOLLOW_LEFT;
	if((resizeMode & EM_FOLLOW_RIGHT) == EM_FOLLOW_RIGHT)
		vResizingMode = vResizingMode | B_FOLLOW_RIGHT;
	if((resizeMode & EM_FOLLOW_H_CENTER) == EM_FOLLOW_H_CENTER)
		vResizingMode = vResizingMode | B_FOLLOW_H_CENTER;
	if((resizeMode & EM_FOLLOW_TOP) == EM_FOLLOW_TOP)
		vResizingMode = vResizingMode | B_FOLLOW_TOP;
	if((resizeMode & EM_FOLLOW_BOTTOM) == EM_FOLLOW_BOTTOM)
		vResizingMode = vResizingMode | B_FOLLOW_BOTTOM;
	if((resizeMode & EM_FOLLOW_V_CENTER) == EM_FOLLOW_V_CENTER)
		vResizingMode = vResizingMode | B_FOLLOW_V_CENTER;
	if((resizeMode & EM_FOLLOW_LEFT_RIGHT) == EM_FOLLOW_LEFT_RIGHT)
		vResizingMode = vResizingMode | B_FOLLOW_LEFT_RIGHT;
	if((resizeMode & EM_FOLLOW_TOP_BOTTOM) == EM_FOLLOW_TOP_BOTTOM)
		vResizingMode = vResizingMode | B_FOLLOW_TOP_BOTTOM;

	fPlainView -> SetResizingMode(vResizingMode);

	if(doubleBuffered && fBuffer == NULL) // The global double buffering buffer is now needed but not set yet
	{
		BRect oRect;
		oRect.left = 0;//frame.m_vLeft;
		oRect.top = 0;//frame.m_vTop;
		oRect.right = 1600;//frame.m_vRight;
		oRect.bottom = 1200;//frame.m_vBottom;

		fBuffer = new BBitmap(BRect(0, 0, /*oRect.Width()*/1600, /*oRect.Height()*/1200), B_RGB16, true);
		fBufferView = new EMBeView(this, oRect, vResizingMode, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE);
		fBufferView -> SetViewColor(B_TRANSPARENT_COLOR); // To avoid the background to be redrawn on every update = flicker
		if(fBuffer -> Lock())
		{
			fBuffer -> AddChild(fBufferView);
			fBufferView -> ResizeTo(1600, 1200);
			fBuffer -> Unlock();
		}
	}

//	auto_ptr<EMBeView> opPlainView(new EMBeView(this, oRect, vResizingMode, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE));
//	EMBeView* opPlainView(new EMBeView(this, oRect, vResizingMode, B_WILL_DRAW | B_FRAME_EVENTS));
	fPlainView -> SetViewColor(B_TRANSPARENT_COLOR); // To avoid the background to be redrawn on every update = flicker
	if(doubleBuffered)
	{
/*
		auto_ptr<BBitmap> opBuffer(new BBitmap(BRect(0, 0, 1600, 1200), B_RGB16, true));
		auto_ptr<EMBeView> opBufferView(new EMBeView(this, oRect, vResizingMode, B_WILL_DRAW | B_FRAME_EVENTS | B_NAVIGABLE));
		opBufferView -> SetViewColor(B_TRANSPARENT_COLOR); // To avoid the background to be redrawn on every update = flicker
		if(opBuffer -> Lock())
		{
			opBuffer -> AddChild(opBufferView.get());
			opBuffer -> Unlock();
		}
*/
//		fPlainView = opPlainView;
//		fBufferView = opBufferView;
//		fBuffer = opBuffer;
		fDrawView = fBufferView;
		fExistingDoubleBufferedViews++;
	}
	else
	{
//		fPlainView = opPlainView;
		fDrawView = fPlainView;
//		fDrawView = fPlainView;
	}
}


EMBeViewContainer::~EMBeViewContainer()
{
	;//cout_commented_out_4_release << "~EMBeViewContainer()" << endl;
	// SInce BeOS deletes allt its windows and attached views itself, only
	// the bitmap and its view are deleted here (done by the auto_ptr)
//	fBufferView -> RemoveSelf();
/*
	// The view must be removed from an eventual window since it will be
	// deleted twice otherwise (by the window and by the auto_ptr destructor)
	if(fPlainView -> Window() != NULL)
	{
		;//cout_commented_out_4_release << "~EMBeViewContainer(): removing view from window...";
		fPlainView -> RemoveSelf();
		;//cout_commented_out_4_release << "done" << endl;
	}
	else
		;//cout_commented_out_4_release <<"~EMBeViewContainer(): not attached" << endl;
*/
	if(fDoubleBuffered)
	{
		fExistingDoubleBufferedViews--;
		if(fExistingDoubleBufferedViews == 0) // If double buffered stuff should be deleted
		{
			delete fBufferView;
			fBufferView = NULL;
			delete fBuffer;
			fBuffer = NULL;
		}
	}
}


void EMBeViewContainer::AddChild(EMGUIComponent* view)
{
	// Sub-views in a double-buffered view is currently not allowed
	if(fDoubleBuffered)
		EMDebugger("Adding views to a double-buffered view is not allowed");
	fPlainView -> AddChild((BView*) view -> GetNativeView());
	view -> InitComponent();
}


// Enters debugger if window is unlocked
void EMBeViewContainer::AssertWindowLocked() const
{
	if(!(fPlainView -> Window() -> IsLocked()))
		EMDebugger("Window must be locked before entering this method\n");
}


EMRect EMBeViewContainer::Bounds() const
{
//	BRect oRect = fDrawView -> Bounds();
	// Using the plain view so that the bitmap buffer does not have to be locked
	// so often if the view is double-buffered
	BRect oRect = fPlainView -> Bounds();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}

void EMBeViewContainer::CalculateStringHeight(const char* str,
		int32 &ascent, int32 &descent)
{
	font_height oHeight;
	fDrawView -> GetFontHeight(&oHeight);
	ascent = (int32)oHeight.ascent;
	descent = (int32)oHeight.descent;
	if(ascent - static_cast<int>(ascent) > 0)
		ascent = static_cast<int>(ascent) + 1;
	if(descent - static_cast<int>(descent) > 0)
		descent = static_cast<int>(descent) + 1;
}


int32 EMBeViewContainer::CalculateStringWidth(const char* str)
{
	int32 vWidth = (int32)fDrawView -> StringWidth(str);
	if(vWidth - static_cast<int>(vWidth) > 0)
		vWidth = static_cast<int>(vWidth) + 1;
	return vWidth;
}


void EMBeViewContainer::ConstrainClippingRect(EMRect rect)
{
	if(!rect.IsValid())
	{
		fPlainView -> ConstrainClippingRegion(NULL);
		if(fDoubleBuffered)
			fBufferView -> ConstrainClippingRegion(NULL);
		return;
	}

//	BRegion* oRegion = new BRegion();
	BRegion oRegion;
	BRect oRect;

	oRect.left = rect.m_vLeft;
	oRect.top = rect.m_vTop;
	oRect.right = rect.m_vRight;
	oRect.bottom = rect.m_vBottom;
//	oRegion -> Set(oRect);
//	fPlainView -> ConstrainClippingRegion(oRegion);
	oRegion.Set(oRect);
	fPlainView -> ConstrainClippingRegion(&oRegion);
	if(fDoubleBuffered)
		fBufferView -> ConstrainClippingRegion(&oRegion);
}


void EMBeViewContainer::ConvertToScreenCoordinates(int32 &x, int32 &y)
{
	BPoint oNewPoint = fPlainView -> ConvertToScreen(BPoint(x, y));
	x = (int32)oNewPoint.x;
	y = (int32)oNewPoint.y;
}


void EMBeViewContainer::DrawAndUnlockBuffer(EMRect rect)
{
//;//cout_commented_out_4_release << "EMBeViewContainer::DrawAndUnlockBuffer: ";
//rect.Print();
	if(!fDoubleBuffered)
		EMDebugger("DrawAndUnlockBuffer() does not make sense in a non-double-buffered view");

	if(!rect.IsValid())
	{
		fBuffer -> Unlock();
		return;
	}


	BRect sourceRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
	sourceRect.OffsetBy(-1 * fBufferScrollOffsetX, -1 * fBufferScrollOffsetY);
	BRect oDestinationRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
//	BRect oDrawRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
	fBufferView -> Sync();
//	fPlainView -> DrawBitmap(fBuffer.get(), oDrawRect, oDrawRect);
	fPlainView -> DrawBitmap(fBuffer, sourceRect, oDestinationRect);
	fBuffer -> Unlock();
}


void EMBeViewContainer::DrawBitmap(const EMBitmap* bitmap)
{
	fDrawView -> DrawBitmap((BBitmap*) bitmap -> GetNativeBitmap());
}



void EMBeViewContainer::DrawBitmap(const EMBitmap* bitmap, int32 x, int32 y)
{
	fDrawView -> DrawBitmap((BBitmap*) bitmap -> GetNativeBitmap(),
		BPoint(x, y));
}


void EMBeViewContainer::DrawBitmap(const EMBitmap* bitmap, EMRect source,
	EMRect destination)
{
	if(!source.IsValid())
		return;

	if(!destination.IsValid())
		return;

	BRect sourceRect(source.m_vLeft, source.m_vTop, source.m_vRight,
			source.m_vBottom);
	BRect oDestinationRect(destination.m_vLeft, destination.m_vTop,
		destination.m_vRight, destination.m_vBottom);

	fDrawView -> DrawBitmap((BBitmap*) bitmap -> GetNativeBitmap(),
		sourceRect, oDestinationRect);
}


/*
void EMBeViewContainer::DrawBitmapOverlay(const EMBitmap* bitmap, EMRect source, EMRect destination)
{
	if(!source.IsValid())
		return;

	if(!destination.IsValid())
		return;

	BRect sourceRect(source.m_vLeft, source.m_vTop, source.m_vRight, source.m_vBottom);
	BRect oDestinationRect(destination.m_vLeft, destination.m_vTop, destination.m_vRight, destination.m_vBottom);
	rgb_color oColor;
	fDrawView -> SetViewOverlay((BBitmap*) bitmap -> GetNativeBitmap(), sourceRect, oDestinationRect, &oColor, B_OVERLAY_FILTER_HORIZONTAL | B_OVERLAY_FILTER_VERTICAL);
}
*/


void EMBeViewContainer::DrawBuffer(EMRect rect)
{
	if(!fDoubleBuffered)
		EMDebugger("DrawBuffer() does not make sense in a non-double-buffered view");

	if(!rect.IsValid())
		return;

	BRect sourceRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
	sourceRect.OffsetBy(-1 * fBufferScrollOffsetX, -1 * fBufferScrollOffsetY);
	BRect destinationRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight,
		rect.m_vBottom);
	fBufferView -> Sync();
	fPlainView -> DrawBitmap(fBuffer, sourceRect, destinationRect);
}


/*
void EMBeViewContainer::DrawBuffer(EMRect rect)
{
	if(!rect.IsValid())
		return;

	if(!fDoubleBuffered)
		EMDebugger("DrawBuffer() does not make sense in a non-double-buffered view");
	BRect oDrawRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
	fBufferView -> Sync();
	fPlainView -> DrawBitmap(fBuffer.get(), oDrawRect, oDrawRect);
}
*/

void EMBeViewContainer::DrawString(float x, float y, const char* text)
{
	fDrawView -> DrawString(text, BPoint(x, y));
}


void EMBeViewContainer::EnableDoubleBuffering(bool enabled)
{
	if(!fDoubleBuffered)
		EMDebugger("EnableDoubleBuffering can only be called on a view that has been created double buffered");

	if(!enabled)
		fDrawView = fPlainView;
	else
		fDrawView = fBufferView;
}


void EMBeViewContainer::FillRect(const EMRect rect)
{
	if(!rect.IsValid())
		return;

	BRect oRect;

	oRect.left = rect.m_vLeft;
	oRect.top = rect.m_vTop;
	oRect.right = rect.m_vRight;
	oRect.bottom = rect.m_vBottom;

	fDrawView -> FillRect(oRect);
}


EMRect EMBeViewContainer::Frame() const
{
//	BRect oRect = fDrawView -> Frame();
	// Using the plain view so that the bitmap buffer does not have to be locked
	// so often if the view is double-buffered
	BRect oRect = fPlainView -> Frame();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}

EMRect EMBeViewContainer::GetClippingRect() const
{
	BRegion oRegion;
	BRect oRect;
	EMRect oRect2;

//	fDrawView -> GetClippingRegion(&oRegion);
	fPlainView -> GetClippingRegion(&oRegion);
/*
;//cout_commented_out_4_release << "Number of clipping rects: " << oRegion.CountRects() << endl;
for(int vIndex = 0; vIndex < oRegion.CountRects(); vIndex++)
{
	oRect = oRegion.RectAt(vIndex);
	oRect2.m_vLeft = oRect.left;
	oRect2.m_vTop = oRect.top;
	oRect2.m_vRight = oRect.right;
	oRect2.m_vBottom = oRect.bottom;
	;//cout_commented_out_4_release << '\t';
	oRect2.Print();
}
*/
	oRect = oRegion.Frame();
	oRect2.m_vLeft = oRect.left;
	oRect2.m_vTop = oRect.top;
	oRect2.m_vRight = oRect.right;
	oRect2.m_vBottom = oRect.bottom;
	return oRect2;
}


EMView* EMBeViewContainer::GetLastMouseDownView()
{
	return fPlainView -> GetLastMouseDownView();
}


void EMBeViewContainer::GetMouse(float &x, float &y, bool &buttonOne,
	bool &buttonTwo, bool &buttonThree) const
{
	BPoint oPoint;
	uint32 vButtons;

	fPlainView -> GetMouse(&oPoint, &vButtons, false);

	x = oPoint.x;
	y = oPoint.y;

	if((vButtons & B_PRIMARY_MOUSE_BUTTON) == B_PRIMARY_MOUSE_BUTTON)
		buttonOne = true;
	else
		buttonOne = false;
	if((vButtons & B_SECONDARY_MOUSE_BUTTON) == B_SECONDARY_MOUSE_BUTTON)
		buttonTwo = true;
	else
		buttonTwo = false;
	if((vButtons & B_TERTIARY_MOUSE_BUTTON) == B_TERTIARY_MOUSE_BUTTON)
		buttonThree = true;
	else
		buttonThree = false;
}


void* EMBeViewContainer::GetNativeView() const
{
	return (void*) fPlainView;
//	return fPlainView;
}


void EMBeViewContainer::Hide()
{
	fPlainView -> Hide();
}


void EMBeViewContainer::Invalidate(const EMRect rect)
{
	if(!rect.IsValid())
		return;

	BRect oRect;

	oRect.left = rect.m_vLeft;
	oRect.top = rect.m_vTop;
	oRect.right = rect.m_vRight;
	oRect.bottom = rect.m_vBottom;

	fPlainView -> Invalidate(oRect);
}


bool EMBeViewContainer::IsDoubleBuffered()
{
	return fDoubleBuffered;
}


bool EMBeViewContainer::IsHidden()
{
	return fPlainView -> IsHidden();
}


bool EMBeViewContainer::LockBuffer()
{
	if(!fDoubleBuffered)
		EMDebugger("LockBuffer() does not make sense in a non-double-buffered view");
	return fBuffer -> Lock();
}


bool EMBeViewContainer::LockWindow()
{
/*
thread_id vThreadID = fPlainView -> Window() -> LockingThread();
thread_id vThisThreadID = find_thread(NULL);
thread_info oThreadInfo;
thread_info oThisThreadInfo;
get_thread_info(vThisThreadID, &oThisThreadInfo);
if(vThreadID != -1)
{
get_thread_info(vThreadID, &oThreadInfo);
if(vThreadID == vThisThreadID)
;//cout_commented_out_4_release << "Before locking window (from view). Already locked by the same thread: " << oThisThreadInfo.name << endl;
else
;//cout_commented_out_4_release << "Before locking window (from view). Already locked by a thread: " << oThreadInfo.name << ", this thread: " << oThisThreadInfo.name << endl;
}
else
;//cout_commented_out_4_release << "Before locking window (from view). This thread: " << oThisThreadInfo.name << endl;
bool vResult =  fPlainView -> Window() -> Lock();
;//cout_commented_out_4_release << " ------------------------  Window Locked (from view) (" << vResult << ") " << oThisThreadInfo.name << " -------------------" << endl;
//EMDebugger("Window locked by view");
	return vResult;
*/
	return fPlainView -> Window() -> Lock();
}


void EMBeViewContainer::ReceiveAllMouseEvents(bool vReceiveAll)
{
	if(vReceiveAll)
		fPlainView -> SetEventMask(B_POINTER_EVENTS, B_NO_POINTER_HISTORY);
	else
		fPlainView -> SetEventMask(0, B_NO_POINTER_HISTORY);
}


bool EMBeViewContainer::RemoveChild(EMGUIComponent* view)
{
	// Sub-views in a double-buffered view is currently not allowed
	if(fDoubleBuffered)
		EMDebugger("Removing views from a double-buffered view is not allowed");
	return fPlainView -> RemoveChild((BView*) view -> GetNativeView());
}


void EMBeViewContainer::ScrollBy(float x, float y)
{
	fPlainView -> ScrollBy(x, y);
	if(fDoubleBuffered)
		fBufferView -> ScrollBy(x, y);
}


void EMBeViewContainer::ScrollTo(float x, float y)
{
	fPlainView -> ScrollTo(x, y);
	if(fDoubleBuffered)
	{
		fBufferView -> SetOrigin(-1 * x, -1 * y);
		fBufferScrollOffsetX = x;
		fBufferScrollOffsetY = y;
//		fBufferView -> ScrollTo(x, y);
	}
}


void EMBeViewContainer::SetBitmap(EMBitmap* bitmap)
{
	// Setting a bitmap in a double-buffered view is currently not allowed
	if(fDoubleBuffered)
		EMDebugger("Setting a bitmap in a double-buffered view is not allowed");
	fPlainView -> SetViewBitmap(static_cast<BBitmap*>(bitmap -> GetNativeBitmap()));
}


void EMBeViewContainer::SetDrawingMode(EMDrawingMode mode)
{
	switch(mode)
	{
	case EM_OP_COPY:
		fDrawView -> SetDrawingMode(B_OP_COPY);
		break;
	case EM_OP_ALPHA:
		fDrawView -> SetDrawingMode(B_OP_ALPHA);
		fDrawView -> SetBlendingMode(B_CONSTANT_ALPHA, B_ALPHA_OVERLAY);
		break;
	case EM_OP_INVERT:
		fDrawView -> SetDrawingMode(B_OP_INVERT);
		break;
	default:
		fDrawView -> SetDrawingMode(B_OP_COPY);
	}
}


void EMBeViewContainer::SetFont(EMFont font)
{
	switch(font)
	{
	case EM_PLAIN:
		fDrawView -> SetFont(be_plain_font);
		break;
	case EM_BOLD:
		fDrawView -> SetFont(be_bold_font);
		break;
	case EM_FIXED:
		fDrawView -> SetFont(be_fixed_font);
		break;
	}
}


void EMBeViewContainer::SetFrame(EMRect frame)
{
	if(Frame() == frame)
		return;

	if(Frame().m_vTop != frame.m_vTop || Frame().m_vLeft != frame.m_vLeft)
		fPlainView -> MoveTo(frame.m_vLeft, frame.m_vTop);
	if(Frame().GetWidth() != frame.GetWidth() || Frame().GetHeight() != frame.GetHeight())
	{
		fPlainView -> ResizeTo(frame.GetWidth(), frame.GetHeight());
/*
		if(fDoubleBuffered)
		{
if(fBuffer == NULL)
;//cout_commented_out_4_release << "Hmm, the buffer is NULL" << endl;
			if(fBuffer -> Lock())
			{
				fBufferView -> ResizeTo(frame.GetWidth(), frame.GetHeight());
				fBuffer -> Unlock();
			}
		}
*/
	}
/*
	if(fDoubleBuffered)
	{
		fBuffer -> RemoveChild(fBufferView.get());
		delete fBuffer.get();
		auto_ptr<BBitmap> opBuffer(new BBitmap(BRect(0, 0, frame.GetWidth(), frame.GetHeight()), B_RGB16, true));
		if(opBuffer -> Lock())
		{
			opBuffer -> AddChild(fBufferView.get());

			fBufferView -> ResizeTo(frame.GetWidth(), frame.GetHeight());
//			fBufferView -> MoveTo(frame.m_vLeft, frame.m_vTop);

			opBuffer -> Unlock();
		}
		fBuffer = opBuffer;
	}
*/
}


void EMBeViewContainer::SetHighColor(const EMColor color)
{
	rgb_color sColor;
	sColor.red = color.m_vRed;
	sColor.blue = color.m_vBlue;
	sColor.green = color.m_vGreen;
	sColor.alpha = color.m_vAlpha;

	fDrawView -> SetHighColor(sColor);
}


void EMBeViewContainer::SetLowColor(const EMColor color)
{
	rgb_color sColor;
	sColor.red = color.m_vRed;
	sColor.blue = color.m_vBlue;
	sColor.green = color.m_vGreen;
	sColor.alpha = color.m_vAlpha;

	fDrawView -> SetLowColor(sColor);
}
/*
// This method is from the game kit
void EMBeViewContainer::SetMousePosition(float x, float y)
{
	set_mouse_position(static_cast<int32>(x), static_cast<int32>(y));
}
*/
void EMBeViewContainer::SetViewColor(const EMColor color)
{
	rgb_color sColor;
	sColor.red = color.m_vRed;
	sColor.blue = color.m_vBlue;
	sColor.green = color.m_vGreen;
	sColor.alpha = color.m_vAlpha;

	fPlainView -> SetViewColor(sColor);
	if(fDoubleBuffered)
		fBufferView -> SetViewColor(sColor);
}


void EMBeViewContainer::Show()
{
	fPlainView -> Show();
}


void EMBeViewContainer::StrokeLine(float x1, float y1, float x2, float y2)
{
	fDrawView -> StrokeLine(BPoint(x1, y1), BPoint(x2, y2));
}


void EMBeViewContainer::StrokeRect(EMRect rect)
{
	if(!rect.IsValid())
		return;

	fDrawView -> StrokeRect(BRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight,
		rect.m_vBottom));
}


void EMBeViewContainer::Sync()
{
	fDrawView -> Sync();
}


void EMBeViewContainer::UpdateBufferFrame()
{
/*
	if(fBuffer -> Lock())
	{
		fBufferView -> ResizeTo((fPlainView -> Bounds()).Width(), (fPlainView -> Bounds()).Height());
;//cout_commented_out_4_release << "EMBeViewContainer::UpdateBufferFrame: fBufferView: ";
;//cout_commented_out_4_release << (fPlainView -> Bounds()).Width() << ", " << (fPlainView -> Bounds()).Height() << endl;
		fBuffer -> Unlock();
	}
*/
}


bool EMBeViewContainer::WindowIsLocked()
{
	return fPlainView -> Window() -> IsLocked();
}


void EMBeViewContainer::UnlockBuffer()
{
	if(!fDoubleBuffered)
		EMDebugger("UnlockBuffer() does not make sense in a non-double-buffered view");
	fBuffer -> Unlock();
}


void EMBeViewContainer::UnlockWindow()
{
	fPlainView -> Window() -> Unlock();
}


#endif
