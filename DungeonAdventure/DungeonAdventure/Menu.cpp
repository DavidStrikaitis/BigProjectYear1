#include "Menu.h"
#include "Game.h"

/// <summary>
/// default constructor
/// </summary>
Menu::Menu()
{
	setupButtons();
}

/// <summary>
/// default deconstructor
/// </summary>
Menu::~Menu()
{
}

/// <summary>
/// process all different events made by the user
/// </summary>
/// <param name="t_event">passed from game loop to speed up code</param>
void Menu::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type) //user pressed a key
	{
		processKeys(t_event);
	}
	if (sf::Event::MouseMoved == t_event.type)
	{
		processMouseMove(t_event);
	}
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		processMouseUp();
	}
}

/// !!!---Private function---!!!
/// <summary>
/// process any input from the user
/// </summary>
/// <param name="t_event">use this for the key press</param>
void Menu::processKeys(sf::Event t_event)
{

}

/// <summary>
/// sets the coordinates after the mouse has moved
/// </summary>
/// <param name="t_event"></param>
void Menu::processMouseMove(sf::Event t_event)
{
	m_mouseCoords.x = static_cast<float>(t_event.mouseMove.x);
	m_mouseCoords.y = static_cast<float>(t_event.mouseMove.y);
}

void Menu::processMouseUp()
{
	int mouse = mouseInsideButton();
	switch (mouse)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		Game::s_closeGame = true;
		break;
	default:
		break;
	}
}

/// <summary>
/// all update functions will be in here
/// </summary>
/// <param name="t_deltaTime">delta time passed from game</param>
void Menu::processUpdate(sf::Time t_deltaTime)
{
	int inButton = mouseInsideButton();
	if (!(inButton == -1))
	{
		menuButtons[inButton].setFillColor(sf::Color::Green);
	}
	else
	{
		for (int i = 0; i < MENU_BUTTON_AMOUNT; i++)
		{
			menuButtons[i].setFillColor(sf::Color::Red);
		}
	}
}

/// <summary>
/// all items that must be rendered
/// </summary>
/// <param name="t_window">render window from game</param>
void Menu::render(sf::RenderWindow& t_window)
{
	for (int i = 0; i < MENU_BUTTON_AMOUNT; i++)
	{
		t_window.draw(menuButtons[i]);
	}
}

/// <summary>
/// Checks if the mouse inside the button
/// </summary>
/// <returns>returns the button the mouse is in !!!---careful with -1 return---!!!</returns>
int Menu::mouseInsideButton()
{
	int buttonNumber{-1};

	for (int i = 0; i < MENU_BUTTON_AMOUNT; i++)
	{
		if (menuButtons[i].getGlobalBounds().contains(m_mouseCoords))
		{
			buttonNumber = i;
			break;
		}
	}
	return buttonNumber;
}

/// <summary>
/// setup buttons (improve this description later)
/// </summary>
void Menu::setupButtons()
{
	for (int i = 0; i < MENU_BUTTON_AMOUNT; i++)
	{
		menuButtons[i].setFillColor(sf::Color::Red);
		menuButtons[i].setSize({ 150, 50 });
		menuButtons[i].setOrigin({ 75,0 });
		menuButtons[i].setPosition(sf::Vector2f( static_cast<float>(SCREEN_WIDTH / 2) , static_cast<float>((100 * i) + 100)));
	}
}