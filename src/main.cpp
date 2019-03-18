#include <iostream>
#include "KeyRecorder.h"
#include <map>
#include <Application.h>

using namespace std;

int main(int argc, char* argv[]) {
    KeyMonitor::Application app(500, 500, "Key monitor");
    try{
        app.run();
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

