#pragma once
#include "GameState.h"
class MainMenuState :public State
{
private:
	sf::RectangleShape shape;
	sf::Font font;

	Button* buttons;

	void initKeyBinds() override;
	void initFont();

public:
	
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~MainMenuState();

	void updateInput(const float& frame);
	void endState();
	void checkQuit() override;
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

