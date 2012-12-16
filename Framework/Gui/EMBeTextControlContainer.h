/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_TEXT_CONTROL_CONTAINER
#define __EM_BE_TEXT_CONTROL_CONTAINER

#include "EMBeTextControl.h"
#include "EMTextControl.h"

class EMBeTextControlContainer : public EMTextControl
{
public:
							EMBeTextControlContainer(EMRect, const char* text,
									uint32 resizeMode);
							~EMBeTextControlContainer();

			void 			InitComponent();

			EMRect			Frame() const;
			void 			SetFrame(EMRect);

			void* 			GetNativeView() const;
			void 			Hide();
			void 			Show();

			void 			Invalidate();

			void 			SelectAll();
			void 			SetFocus();
			void 			SetText(const char*);
			void 			SetMaxBytes(int32);

			const char* 	Text();

			bool			IsEnabled();
			void			Enable(bool);
			void			GetSelection(int32&, int32&);
			void			SetSelection(int32, int32);

private:
			EMBeTextControl*fTextControl;
};

#endif

