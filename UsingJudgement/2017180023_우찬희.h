#pragma once
#include <random>
#include <math.h>
#include <windows.h>
#include "Judgment.h"

int board_2017180023[19][19];
int lastlast_x_2017180023 = -1;
int lastlast_y_2017180023 = -1;
int last_x_2017180023 = -1;
int last_y_2017180023 = -1;

#define BLACK -1
#define WHITE 1
void WhiteAttack_2017180023(int*x, int*y)
{
	default_random_engine dre;
	dre.seed(GetTickCount());
	uniform_int<> RandomPos(0, 7);
	uniform_int<> RandomPos2(0, 18);

	int movePoint[8][2] = { { 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 },{ -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 } };

	pair<int, int> temp[8];
	if ((last_x_2017180023 == -1) && (last_y_2017180023 == -1))  //맵에 상대 돌 없을때
	{

		*x = 10;
		*y = 10;
	}
	else
	{
		bool mata_bool_kayo = true;
		bool first = true;
		for (int qq = 0; qq < 19; qq++)
		{
			if (mata_bool_kayo == false)
				break;
			for (int ww = 0; ww < 19; ww++)
			{
				if (mata_bool_kayo == false)
					break;
				pair<int, int>position_2017180023;


				if (first == false)
				{
					position_2017180023 = { qq,ww };
					if (board_2017180023[ww][qq] != BLACK)
						continue;
				}
				else
				{
					position_2017180023 = { last_x_2017180023,last_y_2017180023 };
					first = false;
					ww--;
				}

				int tempX, tempY;

				pair<int, int> Point[8];
				pair<int, int> emptyPos[8];
				bool boooooooooooooool[8];
				int checkWeight[8];

				for (int way = 0; way < 8; ++way)
				{
					tempX = position_2017180023.first;
					tempY = position_2017180023.second;
					boooooooooooooool[way] = true;
					checkWeight[way] = 0;

					for (int move = 0; move < 6; ++move)
					{

						tempX += movePoint[way][0];
						tempY += movePoint[way][1];

						if (0 <= tempX && tempX <= 18 && 0 <= tempY && tempY <= 18)
						{
							/* 현재 자리에 플레이어 돌이 있다면 */
							if (board_2017180023[tempY][tempX] == WHITE)
							{
								boooooooooooooool[way] = false;
								break;
							}
							/* 현재 자리가 빈칸 이라면 */
							else if (board_2017180023[tempY][tempX] == 0)
							{
								/* 빈칸 자리를 저장 */
								emptyPos[way].first = tempX;
								emptyPos[way].second = tempY;
								break;
							}
							/* 다른 플레이어 돌을 만났다면  */
							else
								checkWeight[way] += 1;
						}
						/* 칸을 넘어감. */
						else
						{
							boooooooooooooool[way] = false;
							break;
						}
					}
				}
				int temp_way4 = 0;
				int temp_way3 = 0;
				int temp_max_num = 0;
				for (int i = 0; i < 4; i++)
				{
					if (checkWeight[i] + checkWeight[i + 4] > 1)
					{
						if ((boooooooooooooool[temp_way4] == false) && (boooooooooooooool[temp_way4 + 4] == false))
							continue;
						if (temp_max_num<(checkWeight[i] + checkWeight[i + 4] + 1))
							temp_max_num = checkWeight[i] + checkWeight[i + 4] + 1;
						if (temp_max_num == 4)
							temp_way4 = i;
						else if (temp_max_num == 3)
							temp_way3 = i;
					}
				}

				if (temp_max_num == 4)
				{
					if (boooooooooooooool[temp_way4] == true)
					{
						*x = emptyPos[temp_way4].first;
						*y = emptyPos[temp_way4].second;
						mata_bool_kayo = false;
						break;
					}
					else if (boooooooooooooool[temp_way4 + 4] == true)
					{
						*x = emptyPos[temp_way4 + 4].first;
						*y = emptyPos[temp_way4 + 4].second;
						mata_bool_kayo = false;
						break;
					}
				}
				else if (temp_max_num == 3)
				{
					if (boooooooooooooool[temp_way3] == true)
					{
						*x = emptyPos[temp_way3].first;
						*y = emptyPos[temp_way3].second;
						mata_bool_kayo = false;
						break;
					}
					else if (boooooooooooooool[temp_way3 + 4] == true)
					{
						*x = emptyPos[temp_way3 + 4].first;
						*y = emptyPos[temp_way3 + 4].second;
						mata_bool_kayo = false;
						break;
					}
				}
			}
		}
		if (mata_bool_kayo == true)
		{
			int temp_x;
			int temp_y;
			bool boooooooool = true;

			if (!((lastlast_x_2017180023 == -1) && (lastlast_y_2017180023 == -1)))  //맵에 상대 돌 여러개 있을 때
			{
				int direction;
				bool blocked_direction[8];

				if ((abs(lastlast_x_2017180023 - last_x_2017180023) <= 1) && (abs(lastlast_y_2017180023 - last_y_2017180023) <= 1))  //이전 돌과 근접해서 놨을경우
				{
					for (int i = 0; i < 8; i++)
					{
						if ((movePoint[i][0] == (last_x_2017180023 - lastlast_x_2017180023)) && (movePoint[i][1] == (last_y_2017180023 - lastlast_y_2017180023)))
							direction = i;
					}

					temp_x = (last_x_2017180023 + movePoint[direction][0]);
					temp_y = (last_y_2017180023 + movePoint[direction][1]);

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
					bool Boooool = true;
					Boooool = false;
					//8방향 전부 막힌경우
					if ((blocked_direction[0] == true) && (blocked_direction[1] && true) && (blocked_direction[2] && true) && (blocked_direction[2] == true) && (blocked_direction[4] && true) &&
						(blocked_direction[5] == true) && (blocked_direction[6] && true) && (blocked_direction[7] && true))
					{
						int temp_x2;
						int temp_y2;

						for (int qq = 0; qq < 19; qq++)
						{
							if (Boooool == false)
								break;
							for (int ww = 0; ww < 19; ww++)
							{
								if (Boooool == false)
									break;
								if (board_2017180023[ww][qq] != BLACK)
									continue;


								int tempX, tempY;
								int PretempX, PretempY;
								int PosttempX, PosttempY;
								int foulLine33 = 0;

								bool empty;
								float attackPoint[8] = { 0, };
								pair<int, int> Point[8];
								pair<int, int> emptyPos[8];
								bool boooooooooooooool[8];
								int checkWeight[8];

								pair<int, int>position_2017180023 = { qq,ww };

								for (int way = 0; way < 8; ++way)
								{
									tempX = position_2017180023.first;
									tempY = position_2017180023.second;
									empty = true;
									boooooooooooooool[way] = true;
									checkWeight[way] = 0;

									for (int move = 0; move < 6; ++move)
									{

										tempX += movePoint[way][0];
										tempY += movePoint[way][1];

										PosttempX = tempX + movePoint[way][0];
										PosttempY = tempY + movePoint[way][1];

										PretempX = tempX - movePoint[way][0];
										PretempY = tempY - movePoint[way][1];

										if (0 <= tempX && tempX <= 18 && 0 <= tempY && tempY <= 18)
										{
											/* 현재 자리에 플레이어 돌이 있다면 */
											if (board_2017180023[tempY][tempX] == WHITE)
											{
												boooooooooooooool[way] = false;
												break;
											}
											/* 현재 자리가 빈칸 이라면 */
											else if (board_2017180023[tempY][tempX] == 0)
											{
												/* 빈칸 자리를 저장 */
												emptyPos[way].first = tempX;
												emptyPos[way].second = tempY;
												break;
											}
											/* 다른 플레이어 돌을 만났다면  */
											else
												checkWeight[way] += 1;
										}
										/* 칸을 넘어감. */
										else
										{
											boooooooooooooool[way] = false;
											break;
										}
									}
								}
								int temp_way4 = 0;
								int temp_way3 = 0;
								int temp_way2 = 0;
								int temp_max_num = 0;
								for (int i = 0; i < 4; i++)
								{
									if (checkWeight[i] + checkWeight[i + 4] > 0)
									{

										if ((boooooooooooooool[temp_way4] == false) && (boooooooooooooool[temp_way4 + 4] == false))
											continue;

										if (temp_max_num <(checkWeight[i] + checkWeight[i + 4] + 1))
											temp_max_num = checkWeight[i] + checkWeight[i + 4] + 1;
										if (temp_max_num == 4)
											temp_way4 = i;
										else if (temp_max_num == 3)
											temp_way3 = i;
										else if (temp_max_num == 2)
											temp_way2 = i;
									}
								}

								if (temp_max_num == 4)
								{
									if (boooooooooooooool[temp_way4] == true)
									{
										*x = emptyPos[temp_way4].first;
										*y = emptyPos[temp_way4].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way4 + 4] == true)
									{
										*x = emptyPos[temp_way4 + 4].first;
										*y = emptyPos[temp_way4 + 4].second;
										Boooool = false;
										break;
									}
								}
								else if (temp_max_num == 3)
								{
									if (boooooooooooooool[temp_way3] == true)
									{
										*x = emptyPos[temp_way3].first;
										*y = emptyPos[temp_way3].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way3 + 4] == true)
									{
										*x = emptyPos[temp_way3 + 4].first;
										*y = emptyPos[temp_way3 + 4].second;
										Boooool = false;
										break;
									}
								}
								else if (temp_max_num == 2)
								{
									if (boooooooooooooool[temp_way2] == true)
									{
										*x = emptyPos[temp_way2].first;
										*y = emptyPos[temp_way2].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way2 + 4] == true)
									{
										*x = emptyPos[temp_way2 + 4].first;
										*y = emptyPos[temp_way2 + 4].second;
										Boooool = false;
										break;
									}
								}
							}
						}
						if (Boooool == true)
						{
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
					}


					else
					{
						rand_direction = RandomPos(dre);
						if (blocked_direction[rand_direction] == true)
							continue;
						temp_x = (last_x_2017180023 + movePoint[rand_direction][0]);
						temp_y = (last_y_2017180023 + movePoint[rand_direction][1]);


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
	}
	board_2017180023[*y][*x] = WHITE;
}
void WhiteDefence_2017180023(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	if ((last_x_2017180023 == -1) && (last_y_2017180023 == -1))
	{
		last_x_2017180023 = x;
		last_y_2017180023 = y;
	}
	else
	{
		lastlast_x_2017180023 = last_x_2017180023;
		lastlast_y_2017180023 = last_y_2017180023;
		last_x_2017180023 = x;
		last_y_2017180023 = y;
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
	if ((last_x_2017180023 == -1) && (last_y_2017180023 == -1))  //맵에 상대 돌 없을때
	{

		*x = 10;
		*y = 10;
	}
	else
	{
		bool mata_bool_kayo = true;
		bool first = true;
		for (int qq = 0; qq < 19; qq++)
		{
			if (mata_bool_kayo == false)
				break;
			for (int ww = 0; ww < 19; ww++)
			{
				if (mata_bool_kayo == false)
					break;
				pair<int, int>position_2017180023;
				
				
				if (first == false)
				{
					position_2017180023 = { qq,ww };
					if (board_2017180023[ww][qq] != WHITE)
						continue;
				}
				else
				{
					position_2017180023 = { last_x_2017180023,last_y_2017180023 };
					first = false;
					ww--;
				}

				int tempX, tempY;

				pair<int, int> Point[8];
				pair<int, int> emptyPos[8];
				bool boooooooooooooool[8];
				int checkWeight[8];

				for (int way = 0; way < 8; ++way)
				{
					tempX = position_2017180023.first;
					tempY = position_2017180023.second;
					boooooooooooooool[way] = true;
					checkWeight[way] = 0;

					for (int move = 0; move < 6; ++move)
					{

						tempX += movePoint[way][0];
						tempY += movePoint[way][1];

						if (0 <= tempX && tempX <= 18 && 0 <= tempY && tempY <= 18)
						{
							/* 현재 자리에 플레이어 돌이 있다면 */
							if (board_2017180023[tempY][tempX] == BLACK)
							{
								boooooooooooooool[way] = false;
								break;
							}
							/* 현재 자리가 빈칸 이라면 */
							else if (board_2017180023[tempY][tempX] == 0)
							{
								/* 빈칸 자리를 저장 */
								emptyPos[way].first = tempX;
								emptyPos[way].second = tempY;
								break;
							}
							/* 다른 플레이어 돌을 만났다면  */
							else
								checkWeight[way] += 1;
						}
						/* 칸을 넘어감. */
						else
						{
							boooooooooooooool[way] = false;
							break;
						}
					}
				}
				int temp_way4 = 0;
				int temp_way3 = 0;
				int temp_max_num = 0;
				for (int i = 0; i < 4; i++)
				{
					if (checkWeight[i] + checkWeight[i + 4] > 1)
					{
						if ((boooooooooooooool[temp_way4] == false) && (boooooooooooooool[temp_way4 + 4] == false))
							continue;
						if(temp_max_num<(checkWeight[i] + checkWeight[i + 4] + 1))
						temp_max_num = checkWeight[i] + checkWeight[i + 4] + 1;
						if (temp_max_num == 4)
							temp_way4 = i;
						else if (temp_max_num == 3)
							temp_way3 = i;
					}
				}

				if (temp_max_num == 4)
				{
					if (boooooooooooooool[temp_way4] == true)
					{
						*x = emptyPos[temp_way4].first;
						*y = emptyPos[temp_way4].second;
						mata_bool_kayo = false;
						break;
					}
					else if (boooooooooooooool[temp_way4 + 4] == true)
					{
						*x = emptyPos[temp_way4 + 4].first;
						*y = emptyPos[temp_way4 + 4].second;
						mata_bool_kayo = false;
						break;
					}
				}
				else if (temp_max_num == 3)
				{
					if (boooooooooooooool[temp_way3] == true)
					{
						*x = emptyPos[temp_way3].first;
						*y = emptyPos[temp_way3].second;
						mata_bool_kayo = false;
						break;
					}
					else if (boooooooooooooool[temp_way3 + 4] == true)
					{
						*x = emptyPos[temp_way3 + 4].first;
						*y = emptyPos[temp_way3 + 4].second;
						mata_bool_kayo = false;
						break;
					}
				}
			}
		}
		if(mata_bool_kayo==true)
		{
			int temp_x;
			int temp_y;
			bool boooooooool = true;

			if (!((lastlast_x_2017180023 == -1) && (lastlast_y_2017180023 == -1)))  //맵에 상대 돌 여러개 있을 때
			{
				int direction;
				bool blocked_direction[8];

				if ((abs(lastlast_x_2017180023 - last_x_2017180023) <= 1) && (abs(lastlast_y_2017180023 - last_y_2017180023) <= 1))  //이전 돌과 근접해서 놨을경우
				{
					for (int i = 0; i < 8; i++)
					{
						if ((movePoint[i][0] == (last_x_2017180023 - lastlast_x_2017180023)) && (movePoint[i][1] == (last_y_2017180023 - lastlast_y_2017180023)))
							direction = i;
					}

					temp_x = (last_x_2017180023 + movePoint[direction][0]);
					temp_y = (last_y_2017180023 + movePoint[direction][1]);

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
					bool Boooool = true;
					Boooool = false;
					//8방향 전부 막힌경우
					if ((blocked_direction[0] == true) && (blocked_direction[1] && true) && (blocked_direction[2] && true) && (blocked_direction[2] == true) && (blocked_direction[4] && true) &&
						(blocked_direction[5] == true) && (blocked_direction[6] && true) && (blocked_direction[7] && true))
					{
						int temp_x2;
						int temp_y2;

						for (int qq = 0; qq < 19; qq++)
						{
							if (Boooool == false)
								break;
							for (int ww = 0; ww < 19; ww++)
							{
								if (Boooool == false)
									break;
								if (board_2017180023[ww][qq] != WHITE)
									continue;
								

								int tempX, tempY;
								int PretempX, PretempY;
								int PosttempX, PosttempY;
								int foulLine33 = 0;

								bool empty;
								float attackPoint[8] = { 0, };
								pair<int, int> Point[8];
								pair<int, int> emptyPos[8];
								bool boooooooooooooool[8];
								int checkWeight[8];

								pair<int, int>position_2017180023 = { qq,ww };
				
								for (int way = 0; way < 8; ++way)
								{
									tempX = position_2017180023.first;
									tempY = position_2017180023.second;
									empty = true;
									boooooooooooooool[way] = true;
									checkWeight[way] = 0;

									for (int move = 0; move < 6; ++move)
									{

										tempX += movePoint[way][0];
										tempY += movePoint[way][1];

										PosttempX = tempX + movePoint[way][0];
										PosttempY = tempY + movePoint[way][1];

										PretempX = tempX - movePoint[way][0];
										PretempY = tempY - movePoint[way][1];

										if (0 <= tempX && tempX <= 18 && 0 <= tempY && tempY <= 18)
										{
											/* 현재 자리에 플레이어 돌이 있다면 */
											if (board_2017180023[tempY][tempX] == BLACK)
											{
												boooooooooooooool[way] = false;
												break;
											}
											/* 현재 자리가 빈칸 이라면 */
											else if (board_2017180023[tempY][tempX] == 0)
											{
												/* 빈칸 자리를 저장 */
												emptyPos[way].first = tempX;
												emptyPos[way].second = tempY;
												break;
											}
											/* 다른 플레이어 돌을 만났다면  */
											else
												checkWeight[way] += 1;
										}
										/* 칸을 넘어감. */
										else
										{
											boooooooooooooool[way] = false;
											break;
										}
									}
								}
								int temp_way4 = 0;
								int temp_way3 = 0;
								int temp_way2 = 0;
								int temp_max_num = 0;
								for (int i = 0; i < 4; i++)
								{
									if (checkWeight[i] + checkWeight[i + 4] > 0)
									{

										if ((boooooooooooooool[temp_way4] == false) && (boooooooooooooool[temp_way4 + 4] == false))
											continue;

										if(temp_max_num <( checkWeight[i] + checkWeight[i + 4] + 1))
										temp_max_num = checkWeight[i] + checkWeight[i + 4] + 1;
										if (temp_max_num == 4)
											temp_way4 = i;
										else if (temp_max_num == 3)
											temp_way3 = i;
										else if (temp_max_num == 2)
											temp_way2 = i;
									}
								}

								if (temp_max_num == 4)
								{
									if (boooooooooooooool[temp_way4] == true)
									{
										*x = emptyPos[temp_way4].first;
										*y = emptyPos[temp_way4].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way4 + 4] == true)
									{
										*x = emptyPos[temp_way4 + 4].first;
										*y = emptyPos[temp_way4 + 4].second;
										Boooool = false;
										break;
									}
								}
								else if (temp_max_num == 3)
								{
									if (boooooooooooooool[temp_way3] == true)
									{
										*x = emptyPos[temp_way3].first;
										*y = emptyPos[temp_way3].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way3 + 4] == true)
									{
										*x = emptyPos[temp_way3 + 4].first;
										*y = emptyPos[temp_way3 + 4].second;
										Boooool = false;
										break;
									}
								}
								else if (temp_max_num == 2)
								{
									if (boooooooooooooool[temp_way2] == true)
									{
										*x = emptyPos[temp_way2].first;
										*y = emptyPos[temp_way2].second;
										Boooool = false;
										break;
									}
									else if (boooooooooooooool[temp_way2 + 4] == true)
									{
										*x = emptyPos[temp_way2 + 4].first;
										*y = emptyPos[temp_way2 + 4].second;
										Boooool = false;
										break;
									}
								}
							}
						}
								if(Boooool ==true)
								{
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
							}
						
					
					else
					{
						rand_direction = RandomPos(dre);
						if (blocked_direction[rand_direction] == true)
							continue;
						temp_x = (last_x_2017180023 + movePoint[rand_direction][0]);
						temp_y = (last_y_2017180023 + movePoint[rand_direction][1]);


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
	}
	board_2017180023[*y][*x] = BLACK;

}
void DefenceBlack_2017180023(int x, int y)
{
	//흰돌 1
	//검은돌 -1
	if ((last_x_2017180023 == -1) && (last_y_2017180023 == -1))
	{
		last_x_2017180023 = x;
		last_y_2017180023 = y;
	}
	else
	{
		lastlast_x_2017180023 = last_x_2017180023;
		lastlast_y_2017180023 = last_y_2017180023;
		last_x_2017180023 = x;
		last_y_2017180023 = y;
	}
	board_2017180023[y][x] = WHITE;

}
