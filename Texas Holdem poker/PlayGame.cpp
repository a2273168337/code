#pragma once
#include "PlayGame.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


PlayGame* pointPlayGame = nullptr;

PlayGame* PlayGame::GetPlayGame() {
	if (pointPlayGame != nullptr) {
		pointPlayGame = new PlayGame();
	}
	return pointPlayGame;
}

int PlayGame::GetKey() {
	return key;
}

vector <Card>& GetPoker() {
	srand((unsigned int)time(0));
	vector<Card> Poker;
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 4; ++j) {
			Card tempCard(j, i);
			Poker.push_back(tempCard);
		}
	}
	for (int j = 0; j < 5; ++j) {
		for (int i = 0; i < Poker.size(); ++i) {
			swap(Poker[i], Poker[rand() % Poker.size()]);
		}
	}

	return Poker;
}

void GetCard(deque<vector<Card> > &Cards , vector<Card>& Poker, int &numCard, int num) {
	for (int i = 0; i < Cards.size(); ++i) {
		for (int j = 0; j < num; ++j) {
			Cards.front().emplace_back(Poker[numCard++]);
		}
		Cards.emplace_back(Cards.front());
		Cards.pop_front();
	}
}

void GetPublicCard(vector<Card> &PublicCard, vector<Card> &Poker,int &numCard,int num) {
	for (int i = 0; i < num; ++i) {
		PublicCard.emplace_back(Poker[numCard++]);
	}
}

void GetFinalCard(vector<Card>& PublicCard, deque<vector<Card> >& Cards) {
	for (int i = 0; i < Cards.size(); ++i) {
		for (int j = 0; j < PublicCard.size(); ++j) {
			Cards.front().emplace_back(PublicCard[j]);
		}
		Cards.emplace_back(Cards.front());
		Cards.pop_front();
	}
}

bool PlayGame::RunOneTurn(){
	key = 1;
	//打开key以便可以更改player的金币

	vector<Card> Poker = GetPoker();
	//生成一副扑克

	deque<Player> GamePlayers = players;
	deque<vector<Card> > cards(players.size());
	vector<Card> publicCard;
	//拿到所有参赛人员的队列

	unsigned long long sumMoney = 0;//总金币
	int numCard = 0; //已发扑克多少张牌
	GamePlayers[0].ChangeMoney(-10);
	sumMoney += 10;
	GamePlayers[1].ChangeMoney(-5);
	sumMoney += 5;
	//大小跟注
	
	GetCard(cards, Poker, numCard, 2);
	//每人发牌
	

	//第一轮跟注
	// 
	GetPublicCard(publicCard, Poker, numCard, 3);
	//第一轮发牌
	// 
	//第二轮跟注
	// 
	GetPublicCard(publicCard, Poker, numCard, 1);
	//第二轮发牌
	// 
	//第三轮跟注
	
	GetPublicCard(publicCard, Poker, numCard, 1);
	//第三轮发牌
	// 
	//最后一轮跟注
	
	GetFinalCard(publicCard,cards);

	//计算最后获胜的人员
	
	key = -1;
	//关闭key
}
