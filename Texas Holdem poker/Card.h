#pragma once

class Card {
public:
	char Color();
	int Number();
	Card(char _color, int _number) : color(_color), number(_number) {
	}
private:
	char color;
	int number;
};