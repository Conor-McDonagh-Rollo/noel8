#include "Player.h"
#include <iostream>

void Player::Setup()
{
	tex.loadFromFile("ASSETS/IMAGES/player.png");
	body.setTexture(tex);
	body.setPosition(360, 545);
	dead = false;
	win = false;

	below = sf::FloatRect(sf::Vector2f(body.getPosition().x, body.getPosition().y + HEIGHT), sf::Vector2f(WIDTH, 5));
	above = sf::FloatRect(body.getPosition() - sf::Vector2f(0, 5), sf::Vector2f(body.getGlobalBounds().width, 5));
	right = sf::FloatRect(sf::Vector2f(body.getPosition().x + WIDTH, body.getPosition().y + 2),sf::Vector2f(1, HEIGHT - 4));
	left = sf::FloatRect(sf::Vector2f(body.getPosition().x - 5, body.getPosition().y + 2), sf::Vector2f(1, HEIGHT - 4));
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::Update(Level& l)
{
	
	if (!grounded)
	{
		body.move(0, vel.y);
		vel.y += 0.5f;
		if (body.getPosition().y >= 545)
		{
			body.setPosition(body.getPosition().x, 545);
			grounded = true;
			vel.y = 0;
		}
	}

	float x = body.getPosition().x;
	float y = body.getPosition().y;

	//below
	below.left = x;
	below.top = y + HEIGHT;
	//above
	above.left = x;
	above.top = y - 5;
	//right
	right.left = x + WIDTH;
	right.top = y + 2;
	//left
	left.left = x - 5;
	left.top = y + 2;
	
	for (int row = 0; row < l.levels[l.currentLevel].numRows; row++)
	{
		for (int col = 0; col < l.numCols; col++)
		{
			if (l.levels[l.currentLevel].data[row][col] > 0)
			{
				float d = sqrt(pow((l.levels[l.currentLevel].shape[row][col].getPosition().x - x),2)
					+ pow((l.levels[l.currentLevel].shape[row][col].getPosition().y - y),2));
				if (d < 100)
				{
					if (l.levels[l.currentLevel].data[row][col] == 1)
					{
						if (above.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							if (vel.y < 0) vel.y = 0;
						}
						if (right.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							if (vel.x > 0) vel.x = 0;
						}
						if (left.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							if (vel.x < 0) vel.x = 0;
						}
						//GROUND CHECKS
						if (!below.intersects(l.levels[l.currentLevel].shape[l.lastIntersectedRow][l.lastIntersectedColumn].getGlobalBounds()) && body.getPosition().y < 545)
						{
							grounded = false;
						}
						if (below.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							grounded = true;
							vel.y = 0;
							body.setPosition(body.getPosition().x, l.levels[l.currentLevel].shape[row][col].getPosition().y - body.getGlobalBounds().height);
							l.lastIntersectedRow = row;
							l.lastIntersectedColumn = col;
						}
					}
					else if (l.levels[l.currentLevel].data[row][col] == 2)
					{
						if (below.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()) && vel.y > 0)
						{
							dead = true;
						}
					}
					else if (l.levels[l.currentLevel].data[row][col] == 3)
					{
						if (body.getGlobalBounds().intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							win = true;
						}
					}
					else if (l.levels[l.currentLevel].data[row][col] == 4)
					{
						if (below.intersects(l.levels[l.currentLevel].shape[row][col].getGlobalBounds()))
						{
							if (vel.y > 0 && vel.y < 15)
							{
								vel.y *= -1.25f;
							}
							else if (vel.y >= 15)
							{
								vel.y *= -1.f;
							}
						}
					}
				}
			}
		}
	}

	body.move(vel.x, 0);
}

void Player::ProcessKeys()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		vel.x = -5;
	}
	else
	{
		if (vel.x == -5) vel.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		vel.x = 5;
	}
	else
	{
		if (vel.x == 5) vel.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && grounded)
	{
		grounded = false;
		vel.y = -10.f;
	}
}

void Player::ProcessKeys2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		vel.x = -5;
	}
	else
	{
		if (vel.x == -5) vel.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		vel.x = 5;
	}
	else
	{
		if (vel.x == 5) vel.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && grounded)
	{
		grounded = false;
		vel.y = -10.f;
	}
}
