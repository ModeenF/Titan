/*******************************************************
* Creator: Martin Rudefelt
* Portability: native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_MENU_CONTAINER
#define __EM_BE_MENU_CONTAINER

#include "EMBeMenu.h"
#include "EMMenu.h"

#include <list>
#include <string>

class EMMenuItem;

class EMBeMenuContainer : public EMMenu
{
public:
							EMBeMenuContainer(string* name);
							~EMBeMenuContainer();

			bool 			AddItem(EMMenu*);
			bool 			AddItem(EMMenuItem*);
			bool 			AddItem(EMMenu*, int32 index);
			bool 			AddItem(EMMenuItem*, int32 index);

			bool 			AddSeparatorItem();

			void			SetFrame(EMRect);
			EMRect 			Frame() const;

			EMMenu* 		GetMenu(string*);
			EMMenuItem* 	GetMenuItem(string*);
			const char* 	GetName();

			void* 			GetNativeView() const;
			void 			Hide();

			bool 			RemoveItem(EMMenu*);
			bool 			RemoveItem(EMMenuItem*);

			void 			Show();

			bool			GetEnabled();
			void			SetEnabled(bool);

			EMMenuItem*		GetMenuItem(uint32);

private:
			void			SetMessageTarget(void*);

private:
		//	EMListener* 	m_opApplicationMessageTarget;
			EMBeMenu* 		m_opNativeMenu;
			list<EMMenu*> 	m_oMenus;
			list<EMMenuItem*> m_oMenuItems;
};

#endif

