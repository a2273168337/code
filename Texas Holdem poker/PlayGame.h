#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "Player.h"
#include "PlayerFactory.h"
using namespace std;
class PlayGame {
private:
	PlayGame(){}
	PlayGame(PlayGame& _PlayGame) = delete;
	static PlayGame* pointPlayGame;
	deque<Player> players;
	int key = -1;
public:
	static PlayGame* GetPlayGame();
	bool RunOneTurn();
	int GetKey();
};



