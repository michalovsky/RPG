#include "Obstacle.h"



Obstacle::Obstacle(bool destr, int hpp) : destructable(destr), hp(hpp) {}

void Obstacle::setCurrentHp(int inp)
{
	hp = inp;
}

void Obstacle::setDestructable(bool inp)
{
	destructable = inp;
}

void Obstacle::setDestroyed(bool inp)
{
	destroyed = inp;
}

int Obstacle::getCurrentHp() const
{
	return hp;
}

bool Obstacle::isDestructable() const
{
	return destructable;
}

int Obstacle::isDestroyed() const
{
	return destroyed;
}

