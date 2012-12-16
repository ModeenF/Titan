#include "EMBeFactory.h"

#include "EMBeBitmapContainer.h"
#include "EMBeBoxContainer.h"
#include "EMBeButtonContainer.h"
#include "EMBeFilePanelContainer.h"
#include "EMBeMenuContainer.h"
#include "EMBeMenuBarContainer.h"
#include "EMBeMenuItemContainer.h"
#include "EMBePopUpMenuContainer.h"
#include "EMBeScrollbarContainer.h"
#include "EMBeTextControlContainer.h"
#include "EMBeTextViewContainer.h"
#include "EMBeViewContainer.h"
#include "EMBeWindowContainer.h"

#include <string>
#include <vector>


EMBitmap*
EMBeFactory	::	CreateBitmap(const void* nativeBitmap)
{
	return new EMBeBitmapContainer(nativeBitmap);
}


EMBorder*
EMBeFactory	::	CreateBorder(EMRect frame, uint32 resizeMode,
							EMBorderStyle style, const char* label)
{
	return new EMBeBoxContainer(frame, resizeMode, style, label);
}


EMButton*
EMBeFactory	::	CreateButton(const EMRect frame,	const char* label,
							uint32 message, uint32 resizeMode,
							uint32 commandID)
{
	return new EMBeButtonContainer(frame, label, message,
		resizeMode, commandID);
}


EMFileWindow*
EMBeFactory	::	CreateFileWindow(EMFilePanelMode mode, const char* title,
						bool multiSelect, const char* saveDefaultText,
						vector<string>* visibleExtensions,
						const char* startDirectory, uint32 message)
{
	return new EMBeFilePanelContainer(mode, title, multiSelect, saveDefaultText,
								visibleExtensions, startDirectory, message);
}


EMMenu*
EMBeFactory	::	CreateMenu(string* name)
{
	return new EMBeMenuContainer(name);
}


EMMenuBar*
EMBeFactory	::	CreateMenuBar()
{
//	return NULL;
	return new EMBeMenuBarContainer();
}


EMMenuItem*
EMBeFactory	::	CreateMenuItem(string* name, uint32 command)
{
	return new EMBeMenuItemContainer(name, command);
}


EMPopUpMenu*
EMBeFactory	::	CreatePopUpMenu()
{
	return new EMBePopUpMenuContainer();
}


EMScrollbar*
EMBeFactory	::	CreateScrollbar(EMRect frame, float min, float max,
						EMOrientation orientation)
{
	return new EMBeScrollbarContainer(frame, min, max, orientation);
}


EMTextControl*
EMBeFactory	::	CreateTextControl(EMRect frame, const char* text, uint32 resizeMode)
{
	return new EMBeTextControlContainer(frame, text, resizeMode);
}


EMTextView*
EMBeFactory	::	CreateTextView(EMRect frame, const char* name, uint32 resizeMode)
{
	return new EMBeTextViewContainer(frame, name, resizeMode);
}


EMView*
EMBeFactory	::	CreateView(const EMRect frame, uint32 resizeMode, bool dblBuf)
{
	return new EMBeViewContainer(frame, resizeMode, dblBuf);
}


EMWindow*
EMBeFactory	::	CreateWindow(const EMRect frame, const char* name,
						const EMWindowType type)
{
	return new EMBeWindowContainer(frame, name, type);
}

