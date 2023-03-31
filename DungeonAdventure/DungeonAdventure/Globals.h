#pragma once

const unsigned int SCREEN_WIDTH = 800u;  // width of the screen window
const unsigned int SCREEN_HEIGHT = 600u; // height of the screen window

enum class GameMode
{
	Blank, // used only as a template and maybe for debugging
	menu,
	levels,
	instructions,
	shop
};