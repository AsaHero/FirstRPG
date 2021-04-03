#include "MainMenuState.h"
void MainMenuState::initKeyBinds()
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

void MainMenuState::initFont()
{
	this->font.loadFromFile("Fonts/FunGames.otf");
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys)
{
	this->initKeyBinds();
	this->initFont();
		
	this->buttons = new Button(15.f, 25.f, 150.f, 50.f, "NEW GAME", &this->font,
		sf::Color(80, 75, 75),
		sf::Color(50, 40, 40),
		sf::Color(100, 100, 100)
	);


	shape.setSize(sf::Vector2f(window->getSize()));
	shape.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	delete buttons;
}

void MainMenuState::endState()
{
	std::cout << "Game is endding!!" << std::endl;
}
void MainMenuState::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->KeyBinds.at("CLOSE"))))
		this->quit = true;
}
void MainMenuState::updateInput(const float& dt)
{
	this->checkQuit();
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
	this->buttons->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(shape);
	
	this->buttons->render(target);
}