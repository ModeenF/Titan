/*******************************************************
* Creator: Martin Rudefelt
* Portability: non-native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_MENU_BAR
#define __EM_MENU_BAR

class EMCommand;
class EMMenu;
class EMMenuItem;

#include "EMGUIComponent.h"

#include <string>

// Menu items with an ID equal or higher than this offset do not trigger commands,
// instead a message is generated (EM_MENU_ITEM_TRIGGERED)
const uint32 COMMAND_NOT_TRIGGERED_MENU_ITEM_OFFSET = 10000;

class EMMenuBar : public EMGUIComponent
{
public:
	virtual 				~EMMenuBar();

	virtual bool 			AddItem(EMMenu*) = 0;
	virtual bool 			AddItem(EMMenu*, int32 index) = 0;

	virtual EMMenuItem* 	GetLastTriggeredMenuItem() = 0;

	virtual EMMenu* 		GetMenu(string* name) = 0;
	static	EMMenuBar* 		Instance();

	virtual bool 			RemoveItem(EMMenu*) = 0;
//	virtual bool 			RemoveItem(EMMenuItem*) = 0;

	static	void 			SetInstance(EMMenuBar*);
	virtual bool 			SetMarked(uint32 menu, uint32 menuItem, bool) = 0;
	virtual bool 			SetEnabled(uint32 menu, bool) = 0;
	virtual bool 			SetEnabled(uint32 menu, uint32 menuItem, bool) = 0;

//	virtual EMMenuItem* 	GetMenuItem(string* p_opName) = 0;


protected:
							EMMenuBar();

//protected:
//	static	uint32 			m_vLastTriggeredMenuItemID;

private:
	static	EMMenuBar* 		m_opInstance;
};

#endif
