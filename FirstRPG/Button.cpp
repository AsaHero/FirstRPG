#include "Button.h"

/*Constructor & destructor*/
Button::Button(float x, float y, float width, float height,
	std::string text, sf::Font* font, sf::Color idleColor,
	sf::Color hoverColor, sf::Color activeColor)
{
	this->btnPressed = BTN_COLOR::BTN_IDLE;

	button.setSize(sf::Vector2f(width, height));
	button.setPosition(x, y);
	button.setFillColor(activeColor);

	this->font = font;
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->text.setFont(*this->font);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(20.5f);
	this->text.setString(text);
	this->text.setPosition(
		(this->button.getSize().x/2.f - this->text.getGlobalBounds().width/3.f), 
		this->button.getSize().y / 2.f + this->text.getGlobalBounds().height / 2.f
	);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->btnPressed == BTN_COLOR::BTN_ACTIVE)
		return true;

	return false;
}

/*Update and Render*/
void Button::update(const sf::Vector2f mousePos)
{
	

	if (this->button.getGlobalBounds().contains(mousePos))
	{
		this->btnPressed = BTN_HOVER;
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->btnPressed = BTN_ACTIVE;
	}
	else
		this->btnPressed = BTN_IDLE;

	switch (this->btnPressed)
	{
	case BTN_IDLE:
		this->button.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->button.setFillColor(this->hoverColor);
		break;
	case BTN_ACTIVE:
		this->button.setFillColor(this->activeColor);
		break;
	default:
		this->button.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->button);
	target->draw(this->text);
}
