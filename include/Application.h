#ifndef KEYRECORDER_APPLICATION_H
#define KEYRECORDER_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <KeyRecorder.h>
#include <UI/Button.h>

namespace KeyMonitor {

    class Application {
    private:
        sf::RenderWindow m_window;
        sf::View m_view;
        KeyRecorder m_keyRecorder;
        void handleEvents();
        Button startButton;
    public:

        Application(u_int width, u_int height, const std::string& title);

        void run();
    };

} // namespace KeyMonitor


#endif //KEYRECORDER_APPLICATION_H
