/*******************************************************
* Creator: Martin Rudefelt
* Portability: non-native
*-------------------------------------------------------
*
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_BE_FACTORY
#define __EM_BE_FACTORY

#include "EMFactory.h"
#include "EMGUIGlobals.h"
#include "EMRect.h"

#include <string>

class EMBitmap;
class EMBorder;
class EMButton;
class EMFileWindow;
class EMMenu;
class EMMenuBar;
class EMMenuItem;
class EMPopUpMenu;
class EMScrollbar;
class EMTextControl;
class EMTextView;
class EMView;
class EMWindow;

class EMBeFactory : public EMFactory
{
public:
			EMBitmap* 		CreateBitmap(const void* nativeBitmap);

			EMBorder* 		CreateBorder(EMRect, uint32 resizingMode,
									 EMBorderStyle, const char* label);

			EMButton* 		CreateButton(EMRect, const char* label,
									uint32 message, uint32 resizingMode,
									uint32 commandID);

			EMFileWindow* 	CreateFileWindow(EMFilePanelMode,
									const char* title, bool multiSelect,
									const char* saveDefaultText,
									vector<string>* visibleExtensions,
									const char* startDir, uint32 message);

			EMMenu* 		CreateMenu(string* name);

			EMMenuBar* 		CreateMenuBar();

			EMMenuItem* 	CreateMenuItem(string* name, uint32 command);

			EMPopUpMenu* 	CreatePopUpMenu();

			EMScrollbar* 	CreateScrollbar(EMRect, float min, float max,
									EMOrientation);

			EMTextControl* 	CreateTextControl(EMRect, const char* text,
									uint32 resizeMode);

			EMTextView* 	CreateTextView(EMRect, const char* name,
									uint32 resizeMode);

			EMView* 		CreateView(EMRect, uint32 resizeMode,
									bool doubleBuffer);

			EMWindow* 		CreateWindow(EMRect, const char* name,
									EMWindowType);
};

#endif

