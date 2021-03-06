#pragma once
#include "Wrapper.h"
#include "StatusBar.h"
#include "Text.h"
#include "HUD.h"

using vectorOfCharacters = std::vector<std::pair<std::unique_ptr<Wrapper>, std::unique_ptr<StatusBar>>>;

class Draw
{
public:
	Draw(sf::RenderWindow & win);
	void drawPlayer(std::unique_ptr<Wrapper> & player);
	void drawNpcs(vectorOfCharacters & npcs);
	void drawEnemies(vectorOfCharacters & enemies);
	void drawEnemiesStatusBar(vectorOfCharacters & enemies);
	void drawStatusBar(StatusBar & statusBar);
	void drawObstacles(std::vector<std::unique_ptr<Wrapper>> & obstacles);
	void drawProjectiles(std::vector<std::unique_ptr<Wrapper>> & projectiles);
	void drawItems(std::vector<std::unique_ptr<Wrapper>> & items);
	void drawHUD(HUD & hud);
	void drawText(std::vector<std::unique_ptr<Text>> & texts);
	void drawRect(Rect & rect);
	void drawRects(std::vector<std::unique_ptr<Wrapper>> & tests);
	void drawRects(vectorOfCharacters & enemies);
private:
	void drawHUDInventory(std::vector<std::unique_ptr<Wrapper>> & HUDItems);
	void drawHUDEquipment(std::vector<std::unique_ptr<Wrapper>> & HUDEquipment);
	void drawHUDSlots(std::vector<std::unique_ptr<Rect>> & HUDInventorySlots);
	sf::RenderWindow & window;
};
