/// Menu class
/// Will handle all interaction with the menu and will transition between scenes
///
#ifndef MENU_H
#define MENU_H

#include<SFML/Graphics.hpp>
#include"Globals.h"

class Menu
{
public:
	Menu();  // standard constructor
	~Menu(); // standard deconstructor (probably wont be used)

	void processEvents(sf::Event t_event);                                // used to handle all new events outside key presses
	void processUpdate(sf::Time t_deltaTime); // all update events
	void render(sf::RenderWindow& t_window);                              // used to render all objects in the scene

private:
	void processKeys(sf::Event t_event);                                  // handles all key inputs
	void processMouseMove(sf::Event t_event);                             // handles mouse movements
	void processMouseUp();                                                // handles mouse release events
	int mouseInsideButton();                                              // returns which button the mouse is inside
	void setupButtons();                                                  // function to initialise the buttons

	sf::Vector2f m_mouseCoords{ 0.0f,0.0f };                              // the mouse co ordinates based on mouse move

	sf::RectangleShape menuButtons[4];                                    // array of menu buttons
	const int MENU_BUTTON_AMOUNT{ 4 };                                    // number of menu buttons
};

#endif // !MENU_H