#ifndef KEYLOGGER_KEYBOARD_H
#define KEYLOGGER_KEYBOARD_H

#include <windows.h>



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

std::string getKeyString(InputType key){
    switch(key){
        case KEY_0:
            return "0";
        case KEY_1:
            return "1";
        case KEY_2:
            return "2";
        case KEY_3:
            return "3";
        case KEY_4:
            return "4";
        case KEY_5:
            return "5";
        case KEY_6:
            return "6";
        case KEY_7:
            return "7";
        case KEY_8:
            return "8";
        case KEY_9:
            return "9";
        case KEY_A:
            return "A";
        case KEY_B:
            return "B";
        case KEY_C:
            return "C";
        case KEY_D:
            return "D";
        case KEY_E:
            return "E";
        case KEY_F:
            return "F";
        case KEY_G:
            return "G";
        case KEY_H:
            return "H";
        case KEY_I:
            return "I";
        case KEY_J:
            return "J";
        case KEY_K:
            return "K";
        case KEY_L:
            return "L";
        case KEY_M:
            return "M";
        case KEY_N:
            return "N";
        case KEY_O:
            return "O";
        case KEY_P:
            return "P";
        case KEY_Q:
            return "Q";
        case KEY_R:
            return "R";
        case KEY_S:
            return "S";
        case KEY_T:
            return "T";
        case KEY_U:
            return "U";
        case KEY_V:
            return "V";
        case KEY_W:
            return "W";
        case KEY_X:
            return "X";
        case KEY_Y:
            return "Y";
        case KEY_Z:
            return "Z";
        case KEY_SHIFT:
            return "SHIFT";
        case KEY_ENTER:
            return "ENTER";
        case KEY_CAPS:
            return "CAPS";
        case KEY_SPACE:
            return "SPACE";
        case KEY_CONTROL:
            return "CONTROL";
        case KEY_MOUSE_RIGHT:
            return "MOUSE_RIGHT";
        case KEY_MOUSE_LEFT:
            return "MOUSE_LEFT";
        case KEY_ESCAPE:
            return "ESCAPE";
        default:
            return "UNKNOWN";
    }
}

InputType getKey(int key){
    switch(key) {
        case KEY_0:
            return KEY_0;
        case KEY_1:
            return KEY_1;
        case KEY_2:
            return KEY_2;
        case KEY_3:
            return KEY_3;
        case KEY_4:
            return KEY_4;
        case KEY_5:
            return KEY_5;
        case KEY_6:
            return KEY_6;
        case KEY_7:
            return KEY_7;
        case KEY_8:
            return KEY_8;
        case KEY_9:
            return KEY_9;
        case KEY_A:
            return KEY_A;
        case KEY_B:
            return KEY_B;
        case KEY_C:
            return KEY_C;
        case KEY_D:
            return KEY_D;
        case KEY_E:
            return KEY_E;
        case KEY_F:
            return KEY_F;
        case KEY_G:
            return KEY_G;
        case KEY_H:
            return KEY_H;
        case KEY_I:
            return KEY_I;
        case KEY_J:
            return KEY_J;
        case KEY_K:
            return KEY_K;
        case KEY_L:
            return KEY_L;
        case KEY_M:
            return KEY_M;
        case KEY_N:
            return KEY_N;
        case KEY_O:
            return KEY_O;
        case KEY_P:
            return KEY_P;
        case KEY_Q:
            return KEY_Q;
        case KEY_R:
            return KEY_R;
        case KEY_S:
            return KEY_S;
        case KEY_T:
            return KEY_T;
        case KEY_U:
            return KEY_U;
        case KEY_V:
            return KEY_V;
        case KEY_W:
            return KEY_W;
        case KEY_X:
            return KEY_X;
        case KEY_Y:
            return KEY_Y;
        case KEY_Z:
            return KEY_Z;
        case KEY_SHIFT:
            return KEY_SHIFT;
        case KEY_ENTER:
            return KEY_ENTER;
        case KEY_CAPS:
            return KEY_CAPS;
        case KEY_SPACE:
            return KEY_SPACE;
        case KEY_CONTROL:
            return KEY_CONTROL;
        case KEY_MOUSE_LEFT:
            return KEY_MOUSE_LEFT;
        case KEY_MOUSE_RIGHT:
            return KEY_MOUSE_RIGHT;
        case KEY_ESCAPE:
            return KEY_ESCAPE;
        default:
            return KEY_UNKNOWN;
    }
}

#endif //KEYLOGGER_KEYBOARD_H
