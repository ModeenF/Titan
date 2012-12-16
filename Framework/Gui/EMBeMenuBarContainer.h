/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifdef PLATFORM_BEOS

#ifndef __EM_BE_MENU_BAR_CONTAINER
#define __EM_BE_MENU_BAR_CONTAINER

#include "EMMenuBar.h"
#include "EMBeMenuBar.h"

#include <list>
#include <string>

class BMenu;
class EMBeMenuBar;
class EMCommand;
class EMListener;

class EMBeMenuBarContainer : public EMMenuBar
{
public:
							EMBeMenuBarContainer();
							~EMBeMenuBarContainer();

			bool			AddItem(EMMenu*);
			bool 			AddItem(EMMenu*, int32 index);

			void			SetFrame(EMRect);
			EMRect 			Frame() const;

			EMMenu* 		GetMenu(string* name);
			void* 			GetNativeView() const;

			void 			Show();
			void 			Hide();

			void 			InitComponent();

			bool			Notify(uint32 message);
			bool 			Notify(list<EMListener*>*, uint32 message);

			bool 			RemoveItem(EMMenu*);

			bool			SetMarked(uint32 menuID, uint32 menuItemID, bool);
			bool			SetEnabled(uint32 menuID, bool);
			bool			SetEnabled(uint32 menuID, uint32 menuItemID, bool);

			EMMenuItem*		GetLastTriggeredMenuItem();


//			void SetApplicationMessageTarget(EMListener* p_opMessageTarget);
//			bool 			MessageReceived(EMListenerRepository* sender,
//									 uint32 message);

private:
			list<EMMenu*> 	m_oMenus;
//			EMListener* 	m_opApplicationMessageTarget;
			EMBeMenuBar* 	m_opNativeMenuBar;
};

#endif

#endif

