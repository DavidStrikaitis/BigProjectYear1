// shop screen
#ifndef SHOP_H
#define SHOP_H

#include<SFML/Graphics.hpp>

class Shop
{
public:
	Shop();  // standard constructor
	~Shop(); // standard deconstructor (probably wont be used)

	void processEvents(sf::Event t_event);    // used to handle all new events outside key presses
	void processUpdate(sf::Time t_deltaTime); // all update events
	void render(sf::RenderWindow& t_window);  // used to render all objects in the scene

private:
	void processKeys(sf::Event t_event);      // handles all key inputs
};

#endif // !SHOP_H

