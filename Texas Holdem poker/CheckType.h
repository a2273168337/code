#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;

class CheckType {
private:
	static CheckType* PointCheckType;
	CheckType(){}
	CheckType(CheckType& _CheckType) = delete;
	int Straight_Flush_Query(vector<Card>& card);
	int Four_Of_A_Kind_Query(vector<Card>& card);
	int Full_House_Query(vector<Card>& card);
	int Flush_Query(vector<Card>& card);
	int Straight_Query(vector<Card>& card);
	int Three_Of_A_Kind_Query(vector<Card>& card);
	int Two_Pairs_Query(vector<Card>& card);
	int One_Pair_Query(vector<Card>& card);
	int High_Card_Query(vector<Card>& card);
public:
	CheckType* GetCheckType();
	int The_Card_Type(vector<Card>& card);
};

