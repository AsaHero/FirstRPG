#pragma once
#include "Entities.h"

class State
{
private:
	
protected:
	sf::RenderWindow* window;
	bool quit;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> KeyBinds;
	// Protected Functions
	virtual void initKeyBinds() = 0;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

public:
	State(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys);
	const bool& getQuit() const;
	virtual void checkQuit() = 0;
	
	virtual void updateMousePos();
	virtual void updateInput(const float& frame) = 0;
	virtual void endState() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

