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
	//��key�Ա���Ը���player�Ľ��

	vector<Card> Poker = GetPoker();
	//����һ���˿�

	deque<Player> GamePlayers = players;
	deque<vector<Card> > cards(players.size());
	vector<Card> publicCard;
	//�õ����в�����Ա�Ķ���

	unsigned long long sumMoney = 0;//�ܽ��
	int numCard = 0; //�ѷ��˿˶�������
	GamePlayers[0].ChangeMoney(-10);
	sumMoney += 10;
	GamePlayers[1].ChangeMoney(-5);
	sumMoney += 5;
	//��С��ע
	
	GetCard(cards, Poker, numCard, 2);
	//ÿ�˷���
	

	//��һ�ָ�ע
	// 
	GetPublicCard(publicCard, Poker, numCard, 3);
	//��һ�ַ���
	// 
	//�ڶ��ָ�ע
	// 
	GetPublicCard(publicCard, Poker, numCard, 1);
	//�ڶ��ַ���
	// 
	//�����ָ�ע
	
	GetPublicCard(publicCard, Poker, numCard, 1);
	//�����ַ���
	// 
	//���һ�ָ�ע
	
	GetFinalCard(publicCard,cards);

	//��������ʤ����Ա
	
	key = -1;
	//�ر�key
}
