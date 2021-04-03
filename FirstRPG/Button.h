#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

enum BTN_COLOR
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button
{
private:

	short unsigned btnPressed;

	sf::RectangleShape button;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:

	/*Constructor & Destructor*/
	Button(float x, float y, float width, float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	/*Function*/
	const bool isPressed() const;

	/*Update and Render*/
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};