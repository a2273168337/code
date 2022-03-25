#pragma once
#include <string>
#include <iostream>
#include "Player.h"
#include "PlayGame.h"
using namespace std;

int Player::Money() {
	return money;
}

void Player::ChangeMoney(int value) {
	if (PlayGame::GetPlayGame()->GetKey() == -1) return;
	money += value;
}

string Player::Name() {
	return name;
}