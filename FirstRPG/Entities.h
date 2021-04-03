#pragma once

#include <iostream>
#include <fstream>

#include "Button.h"

#include <vector>
#include <map>
#include <stack>

class Entities
{
private:

protected:
	sf::RectangleShape shape;
	float movmentSpeed;

public:

	Entities();
	
	virtual ~Entities();

	virtual void move(const float& dt, const float dir_x, const float dir_y);
	virtual void update(const float& dt);

	virtual void render(sf::RenderTarget* target);


};

