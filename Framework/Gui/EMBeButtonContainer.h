/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_BUTTON_CONTAINER
#define __EM_BE_BUTTON_CONTAINER

#include "EMButton.h"
#include "EMGUIGlobals.h"
#include "EMRect.h"

class EMBeButton;

class EMBeButtonContainer : public EMButton
{
public:
							EMBeButtonContainer(const EMRect p_oFrame,
								const char* p_vpName, uint32 p_vMessage,
								uint32 p_vResizingMode, uint32 p_vCommand);
							~EMBeButtonContainer();

			void 			ExecuteCommand();
			EMRect 			Frame() const;
			void* 			GetNativeView() const;
			void 			InitComponent();
			void 			SetCommand(uint32 p_vCommand);
			void 			SetLabel(const char* p_vpLabel);

			void 			Show();
			void 			Hide();
			void			SetFrame(EMRect);

			bool			IsEnabled();
			void			Enable(bool);

private:
			EMBeButton* 	m_opButton;
			uint32 			m_vCommand;
};

#endif
