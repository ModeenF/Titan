/*******************************************************
* Creator: Martin Rudefelt
* Component: none
* Portability: non-native
*-------------------------------------------------------
* Contains some native code
*******************************************************/

#include "EMGlobals.h"

#ifndef __EM_KEYBOARD_GLOBALS
#define __EM_KEYBOARD_GLOBALS

enum EMKeyboardModifierFlags
{
	EM_SHIFT_KEY = 0x00000001,
	EM_COMMAND_KEY = 0x00000002,
	EM_CONTROL_KEY = 0x00000004,
	EM_CAPS_LOCK = 0x00000008,
	EM_SCROLL_LOCK = 0x00000010,
	EM_NUM_LOCK	= 0x00000020,
	EM_OPTION_KEY = 0x00000040,
	EM_MENU_KEY	= 0x00000080,
	EM_LEFT_SHIFT_KEY = 0x00000100,
	EM_RIGHT_SHIFT_KEY = 0x00000200,
	EM_LEFT_COMMAND_KEY = 0x00000400,
	EM_RIGHT_COMMAND_KEY = 0x00000800,
	EM_LEFT_CONTROL_KEY = 0x00001000,
	EM_RIGHT_CONTROL_KEY = 0x00002000,
	EM_LEFT_OPTION_KEY = 0x00004000,
	EM_RIGHT_OPTION_KEY = 0x00008000
};

#ifdef PLATFORM_BEOS

enum EMCommonKeys
{
	EM_BACKSPACE = 0x08,
	EM_RETURN = 0x0a,
	EM_ENTER = 0x0a,
	EM_SPACE = 0x20,
	EM_TAB = 0x09,
	EM_ESCAPE = 0x1b,
	EM_SUBSTITUTE = 0x1a,

	EM_LEFT_ARROW = 0x1c,
	EM_RIGHT_ARROW = 0x1d,
	EM_UP_ARROW = 0x1e,
	EM_DOWN_ARROW = 0x1f,

	EM_INSERT = 0x05,
	EM_DELETE = 0x7f,
	EM_HOME = 0x01,
	EM_END = 0x04,
	EM_PAGE_UP = 0x0b,
	EM_PAGE_DOWN = 0x0c,

	EM_FUNCTION_KEY = 0x10
};

enum EMFunctionKeys
{
	EM_F1_KEY = 0x02,
	EM_F2_KEY = 0x03,
	EM_F3_KEY = 0x04,
	EM_F4_KEY = 0x05,
	EM_F5_KEY = 0x06,
	EM_F6_KEY = 0x07,
	EM_F7_KEY = 0x08,
	EM_F8_KEY = 0x09,
	EM_F9_KEY = 0x0a,
	EM_F10_KEY = 0x0b,
	EM_F11_KEY = 0x0c,
	EM_F12_KEY = 0x0d,
	EM_PRINT_KEY = 0x0e,
	EM_SCROLL_KEY = 0x0f,
	EM_PAUSE_KEY = 0x10
};

#endif


#endif // __EM_KEYBOARD_GLOBALS
