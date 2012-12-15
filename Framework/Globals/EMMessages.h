/*******************************************************
* Creator: Martin Rudefelt
* Component: none
* Portability: non-native
*-------------------------------------------------------
* Here should messages belonging to the framework
* be defined
*******************************************************/

#ifndef __EM_MESSAGES
#define __EM_MESSAGES

#define EM_MESSAGE_BASE_OFFSET 0x1000 // To avoid native OS and framework message collisions
#define EM_PREDEFINED_MESSAGE_BASE_OFFSET 0x800

// Here follows some message types
const uint32 EM_MOUSE_DOWN = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 1;
const uint32 EM_MOUSE_UP = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 2;
const uint32 EM_MOUSE_MOVED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 3;
const uint32 EM_DRAW = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 4;
//const uint32 EM_QUIT_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 5;
const uint32 EM_SAVE_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 6; // Save chosen in the file dialog
const uint32 EM_FILE_CANCEL = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 7; // Cancel chosen in the file dialog
const uint32 EM_LOAD_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 8; // Load chosen in the file dialog
const uint32 EM_PLAY = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 9;
const uint32 EM_STOP = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 10;
const uint32 EM_SEEK = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 11;
const uint32 EM_LOAD_MEDIA_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 12;
const uint32 EM_CREATE_PROJECT_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 13;
const uint32 EM_LOAD_PROJECT_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 14;
const uint32 EM_SCROLLBAR_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 15;
const uint32 EM_TRACK_FRAME_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 16;
const uint32 EM_CLIP_FRAME_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 17;
const uint32 EM_VIEW_BOUNDS_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 18;
const uint32 EM_KEY_DOWN = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 19;
const uint32 EM_KEY_UP = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 20;
const uint32 EM_MIDI_EVENTS_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 21;
const uint32 EM_DOUBLE_CLICK = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 22;
const uint32 EM_TRACK_REPOSITORY_UPDATED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 23;
const uint32 EM_TEXT_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 24;
const uint32 EM_TEXT_CHANGE_UNDOED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 25;
const uint32 EM_UPDATE_NEEDED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 26;
const uint32 EM_CLIP_REPOSITORY_UPDATED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 27;
const uint32 EM_SETTING_UPDATED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 28;
const uint32 EM_SAVE_PROJECT_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 29;
const uint32 EM_BEGIN_DRAG = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 30;
const uint32 EM_LIST_VIEW_ITEM_LABEL_MAY_CHANGE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 31;
const uint32 EM_LIST_VIEW_ITEM_LABEL_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 32;
const uint32 EM_LIST_VIEW_ITEM_DELETED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 33;
const uint32 EM_GUI_COMPONENT_ENTER_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 34;
const uint32 EM_GUI_COMPONENT_ESC_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 35;
const uint32 EM_GUI_COMPONENT_TAB_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 36;
const uint32 EM_TEXT_CONTROL_UP_ARROW_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 37;
const uint32 EM_TEXT_CONTROL_DOWN_ARROW_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 38;
const uint32 EM_TEXT_CONTROL_LEFT_ARROW_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 39;
const uint32 EM_TEXT_CONTROL_RIGHT_ARROW_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 40;
const uint32 EM_TEXT_CONTROL_END_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 41;
const uint32 EM_TEXT_CONTROL_DELETE_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 42;
const uint32 EM_TEXT_CONTROL_SHIFT_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 43;
const uint32 EM_TEXT_CONTROL_SHIFT_RELEASED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 44;
const uint32 EM_GUI_COMPONENT_GOT_FOCUS = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 45;
const uint32 EM_TEXT_CONTROL_LEFT_MOUSE_BUTTON_DOWN = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 46;
const uint32 EM_TEXT_CONTROL_MENU_SELECTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 47;
const uint32 EM_TEXT_CONTROL_SET_SELECTION = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 48;
const uint32 EM_NETWORK_MESSAGE_ARRIVED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 49;
const uint32 EM_NETWORK_USER_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 50;
const uint32 EM_LIST_BOX_DOUBLE_CLICKED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 51;
//const uint32 EM_QUIT_PRE_REQUESTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 52;
const uint32 EM_DROP = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 53;
const uint32 EM_NETWORK_FILE_ARRIVED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 54;
const uint32 EM_NETWORK_FILE_DONE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 55;
const uint32 EM_DRAG_ENTER = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 56;
const uint32 EM_DRAG_LEAVE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 57;
const uint32 EM_RUBBERBAND_NODES_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 58;
const uint32 EM_RUBBERBAND_NODES_ADDED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 59;
const uint32 EM_RUBBERBAND_NODES_DELETED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 60;
const uint32 EM_RUBBERBAND_VALUES_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 61;
const uint32 EM_RUBBERBAND_POSITIONS_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 62;
const uint32 EM_MEDIA_ENGINE_VIDEO_WORKSIZE_CHANGED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 63;
const uint32 EM_NETWORK_LOST_CONNECTION = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 64;
const uint32 EM_GUI_COMPONENT_SHIFT_TAB_PRESSED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 65;
const uint32 EM_MENU_ITEM_TRIGGERED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 66;
const uint32 EM_NETWORK_USER_FOUND = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 67;
const uint32 EM_NETWORK_USER_SEARCH_ENDED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 68;
const uint32 EM_NETWORK_USER_ADDED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 69;
const uint32 EM_NETWORK_USER_DELETED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 70;
const uint32 EM_RENDERING_HAS_FINNISHED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 71;
const uint32 EM_RENDERING_COULD_NOT_START = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 72;
const uint32 EM_QUIT_PHASE_ONE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 73;
const uint32 EM_QUIT_PHASE_TWO = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 74;
const uint32 EM_QUIT_PHASE_THREE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 75;
const uint32 EM_QUIT_PHASE_FOUR = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 76;
const uint32 EM_QUIT_PHASE_FIVE = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 77;
const uint32 EM_QUIT_PHASE_SIX = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 78;
const uint32 EM_QUIT_ABORTED = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 79;
const uint32 EM_CLOSE_WINDOW = EM_PREDEFINED_MESSAGE_BASE_OFFSET + 80;

#endif

