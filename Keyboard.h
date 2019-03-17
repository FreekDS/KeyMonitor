#ifndef KEYLOGGER_KEYBOARD_H
#define KEYLOGGER_KEYBOARD_H

#include <windows.h>
#include <string>

/**
 * Enumeration of all detectable keys (windows only currently)
 */
enum InputType {
    KEY_SPACE = VK_SPACE,
    KEY_CONTROL = VK_CONTROL,
    KEY_SHIFT = VK_SHIFT,
    KEY_ENTER = VK_END,
    KEY_CAPS = VK_CAPITAL,
    KEY_ESCAPE = VK_ESCAPE,

    KEY_MOUSE_LEFT = VK_LBUTTON,
    KEY_MOUSE_RIGHT = VK_RBUTTON,

    KEY_0 = 0x30,
    KEY_1 = 0x31,
    KEY_2 = 0x32,
    KEY_3 = 0x33,
    KEY_4 = 0x34,
    KEY_5 = 0x35,
    KEY_6 = 0x36,
    KEY_7 = 0x37,
    KEY_8 = 0x38,
    KEY_9 = 0x39,

    KEY_A = 0x41,
    KEY_B = 0x42,
    KEY_C = 0x43,
    KEY_D = 0x44,
    KEY_E = 0x45,
    KEY_F = 0x46,
    KEY_G = 0x47,
    KEY_H = 0x48,
    KEY_I = 0x49,
    KEY_J = 0x4A,
    KEY_K = 0x4B,
    KEY_L = 0x4C,
    KEY_M = 0x4D,
    KEY_N = 0x4E,
    KEY_O = 0x4F,
    KEY_P = 0x50,
    KEY_Q = 0x51,
    KEY_R = 0x52,
    KEY_S = 0x53,
    KEY_T = 0x54,
    KEY_U = 0x55,
    KEY_V = 0x56,
    KEY_W = 0x57,
    KEY_X = 0x58,
    KEY_Y = 0x59,
    KEY_Z = 0x5A,

    KEY_UNKNOWN = -1
};

/**
 * This function will get a string representation of a key.
 * @param key Key you want string representation for.
 * @return String representation of the key
 */
std::string getKeyString(InputType key);

/**
 * Convert integer to its InputType enum equivalent.
 * @param key Integer to convert to InputType
 * @return InputType
 */
InputType getKey(int key);

#endif //KEYLOGGER_KEYBOARD_H
