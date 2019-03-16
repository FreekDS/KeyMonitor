#include <iostream>
#include "Keyboard.h"
#include <map>
#include <fstream>

using namespace std;

void resetPressedKeys(std::map<InputType, bool>& pressed){
    for (auto &it : pressed) {
        it.second = false;
    }
}

int main() {

    std::map<InputType, bool> pressed;
    std::map<InputType, int> count;

    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);

    bool run =true;
    while(run) {
        Sleep(10);
        for(int i = 0; i<= 190; i++){
            if(GetAsyncKeyState(i) == -32767){
                InputType key = getKey(i);
                if(key == KEY_UNKNOWN)
                    continue;
                if(count.find(key) != count.end()){
                    count[key]++;
                }
                else{
                    count[key] = 1;
                }
                do{
                    Sleep(10);
                } while(GetAsyncKeyState(i) == -32767);
                if(key == KEY_ESCAPE)
                    run = false;
            }
        }
    }

    std::ofstream out("logging.info");

    for(auto& it : count){
        std::cout << getKeyString(it.first) << " pressed " << it.second << " times" << endl;
        out << getKeyString(it.first) << " pressed " << it.second << " times" << endl;
    }

    out.close();
    return EXIT_SUCCESS;
}

