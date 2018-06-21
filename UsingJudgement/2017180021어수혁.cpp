
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

typedef struct _stone
{
	int x;
	int y;
	BOOL color;
	BOOL isntEmpty;
}stone;

void movexy(int x,int y)
{
	COORD s = { (x-1)*2,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), s);
}
BOOL test = FALSE;
int weightableForB_2017180021[19][19] = { 0 };
int weightableForW_2017180021[19][19] = { 0 };
int weightableForA_2017180021[19][19] = { 0 };

void drawUi()
{
	movexy(1, 1);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			weightableForA_2017180021[j][i] = weightableForW_2017180021[j][i] + weightableForB_2017180021[j][i];
		}
	}
	if (test)
	{
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				printf("%2d", weightableForA_2017180021[j][i]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐\n");
		for (int i = 0; i < 17; i++)
		{
			printf("├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤\n");
		}
		printf("└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘\n");
	}
}

int main()
{
	int choice;

	int getX = -1, getY = -1;
	int p1 = 0, p2 = 0;
	int turnofwho = 0;
	int table[19][19] = { 0 };

	stone UndoStack[361];
	int UndoPointer = 0;

	int nBlack = 0, nWhite = 0;
	int Maximum[2] = { 0 };
	int SavedMaximum[2] = { 0 };
	bool isSamestone[2] = { false };
	bool blink = false;
	int splender[4];
	POINT dangerPoint[2];

	int startingMax[2] = { 0 };
	char MenuChar;

	drawUi();
	for (int i = 0; i < 361; i++)
	{
		UndoStack[i].x = -1;
		UndoStack[i].y = 0;
		UndoStack[i].color = 0;
		UndoStack[i].isntEmpty = 0;
	}

	while(1)
	{
		movexy(30, 25);
		printf("p1 : %d , p2 : %d", p1, p2);
		movexy(30, 20);
		printf("1: 돌 놓기 2: 메뉴");
		movexy(30, 20);
		choice = getch();

		if (choice == '1')
		{
			drawUi();
			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (table[j][i] == 1)
					{
						movexy(j + 1, i + 1);
						printf("★");
					}
					else if (table[j][i] == 2)
					{
						movexy(j + 1, i + 1);
						printf("☆");
					}
				}
			}
			if (turnofwho)
			{
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						weightableForA_2017180021[j][i] = weightableForW_2017180021[j][i] + weightableForB_2017180021[j][i];
					}
				}
				int findMax = 0, fx = 10,fy = 10;
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
				getX = fx+1;
				getY = fy+1;
				goto AI;
			}
			//movexy(30, 19);
			//printf("                   "); //지우기
			movexy(30, 20);
			printf("                   "); //지우기
			movexy(30, 20);
			scanf("%d %d", &getX, &getY);
			AI:

			if (getX == 100 && getY == 1) //저장
			{
				FILE* fp = fopen("save.txt", "w+" );

				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						fprintf(fp, "%d", table[j][i]);
					}
				}

				fclose(fp);
				fp = fopen("stack.txt", "w+");

				for (int i = 0; i < 361; i++)
				{
					fprintf(fp, "%2d", UndoStack[i].x);
					fprintf(fp, "%2d", UndoStack[i].y);
					fprintf(fp, "%2d", UndoStack[i].color);
					fprintf(fp, "%2d", UndoStack[i].isntEmpty);
					fprintf(fp, "\n");
				}
				fprintf(fp, "%2d", UndoPointer);
				fclose(fp);
				
			}
			else if (getX == 100 && getY == 2) //불러오기
			{
				char fileCrop[2];
				int w=0, b=0;
				FILE* fp = fopen("save.txt", "r");

				if (fp == NULL)
				{
					movexy(30, 20);
					printf("파일이 없는걸요!");
					getchar();
					getchar();
					continue;
				}

				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						fgets(fileCrop, 2, fp);

						if (fileCrop[0] == '1')
						{
							table[j][i] = 1;
							b++;
						}
						else if (fileCrop[0] == '2')
						{
							table[j][i] = 2;
							w++;
						}
					}
				}

				turnofwho = b > w ? 1 : 0;

				fclose(fp);

				fp = fopen("stack.txt", "r");

				for (int i = 0; i < 361; i++)
				{
					fscanf(fp, "%2d %2d %2d %2d", &UndoStack[i].x, &UndoStack[i].y, &UndoStack[i].color, &UndoStack[i].isntEmpty);
				}
				fscanf(fp, "%2d", &UndoPointer);
				fclose(fp);
			}
			else if (getX <= 0 || getX > 19 || getY <= 0 || getY > 19)
			{
				movexy(30, 24);
				printf("Don't be rude!");
				movexy(30, 20);
				printf("                   "); //지우기
				movexy(30, 20);
				rewind(stdin);
				getX = -1, getY = -1;
				continue;
			}

			if (table[getX - 1][getY - 1] == 0 && turnofwho == 0)
			{
				UndoStack[UndoPointer].x = getX;
				UndoStack[UndoPointer].y = getY;
				UndoStack[UndoPointer].color = 0;
				UndoStack[UndoPointer].isntEmpty = 1;
				UndoPointer++;


				movexy(getX, getY);
				printf("★");
				movexy(30, 24);
				printf("                   "); //지우기
				movexy(30, 20);
				printf("                   "); //지우기
				movexy(30, 20);
				table[getX - 1][getY - 1] = 1;
		
				//
				for (int j = 0; j < 16; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						splender[k] = table[j + k][getY - 1];
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 3)
									weightableForW_2017180021[j + k][getY - 1] += splender[0] + splender[1] + splender[2] + splender[3] + 10;
								else
									weightableForW_2017180021[j + k][getY - 1] += splender[0] + splender[1] + splender[2] + splender[3];
							}
								
						}
					}
					if (splender[0] == 1 && splender[1] == 1 && splender[2] == 1 && splender[3] == 1)
					{
						if (j > 0 && j < 15)
						{
							weightableForW_2017180021[j - 1][getY - 1] += 50;
							weightableForW_2017180021[j + 4][getY - 1] += 50;
						}
					}
				}
				for (int j = 0; j < 16; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						splender[k] = table[getX - 1][j + k];
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 3)
									weightableForW_2017180021[getX - 1][j + k] += splender[0] + splender[1] + splender[2] + splender[3] + 10;
								else
									weightableForW_2017180021[getX - 1][j + k] += splender[0] + splender[1] + splender[2] + splender[3];
							}
						}
					}
					if (splender[0] == 1 && splender[1] == 1 && splender[2] == 1 && splender[3] == 1)
					{
						if (j > 0 && j < 15)
						{
							weightableForW_2017180021[getX - 1][j - 1] += 50;
							weightableForW_2017180021[getX - 1][j + 4] += 50;
						}
					}
				}
				//우하단
				int yStarter = 0;
				int yKo = 0;
				for (int j = (getX-1)-(getY-1); j < 16; j++, yKo++)
				{
					if (j < 0)
					{
						yStarter++;
						yKo--;
						continue;
					}
					if (yStarter+yKo >= 16)
						break;
					for (int k = 0; k < 4; k++)
					{
						splender[k] = table[j + k][yStarter+yKo+k];
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if(splender[0] + splender[1] + splender[2] + splender[3] == 3)
									weightableForW_2017180021[j + k][yStarter + yKo + k] += splender[0] + splender[1] + splender[2] + splender[3] + 10;
								else
									weightableForW_2017180021[j + k][yStarter + yKo + k] += splender[0] + splender[1] + splender[2] + splender[3];
							}
								
						}
					}
					if (splender[0] == 1 && splender[1] == 1 && splender[2] == 1 && splender[3] == 1)
					{
						if (j > 0 && j < 15 && yStarter+yKo > 0 && yStarter + yKo < 15)
						{
							weightableForW_2017180021[j - 1][yStarter + yKo - 1] += 50;
							weightableForW_2017180021[j + 4][yStarter + yKo + 4] += 50;
						}
					}
				}
				//좌하단
				int ynStarter = 18;
				int ynKo = 0;
				for (int j = (getX - 1) - (18 - (getY - 1)); j < 16; j++, ynKo++)
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
						splender[k] = table[j + k][ynStarter - ynKo - k];
						
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 3)
									weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender[0] + splender[1] + splender[2] + splender[3] + 10;
								else
									weightableForW_2017180021[j + k][ynStarter - ynKo - k] += splender[0] + splender[1] + splender[2] + splender[3];
							}
								
						}
					}
					if (splender[0] == 1 && splender[1] == 1 && splender[2] == 1 && splender[3] == 1)
					{
						if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
						{
							weightableForW_2017180021[j - 1][ynStarter - ynKo + 1] +=50;
							weightableForW_2017180021[j + 4][ynStarter - ynKo - 4] += 50;
						}
					}
				}
				drawUi();
				turnofwho = 1;//턴 변경
				p1++;
				getX = -1, getY = -1;
			}
			else if (table[getX - 1][getY - 1] == 0 && turnofwho == 1)
			{
				UndoStack[UndoPointer].x = getX;
				UndoStack[UndoPointer].y = getY;
				UndoStack[UndoPointer].color = 1;
				UndoStack[UndoPointer].isntEmpty = 1;

				UndoPointer++;
				movexy(getX, getY);
				printf("☆");
				movexy(30, 24);
				printf("                   "); //지우기
				movexy(30, 20);
				printf("                   "); //지우기
				movexy(30, 20);
				table[getX - 1][getY - 1] = 2;

				// W
				for (int j = 0; j < 16; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						splender[k] = table[j + k][getY - 1];
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if ((splender[0] + splender[1] + splender[2] + splender[3]) == 6)
								{
									weightableForB_2017180021[j + k][getY - 1] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2 + 10;
								}
								else
									weightableForB_2017180021[j + k][getY - 1] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2;
							}

						}
					}
					if (splender[0] == 2 && splender[1] == 2 && splender[2] == 2 && splender[3] == 2)
					{
						if (j > 0 && j < 15)
						{
							weightableForB_2017180021[j - 1][getY - 1] += 50;
							weightableForB_2017180021[j + 4][getY - 1] += 50;
						}
					}
				}
				for (int j = 0; j < 16; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						splender[k] = table[getX - 1][j + k];
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 6)
									weightableForB_2017180021[getX - 1][j + k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2 + 10;
								else
									weightableForB_2017180021[getX - 1][j + k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2;
							}
						}
					}
					if (splender[0] == 2 && splender[1] == 2 && splender[2] == 2 && splender[3] == 2)
					{
						if (j > 0 && j < 15)
						{
							weightableForB_2017180021[getX - 1][j - 1] += 100;
							weightableForB_2017180021[getX - 1][j + 4] += 100;
						}
					}
				}
				//우하단
				int yStarter = 0;
				int yKo = 0;
				for (int j = (getX - 1) - (getY - 1); j < 16; j++, yKo++)
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
						splender[k] = table[j + k][yStarter + yKo + k];
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 6)
									weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2 + 10;
								else
									weightableForB_2017180021[j + k][yStarter + yKo + k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2;
							}

						}
					}
					if (splender[0] == 2 && splender[1] == 2 && splender[2] == 2 && splender[3] == 2)
					{
						if (j > 0 && j < 15 && yStarter + yKo > 0 && yStarter + yKo < 15)
						{
							weightableForB_2017180021[j - 1][yStarter + yKo - 1] += 50;
							weightableForB_2017180021[j + 4][yStarter + yKo + 4] += 50;
						}
					}
				}
				//좌하단
				int ynStarter = 18;
				int ynKo = 0;
				for (int j = (getX - 1) - (18 - (getY - 1)); j < 16; j++, ynKo++)
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
						splender[k] = table[j + k][ynStarter - ynKo - k];

					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] > 0)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								if (splender[0] + splender[1] + splender[2] + splender[3] == 6)
									weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2 + 10;
								else
									weightableForB_2017180021[j + k][ynStarter - ynKo - k] += (splender[0] + splender[1] + splender[2] + splender[3]) / 2;
							}

						}
					}
					if (splender[0] == 2 && splender[1] == 2 && splender[2] == 2 && splender[3] == 2)
					{
						if (j > 0 && j < 15 && ynStarter - ynKo > 3 && ynStarter - ynKo < 18)
						{
							weightableForB_2017180021[j - 1][ynStarter - ynKo + 1] += 50;
							weightableForB_2017180021[j + 4][ynStarter - ynKo - 4] += 50;
						}
					}
				}
				//

				turnofwho = 0;//턴 변경
				p2++;
				getX = -1, getY = -1;
				drawUi();
			}
			else if (table[getX - 1][getY - 1] == 1 || table[getX - 1][getY - 1] == 2)
			{
				movexy(30, 20);
				printf("                    "); //지우기
				movexy(30, 24);
				printf("Don't pile!");
				movexy(1, 20);
				rewind(stdin);
				getX = -1, getY = -1;
			}
			/////////////////////////////////////////////////////////////////////////////
			TRACK:
			for (int i = 0; i < 19; i++)
			{
				nBlack = 0;
				nWhite = 0;
				for (int j = 0; j < 19; j++)
				{
					if (table[j][i] == 1)
					{
						weightableForW_2017180021[j][i] = 0;
						weightableForB_2017180021[j][i] = 0;
						weightableForA_2017180021[j][i] = 0;
						nBlack++;
					}
					else if (table[j][i] == 2)
					{
						weightableForW_2017180021[j][i] = 0;
						weightableForB_2017180021[j][i] = 0;
						weightableForA_2017180021[j][i] = 0;
						nWhite++;
					}

				}
				movexy(20, i + 1);
				printf("b %d w %d", nBlack, nWhite);

			}
			for (int i = 0; i < 19; i++)
			{
				nBlack = 0;
				nWhite = 0;
				for (int j = 0; j < 19; j++)
				{
					if (table[i][j] == 1)
					{
						nBlack++;
					}
					else if (table[i][j] == 2)
					{
						nWhite++;
					}

				}
				movexy(i + 1, 20);
				printf("b");
				movexy(i + 1, 21);
				printf("%d", nBlack);
				movexy(i + 1, 22);
				printf("w");
				movexy(i + 1, 23);
				printf("%d", nWhite);

			}
			/////////////////////////////////////////////////////////////////////

			for (int i = 0; i < 19; i++)
			{
				for (int j = 0; j < 19; j++)
				{
					if (table[j][i] == 1)
					{
						movexy(j + 1, i + 1);
						printf("★");
					}
					else if (table[j][i] == 2)
					{
						movexy(j + 1, i + 1);
						printf("☆");
					}
				}
			}
			//가로


			for (int i = 0; i < 19; i++)
			{
				Maximum[0] = 0;
				Maximum[1] = 0;
				SavedMaximum[0] = 0;
				SavedMaximum[1] = 0;
				blink = false;
				dangerPoint[0].x = 0;
				dangerPoint[0].y = 0;
				dangerPoint[1].x = 0;
				dangerPoint[1].y = 0;
				startingMax[0] = 0;
				startingMax[1] = 0;

				for (int j = 0; j < 19; j++)
				{
					if (table[j][i] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
					{
						Maximum[0]++;

						if (SavedMaximum[0] < Maximum[0])
							SavedMaximum[0] = Maximum[0];

						isSamestone[0] = true;
						isSamestone[1] = false;
					}
					else if (table[j][i] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
					{
						Maximum[1]++;

						if (SavedMaximum[1] < Maximum[1])
							SavedMaximum[1] = Maximum[1];

						isSamestone[0] = false;
						isSamestone[1] = true;
					}
					else if (table[j][i] == 1 && isSamestone[0] == true)
					{
						Maximum[0]++;
						if (SavedMaximum[0] < Maximum[0])
						{
							SavedMaximum[0] = Maximum[0];
							if (SavedMaximum[0] == 2)
								startingMax[0] = j;
							else if (SavedMaximum[0] == 3 && blink == true)
								startingMax[0] = j-1;
						}
					}
					else if (table[j][i] == 2 && isSamestone[1] == true)
					{
						Maximum[1]++;
						if (SavedMaximum[1] < Maximum[1])
						{
							SavedMaximum[1] = Maximum[1];
							if (SavedMaximum[1] == 2)
								startingMax[1] = j;
							else if (SavedMaximum[1] == 3 && blink == true)
								startingMax[1] = j - 1;
						}
					}
					else if (blink == false && table[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
					{
						blink = true;
						if (isSamestone[0] == true)
							Maximum[0]++;
						else if (isSamestone[1] == true)
							Maximum[1]++;
					}
					else
					{
						Maximum[0] = 0;
						Maximum[1] = 0;
						if (blink == true)
							j--;
						isSamestone[0] = false;
						isSamestone[1] = false;
						blink = false;
					}
					if (j<16)
					{
						for (int k = 0; k < 4; k++)
						{
							splender[k] = table[j+k][i];
						}
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 3)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[0].x = k + j + 1;
								dangerPoint[0].y = i + 1;
							}
						}
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 6)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[1].x = k + j + 1;
								dangerPoint[1].y = i + 1;
							}
						}
					}
				}

				/*movexy(25, i + 1);
				if (SavedMaximum[0] > SavedMaximum[1])
				{
					printf("b %d", SavedMaximum[0]);
					if (startingMax[0] > 0)
					{
						movexy(startingMax[0], i + 1);
						for (int k = 0; k < SavedMaximum[0]; k++)
						{
							printf("※");
						}
					}

				}
				else if (SavedMaximum[0] < SavedMaximum[1])
				{
					printf("w %d", SavedMaximum[1]);
					if (startingMax[1] > 0)
					{
						movexy(startingMax[1], i + 1);
						for (int k = 0; k < SavedMaximum[1]; k++)
						{
							printf("※");
						}
					}
				}
				else
				{
					printf("= %d", SavedMaximum[0]);
					if (startingMax[0] > 0 && startingMax[1] > 0)
					{
						movexy(startingMax[0], i + 1);
						for (int k = 0; k < SavedMaximum[0]; k++)
						{
							printf("※");
						}
						movexy(startingMax[1], i + 1);
						for (int k = 0; k < SavedMaximum[1]; k++)
						{
							printf("※");
						}
					}
				}*/
				movexy(28, i + 1);
				printf("%d,%d  %d,%d", dangerPoint[0].x, dangerPoint[0].y, dangerPoint[1].x, dangerPoint[1].y);
			}

			//////////////////////////////////////////////////////////////////////////////
			//세로
			Maximum[0] = 0;
			Maximum[1] = 0;

			for (int i = 0; i < 19; i++)
			{
				Maximum[0] = 0;
				Maximum[1] = 0;
				blink = false;
				dangerPoint[0].x = 0;
				dangerPoint[0].y = 0;
				dangerPoint[1].x = 0;
				dangerPoint[1].y = 0;
				SavedMaximum[0] = 0;
				SavedMaximum[1] = 0;

				for (int j = 0; j < 19; j++)
				{
					if (table[i][j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
					{
						Maximum[0]++;

						if (SavedMaximum[0] < Maximum[0])
							SavedMaximum[0] = Maximum[0];

						isSamestone[0] = true;
						isSamestone[1] = false;
					}
					else if (table[i][j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
					{
						Maximum[1]++;

						if (SavedMaximum[1] < Maximum[1])
							SavedMaximum[1] = Maximum[1];

						isSamestone[0] = false;
						isSamestone[1] = true;
					}
					else if (table[i][j] == 1 && isSamestone[0] == true)
					{
						Maximum[0]++;
						if (SavedMaximum[0] < Maximum[0])
						{
							SavedMaximum[0] = Maximum[0];
						}
					}
					else if (table[i][j] == 2 && isSamestone[1] == true)
					{
						Maximum[1]++;
						if (SavedMaximum[1] < Maximum[1])
						{
							SavedMaximum[1] = Maximum[1];
						}
					}
					else if (blink == false && table[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
					{
						blink = true;
						if (isSamestone[0] == true)
							Maximum[0]++;
						else if (isSamestone[1] == true)
							Maximum[1]++;
					}
					else
					{
						Maximum[0] = 0;
						Maximum[1] = 0;
						if (blink == true)
							j--;
						isSamestone[0] = false;
						isSamestone[1] = false;
						blink = false;
					}
					if (j<16)
					{
						for (int k = 0; k < 4; k++)
						{
							splender[k] = table[i][j+k];
						}
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 3)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[0].x = i + 1;
								dangerPoint[0].y = j + k + 1;
							}
						}
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 6)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[1].x = i + 1;
								dangerPoint[1].y = j + k + 1;
							}
						}
					}
					
				}

				/*movexy(i + 1, 25);
				if (SavedMaximum[0] > SavedMaximum[1])
				{
					printf("b");
					movexy(i + 1, 26);
					printf("%d", SavedMaximum[0]);
				}
				else if (SavedMaximum[0] < SavedMaximum[1])
				{
					printf("w");
					movexy(i + 1, 26);
					printf("%d", SavedMaximum[1]);
				}
				else
				{
					printf("=");
					movexy(i + 1, 26);
					printf("%d", SavedMaximum[0]);
				}*/

				movexy(36, i + 1);
				printf("%d,%d  %d,%d", dangerPoint[0].x, dangerPoint[0].y, dangerPoint[1].x, dangerPoint[1].y);
			}
			//////////////////////////////////////////////////////////////////////////////
			//우하단 대각
			Maximum[0] = 0;
			Maximum[1] = 0;

			for (int i = -18; i < 19; i++)
			{
				Maximum[0] = 0;
				Maximum[1] = 0;
				blink = false;
				dangerPoint[0].x = 0;
				dangerPoint[0].y = 0;
				dangerPoint[1].x = 0;
				dangerPoint[1].y = 0;
				SavedMaximum[0] = 0;
				SavedMaximum[1] = 0;

				for (int j = 0; j < 19; j++)
				{
					if (i + j < 0 || i + j >= 19)
						continue;
					if (table[j][i + j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
					{
						Maximum[0]++;

						if (SavedMaximum[0] < Maximum[0])
							SavedMaximum[0] = Maximum[0];

						isSamestone[0] = true;
						isSamestone[1] = false;
					}
					else if (table[j][i + j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
					{
						Maximum[1]++;

						if (SavedMaximum[1] < Maximum[1])
							SavedMaximum[1] = Maximum[1];

						isSamestone[0] = false;
						isSamestone[1] = true;
					}
					else if (table[j][i + j] == 1 && isSamestone[0] == true)
					{
						Maximum[0]++;
						if (SavedMaximum[0] < Maximum[0])
						{
							SavedMaximum[0] = Maximum[0];
						}
					}
					else if (table[j][i + j] == 2 && isSamestone[1] == true)
					{
						Maximum[1]++;
						if (SavedMaximum[1] < Maximum[1])
						{
							SavedMaximum[1] = Maximum[1];
						}
					}
					else if (blink == false && table[j][i] == 0 && isSamestone[0] + isSamestone[1] > 0)
					{
						blink = true;
						if (isSamestone[0] == true)
							Maximum[0]++;
						else if (isSamestone[1] == true)
							Maximum[1]++;
					}
					else
					{
						Maximum[0] = 0;
						Maximum[1] = 0;
						if (blink == true)
							j--;
						isSamestone[0] = false;
						isSamestone[1] = false;
						blink = false;
					}
					if (i + j >= 0 || i + j < 19)
					{
						if (j < 16 && i < 16)
						{
							for (int k = 0; k < 4; k++)
							{
								splender[k] = table[j+k][i+k];
							}
						}
						
					}
					if ((splender[0] == 0 || splender[0] == 1) && (splender[1] == 0 || splender[1] == 1) &&
						(splender[2] == 0 || splender[2] == 1) && (splender[3] == 0 || splender[3] == 1) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 3)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[0].x = k + j + 1;
								dangerPoint[0].y = i + 1;
							}
						}
					}
					if ((splender[0] == 0 || splender[0] == 2) && (splender[1] == 0 || splender[1] == 2) &&
						(splender[2] == 0 || splender[2] == 2) && (splender[3] == 0 || splender[3] == 2) &&
						splender[0] + splender[1] + splender[2] + splender[3] == 6)
					{
						for (int k = 0; k < 4; k++)
						{
							if (splender[k] == 0)
							{
								dangerPoint[1].x = k + j + 1;
								dangerPoint[1].y = i + 1;
							}
						}
					}
				}

				/*movexy(1, i + 46);
				if (SavedMaximum[0] > SavedMaximum[1])
				{
					printf("b %d", SavedMaximum[0]);
				}
				else if (SavedMaximum[0] < SavedMaximum[1])
				{
					printf("w %d", SavedMaximum[1]);
				}
				else
				{
					printf("= %d", SavedMaximum[0]);
				}*/
			}

			//////////////////////////////////////////////////////////////////////////////
			//우상단 대각
			Maximum[0] = 0;
			Maximum[1] = 0;

			for (int i = 0; i < 37; i++)
			{
				Maximum[0] = 0;
				Maximum[1] = 0;
				SavedMaximum[0] = 0;
				SavedMaximum[1] = 0;

				for (int j = 0; j < 19; j++)
				{
					if (i - j < 0 || i - j >= 19)
						continue;
					if (table[j][i - j] == 1 && Maximum[0] == 0) //검은돌이고 처음나온친구
					{
						Maximum[0]++;

						if (SavedMaximum[0] < Maximum[0])
							SavedMaximum[0] = Maximum[0];

						isSamestone[0] = true;
						isSamestone[1] = false;
					}
					else if (table[j][i - j] == 2 && Maximum[1] == 0) //흰돌이고 처음나온친구
					{
						Maximum[1]++;

						if (SavedMaximum[1] < Maximum[1])
							SavedMaximum[1] = Maximum[1];

						isSamestone[0] = false;
						isSamestone[1] = true;
					}
					else if (table[j][i - j] == 1 && isSamestone[0] == true)
					{
						Maximum[0]++;
						if (SavedMaximum[0] < Maximum[0])
						{
							SavedMaximum[0] = Maximum[0];
						}
					}
					else if (table[j][i - j] == 2 && isSamestone[1] == true)
					{
						Maximum[1]++;
						if (SavedMaximum[1] < Maximum[1])
						{
							SavedMaximum[1] = Maximum[1];
						}
					}
					else
					{
						Maximum[0] = 0;
						Maximum[1] = 0;
						isSamestone[0] = false;
						isSamestone[1] = false;
					}
				}

				/*movexy(5, i + 28);
				if (SavedMaximum[0] > SavedMaximum[1])
				{
					printf("b %d", SavedMaximum[0]);
				}
				else if (SavedMaximum[0] < SavedMaximum[1])
				{
					printf("w %d", SavedMaximum[1]);
				}
				else
				{
					printf("= %d", SavedMaximum[0]);
				}*/
			}
		}
		else
		{
			if (test)
				test = FALSE;
			else
				test = TRUE;
			movexy(30, 19);
			printf("                   "); //지우기
			movexy(30, 20);
			printf("                   "); //지우기
			movexy(30, 20);
			printf("U : undo R : Redo");
			movexy(30, 20);
			MenuChar = getch();

			if (MenuChar == 'U')
			{
				if (UndoPointer == 0)
				{
					movexy(30, 19);
					printf("무를 수 없습니다!");
					continue;
				}
				UndoPointer--;
				table[UndoStack[UndoPointer].x - 1][UndoStack[UndoPointer].y - 1] = 0;
				UndoStack[UndoPointer].isntEmpty = 0;

				if (turnofwho == 0)
					turnofwho = 1;
				else
					turnofwho = 0;

				drawUi();
				goto TRACK;
			}
			else if (MenuChar == 'R')
			{
				if (UndoStack[UndoPointer].isntEmpty == 0 && UndoStack[UndoPointer].x != -1)
				{
					UndoStack[UndoPointer].isntEmpty = 1;
					table[UndoStack[UndoPointer].x - 1][UndoStack[UndoPointer].y - 1] = turnofwho + 1;
					UndoPointer++;

					if (turnofwho == 0)
						turnofwho = 1;
					else
						turnofwho = 0;

					drawUi();
					goto TRACK;
				}
			}
		}
	} 
	
}