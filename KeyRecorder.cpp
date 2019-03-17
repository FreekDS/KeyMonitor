#include "KeyRecorder.h"
#include <iostream>
#include <fstream>

void KeyRecorder::start() {
    if (my_thread == nullptr) {
        halt = false;
        my_thread = new std::thread(&KeyRecorder::monitorKeys, this);
    }
}

void KeyRecorder::stop() {
    if (my_thread != nullptr) {
        halt = true;
        my_thread->join();
        delete my_thread;
        my_thread = nullptr;
    } else {
        std::cerr << "Cannot stop keystroke thread as it does not exist" << std::endl;
    }
}

KeyRecorder::KeyRecorder() : my_thread(nullptr), halt(false) {}

void KeyRecorder::monitorKeys() {
    while (!halt) {
        Sleep(5);
        for (int i = 0; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                InputType key = getKey(i);
                if (key == KEY_UNKNOWN)
                    continue;
                if (key_count.find(key) != key_count.end()) {
                    key_count[key]++;
                } else {
                    key_count[key] = 1;
                }
                do {
                    Sleep(10);
                } while (GetAsyncKeyState(i) == -32767);
            }
        }
    }
}

KeyRecorder::~KeyRecorder() {
    // Clean up thread
    if (my_thread != nullptr) {
        halt = true;
        my_thread->join();
        delete my_thread;
        my_thread = nullptr;
    }
}

void KeyRecorder::createLoggingFile(const std::string &file_name) {
    std::ofstream out(file_name + ".log");
    if (!out.is_open())
        throw std::runtime_error("Unable to open file " + file_name);
    out << *this;
    out.close();
}

int KeyRecorder::operator[](InputType key) {
    return key_count[key];
}

std::ostream &operator<<(std::ostream &os, const KeyRecorder &recorder) {
    for (auto &it : recorder.key_count) {
        os << getKeyString(it.first) << " -> " << it.second << std::endl;
    }
    return os;
}