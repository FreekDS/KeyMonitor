#ifndef KEYRECORDER_APPLICATION_H
#define KEYRECORDER_APPLICATION_H

#include <SFML/Graphics.hpp>
#include <KeyRecorder.h>
#include <UI/Button.h>

namespace KeyMonitor {

    class Application {
    private:
        sf::RenderWindow m_window;
        KeyRecorder m_keyRecorder;
        void handleEvents();
        std::vector<Button*> m_buttons;
        Button* m_stopButton;
        void resetButtons();
    public:

        virtual ~Application();

        Application(u_int width, u_int height, const std::string& title);

        void run();

    };

} // namespace KeyMonitor


#endif //KEYRECORDER_APPLICATION_H
