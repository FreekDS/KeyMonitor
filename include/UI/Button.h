#ifndef KEYRECORDER_BUTTON_H
#define KEYRECORDER_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>


class Button {
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RectangleShape m_temp;
    std::function<void()> performAction;
    bool m_active;
    void setInitColor();
public:
    template<typename T>
    void updateButtonBehaviour(const std::function<void(T*)>& function, T* callOn){
        performAction = std::bind(function, callOn);
    }

    Button();

    bool isClicked(const sf::Vector2u& mouseClick);

    void clickButton();

    void draw(sf::RenderWindow& window) const;

    bool isActive() const;
};


#endif //KEYRECORDER_BUTTON_H
