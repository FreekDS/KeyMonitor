#include <UI/Button.h>

void Button::clickButton() {
    if(m_active){
        setInitColor();
        m_active = false;
    }else{
        m_temp.setOutlineColor(sf::Color::Red);
        m_temp.setFillColor(sf::Color::Green);
        m_active = true;
    }
    performAction();
}

bool Button::isClicked(const sf::Vector2u &mouseClick) {
    return m_temp.getGlobalBounds().contains(mouseClick.x, mouseClick.y);
}

Button::Button() : m_temp(sf::Vector2f(30,30)), m_active(false) {
    m_temp.setOutlineThickness(2.0f);
    setInitColor();
    m_temp.setPosition(100, 100);
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(m_temp);
}

void Button::setInitColor() {
    m_temp.setOutlineColor(sf::Color::Green);
    m_temp.setFillColor(sf::Color::Blue);
}

bool Button::isActive() const {
    return m_active;
}
