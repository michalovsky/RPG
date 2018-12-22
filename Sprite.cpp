#include "Sprite.h"



Sprite::Sprite(std::string path, int sx, int sy, int dimx, int dimy) : spriteX(sx), spriteY(sy), pathName(path)
{
	offByRectX = offByRectY = 0;
	texture.loadFromFile(pathName);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(dimx, dimy, spriteX, spriteY));

	if (path == "stuff/player.png")
	{
		offByRectX = -16;
		offByRectY = -20;
	}
}

void Sprite::setTextureRect(int dimx, int dimy, int sx, int sy)
{
	sprite.setTextureRect(sf::IntRect(dimx, dimy, sx, sy));
}

void Sprite::setPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f((float)(x + offByRectX), (float)(y + offByRectY)));
}

void Sprite::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position.x + (float)offByRectX, position.y + (float)offByRectY);
}

//getters

std::string Sprite::getPathName()
{
	return pathName;
}

int Sprite::getSpriteX() const
{
	return spriteX;
}

int Sprite::getSpriteY() const
{
	return spriteY;
}

sf::Sprite & Sprite::getSprite()
{
	return sprite;
}

sf::Texture & Sprite::getTexture()
{
	return texture;
}

sf::Vector2f Sprite::getPosition() const
{
	return sprite.getPosition();
}