#include <random>

int weightableForB_2017180021[19][19] = { 0 };
int weightableForW_2017180021[19][19] = { 0 };
int weightableForA_2017180021[19][19] = { 0 };

int tmptable[19][19] = { 0 };

int getX_2017180021 = -1, getY_2017180021 = -1;
int table_2017180021[19][19] = { 0 };

int splender_2017180021[4];

int isExitedStone_2017180021(int x, int y)
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			tmptable[j][i] = table_2017180021[j][i];
		}
	}
	tmptable[x][y] = 1;
	{
		//int nBlack = 0, nWhite = 0;
		//int Maximum[2] = { 0 };
		//int over3 = 0;
		//int SavedMaximum[2] = { 0 };
		//bool isSamestone[2] = { false };
		//bool blink = false;

		////가로
		//for (int i = y; i <= y; i++)
		//{
		//	Maximum[0] = 0;
		//	Maximum[1] = 0;
		//	SavedMaximum[0] = 0;
		//	SavedMaximum[1] = 0;
		//	blink = false;

		//	for (int j = x-3; j < x+4; j++)
		//	{
		//		if (j < 0 || j>18)
		//			continue;
		//		if (tmptable[j][i] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
		//		{
		//			Maximum[0]++;

		//			if (SavedMaximum[0] < Maximum[0])
		//				SavedMaximum[0] = Maximum[0];

		//			isSamestone[0] = true;
		//			isSamestone[1] = false;
		//		}
		//		else if (tmptable[j][i] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
		//		{
		//			break;
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//				SavedMaximum[1] = Maximum[1];

		//			isSamestone[0] = false;
		//			isSamestone[1] = true;
		//		}
		//		else if (tmptable[j][i] == 1 && isSamestone[0] == true)
		//		{
		//			Maximum[0]++;
		//			if (SavedMaximum[0] < Maximum[0])
		//			{
		//				SavedMaximum[0] = Maximum[0];
		//			}
		//		}
		//		else if (tmptable[j][i] == 2 && isSamestone[1] == true)
		//		{
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//			{
		//				SavedMaximum[1] = Maximum[1];

		//			}
		//		}
		//		else if (blink == false && tmptable[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
		//		{
		//			blink = true;
		//			if (isSamestone[0] == true)
		//				Maximum[0]++;
		//			else if (isSamestone[1] == true)
		//				Maximum[1]++;
		//		}
		//		else
		//		{
		//			Maximum[0] = 0;
		//			Maximum[1] = 0;
		//			SavedMaximum[0] = 0;
		//			if (blink == true)
		//				j--;
		//			isSamestone[0] = false;
		//			isSamestone[1] = false;
		//			blink = false;
		//		}
		//	}
		//}
		//if (SavedMaximum[0] == 3)
		//{
		//	printf("%d %d G!",x, y);
		//	over3++;
		//}

		////세로
		//for (int i = x; i <= x; i++)
		//{
		//	Maximum[0] = 0;
		//	Maximum[1] = 0;
		//	blink = false;
		//	SavedMaximum[0] = 0;
		//	SavedMaximum[1] = 0;

		//	for (int j = y-3; j < y+4; j++)
		//	{
		//		if (j < 0 || j>18)
		//			continue;
		//		if (tmptable[i][j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
		//		{
		//			Maximum[0]++;

		//			if (SavedMaximum[0] < Maximum[0])
		//				SavedMaximum[0] = Maximum[0];

		//			isSamestone[0] = true;
		//			isSamestone[1] = false;
		//		}
		//		else if (tmptable[i][j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
		//		{
		//			break;
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			Maximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//				SavedMaximum[1] = Maximum[1];

		//			isSamestone[0] = false;
		//			isSamestone[1] = true;
		//		}
		//		else if (tmptable[i][j] == 1 && isSamestone[0] == true)
		//		{
		//			Maximum[0]++;
		//			if (SavedMaximum[0] < Maximum[0])
		//			{
		//				SavedMaximum[0] = Maximum[0];
		//			}
		//		}
		//		else if (tmptable[i][j] == 2 && isSamestone[1] == true)
		//		{
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//			{
		//				SavedMaximum[1] = Maximum[1];
		//			}
		//		}
		//		else if (blink == false && tmptable[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
		//		{
		//			blink = true;
		//			if (isSamestone[0] == true)
		//				Maximum[0]++;
		//			else if (isSamestone[1] == true)
		//				Maximum[1]++;
		//		}
		//		else
		//		{
		//			Maximum[0] = 0;
		//			Maximum[1] = 0;
		//			SavedMaximum[0] = 0;
		//			if (blink == true)
		//				j--;
		//			isSamestone[0] = false;
		//			isSamestone[1] = false;
		//			blink = false;
		//		}
		//	}
		//}

		//if (SavedMaximum[0] == 3)
		//{
		//	printf("%d %d S!",x,y);
		//	over3++;
		//}

		////우하단 
		//for (int i = y-x; i <= y-x; i++)
		//{
		//	Maximum[0] = 0;
		//	Maximum[1] = 0;
		//	blink = false;
		//	SavedMaximum[0] = 0;
		//	SavedMaximum[1] = 0;

		//	for (int j = x-3; j < x+4; j++)
		//	{
		//		if (i + j < 0 || i + j >= 19)
		//			continue;
		//		if (tmptable[j][i + j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
		//		{
		//			Maximum[0]++;

		//			if (SavedMaximum[0] < Maximum[0])
		//				SavedMaximum[0] = Maximum[0];

		//			isSamestone[0] = true;
		//			isSamestone[1] = false;
		//		}
		//		else if (tmptable[j][i + j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
		//		{
		//			break;
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//				SavedMaximum[1] = Maximum[1];

		//			isSamestone[0] = false;
		//			isSamestone[1] = true;
		//		}
		//		else if (tmptable[j][i + j] == 1 && isSamestone[0] == true)
		//		{
		//			Maximum[0]++;
		//			if (SavedMaximum[0] < Maximum[0])
		//			{
		//				SavedMaximum[0] = Maximum[0];
		//			}
		//		}
		//		else if (tmptable[j][i + j] == 2 && isSamestone[1] == true)
		//		{
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//			{
		//				SavedMaximum[1] = Maximum[1];
		//			}
		//		}
		//		else if (blink == false && tmptable[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
		//		{
		//			blink = true;
		//			if (isSamestone[0] == true)
		//				Maximum[0]++;
		//			else if (isSamestone[1] == true)
		//				Maximum[1]++;
		//		}
		//		else
		//		{
		//			Maximum[0] = 0;
		//			Maximum[1] = 0;
		//			SavedMaximum[0] = 0;
		//			if (blink == true)
		//				j--;
		//			isSamestone[0] = false;
		//			isSamestone[1] = false;
		//			blink = false;
		//		}
		//	}
		//}
		//if (SavedMaximum[0] == 3)
		//{
		//	printf("%d %d D!",x,y);
		//	over3++;
		//}

		////우상단 대각
		//Maximum[0] = 0;
		//Maximum[1] = 0;

		//for (int i = y+x; i <= y+x; i++)
		//{
		//	Maximum[0] = 0;
		//	Maximum[1] = 0;
		//	SavedMaximum[0] = 0;
		//	SavedMaximum[1] = 0;

		//	for (int j = x-3; j < x+4; j++)
		//	{
		//		if (i - j < 0 || i - j >= 19)
		//			continue;
		//		if (tmptable[j][i - j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
		//		{
		//			Maximum[0]++;

		//			if (SavedMaximum[0] < Maximum[0])
		//				SavedMaximum[0] = Maximum[0];

		//			isSamestone[0] = true;
		//			isSamestone[1] = false;
		//		}
		//		else if (tmptable[j][i - j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
		//		{
		//			break;
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//				SavedMaximum[1] = Maximum[1];

		//			isSamestone[0] = false;
		//			isSamestone[1] = true;
		//		}
		//		else if (tmptable[j][i - j] == 1 && isSamestone[0] == true)
		//		{
		//			Maximum[0]++;
		//			if (SavedMaximum[0] < Maximum[0])
		//			{
		//				SavedMaximum[0] = Maximum[0];
		//			}
		//		}
		//		else if (tmptable[j][i - j] == 2 && isSamestone[1] == true)
		//		{
		//			Maximum[1]++;
		//			SavedMaximum[0] = 0;
		//			if (SavedMaximum[1] < Maximum[1])
		//			{
		//				SavedMaximum[1] = Maximum[1];
		//			}
		//		}
		//		else if (blink == false && tmptable[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
		//		{
		//			blink = true;
		//			if (isSamestone[0] == true)
		//				Maximum[0]++;
		//			else if (isSamestone[1] == true)
		//				Maximum[1]++;
		//		}
		//		else
		//		{
		//			Maximum[0] = 0;
		//			Maximum[1] = 0;
		//			SavedMaximum[0] = 0;
		//			isSamestone[0] = false;
		//			isSamestone[1] = false;
		//		}
		//	}
		//}
		//if (SavedMaximum[0] == 3)
		//{
		//	printf("%d %d U!",x,y);
		//	over3++;
		//}
		//
		//printf("									%d\n", over3);
		//Sleep(1000);

		//if (over3 > 1)
		//	return 1;
		//return 0;
	}

	{
	//33
		int count = 0;
		// 가로체크. 
		if (x > 3 && x < 15)
		{
			if ((tmptable[x - 4][y] == 0 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 0 && tmptable[x + 1][y] == 0) ||
				(tmptable[x - 4][y] == 0 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0) ||
				(tmptable[x - 3][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0) ||

				(tmptable[x + 4][y] == 0 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 0 && tmptable[x - 1][y] == 0) ||
				(tmptable[x + 4][y] == 0 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 0 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0) ||
				(tmptable[x + 3][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0) ||

				(tmptable[x - 2][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x + 2][y] == 0) ||
				(tmptable[x - 3][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 0 && tmptable[x + 1][y] == 2 && tmptable[x + 2][y] == 0) ||
				(tmptable[x - 2][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 3][y] == 0))
			{
				//printf("%d %d G!", x, y);
				//Sleep(1000);
				count++;
			}
		}
		// 세로체크. 
		if (y > 3 && y < 15)
		{
			if ((tmptable[x][y - 4] == 0 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 0 && tmptable[x][y + 1] == 0) ||
				(tmptable[x][y - 4] == 0 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0) ||
				(tmptable[x][y - 3] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0) ||

				(tmptable[x][y + 4] == 0 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 0 && tmptable[x][y - 1] == 0) ||
				(tmptable[x][y + 4] == 0 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 0 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0) ||
				(tmptable[x][y + 3] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0) ||

				(tmptable[x][y - 2] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y + 2] == 0) ||
				(tmptable[x][y - 3] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 0 && tmptable[x][y + 1] == 2 && tmptable[x][y + 2] == 0) ||
				(tmptable[x][y - 2] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 3] == 0))
			{
				//printf("%d %d S!", x, y);
				//Sleep(1000);
				count++;
			}
		}
		// 대각선체크. 
		if (x > 3 && x < 15 && y > 3 && y < 15)
		{
			if ((tmptable[x - 4][y - 4] == 0 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 0 && tmptable[x + 1][y + 1] == 0) ||
				(tmptable[x - 4][y - 4] == 0 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0) ||
				(tmptable[x - 3][y - 3] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0) ||

				(tmptable[x + 4][y + 4] == 0 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 0 && tmptable[x - 1][y - 1] == 0) ||
				(tmptable[x + 4][y + 4] == 0 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 0 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0) ||
				(tmptable[x + 3][y + 3] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0) ||

				(tmptable[x - 2][y - 2] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x + 2][y + 2] == 0) ||
				(tmptable[x - 3][y - 3] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 0 && tmptable[x + 1][y + 1] == 2 && tmptable[x + 2][y + 2] == 0) ||
				(tmptable[x - 2][y - 2] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 3][y + 3] == 0))
			{
				//printf("%d %d D!", x, y);
				//Sleep(1000);
				count++;
			}
		}
		// 반대 대각선	   체크. 
		if (x > 3 && x < 15 && y > 3 && y < 15)
		{
			if ((tmptable[x + 4][y - 4] == 0 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 0 && tmptable[x - 1][y + 1] == 0) ||
				(tmptable[x + 4][y - 4] == 0 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0) ||
				(tmptable[x + 3][y - 3] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0) ||

				(tmptable[x - 4][y + 4] == 0 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 0 && tmptable[x + 1][y - 1] == 0) ||
				(tmptable[x - 4][y + 4] == 0 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 0 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0) ||
				(tmptable[x - 3][y + 3] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0) ||

				(tmptable[x + 2][y - 2] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x - 2][y + 2] == 0) ||
				(tmptable[x + 3][y - 3] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 0 && tmptable[x - 1][y + 1] == 2 && tmptable[x - 2][y + 2] == 0) ||
				(tmptable[x + 2][y - 2] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 3][y + 3] == 0))
			{
				//printf("%d %d U!", x, y);
				//Sleep(1000);
				count++;
			}
		}
		if (count > 1) return 1;
	}

		{ //44
			int count = 0;
			// 가로체크. 
			if (x > 4 && x < 14)
			{
				if ((tmptable[x - 5][y] == 0 && tmptable[x - 4][y] == 2 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 0 && tmptable[x + 1][y] == 0) ||
					(tmptable[x - 5][y] == 0 && tmptable[x - 4][y] == 2 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0) ||
					(tmptable[x - 5][y] == 0 && tmptable[x - 4][y] == 2 && tmptable[x - 3][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0) ||
					(tmptable[x - 4][y] == 0 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0) ||

					(tmptable[x + 5][y] == 0 && tmptable[x + 4][y] == 2 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 0 && tmptable[x - 1][y] == 0) ||
					(tmptable[x + 5][y] == 0 && tmptable[x + 4][y] == 2 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 0 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0) ||
					(tmptable[x + 5][y] == 0 && tmptable[x + 4][y] == 2 && tmptable[x + 3][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0) ||
					(tmptable[x + 4][y] == 0 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0) ||

					(tmptable[x - 4][y] == 0 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 0 && tmptable[x + 1][y] == 2 && tmptable[x + 2][y] == 0) ||
					(tmptable[x - 4][y] == 0 && tmptable[x - 3][y] == 2 && tmptable[x - 2][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x + 2][y] == 0) ||
					(tmptable[x - 3][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x + 2][y] == 0) ||
					(tmptable[x - 3][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x + 1][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 3][y] == 0) ||

					(tmptable[x + 4][y] == 0 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 0 && tmptable[x - 1][y] == 2 && tmptable[x - 2][y] == 0) ||
					(tmptable[x + 4][y] == 0 && tmptable[x + 3][y] == 2 && tmptable[x + 2][y] == 0 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x - 2][y] == 0) ||
					(tmptable[x + 3][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 2 && tmptable[x - 2][y] == 0) ||
					(tmptable[x + 3][y] == 0 && tmptable[x + 2][y] == 2 && tmptable[x + 1][y] == 2 && tmptable[x - 1][y] == 0 && tmptable[x - 2][y] == 2 && tmptable[x - 3][y] == 0))
				{
					//printf("%d %d G!", x, y);
					//Sleep(1000);
					count++;
				}
			}
			// 세로체크. 
			if (y > 4 && y < 14)
			{
				if ((tmptable[x][y - 5] == 0 && tmptable[x][y - 4] == 2 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 0 && tmptable[x][y + 1] == 0) ||
					(tmptable[x][y - 5] == 0 && tmptable[x][y - 4] == 2 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0) ||
					(tmptable[x][y - 5] == 0 && tmptable[x][y - 4] == 2 && tmptable[x][y - 3] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0) ||
					(tmptable[x][y - 4] == 0 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0) ||

					(tmptable[x][y + 5] == 0 && tmptable[x][y + 4] == 2 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 0 && tmptable[x][y - 1] == 0) ||
					(tmptable[x][y + 5] == 0 && tmptable[x][y + 4] == 2 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 0 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0) ||
					(tmptable[x][y + 5] == 0 && tmptable[x][y + 4] == 2 && tmptable[x][y + 3] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0) ||
					(tmptable[x][y + 4] == 0 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0) ||

					(tmptable[x][y - 4] == 0 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 0 && tmptable[x][y + 1] == 2 && tmptable[x][y + 2] == 0) ||
					(tmptable[x][y - 4] == 0 && tmptable[x][y - 3] == 2 && tmptable[x][y - 2] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y + 2] == 0) ||
					(tmptable[x][y - 3] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y + 2] == 0) ||
					(tmptable[x][y - 3] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y + 1] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 3] == 0) ||

					(tmptable[x][y + 4] == 0 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 0 && tmptable[x][y - 1] == 2 && tmptable[x][y - 2] == 0) ||
					(tmptable[x][y + 4] == 0 && tmptable[x][y + 3] == 2 && tmptable[x][y + 2] == 0 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y - 2] == 0) ||
					(tmptable[x][y + 3] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 2 && tmptable[x][y - 2] == 0) ||
					(tmptable[x][y + 3] == 0 && tmptable[x][y + 2] == 2 && tmptable[x][y + 1] == 2 && tmptable[x][y - 1] == 0 && tmptable[x][y - 2] == 2 && tmptable[x][y - 3] == 0))
				{
					//printf("%d %d S!", x, y);
					//Sleep(1000);
					count++;
				}
			}
			// 대각선체크. 
			if (x > 4 && x < 14 && y > 4 && y < 14)
			{
				if ((tmptable[x - 5][y - 5] == 0 && tmptable[x - 4][y - 4] == 2 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 0 && tmptable[x + 1][y + 1] == 0) ||
					(tmptable[x - 5][y - 5] == 0 && tmptable[x - 4][y - 4] == 2 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0) ||
					(tmptable[x - 5][y - 5] == 0 && tmptable[x - 4][y - 4] == 2 && tmptable[x - 3][y - 3] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0) ||
					(tmptable[x - 4][y - 4] == 0 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0) ||

					(tmptable[x + 5][y + 5] == 0 && tmptable[x + 4][y + 4] == 2 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 0 && tmptable[x - 1][y - 1] == 0) ||
					(tmptable[x + 5][y + 5] == 0 && tmptable[x + 4][y + 4] == 2 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 0 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0) ||
					(tmptable[x + 5][y + 5] == 0 && tmptable[x + 4][y + 4] == 2 && tmptable[x + 3][y + 3] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0) ||
					(tmptable[x + 4][y + 4] == 0 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0) ||

					(tmptable[x - 4][y - 4] == 0 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 0 && tmptable[x + 1][y + 1] == 2 && tmptable[x + 2][y + 2] == 0) ||
					(tmptable[x - 4][y - 4] == 0 && tmptable[x - 3][y - 3] == 2 && tmptable[x - 2][y - 2] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x + 2][y + 2] == 0) ||
					(tmptable[x - 3][y - 3] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x + 2][y + 2] == 0) ||
					(tmptable[x - 3][y - 3] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x + 1][y + 1] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 3][y + 3] == 0) ||

					(tmptable[x + 4][y + 4] == 0 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 0 && tmptable[x - 1][y - 1] == 2 && tmptable[x - 2][y - 2] == 0) ||
					(tmptable[x + 4][y + 4] == 0 && tmptable[x + 3][y + 3] == 2 && tmptable[x + 2][y + 2] == 0 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x - 2][y - 2] == 0) ||
					(tmptable[x + 3][y + 3] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 2 && tmptable[x - 2][y - 2] == 0) ||
					(tmptable[x + 3][y + 3] == 0 && tmptable[x + 2][y + 2] == 2 && tmptable[x + 1][y + 1] == 2 && tmptable[x - 1][y - 1] == 0 && tmptable[x - 2][y - 2] == 2 && tmptable[x - 3][y - 3] == 0))
				{
					//printf("%d %d D!", x, y);
					//Sleep(1000);
					count++;
				}
			}
			// 반대 대각선	   체크. 
			if (x > 4 && x < 14 && y > 4 && y < 14)
			{
				if ((tmptable[x + 5][y - 5] == 0 && tmptable[x + 4][y - 4] == 2 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 0 && tmptable[x - 1][y + 1] == 0) ||
					(tmptable[x + 5][y - 5] == 0 && tmptable[x + 4][y - 4] == 2 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0) ||
					(tmptable[x + 5][y - 5] == 0 && tmptable[x + 4][y - 4] == 2 && tmptable[x + 3][y - 3] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0) ||
					(tmptable[x + 4][y - 4] == 0 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0) ||

					(tmptable[x - 5][y + 5] == 0 && tmptable[x - 4][y + 4] == 2 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 0 && tmptable[x + 1][y - 1] == 0) ||
					(tmptable[x - 5][y + 5] == 0 && tmptable[x - 4][y + 4] == 2 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 0 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0) ||
					(tmptable[x - 5][y + 5] == 0 && tmptable[x - 4][y + 4] == 2 && tmptable[x - 3][y + 3] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0) ||
					(tmptable[x - 4][y + 4] == 0 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0) ||

					(tmptable[x + 4][y - 4] == 0 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 0 && tmptable[x - 1][y + 1] == 2 && tmptable[x - 2][y + 2] == 0) ||
					(tmptable[x + 4][y - 4] == 0 && tmptable[x + 3][y - 3] == 2 && tmptable[x + 2][y - 2] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x - 2][y + 2] == 0) ||
					(tmptable[x + 3][y - 3] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x - 2][y + 2] == 0) ||
					(tmptable[x + 3][y - 3] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x - 1][y + 1] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 3][y + 3] == 0) ||

					(tmptable[x - 4][y + 4] == 0 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 0 && tmptable[x + 1][y - 1] == 2 && tmptable[x + 2][y - 2] == 0) ||
					(tmptable[x - 4][y + 4] == 0 && tmptable[x - 3][y + 3] == 2 && tmptable[x - 2][y + 2] == 0 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x + 2][y - 2] == 0) ||
					(tmptable[x - 3][y + 3] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 2 && tmptable[x + 2][y - 2] == 0) ||
					(tmptable[x - 3][y + 3] == 0 && tmptable[x - 2][y + 2] == 2 && tmptable[x - 1][y + 1] == 2 && tmptable[x + 1][y - 1] == 0 && tmptable[x + 2][y - 2] == 2 && tmptable[x + 3][y - 3] == 0))
				{
					//printf("%d %d U!", x, y);
					//Sleep(1000);
					count++;
				}
			}
		if (count > 1) return 1;
		else return 0;
	}
}

void WhiteAttack_2017180021(int*x, int*y)
{
	//
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (table_2017180021[j][i] == 1 || table_2017180021[j][i] == 2)
			{
				weightableForW_2017180021[j][i] = 0;
				weightableForB_2017180021[j][i] = 0;
				weightableForA_2017180021[j][i] = 0;
			}
		}
	}

	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				weightableForA_2017180021[j][i] = weightableForW_2017180021[j][i] + weightableForB_2017180021[j][i];
			}
		}
		int findMax = 0, fx = 10, fy = 10;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (weightableForA_2017180021[j][i] > findMax)
				{
					findMax = weightableForA_2017180021[j][i];
					fx = j;
					fy = i;
				}
			}
		}

		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (weightableForA_2017180021[j][i] == findMax)
				{
					//ㅍ평가함수
				}
			}
		}
		getX_2017180021 = fx;
		getY_2017180021 = fy;
	}
	*x = getX_2017180021;
	*y = getY_2017180021;

	table_2017180021[getX_2017180021][getY_2017180021] = 2;

	getX_2017180021++;
	getY_2017180021++;
	{
		// W
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][getY_2017180021 - 1];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if ((splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
						{
							weightableForB_2017180021[j + k][getY_2017180021 - 1] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2 + 10;
						}
						else
							weightableForB_2017180021[j + k][getY_2017180021 - 1] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2;
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[j + 4][getY_2017180021 - 1] == 0)
							{
								weightableForB_2017180021[j][getY_2017180021 - 1] += 10;
								weightableForB_2017180021[j + 4][getY_2017180021 - 1] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15)
				{
					weightableForB_2017180021[j - 1][getY_2017180021 - 1] += 70;
					weightableForB_2017180021[j + 4][getY_2017180021 - 1] += 70;
				}
			}
		}
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[getX_2017180021 - 1][j + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[getX_2017180021 - 1][j + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2 + 10;
						else
							weightableForB_2017180021[getX_2017180021 - 1][j + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2;
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[getX_2017180021 - 1][j + 4] == 0)
							{
								weightableForB_2017180021[getX_2017180021 - 1][j] += 10;
								weightableForB_2017180021[getX_2017180021 - 1][j + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15)
				{
					weightableForB_2017180021[getX_2017180021 - 1][j - 1] += 100;
					weightableForB_2017180021[getX_2017180021 - 1][j + 4] += 100;
				}
			}
		}
		//우하단
		int yStarter = 0;
		int yKo = 0;
		for (int j = (getX_2017180021 - 1) - (getY_2017180021 - 1); j < 16; j++, yKo++)
		{
			if (j < 0)
			{
				yStarter++;
				yKo--;
				continue;
			}
			if (yStarter + yKo >= 16)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][yStarter + yKo + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2 + 10;
						else
							weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2;
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19 && yStarter + yKo + 4 < 19)
						{
							if (table_2017180021[j + 4][yStarter + yKo + 4] == 0)
							{
								weightableForB_2017180021[j][yStarter + yKo] += 10;
								weightableForB_2017180021[j + 4][yStarter + yKo + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15 && yStarter + yKo > 0 && yStarter + yKo < 15)
				{
					weightableForB_2017180021[j - 1][yStarter + yKo - 1] += 70;
					weightableForB_2017180021[j + 4][yStarter + yKo + 4] += 70;
				}
			}
		}
		//좌하단
		int ynStarter = 18;
		int ynKo = 0;
		for (int j = (getX_2017180021 - 1) - (18 - (getY_2017180021 - 1)); j < 16; j++, ynKo++)
		{
			if (j < 0)
			{
				ynStarter--;
				ynKo--;
				continue;
			}
			if (ynStarter - ynKo < 3)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][ynStarter - ynKo - k];

			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2 + 10;
						else
							weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) / 2;
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19 && ynStarter - ynKo - 4 >= 0)
						{
							if (table_2017180021[j + 4][ynStarter - ynKo - 4] == 0)
							{
								weightableForB_2017180021[j][ynStarter - ynKo] += 10;
								weightableForB_2017180021[j + 4][ynStarter - ynKo - 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
				{
					weightableForB_2017180021[j - 1][ynStarter - ynKo + 1] += 70;
					weightableForB_2017180021[j + 4][ynStarter - ynKo - 4] += 70;
				}
			}
		}
	}

}
void WhiteDefence_2017180021(int x, int y)
{
	table_2017180021[x][y] = 1;
	getX_2017180021 = x + 1;
	getY_2017180021 = y + 1;
	//
	{
		//
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][getY_2017180021 - 1];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][getY_2017180021 - 1] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][getY_2017180021 - 1] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[j + 4][getY_2017180021 - 1] == 0)
							{
								weightableForW_2017180021[j][getY_2017180021 - 1] += 10;
								weightableForW_2017180021[j + 4][getY_2017180021 - 1] += 10;
							}
						}
					}

				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15)
				{
					weightableForW_2017180021[j - 1][getY_2017180021 - 1] += 70;
					weightableForW_2017180021[j + 4][getY_2017180021 - 1] += 70;
				}
			}
		}
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[getX_2017180021 - 1][j + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[getX_2017180021 - 1][j + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[getX_2017180021 - 1][j + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[getX_2017180021 - 1][j + 4] == 0)
							{
								weightableForW_2017180021[getX_2017180021 - 1][j] += 10;
								weightableForW_2017180021[getX_2017180021 - 1][j + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15)
				{
					weightableForW_2017180021[getX_2017180021 - 1][j - 1] += 70;
					weightableForW_2017180021[getX_2017180021 - 1][j + 4] += 70;
				}
			}
		}
		//우하단
		int yStarter = 0;
		int yKo = 0;
		for (int j = (getX_2017180021 - 1) - (getY_2017180021 - 1); j < 16; j++, yKo++)
		{
			if (j < 0)
			{
				yStarter++;
				yKo--;
				continue;
			}
			if (yStarter + yKo >= 16)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][yStarter + yKo + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][yStarter + yKo + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][yStarter + yKo + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19 && yStarter + yKo + 4 < 19)
						{
							if (table_2017180021[j + 4][yStarter + yKo + 4] == 0)
							{
								weightableForW_2017180021[j][yStarter + yKo] += 10;
								weightableForW_2017180021[j + 4][yStarter + yKo + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15 && yStarter + yKo > 0 && yStarter + yKo < 15)
				{
					weightableForW_2017180021[j - 1][yStarter + yKo - 1] += 70;
					weightableForW_2017180021[j + 4][yStarter + yKo + 4] += 70;
				}
			}
		}
		//좌하단
		int ynStarter = 18;
		int ynKo = 0;
		for (int j = (getX_2017180021 - 1) - (18 - (getY_2017180021 - 1)); j < 16; j++, ynKo++)
		{
			if (j < 0)
			{
				ynStarter--;
				ynKo--;
				continue;
			}
			if (ynStarter - ynKo < 3)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][ynStarter - ynKo - k];

			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19 && ynStarter - ynKo - 4 >= 0)
						{
							if (table_2017180021[j + 4][ynStarter - ynKo - 4] == 0)
							{
								weightableForW_2017180021[j][ynStarter - ynKo] += 10;
								weightableForW_2017180021[j + 4][ynStarter - ynKo - 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
				{
					weightableForW_2017180021[j - 1][ynStarter - ynKo + 1] += 70;
					weightableForW_2017180021[j + 4][ynStarter - ynKo - 4] += 70;
				}
			}
		}
	}
}
void AttackBlack_2017180021(int*x, int*y)
{
	//
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (table_2017180021[j][i] == 1 || table_2017180021[j][i] == 2)
			{
				weightableForW_2017180021[j][i] = 0;
				weightableForB_2017180021[j][i] = 0;
				weightableForA_2017180021[j][i] = 0;
			}
		}
	}

	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				weightableForA_2017180021[j][i] = weightableForW_2017180021[j][i] + weightableForB_2017180021[j][i];
			}
		}
		//for (int i = 0; i < 19; i++)
		//{
		//	for (int j = 0; j < 19; j++)
		//	{
		//		if (weightableForA[j][i] > 0)
		//		{
		//			
		//		}
		//	}
		//}
		REF:
		int findMax = 0, fx = 10, fy = 10;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (weightableForA_2017180021[j][i] > findMax)
				{
					findMax = weightableForA_2017180021[j][i];
					fx = j;
					fy = i;
				}
			}
		}
		if (isExitedStone_2017180021(fx, fy))
		{
			//printf("!! %d %d !!", fx, fy);
			//Sleep(4000);
			weightableForA_2017180021[fx][fy] = 0;
			goto REF;
		}
		if (findMax == 0)
		{
			fx = 9;
			fy = 9;
		}
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (weightableForA_2017180021[j][i] == findMax)
				{
					//ㅍ평가함수
				}
			}
		}
		getX_2017180021 = fx;
		getY_2017180021 = fy;
	}
	*x = getX_2017180021;
	*y = getY_2017180021;

	table_2017180021[getX_2017180021][getY_2017180021] = 2;

	getX_2017180021++;
	getY_2017180021++;
	{
		// W
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][getY_2017180021 - 1];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if ((splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
						{
							weightableForB_2017180021[j + k][getY_2017180021 - 1] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) + 10;
						}
						else
							weightableForB_2017180021[j + k][getY_2017180021 - 1] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]);
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[j + 4][getY_2017180021 - 1] == 0)
							{
								weightableForB_2017180021[j][getY_2017180021 - 1] += 10;
								weightableForB_2017180021[j + 4][getY_2017180021 - 1] += 10;
							}
						}
					}

				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15)
				{
					weightableForB_2017180021[j - 1][getY_2017180021 - 1] += 70;
					weightableForB_2017180021[j + 4][getY_2017180021 - 1] += 70;
				}
			}
		}
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[getX_2017180021 - 1][j + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[getX_2017180021 - 1][j + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) + 10;
						else
							weightableForB_2017180021[getX_2017180021 - 1][j + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]);
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[getX_2017180021 - 1][j + 4] == 0)
							{
								weightableForB_2017180021[getX_2017180021 - 1][j] += 10;
								weightableForB_2017180021[getX_2017180021 - 1][j + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15)
				{
					weightableForB_2017180021[getX_2017180021 - 1][j - 1] += 100;
					weightableForB_2017180021[getX_2017180021 - 1][j + 4] += 100;
				}
			}
		}
		//우하단
		int yStarter = 0;
		int yKo = 0;
		for (int j = (getX_2017180021 - 1) - (getY_2017180021 - 1); j < 16; j++, yKo++)
		{
			if (j < 0)
			{
				yStarter++;
				yKo--;
				continue;
			}
			if (yStarter + yKo >= 16)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][yStarter + yKo + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) + 10;
						else
							weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]);
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19 && yStarter + yKo + 4 < 19)
						{
							if (table_2017180021[j + 4][yStarter + yKo + 4] == 0)
							{
								weightableForB_2017180021[j][yStarter + yKo] += 10;
								weightableForB_2017180021[j + 4][yStarter + yKo + 4] += 10;
							}
						}
					}

				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15 && yStarter + yKo > 0 && yStarter + yKo < 15)
				{
					weightableForB_2017180021[j - 1][yStarter + yKo - 1] += 70;
					weightableForB_2017180021[j + 4][yStarter + yKo + 4] += 70;
				}
			}
		}
		//좌하단
		int ynStarter = 18;
		int ynKo = 0;
		for (int j = (getX_2017180021 - 1) - (18 - (getY_2017180021 - 1)); j < 16; j++, ynKo++)
		{
			if (j < 0)
			{
				ynStarter--;
				ynKo--;
				continue;
			}
			if (ynStarter - ynKo < 3)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][ynStarter - ynKo - k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 2) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 2) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 2) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 2) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 6)
							weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) + 10;
						else
							weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]);
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 6)
					{
						if (j + 4 < 19 && ynStarter - ynKo - 4 >= 0)
						{
							if (table_2017180021[j + 4][ynStarter - ynKo - 4] == 0)
							{
								weightableForB_2017180021[j][ynStarter - ynKo] += 10;
								weightableForB_2017180021[j + 4][ynStarter - ynKo - 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 2 && splender_2017180021[1] == 2 && splender_2017180021[2] == 2 && splender_2017180021[3] == 2)
			{
				if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
				{
					weightableForB_2017180021[j - 1][ynStarter - ynKo + 1] += 70;
					weightableForB_2017180021[j + 4][ynStarter - ynKo - 4] += 70;
				}
			}
		}
	}
}
void DefenceBlack_2017180021(int x, int y)
{
	table_2017180021[x][y] = 1;
	getX_2017180021 = x + 1;
	getY_2017180021 = y + 1;
	//
	{
		//
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][getY_2017180021 - 1];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][getY_2017180021 - 1] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][getY_2017180021 - 1] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[j + 4][getY_2017180021 - 1] == 0)
							{
								weightableForW_2017180021[j][getY_2017180021 - 1] += 10;
								weightableForW_2017180021[j + 4][getY_2017180021 - 1] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15)
				{
					weightableForW_2017180021[j - 1][getY_2017180021 - 1] += 70;
					weightableForW_2017180021[j + 4][getY_2017180021 - 1] += 70;
				}
			}
		}
		for (int j = 0; j < 16; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[getX_2017180021 - 1][j + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[getX_2017180021 - 1][j + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[getX_2017180021 - 1][j + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19)
						{
							if (table_2017180021[getX_2017180021 - 1][j + 4] == 0)
							{
								weightableForW_2017180021[getX_2017180021 - 1][j] += 10;
								weightableForW_2017180021[getX_2017180021 - 1][j + 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15)
				{
					weightableForW_2017180021[getX_2017180021 - 1][j - 1] += 70;
					weightableForW_2017180021[getX_2017180021 - 1][j + 4] += 70;
				}
			}
		}
		//우하단
		int yStarter = 0;
		int yKo = 0;
		for (int j = (getX_2017180021 - 1) - (getY_2017180021 - 1); j < 16; j++, yKo++)
		{
			if (j < 0)
			{
				yStarter++;
				yKo--;
				continue;
			}
			if (yStarter + yKo >= 16)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][yStarter + yKo + k];
			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][yStarter + yKo + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][yStarter + yKo + k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19 && yStarter + yKo + 4 < 19)
						{
							if (table_2017180021[j + 4][yStarter + yKo + 4] == 0)
							{
								weightableForW_2017180021[j][yStarter + yKo] += 10;
								weightableForW_2017180021[j + 4][yStarter + yKo + 4] += 10;
							}
						}
					}

				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15 && yStarter + yKo > 0 && yStarter + yKo < 15)
				{
					weightableForW_2017180021[j - 1][yStarter + yKo - 1] += 70;
					weightableForW_2017180021[j + 4][yStarter + yKo + 4] += 70;
				}
			}
		}
		//좌하단
		int ynStarter = 18;
		int ynKo = 0;
		for (int j = (getX_2017180021 - 1) - (18 - (getY_2017180021 - 1)); j < 16; j++, ynKo++)
		{
			if (j < 0)
			{
				ynStarter--;
				ynKo--;
				continue;
			}
			if (ynStarter - ynKo < 3)
				break;
			for (int k = 0; k < 4; k++)
			{
				splender_2017180021[k] = table_2017180021[j + k][ynStarter - ynKo - k];

			}
			if ((splender_2017180021[0] == 0 || splender_2017180021[0] == 1) && (splender_2017180021[1] == 0 || splender_2017180021[1] == 1) &&
				(splender_2017180021[2] == 0 || splender_2017180021[2] == 1) && (splender_2017180021[3] == 0 || splender_2017180021[3] == 1) &&
				splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					if (splender_2017180021[k] == 0)
					{
						if (splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] == 3)
							weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3] + 20;
						else
							weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender_2017180021[0] + splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3];
					}
					if (splender_2017180021[0] == 0 && (splender_2017180021[1] + splender_2017180021[2] + splender_2017180021[3]) == 3)
					{
						if (j + 4 < 19 && ynStarter - ynKo - 4 >= 0)
						{
							if (table_2017180021[j + 4][ynStarter - ynKo - 4] == 0)
							{
								weightableForW_2017180021[j][ynStarter - ynKo] += 10;
								weightableForW_2017180021[j + 4][ynStarter - ynKo - 4] += 10;
							}
						}
					}
				}
			}
			if (splender_2017180021[0] == 1 && splender_2017180021[1] == 1 && splender_2017180021[2] == 1 && splender_2017180021[3] == 1)
			{
				if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
				{
					weightableForW_2017180021[j - 1][ynStarter - ynKo + 1] += 70;
					weightableForW_2017180021[j + 4][ynStarter - ynKo - 4] += 70;
				}
			}
		}
	}
}
