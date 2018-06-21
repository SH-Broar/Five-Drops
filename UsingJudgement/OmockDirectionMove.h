#pragma once
#include "Judgment.h"

static int MyBlackMap[MapSize][MapSize] = { 0 };
static int MyWhiteMap[MapSize][MapSize] = { 0 };

void BlackAttack_Me(int* x, int* y)
{
	scanf("%d %d", x, y);
}

void BlackDefence_Me(int x, int y)
{
	MyBlackMap[x][y] = WhitePlayer;
}

void WhiteAttack_Me(int* x, int* y)
{
	scanf("%d %d", x, y);
}

void WhiteDefence_Me(int x, int y)
{
	MyWhiteMap[x][y] = BlackPlayer;
}