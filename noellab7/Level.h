#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct Data
{
	const int numRows = 0;
	Data(int _rows) :
		numRows{ _rows }
	{
		for (int i = 0; i < _rows; i++)
		{
			data.push_back(std::vector<int>({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }));
			shape.push_back(std::vector<sf::RectangleShape>({
				{ sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
				sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
				sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
				sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
				sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape() }
			}));
		}
	}

	std::vector<std::vector<int>> data =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};

	std::vector<std::vector<sf::RectangleShape>> shape =
	{
		{ sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
		sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
		sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
		sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape(),
		sf::RectangleShape(),sf::RectangleShape(),sf::RectangleShape() }
	};
};

class Level
{
private:
	sf::FloatRect inView;
	sf::FloatRect placeableArea;
	sf::RenderWindow* window;
public:
	Level(sf::RenderWindow& _window);

	void LevelEditor();
	int currentBlockType = 1;

	void setup();
	void draw();

	bool reset = false;

	const int numCols = 15;

	Data levels[9];
	int currentLevel = 0;

	int lastIntersectedRow = 0;
	int lastIntersectedColumn = 0;

	sf::Texture texBlock;
	sf::Texture texSpike;
	sf::Texture texFlag;
	sf::Texture texBounce;
	
};

