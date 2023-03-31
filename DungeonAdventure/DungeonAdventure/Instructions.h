// instructions screens
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include<SFML/Graphics.hpp>

class Instructions
{
public:
	Instructions();  // standard constructor
	~Instructions(); // standard deconstructor (probably wont be used)

	void processEvents(sf::Event t_event);    // used to handle all new events outside key presses
	void processUpdate(sf::Time t_deltaTime); // all update events
	void render(sf::RenderWindow& t_window);  // used to render all objects in the scene

private:
	void processKeys(sf::Event t_event);      // handles all key inputs
};

#endif // !INSTRUCTIONS_H