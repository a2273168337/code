#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "CheckType.h"
#include "Card.h"
using namespace std;
CheckType* CheckType::PointCheckType = nullptr;

CheckType* CheckType::GetCheckType() {
	if (PointCheckType == nullptr) {
		PointCheckType = new CheckType();
	}
	return PointCheckType;
}

int CheckType::The_Card_Type(vector<Card>& card)
{
    return 0;
}

int CheckType::Straight_Flush_Query(vector<Card>& card) { //同花顺
    int maxNumber = 0;
    char maxNumberColor;
    for (int i = 0; i < card.size(); ++i) {
        int last = 1;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[j].Color() == card[i].Color() && card[i].Number() - last == card[j].Number()) {
                last++;
            }
        }
        if (last >= 5) {
            if (card[i].Number() > maxNumber) {
                maxNumber = card[i].Number();
                maxNumberColor = card[i].Color();
            }
        }
    }
    if (maxNumber) {
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Color() == maxNumberColor) {
                int idx = maxNumber - card[i].Number();
                if (idx < 5 && idx >= 0) swap(card[idx], card[i]);
            }
        }
        return 1;
    }
    return -1;
}

int CheckType::Four_Of_A_Kind_Query(vector<Card>& card) {//四条
    int maxNumber = 0;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[i].Number() == card[j].Number()) si++;
        }
        if (si >= 4) {
            maxNumber = max(maxNumber, card[i].Number());
        }
    }
    if (maxNumber) {
        int idx = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Number() == maxNumber) {
                swap(card[i], card[idx]);
                idx++;
            }
        }
        sort(card.begin() + 4, card.end(), [](Card& a, Card& b) {return a.Number() > b.Number(); });
        return 2;
    }
    return -1;
}

int CheckType::Full_House_Query(vector<Card>& card) { //葫芦
    int three_of_a_kind = -1, two_of_a_kind = -1;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        if (card[i].Number() == three_of_a_kind) continue;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[i].Number() == card[j].Number()) si++;
        }
        if (si >= 3 && three_of_a_kind == -1 && card[i].Number() > three_of_a_kind) {
            three_of_a_kind = card[i].Number();
        }
        else if (si >= 2 && card[i].Number() > two_of_a_kind) two_of_a_kind = card[i].Number();
    }
    if (three_of_a_kind != -1 && two_of_a_kind != -1) {
        int three_of_a_kind_idx = 0, two_of_a_kind_idx = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Number() == three_of_a_kind && three_of_a_kind_idx < 3) {
                swap(card[three_of_a_kind_idx], card[i]);
                three_of_a_kind_idx++;
            }
            else if (card[i].Number() == two_of_a_kind) {
                swap(card[two_of_a_kind_idx], card[i]);
                two_of_a_kind_idx++;
            }
        }
        return 3;
    }
    return -1;
}

int CheckType::Flush_Query(vector<Card>& card) {//同花
    priority_queue<int> priorityNumber[4];
    for (int i = 0; i < card.size(); ++i) {
        char color = card[i].Color();
        priorityNumber[color].push(card[i].Number());
    }
    vector<int> maxNumber(5);
    char maxNumberColor = -1;
    for (char i = 0; i < 4; ++i) {
        if (priorityNumber[i].size() > 5) {
            for (int j = 0; j < 5; ++j) {
                if (priorityNumber[i].top() < maxNumber[j]) break;
                maxNumber[j] = priorityNumber[i].top();
                priorityNumber[i].pop();
                if (j == 4) maxNumberColor = i;
            }
        }
    }
    if (maxNumberColor != -1) {
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Color() != maxNumberColor) continue;
            for (int j = 0; j < maxNumber.size(); ++j) {
                if (card[i].Number() == maxNumber[j]) {
                    swap(card[i], card[j]);
                }
            }
        }
        return 4;
    }
    return -1;
}

int CheckType::Straight_Query(vector<Card>& card) {//顺子
    int maxNumber = 0;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[j].Number() == card[i].Number() - si) si++;
        }
        if (si >= 5) {
            maxNumber = max(maxNumber, card[i].Number());
        }
    }
    if (maxNumber) {
        for (int i = 0; i < card.size(); ++i) {
            int idx = maxNumber - card[i].Number();
            if (idx >= 0 && idx < 5) {
                swap(card[idx], card[i]);
            }
        }
        return 5;
    }
    return -1;
}

int CheckType::Three_Of_A_Kind_Query(vector<Card>& card) {//三条
    int maxNumber = 0;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[i].Number() == card[j].Number()) si++;
        }
        if (si >= 3) maxNumber = max(maxNumber, card[i].Number());
    }
    if (maxNumber) {
        int idx = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Number() == maxNumber) {
                swap(card[i], card[idx]);
                idx++;
            }
        }
        sort(card.begin() + 3, card.end(), [](Card& a, Card& b) {return a.Number() > b.Number(); });
        return 6;
    }
    return -1;
}

int CheckType::Two_Pairs_Query(vector<Card>& card) {//俩对
    int one_pair = -1, two_pair = -1;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        if (card[i].Number() == one_pair) continue;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[i].Number() == card[j].Number()) si++;
        }
        if (si >= 2 && one_pair == -1 && card[i].Number() > one_pair) {
            two_pair = max(two_pair, one_pair);
            one_pair = card[i].Number();
        }
        else if (si >= 2 && card[i].Number() > two_pair) two_pair = card[i].Number();
    }
    if (one_pair != -1 && two_pair != -1) {
        int one_pair_idx = 0, two_pair_idx = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Number() == one_pair && one_pair_idx < 2) {
                swap(card[i], card[one_pair_idx]);
                one_pair_idx++;
            }
            else if (card[i].Number() == two_pair) {
                swap(card[i], card[two_pair_idx]);
                two_pair_idx++;
            }
        }
        sort(card.begin() + 4, card.end(), [](Card& a, Card& b) {return a.Number() > b.Number(); });
        return 7;
    }
    return -1;
}

int CheckType::One_Pair_Query(vector<Card>& card) {//一对
    int maxNumber = 0;
    for (int i = 0; i < card.size(); ++i) {
        int si = 1;
        for (int j = 0; j < card.size(); ++j) {
            if (i == j) continue;
            if (card[i].Number() == card[j].Number()) si++;
        }
        if (si >= 2) {
            maxNumber = max(maxNumber, card[i].Number());
        }
    }
    if (maxNumber) {
        int idx = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (card[i].Number() == maxNumber) {
                swap(card[i], card[idx]);
                idx++;
            }
        }
        sort(card.begin() + 2, card.end(), [](Card& a, Card& b) {return a.Number() > b.Number(); });
        return 8;
    }
    return -1;
}

int CheckType::High_Card_Query(vector<Card>& card) {//高牌
    sort(card.begin(), card.end(), [](Card& a, Card& b) {return a.Number() > b.Number(); });
    return 9;
}


int CheckType::The_Card_Type(vector<Card>& card) { //判断牌型，并将前五张牌变成最大牌型
