#include "MainMenuState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event event;
	
	// Clock
	sf::Clock dClock;
	float dt;
	
	// States
	std::stack<State*> staties;
	std::map<std::string, int> supportedKeys;
	

	// Private Functions
	void initWindow();
	void initKeys();
	void initStates();

public:
	// Costructors & Destructor
	Game();
	virtual ~Game();

	/*Functions*/

	//Regular
	void endAppliction();

	// Update
	void updateEvent();
	void updateDt();
	void update();

	// Render
	void render();
	
	// Run
	void run();

};

