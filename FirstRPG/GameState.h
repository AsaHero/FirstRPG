#pragma once
#include "State.h"
class GameState : public State
{
private:
	
	Entities player;
	void initKeyBinds() override;
public:

	GameState(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();
	void updateInput(const float& frame);
	void endState();
	void checkQuit() override;
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);

};

