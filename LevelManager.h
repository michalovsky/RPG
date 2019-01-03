#pragma once
#include "Player.h"
#include "Enemy.h"

class LevelManager
{
public:
	LevelManager() = delete;
	static std::string update(std::unique_ptr<Player> & player);
	static int getRequireExperience();
	static void getExperience(std::unique_ptr<Player> &, std::unique_ptr<Enemy> &);
private:
	static int requireExperience, requireDistanceHits, requireMeleeHits;
};
