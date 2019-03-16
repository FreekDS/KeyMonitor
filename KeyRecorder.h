#ifndef KEYLOGGER_KEYRECORDER_H
#define KEYLOGGER_KEYRECORDER_H

#include "Keyboard.h"
#include <windows.h>
#include <thread>
#include <map>

class KeyRecorder {
private:
    std::thread* _thread;
    bool _halt;
    std::map<InputType, int> _key_count;
public:
    KeyRecorder();

    void start();
    void stop();
};


#endif //KEYLOGGER_KEYRECORDER_H
