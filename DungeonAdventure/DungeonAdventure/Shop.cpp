#include "Shop.h"

/// <summary>
/// default constructor
/// </summary>
Shop::Shop()
{
}

/// <summary>
/// default deconstructor
/// </summary>
Shop::~Shop()
{
}

/// <summary>
/// process all different events made by the user
/// </summary>
/// <param name="t_event">passed from game loop to speed up code</param>
void Shop::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type) //user pressed a key
	{
		processKeys(t_event);
	}
}

/// !!!---Private function---!!!
/// <summary>
/// process any input from the user
/// </summary>
/// <param name="t_event">use this for the key press</param>
void Shop::processKeys(sf::Event t_event)
{

}

/// <summary>
/// all update functions will be in here
/// </summary>
/// <param name="t_deltaTime">delta time passed from game</param>
void Shop::processUpdate(sf::Time t_deltaTime)
{
}

/// <summary>
/// all items that must be rendered
/// </summary>
/// <param name="t_window">render window from game</param>
void Shop::render(sf::RenderWindow& t_window)
{
}
