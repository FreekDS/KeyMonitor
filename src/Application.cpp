#include <Application.h>
#include <iostream>


using namespace KeyMonitor;

void Application::run() {
    while (m_window.isOpen()) {
        handleEvents();
        m_window.clear(sf::Color::White);
        startButton.draw(m_window);
        m_window.display();
    }
}

Application::Application(u_int width, u_int height, const std::string &title) : m_window(sf::VideoMode(width, height),
                                                                                         title),
                                                                                m_view(m_window.getDefaultView()) {
    m_window.setVerticalSyncEnabled(true);
    startButton.updateButtonBehaviour<KeyRecorder>(&KeyRecorder::start, &m_keyRecorder);

}

void Application::handleEvents() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        if(event.type == sf::Event::MouseButtonPressed){
            if(startButton.isClicked({static_cast<u_int>(event.mouseButton.x), static_cast<u_int>(event.mouseButton.y)})){
                startButton.clickButton();
                if(startButton.isActive())
                    startButton.updateButtonBehaviour<KeyRecorder>(&KeyRecorder::stop, &m_keyRecorder);
                else
                    startButton.updateButtonBehaviour<KeyRecorder>(&KeyRecorder::start, &m_keyRecorder);
            }
        }
    }
}
