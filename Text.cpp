#include "Text.h"


Text::Text(sf::Color col, std::string type, int font)
	: color(col), fontSize(font), HUDtype(type)
{

}

Text::Text(std::string msg, sf::Vector2f pos, sf::Color col, bool move, int font, bool mid)
	:message(msg), position(pos), color(col), fontSize(font), moving(move), positionMid(mid)
{
	if (moving)
	{
		movementSpeed = 1;
		lifetime = 40;
	}
	else
	{
		movementSpeed = 0;
		lifetime = 150;
	}

	lifeCounter = 0;
	destroyed = false;
}

//setters
void Text::setDestroyed()
{
	destroyed = true;
}

//getters
float Text::getMovementSpeed() const
{
	return movementSpeed;
}

bool Text::isDestroyed() const
{
	return destroyed;
}

sf::Text & Text::getText()
{
	return text;
}

std::string Text::getHUDtype() const
{
	return HUDtype;
}

void Text::update(sf::View view)
{
	if (!set) setup();

	if (positionMid) text.setPosition(view.getCenter().x - 145, view.getCenter().y - 80);

	if (lifeCounter >= lifetime)
	{
		destroyed = true;
	}
	lifeCounter++;
}

void Text::updateHUD(sf::View view, int value, int valueMax)
{
	if (!set) setup();

	if (HUDtype == "HP")
	{
		text.setPosition(view.getCenter().x - 300, view.getCenter().y - 300);

	}
	else if (HUDtype == "EXP")
	{
		text.setPosition(view.getCenter().x - 300, view.getCenter().y - 280);
	}
	else if (HUDtype == "COINS")
	{
		text.setPosition(view.getCenter().x -300, view.getCenter().y -260);
	}

	message = (valueMax != -1) ? (HUDtype + " : " + std::to_string(value) + "/" + std::to_string(valueMax)) : (HUDtype + " : " + std::to_string(value));
	text.setString(message);
}

void Text::setup()
{
	font.loadFromFile("stuff/font.ttf");
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(1);
	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(fontSize);
	text.setPosition(position);
	text.setString(message);
	set = true;
}


Text & Text::operator=(Text other)
{
	font = other.font;
	text = other.text;
	text.setFont(font);
	set = other.set;
	destroyed = other.destroyed;
	message = other.message;
	position = other.position;
	color = other.color;
	fontSize = other.fontSize;
	movementSpeed = other.movementSpeed;
	lifetime = other.lifetime;
	lifeCounter = other.lifeCounter;
	moving = other.moving;
	positionMid = other.positionMid;
	return *this;
}

