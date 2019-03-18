#ifndef KEYRECORDER_BUTTON_H
#define KEYRECORDER_BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>


class Button {
    sf::Texture m_textureNormal;
    sf::Texture m_textureActive;
    sf::Sprite m_sprite;
    std::function<bool()> performAction;
    bool m_active;
public:
    template<typename T>
    void updateButtonBehaviour(const std::function<bool(T*)>& function, T* callOn){
        performAction = std::bind(function, callOn);
    }

    explicit Button(const std::string& file_name);

    bool isClicked(const sf::Vector2u& mouseClick);

    void clickButton(bool surpressToggle);

    void draw(sf::RenderWindow* window) const;

    bool isActive() const;

    void setPos(const sf::Vector2f& position);

    void setPos(float x, float y);

    void resetButton();

    sf::Vector2f next(float margin) const;
};


#endif //KEYRECORDER_BUTTON_H
