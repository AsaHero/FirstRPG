#include "Game.h"

// Private Functions
void Game::initWindow()
{
	std::string titlename = "";
	sf::VideoMode videoMode;
	unsigned frame_limit = 120;
	bool vertival_sync_enabled = false;

	std::ifstream ifs;

	ifs.open("Config/window.ini");
	if (ifs.is_open())
	{
		std::getline(ifs, titlename);
		ifs >> videoMode.width >> videoMode.height;
		ifs >> frame_limit;
		ifs >> vertival_sync_enabled;
	}
	ifs.close();

	window = new sf::RenderWindow(videoMode, titlename);
	window->setFramerateLimit(frame_limit);
	window->setVerticalSyncEnabled(vertival_sync_enabled);
}

void Game::initKeys()
{
	unsigned value = 0;
	std::string key = "";

	std::ifstream ifn("Config/supportedkeys.ini");
	
	if (ifn.is_open())
	{
		while (!ifn.eof())
		{
				ifn >> key >> value;
				this->supportedKeys[key] = sf::Keyboard::Key(value);
		}
	}
	ifn.close();
}
void Game::initStates()
{
	this->staties.push(new MainMenuState(this->window, &this->supportedKeys));
}

// Costructors & Destructor
Game::Game()
{
	
	this->initWindow();
	this->initKeys();
	this->initStates();
	
}
Game::~Game()
{
	delete this->window;
}

//Functions

void Game::endAppliction()
{
	std::cout << "Ending application" << "\n";
}

void Game::updateEvent()
{
	while (window->pollEvent(this->event))
	{
		if (event.type == sf::Event::Closed) window->close();
	}
}
void Game::updateDt()
{
	this->dt = this->dClock.restart().asSeconds();
}
void Game::update()
{
	this->updateEvent();
	
	if (!this->staties.empty())
	{
		this->staties.top()->update(this->dt);
		if (this->staties.top()->getQuit())
		{
			this->staties.top()->endState();
			delete this->staties.top();
			this->staties.pop();
		}
		
	}
	else
	{
		this->endAppliction();
		this->window->close();
	}
	
}
void Game::render()
{
	this->window->clear();

	if (!this->staties.empty())
		this->staties.top()->render();
	
	this->window->display();
}
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
