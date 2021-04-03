#include "Entities.h"

Entities::Entities()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::White);
	this->movmentSpeed = 100.f;
}

Entities::~Entities()
{
}

void Entities::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move(dir_x * movmentSpeed* dt, dir_y* movmentSpeed* dt);
}

void Entities::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt,-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, -1.f);
}

void Entities::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
