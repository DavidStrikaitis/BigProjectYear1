// this will be used as a standard template for levels, this wont be used in the final game and will be removed
// this can act as game.h this will just make it easier to split up code
#ifndef BLANK_H
#define BLANK_H

#include<SFML/Graphics.hpp>

class Blank
{
public:
	Blank();  // standard constructor
	~Blank(); // standard deconstructor (probably wont be used)

	void processEvents(sf::Event t_event);    // used to handle all new events outside key presses
	void processUpdate(sf::Time t_deltaTime); // all update events
	void render(sf::RenderWindow& t_window);  // used to render all objects in the scene

private:
	void processKeys(sf::Event t_event);      // handles all key inputs
};

#endif // !BLANK_H