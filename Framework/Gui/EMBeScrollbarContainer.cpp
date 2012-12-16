#include "EMBeScrollbarContainer.h"

#include "EMListener.h"

#include <Rect.h>
#include <View.h>

EMBeScrollbarContainer::EMBeScrollbarContainer(EMRect frame, float minValue,
		float maxValue, EMOrientation orient)
{
	BRect oRect;

	if(orient == EM_HORIZONTAL)
	{
//		oRect.left = frame.m_vLeft + 1;
		oRect.top = frame.m_vTop + 1;
//		oRect.right = frame.m_vRight - 1;
//		oRect.bottom = frame.m_vBottom - 1;
	}
	else
		oRect.bottom = frame.m_vBottom - 1;
	orientation vOrientation;
	if(orient == EM_VERTICAL)
		vOrientation = B_VERTICAL;
	else
		vOrientation = B_HORIZONTAL;

	fScrollbar = new EMBeScrollbar(this, oRect, minValue, maxValue, vOrientation);
}


EMBeScrollbarContainer::~EMBeScrollbarContainer()
{
}


EMRect EMBeScrollbarContainer::Frame() const
{
	BRect oRect = fScrollbar -> Frame();
//	return EMRect(oRect.left - 1, oRect.top - 1, oRect.right + 1, oRect.bottom + 1);
	if(fScrollbar -> Orientation() == B_HORIZONTAL)
		return EMRect(oRect.left, oRect.top - 1, oRect.right, oRect.bottom);
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}


void* EMBeScrollbarContainer::GetNativeView() const
{
	return static_cast<void*>(fScrollbar);
}


void EMBeScrollbarContainer::GetRange(int32& min, int32& max)
{
	fScrollbar -> GetRange((float*)&min, (float*)&max);
}


void EMBeScrollbarContainer::GetSteps(int32& small, int32& big)
{
	fScrollbar -> GetSteps((float*)&small, (float*)&big);
}


int32 EMBeScrollbarContainer::GetValue()
{
	return (int32)fScrollbar -> Value();
}


void EMBeScrollbarContainer::Hide()
{
	fScrollbar -> Hide();
}


EMOrientation EMBeScrollbarContainer::Orientation()
{
	if(fScrollbar -> Orientation() == B_HORIZONTAL)
		return EM_HORIZONTAL;
	return EM_VERTICAL;
}


void EMBeScrollbarContainer::SetFrame(EMRect frame)
{
	if(Frame() == frame)
		return;
/*
	if(fScrollbar -> Orientation() == B_VERTICAL)
		frame.m_vRight = frame.m_vLeft + B_V_SCROLL_BAR_WIDTH; // The standard BeOS scrollbar size
	else
		frame.m_vBottom = frame.m_vTop + B_V_SCROLL_BAR_WIDTH; // The standard BeOS scrollbar size, should really be B_H_SCROLL_BAR_HEIGTH
*/
	if(fScrollbar -> Orientation() == B_HORIZONTAL)
	{
//		frame.m_vLeft++;
		frame.m_vTop++;
//		frame.m_vRight--;
//		frame.m_vBottom--;
	}

	fScrollbar -> ResizeTo(frame.GetWidth(), frame.GetHeight());
	fScrollbar -> MoveTo(frame.m_vLeft, frame.m_vTop);
}


void EMBeScrollbarContainer::SetProportion(float proportion)
{
	fScrollbar -> SetProportion(proportion);
}


void EMBeScrollbarContainer::SetRange(float min, float max)
{
	if(max <= min)
		fScrollbar -> SetRange(0, 0);
	else
		fScrollbar -> SetRange(min, max);
}


void EMBeScrollbarContainer::SetSteps(int32 small, int32 big)
{
	fScrollbar -> SetSteps((float)small, (float)big);
}


void EMBeScrollbarContainer::SetValue(int32 value)
{
	fScrollbar -> SetValue((float)value);
}


void EMBeScrollbarContainer::Show()
{
	fScrollbar -> Show();
}

