#include "GameManager.h"
#include "LinkedList.h"
#include <string>
#include <ctime>
#include "Tile.h"
#include <iostream>
#include <random>

using namespace std;

GameManager::GameManager()
{
}
GameManager::~GameManager()
{
	_snakeList.DeleteList();
}

void GameManager::Init(int mapSizeX, int mapSizeY)
{
	_currentMapX = mapSizeX;
	_currentMapY = mapSizeY;
	for (int i = 0; i < START_LENGTH; i++)
	{
		_snakeList.InsertHeadNode(IntVector2(i, 0));
	}
	_inputDirection = IntVector2(1, 0);
	PutApple();
}

void GameManager::Update()
{
	long startTime = (long)clock();

	while(1)
	{
		long currentTime = (long)clock();
		if (currentTime - startTime >= (_gameSpeed * 1000))
		{
			startTime = (long)clock();
			
			GamePlay();
			Render();
		}
		if (_gameOver)
			break;
	}
}
void GameManager::PutApple()
{
	srand((unsigned int)time(NULL));

	while (1)
	{
		_appleIdx = IntVector2((int)(rand() % _currentMapX), (int)(rand() % _currentMapY));
		if (!_snakeList.Contains(_appleIdx))
			break;
	}
}

void GameManager::GamePlay()
{
	if (_gameOver)
		return;
	IntVector2 snakeHeadIdx = _snakeList._head->_data;
	if (GetAsyncKeyState(VK_UP))
	{
		_inputDirection = IntVector2(0, -1);
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		_inputDirection = IntVector2(-1, 0);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		_inputDirection = IntVector2(1, 0);
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		_inputDirection = IntVector2(0, 1);
	}
	snakeHeadIdx += _inputDirection;
	if (_snakeList.Contains(snakeHeadIdx) || snakeHeadIdx._x < 0 || snakeHeadIdx._y < 0 || snakeHeadIdx._x >= _currentMapX || snakeHeadIdx._y >= _currentMapY)
	{
		_gameOver = true;
		return;
	}
	else if (snakeHeadIdx == _appleIdx)
	{
		_score++;
		if(_gameSpeed > 0.2f)
			_gameSpeed -= 0.01f;
		
		_snakeList.InsertHeadNode(snakeHeadIdx);
		PutApple();
	}
	else
	{
		_snakeList.InsertHeadNode(_snakeList.PopTailNode(), snakeHeadIdx);
	}
}

void GameManager::Render()
{
	system("cls");
	string renderString;
	renderString.resize(((_currentMapX + 3) * (_currentMapY + 2)), ' ');
	for (int i = 0; i < _currentMapY + 2; i++)
	{
		if (i == 0 || i == _currentMapY + 1)
		{
			string temp;
			temp.resize(_currentMapX + 2, '#');
			renderString.replace(i * (_currentMapX + 3), (_currentMapX + 2), temp);
		}
		else
		{
			int idx = i * (_currentMapX + 3);
			renderString[idx] = '#';
			renderString[idx + _currentMapX +1] = '#';
		}
		renderString[((i + 1) * (_currentMapX + 3))-1] = '\n';
	}
	
	Node<IntVector2>* snakeNode = _snakeList._head;
	renderString[((snakeNode->_data._y + 1) * (_currentMapX + 3)) + snakeNode->_data._x + 1] = 'H';
	snakeNode = snakeNode->_next;
	while (1)
	{
		renderString[((snakeNode->_data._y+1) * (_currentMapX + 3)) + snakeNode->_data._x + 1] = '*';

		if (snakeNode->_next == nullptr)
		{
			break;
		}
		snakeNode = snakeNode->_next;
	}
	renderString[((_appleIdx._y+1) * (_currentMapX+3)) + _appleIdx._x + 1] = '@';
	
	cout << renderString;
	cout << "Score : " << _score << '\n';
	if(_gameOver)
		cout << "GAME OVER";
}