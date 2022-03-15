#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"

class Player
{
private:
	sf::Texture tex;
	sf::Sprite body;
	bool grounded = true;
	sf::Vector2f vel;

	const int HEIGHT = 55;
	const int WIDTH = 40;

	sf::FloatRect below;
	sf::FloatRect above;
	sf::FloatRect right;
	sf::FloatRect left;
	
public:
	void Setup();
	void Draw(sf::RenderWindow& window);
	void Update(Level& l);
	void ProcessKeys(); 
	void ProcessKeys2();
	sf::FloatRect GetBounds() { return body.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	void changeColour() { tex.loadFromFile("ASSETS/IMAGES/player2.png"); }

	bool dead = false;
	bool win = false;
};

