#include "EMBeTextControlContainer.h"

#ifdef PLATFORM_BEOS

#include "EMGUIGlobals.h"

#include <TextView.h>

EMBeTextControlContainer::EMBeTextControlContainer(EMRect frame,
	const char* text, uint32 resizeMode)
	:
	EMTextControl(false)
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

	BRect oRect(frame.m_vLeft, frame.m_vTop, frame.m_vRight, frame.m_vBottom);

	fTextControl = new EMBeTextControl(this, oRect, text, vResizingMode);
}


EMBeTextControlContainer::~EMBeTextControlContainer()
{
}


EMRect EMBeTextControlContainer::Frame() const
{
	BRect oRect = fTextControl -> Frame();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}


void* EMBeTextControlContainer::GetNativeView() const
{
	return static_cast<void*>(fTextControl);
}


void EMBeTextControlContainer::Hide()
{
	fTextControl -> Hide();
}


void EMBeTextControlContainer::InitComponent()
{
	fTextControl -> SetTarget(fTextControl);
}


void EMBeTextControlContainer::Invalidate()
{
	fTextControl -> Invalidate();
}


void EMBeTextControlContainer::SelectAll()
{
	fTextControl -> TextView() -> SelectAll();
}


void EMBeTextControlContainer::SetFocus()
{
	fTextControl -> MakeFocus();
}


void EMBeTextControlContainer::SetFrame(EMRect frame)
{
	if(Frame() == frame)
		return;
	fTextControl -> ResizeTo(frame.GetWidth(), frame.GetHeight());
	fTextControl -> MoveTo(frame.m_vLeft, frame.m_vTop);
}


void EMBeTextControlContainer::SetText(const char* text)
{
	fTextControl -> SetText(text);
}


void EMBeTextControlContainer::Show()
{
	fTextControl -> Show();
}


void EMBeTextControlContainer::SetMaxBytes(int32 maxBytes)
{
	fTextControl -> TextView() -> SetMaxBytes(maxBytes);
}


const char* EMBeTextControlContainer::Text()
{
	return fTextControl -> Text();
}

#endif


