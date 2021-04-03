#include "State.h"
// Private function


// Constructor & Destructor
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->quit = false;
	this->supportedKeys = supportedKeys;
}

const bool& State::getQuit() const
{
	return this->quit;
}
void State::updateMousePos()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
// Funtion 