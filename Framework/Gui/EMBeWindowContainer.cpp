#include "EMBeWindowContainer.h"

#include "EMBeWindow.h"
#include "EMView.h"

EMBeWindowContainer	::	EMBeWindowContainer(EMRect rect, const char* name,
		const EMWindowType type)
{
	BRect oRect(rect.m_vLeft, rect.m_vTop, rect.m_vRight, rect.m_vBottom);
	switch(type)
	{
		case EM_WINDOW_NORMAL:
			m_opWindow = new EMBeWindow(this, oRect, name, B_TITLED_WINDOW,
				B_ASYNCHRONOUS_CONTROLS);
			break;
		case EM_WINDOW_NUDGE:
			m_opWindow = new EMBeWindow(this, oRect, name, B_DOCUMENT_WINDOW,
				B_ASYNCHRONOUS_CONTROLS);
			break;
		case EM_WINDOW_UNRESIZABLE:
			m_opWindow = new EMBeWindow(this, oRect, name, B_TITLED_WINDOW,
				B_ASYNCHRONOUS_CONTROLS | B_NOT_RESIZABLE);
			break;
		case EM_WINDOW_TOOLBOX:
			m_opWindow = new EMBeWindow(this, oRect, name, B_FLOATING_WINDOW,
				B_ASYNCHRONOUS_CONTROLS | B_NOT_RESIZABLE);
			break;
		case EM_WINDOW_POPUP:
			m_opWindow = new EMBeWindow(this, oRect, name,
				B_NO_BORDER_WINDOW_LOOK, B_MODAL_ALL_WINDOW_FEEL,
				B_ASYNCHRONOUS_CONTROLS | B_NOT_RESIZABLE
					| B_NO_WORKSPACE_ACTIVATION);
			break;
		default:
			EMDebugger("EMBeWindowContainer: Window type not allowed:"
				" EM_WINDOW_UNKNOWN");
	}
}


EMBeWindowContainer	::	~EMBeWindowContainer()
{
}


void
EMBeWindowContainer	::	AddChild(EMGUIComponent* p_opView)
{
	m_opWindow -> AddChild((BView*) p_opView -> GetNativeView());
	p_opView -> InitComponent();
}


EMRect
EMBeWindowContainer	::	Bounds() const
{
	BRect oRect = m_opWindow -> Bounds();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}



EMRect
EMBeWindowContainer	::	Frame() const
{
	BRect oRect = m_opWindow -> Frame();
	return EMRect(oRect.left, oRect.top, oRect.right, oRect.bottom);
}


void*
EMBeWindowContainer	::	GetNativeView() const
{
	return (void*) m_opWindow;
}


void
EMBeWindowContainer	::	Hide()
{
	m_opWindow -> Hide();
}


bool
EMBeWindowContainer	::	IsHidden()
{
	return m_opWindow -> IsHidden();
}


bool
EMBeWindowContainer	::	Lock()
{
	return m_opWindow -> Lock();
}


void
EMBeWindowContainer	::	MoveTo(int32 x, int32 y)
{
	m_opWindow -> MoveTo((float)x, (float)y);
}


void
EMBeWindowContainer	::	SetBounds(EMRect p_oBounds)
{
	m_opWindow -> MoveTo(p_oBounds.m_vLeft, p_oBounds.m_vTop);
	m_opWindow -> ResizeTo(p_oBounds.GetWidth(), p_oBounds.GetHeight());
}


void
EMBeWindowContainer	::	SetFrame(EMRect frame)
{
	if(Frame() == frame)
		return;

	if(Frame().m_vTop != frame.m_vTop || Frame().m_vLeft != frame.m_vLeft)
		m_opWindow -> MoveTo(frame.m_vLeft, frame.m_vTop);

	if(Frame().GetWidth() != frame.GetWidth()
		|| Frame().GetHeight() != frame.GetHeight())
		m_opWindow -> ResizeTo(frame.GetWidth(), frame.GetHeight());
}


void
EMBeWindowContainer	::	SetSizeLimits(int32 minW, int32 maxW, int32 minH,
			int32 maxH)
{
	m_opWindow -> SetSizeLimits(minW, maxW, minH, maxH);
}


void
EMBeWindowContainer	::	SetTitle(const char* p_vpTitle)
{
	m_opWindow -> SetTitle(p_vpTitle);
}


void
EMBeWindowContainer	::	Show()
{
	m_opWindow -> Show();
}


void
EMBeWindowContainer	::	Unlock()
{
	m_opWindow -> Unlock();
}


