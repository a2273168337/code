#pragma once
#include "PlayerFactory.h"

Player* PlayerFactory::GetPlayer(string chess) {
	Player* p = nullptr;
	if (chess == "Human") p = new Human_Player();
	else if (chess == "AI") p = new Ai_Player();
	return p;
}