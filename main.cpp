#include <iostream>
#include "KeyRecorder.h"
#include <map>

using namespace std;

int main() {
    KeyRecorder recorder;
    while (true) {
        recorder.start();
    }
    return EXIT_SUCCESS;
}

