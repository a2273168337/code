#pragma once
#include <iostream>
#include <queue>
#include "Player.h"
#include "Ai_Player.h"
#include "Human_Player.h"
using namespace std;

class PlayerFactory {
public:
	Player* GetPlayer(string chess);
};