#pragma once
#include <iostream>
using namespace std;

enum Tile_Type
{
	//TILE_EMPTY,
	TILE_SNAKE,
	TILE_APPLE
};
struct IntVector2
{
	int _x , _y;
	IntVector2() { _x = 0; _y = 0; };
	IntVector2(int x, int y)
	{
		_x = x;
		_y = y;
	}

	bool operator==(const IntVector2& data) 
	{
		return _x==data._x && _y==data._y;
	}
	void operator=(const IntVector2& data)
	{
		_x = data._x;
		_y = data._y;
	}
	IntVector2 operator+(const IntVector2& data)
	{
		return IntVector2(_x + data._x, _y + data._y);
	}
	void operator+=(const IntVector2& data)
	{
		_x += data._x;
		_y += data._y;
	}
	void CoutVector()
	{
		cout << _x << _y;
	}
};
class Tile
{

public:
	Tile_Type _type;
	IntVector2 _idx;

	int GetIdxX()
	{
		return _idx._x;
	}
	int GetIdxY()
	{
		return _idx._y;
	}

};

