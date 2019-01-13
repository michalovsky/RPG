#include "EnemySpawner.h"

int EnemySpawner::amountOfEnemies;

EnemySpawner::EnemySpawner()
{
	// name, hp, attackDamage, attackSpeed, movementSpeed, experience, lootChance
	characterSkeleton = new Skeleton("Skeleton", 200, 5, 3, 1, 70, 1.0f);
	characterSkeletonBerserker = new SkeletonBerserker("Berserker", 400, 40, 5, 4, 1000, 1.0f);
	characterDragon = new Dragon("Dragon", 1000, 25, 2, 1, 400, 1.0f);
}

EnemySpawner::~EnemySpawner()
{
	delete characterSkeleton;
	delete characterSkeletonBerserker;
	delete characterDragon;
}

void EnemySpawner::spawnSkeleton(enemyPair & enemies, sf::Vector2f respawnPosition)
{
	if (!(amountOfEnemies <= MAX_ENEMIES_NUMBER)) return;

	if (respawnPosition == sf::Vector2f{ RANDOM,RANDOM })
	{
		respawnPosition = getRandomPosition();
	}

	amountOfEnemies++;
	Create::createSkeleton(*characterSkeleton, enemies, respawnPosition);
}

void EnemySpawner::spawnSkeletonBerserker(enemyPair & enemies, sf::Vector2f respawnPosition)
{
	if (!(amountOfEnemies <= MAX_ENEMIES_NUMBER)) return;

	if (respawnPosition == sf::Vector2f{ RANDOM,RANDOM })
	{
		respawnPosition = getRandomPosition();
	}

	amountOfEnemies++;
	Create::createSkeletonBerserker(*characterSkeletonBerserker, enemies, respawnPosition);
}

void EnemySpawner::spawnDragon(enemyPair & enemies, sf::Vector2f respawnPosition)
{
	if (!(amountOfEnemies <= MAX_ENEMIES_NUMBER)) return;

	if (respawnPosition == sf::Vector2f{ RANDOM,RANDOM })
	{
		respawnPosition = getRandomPosition();
	}

	amountOfEnemies++;
	Create::createDragon(*characterDragon, enemies, respawnPosition);
}

void EnemySpawner::spawnRandomEnemy(enemyPair & enemies, sf::Vector2f respawnPosition)
{
	switch (getRandomEnemyType())
	{
	case Enemy::EnemyType::SKELETON:
		spawnSkeleton(enemies, respawnPosition);
		break;
	case Enemy::EnemyType::SKELETON_BERSERKER:
		spawnSkeletonBerserker(enemies, respawnPosition);
		break;
	case Enemy::EnemyType::DRAGON:
		spawnDragon(enemies, respawnPosition);
		break;
	}
}

void EnemySpawner::initializeObjectsPositions(std::vector<std::unique_ptr<Tile>>& mapPositions)
{
	for (auto & mp : mapPositions)
	{
		obstacles.push_back(std::unique_ptr<Tile>(new Tile(mp->getPosition(), true, false)));
	}
}

void EnemySpawner::updateObjectsPositions(std::vector<std::unique_ptr<Tile>>& mapPositions)
{
	obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](std::unique_ptr<Tile> & mp) {return mp->isEnemy(); }), obstacles.end());

	for (auto & mp : mapPositions)
	{
		obstacles.push_back(std::unique_ptr<Tile>(new Tile(mp->getPosition(), true, true)));
	}
}

int EnemySpawner::getRandomEnemyType() const
{
	return Random::getRandomNumber(0, 2);
}

sf::Vector2f EnemySpawner::getRandomPosition() const
{
	sf::Vector2i randomPosition = { Random::getRandomNumber(0,MAP_WIDTH),Random::getRandomNumber(0,MAP_HEIGHT) };
	randomPosition = { randomPosition.x * 40, randomPosition.y * 40 };

	while (!isPossibleToAddPosition(randomPosition))
	{
		randomPosition = {Random::getRandomNumber(0,MAP_WIDTH),Random::getRandomNumber(0,MAP_HEIGHT) };
		randomPosition = { randomPosition.x * 40, randomPosition.y * 40 };
	}

	return sf::Vector2f(randomPosition);
}

bool EnemySpawner::isPossibleToAddPosition(sf::Vector2i position) const
{
	for (auto & obstacle : obstacles)
	{
		if (!isPositionFree(position, sf::Vector2i(obstacle->getPosition())))
		{
			return false;
		}
	}
	return true;
}

bool EnemySpawner::isPositionFree(sf::Vector2i positionToCheck, sf::Vector2i obstaclePosition) const
{
	return (!(positionToCheck.x + 40 > obstaclePosition.x &&
		obstaclePosition.x + 40 > positionToCheck.x &&
		positionToCheck.y + 40 > obstaclePosition.y &&
		obstaclePosition.y + 40 > positionToCheck.y));
}

