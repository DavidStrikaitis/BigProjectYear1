// game header File, for authors go to "Game.cpp"
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

#include"Globals.h"
#include"Blank.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	static GameMode s_currentGameMode;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	Blank blankGameMode;

};

#endif // !GAME_HPP

