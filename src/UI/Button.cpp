#include <UI/Button.h>
#include <iostream>

void Button::clickButton(bool toggle) {
    if (m_active) {
        if(toggle)
            m_sprite.setTexture(m_textureNormal);
        m_active = false;
    } else {
        m_sprite.setTexture(m_textureActive);
        m_active = true;
        if(!performAction() && toggle){
            m_sprite.setTexture(m_textureNormal);
        }
    }
}

bool Button::isClicked(const sf::Vector2u &mouseClick) {
    return m_sprite.getGlobalBounds().contains(mouseClick.x, mouseClick.y);
}

Button::Button(const std::string &file_name) : m_active(true) {
    if (!m_textureNormal.loadFromFile("res/" + file_name + "0.png")) {
        throw std::invalid_argument("There is no such file '" + file_name + "0.png'!");
    }
    if (!m_textureActive.loadFromFile("res/" + file_name + "1.png")) {
        throw std::invalid_argument("There is no such file '" + file_name + "1.png'!");
    }
    m_sprite.setTexture(m_textureNormal);
}

void Button::draw(sf::RenderWindow *window) const {
    window->draw(m_sprite);
}


bool Button::isActive() const {
    return m_active;
}

void Button::setPos(const sf::Vector2f &position) {
    m_sprite.setPosition(position);
}

void Button::setPos(float x, float y) {
    m_sprite.setPosition(x, y);
}

void Button::resetButton() {
    m_sprite.setTexture(m_textureNormal);
    m_active = false;
}

sf::Vector2f Button::next(float margin) const {
    return {m_sprite.getPosition().x + m_sprite.getGlobalBounds().width + margin, m_sprite.getPosition().y};
}
