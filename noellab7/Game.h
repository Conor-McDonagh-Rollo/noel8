#pragma once
#include "Level.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

enum class gameState {
	Game,
	LevelEditor,
	Win
};

class Game
{
public:
	Game();
	void run();
private:
	gameState state;

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setup();

	Level level;
	Player player[2];

	sf::Texture bgtex;
	sf::Sprite bg;
	sf::Sprite bg2;

	sf::Texture wintex;
	sf::Sprite win;

	sf::View view[5];

	sf::RectangleShape divider = sf::RectangleShape(sf::Vector2f(10.f,600.f));

	sf::RenderWindow m_window; // main SFML window
	bool m_exitGame; // control exiting game

	// EDITOR STUFF
	sf::Vector2f editorOffset;
	sf::Vector2f editorOffset2;
};

