#include "GameState.h"

void GameState::initKeyBinds()
{
	std::string key = "";
	std::string key_bind = "";

	std::ifstream ifn("Config/keybinds.ini");

	if (ifn.is_open())
	{
		while (ifn >> key_bind >> key)
			this->KeyBinds[key_bind] = this->supportedKeys->at(key);
	}
	ifn.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	this->initKeyBinds();
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Game is endding!!" << std::endl;
}
void GameState::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("CLOSE"))))
		this->quit = true;
}
void GameState::updateInput(const float& dt)
{
	this->checkQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("MOVE_LEFT"))))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("MOVE_RIGHT"))))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("MOVE_DOWN"))))
		this->player.move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("MOVE_UP"))))
		this->player.move(dt, 0.f, -1.f);
	
}

void GameState::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
	this->player.update(dt);
	
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);
}
