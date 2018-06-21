#include <random>


int board_20171800091[19][19] = { 0 };
int boardimportance_20171800091[19][19] = { 0 };
int Count_20171800091;
#define BLACK -1
#define WHITE 1
#define MAX 19

struct space1
{
	int state;
	double weight;
	bool checked;
};

space1 Map20171800091[MAX][MAX] = { 0, 1.0, false };
int checkMap20171800091[8][2] = {
	{ 1, -1 },
	{ 0, 1 },
	{ 1, 1 },
	{ 1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ -1, -1 },
	{ -1, 0 }
};

// 돌의 각 끝점을 찾아서 그 주위 ㄱ자 모양으로 가중치를 체크 밑부분은 ㄴ자 모양으로 체크
void AI1(int Next, int first)// Next 니꺼 first 내꺼
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				Map20171800091[i][j].checked = false;

		for (int y = 0; y < MAX; y++)
		{
			for (int x = 0; x < MAX; x++)
			{
				if (Map20171800091[y][x].state == Next && Map20171800091[y][x].checked == false)
				{
					int Count = 0;
					int tx = x, ty = y;
					while (Map20171800091[ty][tx].state == Next && tx >= 0 && ty >= 0 && tx <= MAX && ty <= MAX)
					{
						Count++;//연속된 돌의 갯수
						Map20171800091[ty][tx].checked = true;
						tx += checkMap20171800091[k][0];//연속된 만큼 나아갈 방향 | / - ` 방향 아래쪽으로감
						ty += checkMap20171800091[k][1];
					}
					if (x - checkMap20171800091[k][0] >= 0 && y - checkMap20171800091[k][1] >= 0 && x - checkMap20171800091[k][0] <= MAX && y - checkMap20171800091[k][1] <= MAX)
					{
						if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == 0)// 안막힌 연속된 돌이면
						{
							Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 11 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 10 * Count * Count;
							}
						}
						else if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == first)// 반대방향이 막힌 돌이면
						{
							Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 8 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 10 * Count * Count;
							}
						}
					}
					if (tx + checkMap20171800091[k][0] >= 0 && ty + checkMap20171800091[k][1] >= 0 && tx + checkMap20171800091[k][0] <= MAX && ty + checkMap20171800091[k][1] <= MAX)
					{
						if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == 0)// 안막힌 연속된 돌이면
						{
							Map20171800091[ty][tx].weight += 11 * Count*Count;
							if (Count >= 3)
							{

								Map20171800091[ty][tx].weight += 10 * Count * Count;
							}
						}
						else if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == first && Map20171800091[ty][tx].state == 0)// 반대방향이 막힌 돌이면
						{
							Map20171800091[ty][tx].weight += 8 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[ty][tx].weight += 10 * Count * Count;
							}
						}
					}
				}
				if (Map20171800091[y][x].state == first && Map20171800091[y][x].checked == false)
				{
					int Count = 0;
					int tx = x, ty = y;
					while (Map20171800091[ty][tx].state == first && tx >= 0 && ty >= 0 && tx <= MAX && ty <= MAX)
					{
						Count++;//연속된 돌의 갯수
						Map20171800091[ty][tx].checked = true;
						tx += checkMap20171800091[k][0];//연속된 만큼 나아갈 방향 | / - ` 방향 아래쪽으로감
						ty += checkMap20171800091[k][1];
					}
					if (x - checkMap20171800091[k][0] >= 0 && y - checkMap20171800091[k][1] >= 0 && x - checkMap20171800091[k][0] <= MAX && y - checkMap20171800091[k][1] <= MAX)
					{
						if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == 0)// 안막힌 연속된 돌이면
						{
							Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 9 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 10 * Count * Count;
							}
						}
						else if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == Next)// 반대방향이 막힌 돌이면
						{
							Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 7 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].weight += 10 * Count * Count;
							}
						}
					}
					if (tx + checkMap20171800091[k][0] >= 0 && ty + checkMap20171800091[k][1] >= 0 && tx + checkMap20171800091[k][0] <= MAX && ty + checkMap20171800091[k][1] <= MAX)
					{
						if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == 0 && Map20171800091[ty][tx].state == 0)// 안막힌 연속된 돌이면
						{
							Map20171800091[ty][tx].weight += 9 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[ty][tx].weight += 10 * Count * Count;
							}
						}
						else if (Map20171800091[y - checkMap20171800091[k][1]][x - checkMap20171800091[k][0]].state == Next && Map20171800091[ty][tx].state == 0)// 반대방향이 막힌 돌이면
						{
							Map20171800091[ty][tx].weight += 7 * Count*Count;
							if (Count >= 3)
							{
								Map20171800091[ty][tx].weight += 10 * Count * Count;
							}
						}
					}
				}
			}
		}
	}
}

/////////////////
void WhiteAttack_20171800091(int*x, int*y)
{

	//직접 구현한 돌 놓기 로직을 넣으시면 됩니다.
	Count_20171800091++;
	int xpos;
	int ypos;


	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			Map20171800091[i][j].weight = 1.0;

	bool put;
	double max_weight;
	int ex, ey;
	put = false;
	while (!put)
	{
		AI1(-1, 1);
		ex = ey = 0;
		max_weight = 0.0;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (Map20171800091[i][j].weight > max_weight && Map20171800091[i][j].state == 0)
				{
					ex = j, ey = i;
					max_weight = Map20171800091[i][j].weight;
				}
			}
		}

		if (Map20171800091[ey][ex].state == 0)
		{
			Map20171800091[ey][ex].state = WHITE;
			*x = ex;
			*y = ey;
			put = true;
		}
	}


	board_20171800091[ey][ex] = WHITE;


}
void WhiteDefence_20171800091(int x, int y)
{
	Count_20171800091++;
	//흰돌 1
	//검은돌 -1
	//Sleep(1000);
	board_20171800091[y][x] = BLACK;
	Map20171800091[y][x].state = -1;


}
//////////////////
void AttackBlack_20171800091(int*x, int*y)
{
	//직접 구현한 돌 놓기 로직을 넣으시면 됩니다.
	Count_20171800091++;
	int xpos;
	int ypos;


	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			Map20171800091[i][j].weight = 1.0;

	bool put;
	double max_weight;
	int ex, ey;
	if (Count_20171800091 == 1)
	{
		ex = 9;
		ey = 9;
		Map20171800091[ey][ex].state = BLACK;
		*x = ex;
		*y = ey;
		return;
	}
	put = false;
	while (!put)
	{
		AI1(1, -1);
		ex = ey = 0;
		max_weight = 0.0;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if (Map20171800091[i][j].weight > max_weight && Map20171800091[i][j].state == 0)
				{
					ex = j, ey = i;
					max_weight = Map20171800091[i][j].weight;
				}
			}
		}

		if (Map20171800091[ey][ex].state == 0)
		{
			Map20171800091[ey][ex].state = BLACK;
			*x = ex;
			*y = ey;
			put = true;
		}
	}


	board_20171800091[ey][ex] = BLACK;

}
void DefenceBlack_20171800091(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	Count_20171800091++;
	board_20171800091[y][x] = WHITE;
	Map20171800091[y][x].state = 1;
}