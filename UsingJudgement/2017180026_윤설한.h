#include <random>
#include <iomanip>

int board_2017180026[19][19];
int board_value_2017180026[19][19];
#define BLACK -1
#define WHITE 1


void lineValue_2017180026(int x, int y, int xMove, int yMove, int color)
{
	int tempX = x;
	int tempY = y;
	int count_defence = 0;
	int is_open_defence = 0;
	int value[9] = { 0,2,10,10,50,100,300,500,999 };
	// 2*이어진 돌 수-막힘 여부
	int pointer = 0;
	int preValue_defence[19] = { 0, };
	while (1)
	{
		if (board_2017180026[tempX][tempY] == -color)
		{
			count_defence++;
		}
		else if (board_2017180026[tempX][tempY] == color)
		{
			count_defence = 0;
			is_open_defence = 1;
		}
		else
		{
			if (count_defence == 0)
			{
				is_open_defence = 0;
			}
			preValue_defence[pointer] += value[2 * count_defence - is_open_defence];
			is_open_defence = 0;
			count_defence = 0;
		}
		tempX += xMove;
		tempY += yMove;
		if (tempX > 18 || tempX < 0 || tempY > 18 || tempY < 0)
		{
			tempX -= xMove;
			tempY -= yMove;
			break;
		}
		pointer++;
	}
	xMove = -xMove;
	yMove = -yMove;
	count_defence = 0;
	is_open_defence = 0;
	while (1) {
		if (board_2017180026[tempX][tempY] == -color)
		{
			count_defence++;
		}
		else if (board_2017180026[tempX][tempY] == color)
		{
			count_defence = 0;
			is_open_defence = 1;
		}
		else
		{
			if (count_defence == 0)
			{
				is_open_defence = 0;
			}

			if (preValue_defence[pointer] != 0)
			{
				if (value[2 * count_defence - is_open_defence] != 0)
				{
					preValue_defence[pointer] += value[2 * count_defence - is_open_defence];
					preValue_defence[pointer] *= 5;
				}
			}
			else
			{
				preValue_defence[pointer] += value[2 * count_defence - is_open_defence];
			}

			//preValue_defence[pointer] += value[2 * count_defence - is_open_defence];
			count_defence = 0;
			is_open_defence = 0;
		}
		board_value_2017180026[tempX][tempY] += preValue_defence[pointer];
		tempX += xMove;
		tempY += yMove;
		if (tempX > 18 || tempX < 0 || tempY > 18 || tempY < 0)
		{
			break;
		}
		pointer--;
	}
}

void calValue_2017180026(int color)
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			board_value_2017180026[i][j] = 0;
		}
	}

	for (int i = 0; i < 19; i++)
	{
		lineValue_2017180026(0, i, 1, 0, color);
	}

	for (int i = 0; i < 19; i++)
	{
		lineValue_2017180026(i, 0, 0, 1, color);
	}

	for (int i = 0; i < 19; i++)
	{
		lineValue_2017180026(i, 0, 1, 1, color);
	}
	for (int i = 1; i < 19; i++)
	{
		lineValue_2017180026(0, i, 1, 1, color);
	}

	for (int i = 0; i < 19; i++)
	{
		lineValue_2017180026(0, i, 1, -1, color);
	}
	for (int i = 1; i < 19; i++)
	{
		lineValue_2017180026(i, 18, 1, -1, color);
	}
}

void WhiteAttack_2017180026(int*x, int*y)
{
	//직접 구현한 돌 놓기 로직을 넣으시면 됩니다.
	calValue_2017180026(WHITE);
	int max_defence = 0;
	int defence_xPos = 9;
	int defence_yPos = 9;
	int xPos = 9;
	int yPos = 9;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board_value_2017180026[i][j] > max_defence)
			{
				max_defence = board_value_2017180026[i][j];
				defence_xPos = i;
				defence_yPos = j;
			}
		}
		cout << endl;
	}

	calValue_2017180026(BLACK);
	int max_attack = 0;
	int attack_xPos = 10;
	int attack_yPos = 10;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board_value_2017180026[i][j] > max_attack)
			{
				max_attack = board_value_2017180026[i][j];
				attack_xPos = i;
				attack_yPos = j;
			}
		}
	}

	if (max_defence < 300 && max_attack > 50)
	{
		xPos = attack_xPos;
		yPos = attack_yPos;
	}
	else
	{
		xPos = defence_xPos;
		yPos = defence_yPos;
	}
	*x = xPos;
	*y = yPos;

	board_2017180026[xPos][yPos] = WHITE;

}
void WhiteDefence_2017180026(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	board_2017180026[x][y] = BLACK;
}
void AttackBlack_2017180026(int*x, int*y)
{
	//직접 구현한 돌 놓기 로직을 넣으시면 됩니다.

	calValue_2017180026(BLACK);
	int max_defence = 0;
	int defence_xPos = 9;
	int defence_yPos = 9;
	int xPos = 9;
	int yPos = 9;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board_value_2017180026[i][j] > max_defence)
			{
				max_defence = board_value_2017180026[i][j];
				defence_xPos = i;
				defence_yPos = j;
			}
		}
		cout << endl;
	}

	calValue_2017180026(WHITE);
	int max_attack = 0;
	int attack_xPos = 9;
	int attack_yPos = 9;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (board_value_2017180026[i][j] > max_attack)
			{
				max_attack = board_value_2017180026[i][j];
				attack_xPos = i;
				attack_yPos = j;
			}
		}
	}

	if (max_attack - 100 > max_defence)
	{
		xPos = attack_xPos;
		yPos = attack_yPos;
	}
	else
	{
		xPos = defence_xPos;
		yPos = defence_yPos;
	}
	*x = xPos;
	*y = yPos;

	board_2017180026[xPos][yPos] = BLACK;

}
void DefenceBlack_2017180026(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	board_2017180026[x][y] = WHITE;
}


