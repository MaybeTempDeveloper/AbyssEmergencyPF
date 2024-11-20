// EmergencyPortFolio.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "GameManager.h"
#include <iostream>

int main()
{
	int mapX = 10, mapY = 10;
	
	cout << "Snake Game\n";
	while (1)
	{
		cout << "맵의 가로크기 입력(10이상의 정수 권장) : ";
		cin >> mapX;
		if (mapX >= 3)
			break;
	}
	while (1)
	{
		cout << "맵의 세로크기 입력(3이상의 정수 권장) : ";
		cin >> mapY;
		if (mapY >= 3)
			break;
	}
	GameManager manager;
	manager.Init(mapX, mapY);
	manager.Update();
}