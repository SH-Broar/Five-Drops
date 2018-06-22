#pragma once
#include <random>
#include <math.h>
#include <windows.h>
#include "Judgment.h"

int board_2017180023[19][19];
int lastlast_x = -1;
int lastlast_y = -1;
int last_x = -1;
int last_y = -1;

#define BLACK -1
#define WHITE 1
void WhiteAttack_2017180023(int*x, int*y)
{
	//직접 구현한 돌 놓기 로직을 넣으시면 됩니다.
	default_random_engine dre;
	dre.seed(GetTickCount());
	uniform_int<> RandomPos(0, 7);
	uniform_int<> RandomPos2(0, 18);

	int movePoint[8][2] = { { 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 } };

	pair<int, int> temp[8];
	if ((last_x == -1) && (last_y == -1))  //맵에 상대 돌 없을때
	{

		*x = 10;
		*y = 10;
	}
	else
	{
		int temp_x;
		int temp_y;
		bool boooooooool = true;

		if (!((lastlast_x == -1) && (lastlast_y == -1)))  //맵에 상대 돌 여러개 있을 때
		{
			int direction;
			bool blocked_direction[8];

			if ((abs(lastlast_x - last_x) <= 1) && (abs(lastlast_y - last_y) <= 1))  //이전 돌과 근접해서 놨을경우
			{
				for (int i = 0; i < 8; i++)
				{
					if ((movePoint[i][0] == (last_x - lastlast_x)) && (movePoint[i][1] == (last_y - lastlast_y)))
						direction = i;
				}

				temp_x = (last_x + movePoint[direction][0]);
				temp_y = (last_y + movePoint[direction][1]);

				if (board_2017180023[temp_y][temp_x] == 0)
				{
					*x = temp_x;
					*y = temp_y;
					boooooooool = false;
				}
			}
		}

		if (boooooooool == true)
		{
			int rand_direction;
			bool blocked_direction[8];

			for (int i = 0; i < 8; i++)
				blocked_direction[i] = false;

			while (true)
			{

				//8방향 전부 막힌경우
				if ((blocked_direction[0] == true) && (blocked_direction[1] && true) && (blocked_direction[2] && true) && (blocked_direction[2] == true) && (blocked_direction[4] && true) &&
					(blocked_direction[5] == true) && (blocked_direction[6] && true) && (blocked_direction[7] && true))
				{
					int temp_x2;
					int temp_y2;

					while (true)  //새 땅을 찾아 떠나요~
					{
						temp_x2 = RandomPos2(dre);
						temp_y2 = RandomPos2(dre);

						if ((temp_x2 < 0) || (temp_x2 > 18) || (temp_y2 < 0) || (temp_y2 > 18))
							continue;
						else if (board_2017180023[temp_y2][temp_x2] == 0)
						{
							*x = temp_x2;
							*y = temp_y2;
							break;
						}
						else
							continue;
					}
				}
				else
				{
					rand_direction = RandomPos(dre);
					if (blocked_direction[rand_direction] == true)
						continue;
					temp_x = (last_x + movePoint[rand_direction][0]);
					temp_y = (last_y + movePoint[rand_direction][1]);


					if ((temp_x < 0) || (temp_x > 18) || (temp_y < 0) || (temp_y > 18))
					{
						blocked_direction[rand_direction] = true;
						continue;
					}
					else if (board_2017180023[temp_y][temp_x] != 0)
					{
						blocked_direction[rand_direction] = true;
						continue;
					}
					else if (board_2017180023[temp_y][temp_x] == 0)
					{
						*x = temp_x;
						*y = temp_y;
						break;
					}
				}

			}
		}
	}
	board_2017180023[*y][*x] = WHITE;
}
void WhiteDefence_2017180023(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	if ((last_x == -1) && (last_y == -1))
	{
		last_x = x;
		last_y = y;
	}
	else
	{
		lastlast_x = last_x;
		lastlast_y = last_y;
		last_x = x;
		last_y = y;
	}
	board_2017180023[y][x] = BLACK;
}
void AttackBlack_2017180023(int*x, int*y)
{
	default_random_engine dre;
	dre.seed(GetTickCount());
	uniform_int<> RandomPos(0, 7);
	uniform_int<> RandomPos2(0, 18);

	int movePoint[8][2] = { { 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 } };

	pair<int, int> temp[8];
	if ((last_x == -1) && (last_y == -1))  //맵에 상대 돌 없을때
	{

		*x = 10;
		*y = 10;
	}
	else
	{
		int temp_x;
		int temp_y;
		bool boooooooool = true;

		if (!((lastlast_x == -1) && (lastlast_y == -1)))  //맵에 상대 돌 여러개 있을 때
		{
			int direction;
			bool blocked_direction[8];

			if ((abs(lastlast_x - last_x) <= 1) && (abs(lastlast_y - last_y) <= 1))  //이전 돌과 근접해서 놨을경우
			{
				for (int i = 0; i < 8; i++)
				{
					if ((movePoint[i][0] == (last_x - lastlast_x)) && (movePoint[i][1] == (last_y - lastlast_y)))
						direction = i;
				}

				temp_x = (last_x + movePoint[direction][0]);
				temp_y = (last_y + movePoint[direction][1]);

				if (board_2017180023[temp_y][temp_x] == 0)
				{
					*x = temp_x;
					*y = temp_y;
					boooooooool = false;
				}
			}
		}

		if (boooooooool == true)
		{
			int rand_direction;
			bool blocked_direction[8];

			for (int i = 0; i < 8; i++)
				blocked_direction[i] = false;

			while (true)
			{

				//8방향 전부 막힌경우
				if ((blocked_direction[0] == true) && (blocked_direction[1] && true) && (blocked_direction[2] && true) && (blocked_direction[2] == true) && (blocked_direction[4] && true) &&
					(blocked_direction[5] == true) && (blocked_direction[6] && true) && (blocked_direction[7] && true))
				{
					int temp_x2;
					int temp_y2;

					while (true)  //새 땅을 찾아 떠나요~
					{
						temp_x2 = RandomPos2(dre);
						temp_y2 = RandomPos2(dre);

						if ((temp_x2 < 0) || (temp_x2 > 18) || (temp_y2 < 0) || (temp_y2 > 18))
							continue;
						else if (board_2017180023[temp_y2][temp_x2] == 0)
						{
							*x = temp_x2;
							*y = temp_y2;
							break;
						}
						else
							continue;
					}
				}
				else
				{
					rand_direction = RandomPos(dre);
					if (blocked_direction[rand_direction] == true)
						continue;
					temp_x = (last_x + movePoint[rand_direction][0]);
					temp_y = (last_y + movePoint[rand_direction][1]);


					if ((temp_x < 0) || (temp_x > 18) || (temp_y < 0) || (temp_y > 18))
					{
						blocked_direction[rand_direction] = true;
						continue;
					}
					else if (board_2017180023[temp_y][temp_x] != 0)
					{
						blocked_direction[rand_direction] = true;
						continue;
					}
					else if (board_2017180023[temp_y][temp_x] == 0)
					{
						*x = temp_x;
						*y = temp_y;
						break;
					}
				}

			}
		}		 
	}

	board_2017180023[*y][*x] = BLACK;

}
void DefenceBlack_2017180023(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	if ((last_x == -1) && (last_y == -1))
	{
		last_x = x;
		last_y = y;
	}
	else
	{
		lastlast_x = last_x;
		lastlast_y = last_y;
		last_x = x;
		last_y = y;
	}
	board_2017180023[y][x] = WHITE;

}
