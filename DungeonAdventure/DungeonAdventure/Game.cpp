/// <summary>
/// Dungeon adventure
/// 
/// Game made by: David Strikaitis, Rachel O'Connor, Ricky Rechtackova
/// 
/// Concept by: Ricky Rechtackova
/// Design by: Ricky Rechtackova and Rachel O'Connor
/// 
/// </summary>

#include "Game.h"
#include <iostream>

GameMode Game::s_currentGameMode = GameMode::menu;
bool Game::s_closeGame = false;

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ SCREEN_WIDTH, SCREEN_HEIGHT, 32U }, "Dungeon Adventure" }
{
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			s_closeGame = true;
		}
	}
	switch (s_currentGameMode)
	{
	case GameMode::Blank:
		blankGameMode.processEvents(newEvent);
		break;
	case GameMode::menu:
		menuGameMode.processEvents(newEvent);
		break;
	case GameMode::instructions:
		InstructionsGameMode.processEvents(newEvent);
		break;
	case GameMode::levels:
		levelsGameMode.processEvents(newEvent);
		break;
	case GameMode::shop:
		shopGameMode.processEvents(newEvent);
		break;
	default:
		break;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (s_closeGame)
	{
		m_window.close();
	}
	switch (s_currentGameMode)
	{
	case GameMode::Blank:
		blankGameMode.processUpdate(t_deltaTime);
		break;
	case GameMode::menu:
		menuGameMode.processUpdate(t_deltaTime);
		break;
	case GameMode::instructions:
		InstructionsGameMode.processUpdate(t_deltaTime);
		break;
	case GameMode::levels:
		levelsGameMode.processUpdate(t_deltaTime);
		break;
	case GameMode::shop:
		shopGameMode.processUpdate(t_deltaTime);
		break;
	default:
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (s_currentGameMode)
	{
	case GameMode::Blank:
		blankGameMode.render(m_window);
		break;
	case GameMode::menu:
		menuGameMode.render(m_window);
		break;
	case GameMode::instructions:
		InstructionsGameMode.render(m_window);
		break;
	case GameMode::levels:
		levelsGameMode.render(m_window);
		break;
	case GameMode::shop:
		shopGameMode.render(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}

