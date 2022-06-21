#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
private:

	enum movingDirection { UP, DOWN, LEFT, RIGHT };
	sf::Sprite sprite;
	float movespeed;
	bool isMovingInDirection[4];
	bool walking;
	sf::Vector2f nextPosition;
	sf::Vector2f previousPosition;

public:

	Player();
	Player(sf::Texture& pTexture, sf::Vector2f pStartingPosition);
	void setingMoveDirectionOnKeyPressed();
	void movement();
	sf::Vector2f getNextPosition();
	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const;
	void stopMovement();
	void setPosition(sf::Vector2f pPosition);
};

#endif // !PLAYER_H
