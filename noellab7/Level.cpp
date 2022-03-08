#include "Level.h"
#include <iostream>
Level::Level(sf::RenderWindow& _window) :
	window{ &_window }, 
	levels{ Data(76),Data(76),Data(76),
		Data(76),Data(76),Data(76),
		Data(76),Data(76),Data(76) }
{
	levels[0].data =
	{
		{ 0,0,2,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,2,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,2,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,1,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,4,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,4,1,1,1,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,4,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,4,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 2,1,1,1,0,0,0,1,1,1,1,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,4,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,4,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,3,1,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
		{ 2,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};
}

void Level::setup()
{
	reset = false;
	texBlock.loadFromFile("ASSETS/IMAGES/block.png");
	texSpike.loadFromFile("ASSETS/IMAGES/spike.png");
	texFlag.loadFromFile("ASSETS/IMAGES/flag.png");
	texBounce.loadFromFile("ASSETS/IMAGES/bounce.png");
	for (int row = 0; row < levels[currentLevel].numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (levels[currentLevel].data[row][col] == 1) levels[currentLevel].shape[row][col].setTexture(&texBlock);
			if (levels[currentLevel].data[row][col] == 2) levels[currentLevel].shape[row][col].setTexture(&texSpike);
			if (levels[currentLevel].data[row][col] == 3) levels[currentLevel].shape[row][col].setTexture(&texFlag);
			if (levels[currentLevel].data[row][col] == 4) levels[currentLevel].shape[row][col].setTexture(&texBounce);
			levels[currentLevel].shape[row][col].setSize(sf::Vector2f(40.f, 40.f));
			levels[currentLevel].shape[row][col].setPosition(row * 40, col * 40);

			if (row == levels[currentLevel].numRows - 1 && col == numCols - 1)
			{
				float width = (levels[currentLevel].shape[row][col].getPosition().x + levels[currentLevel].shape[row][col].getSize().x)
					- levels[currentLevel].shape[0][0].getPosition().x;
				placeableArea.width = width;
				placeableArea.height = 600;
				placeableArea.top = levels[currentLevel].shape[0][0].getPosition().y;
				placeableArea.left = levels[currentLevel].shape[0][0].getPosition().x;
			}
		}
	}
}

void Level::LevelEditor()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		currentBlockType = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		currentBlockType = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		currentBlockType = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		currentBlockType = 4;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i mouse = sf::Mouse::getPosition(*window);
		sf::Vector2f mousePos = window->mapPixelToCoords(mouse);
		if (placeableArea.contains(mousePos))
		{
			for (int row = 0; row < levels[currentLevel].numRows; row++)
			{
				for (int col = 0; col < numCols; col++)
				{
					if (levels[currentLevel].shape[row][col].getGlobalBounds().contains(mousePos))
					{
						levels[currentLevel].data[row][col] = currentBlockType;
						if (currentBlockType == 1) levels[currentLevel].shape[row][col].setTexture(&texBlock);
						if (currentBlockType == 2) levels[currentLevel].shape[row][col].setTexture(&texSpike);
						if (currentBlockType == 3) levels[currentLevel].shape[row][col].setTexture(&texFlag);
						if (currentBlockType == 4) levels[currentLevel].shape[row][col].setTexture(&texBounce);
					}
				}
			}
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		sf::Vector2i mouse = sf::Mouse::getPosition(*window);
		sf::Vector2f mousePos = window->mapPixelToCoords(mouse);
		if (placeableArea.contains(mousePos))
		{
			for (int row = 0; row < levels[currentLevel].numRows; row++)
			{
				for (int col = 0; col < numCols; col++)
				{
					if (levels[currentLevel].shape[row][col].getGlobalBounds().contains(mousePos))
					{
						levels[currentLevel].data[row][col] = 0;
						levels[currentLevel].shape[row][col].setTexture(nullptr);
					}
				}
			}
		}
	}
}

void Level::draw()
{
	
	inView = sf::FloatRect(window->getView().getCenter() - (window->getView().getSize() / 2.f), window->getView().getSize());
	for (int row = 0; row < levels[currentLevel].numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (levels[currentLevel].data[row][col] > 0)
			{
				if (levels[currentLevel].shape[row][col].getGlobalBounds().intersects(inView)) window->draw(levels[currentLevel].shape[row][col]);
			}
		}
	}
}


