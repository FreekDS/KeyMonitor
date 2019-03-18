#include <Application.h>
#include <iostream>

using namespace KeyMonitor;

void Application::run() {
    while (m_window.isOpen()) {
        m_window.clear();
        for (Button *button : m_buttons) {
            button->draw(&m_window);
        }
        m_stopButton->draw(&m_window);
        m_window.display();
        handleEvents();
    }
}

Application::Application(u_int width, u_int height, const std::string &title) : m_window(sf::VideoMode(width, height),
                                                                                         title) {

    sf::Image icon;
    icon.loadFromFile("res/icon.png");
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    Button* play = new Button("play");
    play->updateButtonBehaviour<KeyRecorder>(&KeyRecorder::start, &m_keyRecorder);
    play->setPos(5,5);
    Button* pause = new Button("pause");
    pause->updateButtonBehaviour<KeyRecorder>(&KeyRecorder::pause, &m_keyRecorder);
    pause->setPos(play->next(5));
    m_stopButton = new Button("stop");
    m_stopButton->updateButtonBehaviour<KeyRecorder>(&KeyRecorder::stop, &m_keyRecorder);
    m_stopButton->setPos(pause->next(5));
    m_buttons.push_back(play);
    m_buttons.push_back(pause);

    m_window.setVerticalSyncEnabled(true);
}

void Application::handleEvents() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2u mouseClick{
                    static_cast<u_int>(event.mouseButton.x),
                    static_cast<u_int>(event.mouseButton.y)};
            if(m_stopButton->isClicked(mouseClick)){
                resetButtons();
                m_stopButton->clickButton(true);
            }
            for (Button *button : m_buttons) {
                if (button->isClicked(mouseClick)){
                    resetButtons();
                    m_stopButton->resetButton();
                    button->clickButton(false);
                }
            }
        }
    }
}

Application::~Application() {
    for (auto &m_button : m_buttons) {
        delete m_button;
        m_button = nullptr;
    }
}

void Application::resetButtons() {
    for (auto &m_button : m_buttons) {
        m_button->resetButton();
    }
}
