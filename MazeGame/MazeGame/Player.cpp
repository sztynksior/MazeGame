#include "Player.h"

Player::Player()
{
}

Player::Player(sf::Texture& pTexture, sf::Vector2f pStartingPosition)
{
    this->sprite.setTexture(pTexture);
    this->sprite.setPosition(pStartingPosition);
    this->walking = false;
    this->movespeed = 1.0;

    for (bool direction : this->isMovingInDirection)
    {
        direction = false;
    }
}

void Player::setingMoveDirectionOnKeyPressed()
{
    sf::Vector2f position = this->sprite.getPosition();
    int spriteSize = this->sprite.getTexture()->getSize().x;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (walking == false)
        {
            nextPosition.y = position.y - spriteSize;

            this->isMovingInDirection[UP] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (walking == false)
        {
            nextPosition.y = position.y + spriteSize;
            this->isMovingInDirection[DOWN] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (walking == false)
        {
            nextPosition.x = position.x - spriteSize;
            this->isMovingInDirection[LEFT] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (walking == false)
        {
            nextPosition.x = position.x + spriteSize;
            this->isMovingInDirection[RIGHT] = true;
            walking = true;
        }
    }
}

void Player::movement()
{
    sf::Vector2f position = this->sprite.getPosition();
    int spriteSize = this->sprite.getTexture()->getSize().x;

    if (walking == true)
    {
        if (this->isMovingInDirection[UP] == true)
        {
            position.y -= movespeed;
            this->sprite.setPosition(position);

            if (position.y <= nextPosition.y)
            {
                this->sprite.setPosition(nextPosition);
                walking = false;
                this->isMovingInDirection[UP] = false;
            }
        }

        if (this->isMovingInDirection[DOWN] == true)
        {
            position.y += movespeed;
            this->sprite.setPosition(position);

            if (position.y >= nextPosition.y)
            {
                this->sprite.setPosition(nextPosition);
                walking = false;
                this->isMovingInDirection[DOWN] = false;
            }
        }
        if (this->isMovingInDirection[LEFT] == true)
        {
            position.x -= movespeed;
            this->sprite.setPosition(position);

            if (position.x <= nextPosition.x)
            {
                this->sprite.setPosition(nextPosition);
                walking = false;
                this->isMovingInDirection[LEFT] = false;
            }
        }
        if (this->isMovingInDirection[RIGHT] == true)
        {
            position.x += movespeed;
            this->sprite.setPosition(position);

            if (position.x >= nextPosition.x)
            {
                this->sprite.setPosition(nextPosition);
                walking = false;
                this->isMovingInDirection[RIGHT] = false;
            }
        }
    }
}

sf::Vector2f Player::getNextPosition()
{
    return this->nextPosition;
}

void Player::draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const
{
    pTarget.draw(this->sprite, pStates);
}

void Player::stopMovement()
{
    this->walking = false;

    for (bool i : this->isMovingInDirection)
    {
        i = false;
    }
}

