#pragma once
#include <string>
#include "LinkedList.h"
#include <Windows.h>

#define START_LENGTH 5

class GameManager
{
	int _score = 0;
	float _gameSpeed = 0.5f;
	int _currentMapX = 10;
	int _currentMapY = 10;
	bool _gameOver = false;
	void Render();
	void GamePlay();
	IntVector2 _inputDirection;
	IntVector2 _appleIdx;
	void PutApple();
public:
	GameManager();
	~GameManager();
	LinkedList<IntVector2> _snakeList;
	void Init(int mapSizeX, int mapSizeY);
	void Update();
	
};

