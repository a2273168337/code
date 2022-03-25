#pragma once
#include<iostream>
#include<string>
#include <vector>
#include "Card.h"
using namespace std;

class Player {
public:
	virtual void Behavior() = 0;
	void ChangeMoney(int);
	int Money();
	string Name();
private:
	int money;
	string name;
};
