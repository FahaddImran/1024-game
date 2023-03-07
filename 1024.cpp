#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int grid[4][4] = {};
bool flag_random = false;
int current_score = 0;

void move_left()
{
	flag_random = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (col == 0)
			{
				continue;
			}
			if (col == 1)
			{
				//ADD
				if (grid[row][col - 1] == grid[row][col] && (grid[row][col - 1] != 0 && grid[row][col] != 0))
				{
					grid[row][col - 1] *= 2;
					grid[row][col] = grid[row][col + 1];
					grid[row][col + 1] = grid[row][col + 2];
					grid[row][col + 2] = 0;
					flag_random = true;
					current_score += grid[row][col - 1];
				}
				//MOVE
				if (grid[row][col - 1] == 0 && grid[row][col] != 0)
				{
					grid[row][col - 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (col == 2)
			{
				//ADD
				if (grid[row][col - 1] == grid[row][col] || grid[row][col - 2] == grid[row][col])
				{
					if (grid[row][col - 1] == grid[row][col] && (grid[row][col - 1] != 0 && grid[row][col] != 0))
					{
						grid[row][col - 1] *= 2;
						grid[row][col] = grid[row][col + 1];
						grid[row][col + 1] = 0;
						flag_random = true;
						current_score += grid[row][col - 1];
					}
					else if (grid[row][col - 2] == grid[row][col] && grid[row][col - 1] == 0 && (grid[row][col - 2] != 0 && grid[row][col] != 0))
					{
						grid[row][col - 2] *= 2;
						grid[row][col - 1] = grid[row][col + 1];
						grid[row][col + 1] = 0;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col - 2];
					}
				}
				//MOVE
				if (grid[row][col - 1] == 0 && grid[row][col - 2] == 0 && grid[row][col] != 0)
				{
					grid[row][col - 2] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col - 1] == 0 && grid[row][col - 2] != 0 && grid[row][col] != 0)
				{
					grid[row][col - 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (col == 3)
			{
				//ADD
				if (grid[row][col - 1] == grid[row][col] || grid[row][col - 2] == grid[row][col] || grid[row][col - 3] == grid[row][col])
				{
					if (grid[row][col - 1] == grid[row][col] && (grid[row][col - 1] != 0 && grid[row][col] != 0))
					{
						grid[row][col - 1] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col - 1];
					}
					else if (grid[row][col - 2] == grid[row][col] && grid[row][col - 1] == 0 && (grid[row][col - 2] != 0 && grid[row][col] != 0))
					{
						grid[row][col - 2] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col - 2];
					}
					else if (grid[row][col - 3] == grid[row][col] && grid[row][col - 1] == 0 && grid[row][col - 2] == 0 && (grid[row][col - 3] != 0 && grid[row][col] != 0))
					{
						grid[row][col - 3] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col - 3];
					}
				}
				//MOVE
				if (grid[row][col - 1] == 0 && grid[row][col - 2] == 0 && grid[row][col - 3] == 0 && grid[row][col] != 0)
				{
					grid[row][col - 3] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col - 1] == 0 && grid[row][col - 2] == 0 && grid[row][col - 3] != 0 && grid[row][col] != 0)
				{
					grid[row][col - 2] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col - 1] == 0 && grid[row][col - 2] != 0 && grid[row][col - 3] != 0 && grid[row][col] != 0)
				{
					grid[row][col - 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}

			}
		}
	}
	if (flag_random == true)
	{
		srand(time(0));
		bool flag = true;
		int random_row, random_col;
		while (flag == true)
		{
			random_row = rand() % 4;
			random_col = rand() % 4;
			if (grid[random_row][random_col] == 0)
			{
				grid[random_row][random_col] = (rand() % 2 + 1);
				flag = false;
			}
			else
			{
				continue;
			}
		}

	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << grid[row][col] << "    ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "SCORE: " << current_score << "\n";
}

void move_right()
{
	flag_random = false;
	for (int row = 3; row >= 0; row--)
	{
		for (int col = 3; col >= 0; col--)
		{
			if (col == 3)
			{
				continue;
			}
			if (col == 2)
			{
				//ADD
				if (grid[row][col + 1] == grid[row][col] && (grid[row][col + 1] != 0 && grid[row][col] != 0))
				{
					grid[row][col + 1] *= 2;
					grid[row][col] = grid[row][col - 1];
					grid[row][col - 1] = grid[row][col - 2];
					grid[row][col - 2] = 0;
					flag_random = true;
					current_score += grid[row][col + 1];
				}
				//MOVE
				if (grid[row][col + 1] == 0 && grid[row][col] != 0)
				{
					grid[row][col + 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (col == 1)
			{
				//ADD
				if (grid[row][col + 1] == grid[row][col] || grid[row][col + 2] == grid[row][col])
				{
					if (grid[row][col + 1] == grid[row][col] && (grid[row][col + 1] != 0 && grid[row][col] != 0))
					{
						grid[row][col + 1] *= 2;
						grid[row][col] = grid[row][col - 1];
						grid[row][col - 1] = 0;
						flag_random = true;
						current_score += grid[row][col + 1];
					}
					else if (grid[row][col + 2] == grid[row][col] && grid[row][col + 1] == 0 && (grid[row][col + 2] != 0 && grid[row][col] != 0))
					{
						grid[row][col + 2] *= 2;
						grid[row][col + 1] = grid[row][col - 1];
						grid[row][col - 1] = 0;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col + 2];
					}
				}
				//MOVE
				if (grid[row][col + 1] == 0 && grid[row][col + 2] == 0 && grid[row][col] != 0)
				{
					grid[row][col + 2] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col + 1] == 0 && grid[row][col + 2] != 0 && grid[row][col] != 0)
				{
					grid[row][col + 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (col == 0)
			{
				//ADD
				if (grid[row][col + 1] == grid[row][col] || grid[row][col + 2] == grid[row][col] || grid[row][col + 3] == grid[row][col])
				{
					if (grid[row][col + 1] == grid[row][col] && (grid[row][col + 1] != 0 && grid[row][col] != 0))
					{
						grid[row][col + 1] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col + 1];
					}
					else if (grid[row][col + 2] == grid[row][col] && grid[row][col + 1] == 0 && (grid[row][col + 2] != 0 && grid[row][col] != 0))
					{
						grid[row][col + 2] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col + 2];
					}
					else if (grid[row][col + 3] == grid[row][col] && grid[row][col + 1] == 0 && grid[row][col + 2] == 0 && (grid[row][col + 3] != 0 && grid[row][col] != 0))
					{
						grid[row][col + 3] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col + 3];
					}
				}
				//MOVE
				if (grid[row][col + 1] == 0 && grid[row][col + 2] == 0 && grid[row][col + 3] == 0 && grid[row][col] != 0)
				{
					grid[row][col + 3] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col + 1] == 0 && grid[row][col + 2] == 0 && grid[row][col + 3] != 0 && grid[row][col] != 0)
				{
					grid[row][col + 2] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row][col + 1] == 0 && grid[row][col + 2] != 0 && grid[row][col + 3] != 0 && grid[row][col] != 0)
				{
					grid[row][col + 1] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}

			}
		}
	}
	if (flag_random == true)
	{
		srand(time(0));
		bool flag = true;
		int random_row, random_col;
		while (flag == true)
		{
			random_row = rand() % 4;
			random_col = rand() % 4;
			if (grid[random_row][random_col] == 0)
			{
				grid[random_row][random_col] = (rand() % 2 + 1);
				flag = false;
			}
			else
			{
				continue;
			}
		}

	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << grid[row][col] << "    ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "SCORE: " << current_score << "\n";
}

void move_down()
{
	flag_random = false;
	for (int row = 3; row >= 0; row--)
	{
		for (int col = 3; col >= 0; col--)
		{
			if (row == 3)
			{
				continue;
			}
			if (row == 2)
			{
				//ADD
				if (grid[row + 1][col] == grid[row][col] && (grid[row + 1][col] != 0 && grid[row][col] != 0))
				{
					grid[row + 1][col] *= 2;
					grid[row][col] = grid[row - 1][col];
					grid[row - 1][col] = grid[row - 2][col];
					grid[row - 2][col] = 0;
					flag_random = true;
					current_score += grid[row + 1][col];

				}
				//MOVE
				if (grid[row + 1][col] == 0 && grid[row][col] != 0)
				{
					grid[row + 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (row == 1)
			{
				//ADD
				if (grid[row + 1][col] == grid[row][col] || grid[row + 2][col] == grid[row][col])
				{
					if (grid[row + 1][col] == grid[row][col] && (grid[row + 1][col] != 0 && grid[row][col] != 0))
					{
						grid[row + 1][col] *= 2;
						grid[row][col] = grid[row - 1][col];
						grid[row - 1][col] = 0;
						flag_random = true;
						current_score += grid[row + 1][col];
					}
					else if (grid[row + 2][col] == grid[row][col] && grid[row + 1][col] == 0 && (grid[row + 2][col] != 0 && grid[row][col] != 0))
					{

						grid[row + 2][col] *= 2;
						grid[row + 1][col] = grid[row - 1][col];
						grid[row - 1][col] = 0;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row + 2][col];
					}
				}
				//MOVE
				if (grid[row + 1][col] == 0 && grid[row + 2][col] == 0 && grid[row][col] != 0)
				{
					grid[row + 2][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row + 1][col] == 0 && grid[row + 2][col] != 0 && grid[row][col] != 0)
				{
					grid[row + 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (row == 0)
			{
				//ADD
				if (grid[row + 1][col] == grid[row][col] || grid[row + 2][col] == grid[row][col] || grid[row + 3][col] == grid[row][col])
				{
					if (grid[row + 1][col] == grid[row][col] && (grid[row + 1][col] != 0 && grid[row][col] != 0))
					{
						grid[row + 1][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row + 1][col];
					}
					else if (grid[row + 2][col] == grid[row][col] && grid[row + 1][col] == 0 && (grid[row + 2][col] != 0 && grid[row][col] != 0))
					{
						grid[row + 2][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row + 2][col];
					}
					else if (grid[row + 3][col] == grid[row][col] && grid[row + 1][col] == 0 && grid[row + 2][col] == 0 && (grid[row + 3][col] != 0 && grid[row][col] != 0))
					{
						grid[row + 3][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row + 3][col];
					}
				}
				//MOVE
				if (grid[row + 1][col] == 0 && grid[row + 2][col] == 0 && grid[row + 3][col] == 0 && grid[row][col] != 0)
				{
					grid[row + 3][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row + 1][col] == 0 && grid[row + 2][col] == 0 && grid[row + 3][col] != 0 && grid[row][col] != 0)
				{
					grid[row + 2][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row + 1][col] == 0 && grid[row + 2][col] != 0 && grid[row + 3][col] != 0 && grid[row][col] != 0)
				{
					grid[row + 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}

			}
		}
	}
	if (flag_random == true)
	{
		srand(time(0));
		bool flag = true;
		int random_row, random_col;
		while (flag == true)
		{
			random_row = rand() % 4;
			random_col = rand() % 4;
			if (grid[random_row][random_col] == 0)
			{
				grid[random_row][random_col] = (rand() % 2 + 1);
				flag = false;
			}
			else
			{
				continue;
			}
		}

	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << grid[row][col] << "    ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "SCORE: " << current_score << "\n";
}

void move_up()
{
	flag_random = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (row == 0)
			{
				continue;
			}
			if (row == 1)
			{
				//ADD
				if ((grid[row - 1][col] == grid[row][col]) && (grid[row - 1][col] != 0 && grid[row][col] != 0))
				{

					grid[row - 1][col] *= 2;
					grid[row][col] = grid[row + 1][col];
					grid[row + 1][col] = grid[row + 2][col];
					grid[row + 2][col] = 0;
					flag_random = true;
					current_score += grid[row - 1][col];

				}
				//MOVE
				if (grid[row - 1][col] == 0 && grid[row][col] != 0)
				{
					grid[row - 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (row == 2)
			{
				//ADD
				if (grid[row - 1][col] == grid[row][col] || grid[row - 2][col] == grid[row][col])
				{
					if (grid[row - 1][col] == grid[row][col] && (grid[row - 1][col] != 0 && grid[row][col] != 0))
					{

						grid[row - 1][col] *= 2;
						grid[row][col] = grid[row + 1][col];
						grid[row + 1][col] = 0;
						flag_random = true;
						current_score += grid[row - 1][col];
					}
					else if (grid[row - 2][col] == grid[row][col] && grid[row - 1][col] == 0 && (grid[row - 2][col] != 0 && grid[row][col] != 0))
					{

						grid[row - 2][col] *= 2;
						grid[row - 1][col] = grid[row + 1][col];
						grid[row + 1][col] = 0;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row][col];
					}
				}
				//MOVE
				if (grid[row - 1][col] == 0 && grid[row - 2][col] == 0 && grid[row][col] != 0)
				{
					grid[row - 2][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row - 1][col] == 0 && grid[row - 2][col] != 0 && grid[row][col] != 0)
				{
					grid[row - 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}
			}
			if (row == 3)
			{
				//ADD
				if (grid[row - 1][col] == grid[row][col] || grid[row - 2][col] == grid[row][col] || grid[row - 3][col] == grid[row][col])
				{
					if (grid[row - 1][col] == grid[row][col] && (grid[row - 1][col] != 0 && grid[row][col] != 0))
					{
						grid[row - 1][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row - 1][col];
					}
					else if (grid[row - 2][col] == grid[row][col] && grid[row - 1][col] == 0 && (grid[row - 2][col] != 0 && grid[row][col] != 0))
					{
						grid[row - 2][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row - 2][col];
					}
					else if (grid[row - 3][col] == grid[row][col] && grid[row - 1][col] == 0 && grid[row - 2][col] == 0 && (grid[row - 3][col] != 0 && grid[row][col] != 0))
					{
						grid[row - 3][col] *= 2;
						grid[row][col] = 0;
						flag_random = true;
						current_score += grid[row - 3][col];
					}
				}
				//MOVE
				if (grid[row - 1][col] == 0 && grid[row - 2][col] == 0 && grid[row - 3][col] == 0 && grid[row][col] != 0)
				{
					grid[row - 3][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row - 1][col] == 0 && grid[row - 2][col] == 0 && grid[row - 3][col] != 0 && grid[row][col] != 0)
				{
					grid[row - 2][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}
				else if (grid[row - 1][col] == 0 && grid[row - 2][col] != 0 && grid[row - 3][col] != 0 && grid[row][col] != 0)
				{
					grid[row - 1][col] = grid[row][col];
					grid[row][col] = 0;
					flag_random = true;
				}

				else
				{
					continue;
				}

			}

		}
	}

	if (flag_random == true)
	{
		srand(time(0));
		bool flag = true;
		int random_row, random_col;
		while (flag == true)
		{
			random_row = rand() % 4;
			random_col = rand() % 4;
			if (grid[random_row][random_col] == 0)
			{
				grid[random_row][random_col] = (rand() % 2 + 1);
				flag = false;
			}
			else
			{
				continue;
			}
		}

	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << grid[row][col] << "    ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "SCORE: " << current_score << "\n";
}

void control_panel()
{
	char move;
	char choice;
	while (true)
	{
		cout << "\nU for up\nD for down\nR for right\nL for left\nEnter your move: ";
		cin >> move;

		if (move == 'U')
		{
			system("cls");
			move_up();
		}
		if (move == 'D')
		{
			system("cls");
			move_down();
		}
		if (move == 'R')
		{
			system("cls");
			move_right();
		}
		if (move == 'L')
		{
			system("cls");
			move_left();
		}
		//WIN CHECK
		bool flag_win = false;
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (grid[row][col] == 1024)
				{
					flag_win = true;
				}
			}
		}
		if (flag_win == true)
		{
			cout << "YOU WIN!!!! \n";
			break;
		}
		//LOSE CHECK
		bool flag_lose = false, flag_lose2 = false;
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (grid[row][col] == 0)
				{
					flag_lose = true;
				}
			}
		}
		if (flag_lose == false)
		{
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					/*		if (row == 0)
							{
								if (col == 0 && (grid[row + 1][col] == grid[row][col] || grid[row][col + 1]==grid[row][col]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									 break;
								}
								if (col == 3&&(grid[row+1][col]==grid[row][col]||grid[row][col-1]==grid[row][col]))
								{
									flag_lose2 = false;
									cout << row << " " << col;

									break;
								}
								else if (col == 1||col == 2)
								{
									if (grid[row + 1][col] == grid[row][col] || grid[row][col - 1] == grid[row][col] ||  grid[row][col + 1] == grid[row][col])
									{
										flag_lose2 = false;
										cout << row << " " << col;
										break;
									}
								}
								else
								{
									cout << row << " " << col;
									flag_lose2 = true;
								}
							}
							if (row == 1||row==2)
							{
								if (col == 0 && (grid[row][col] == grid[row + 1][col] || grid[row][col] == grid[row - 1][col] || grid[row][col] == grid[row][col + 1]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								if (col == 1 || col == 2 && (grid[row][col] == grid[row + 1][col] || grid[row][col] == grid[row - 1][col] || grid[row][col] == grid[row][col + 1] || grid[row][col] == grid[row][col - 1]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								if (col == 3 && (grid[row - 1][col] == grid[row][col] || grid[row][col] == grid[row + 1][col] || grid[row][col] == grid[row][col - 1]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								else
								{
									cout << row << " " << col;
									flag_lose2 = true;
								}
							}
							if (row == 3)
							{
								if (col == 0 && (grid[row][col] == grid[row - 1][col] || grid[row][col] == grid[row][col + 1]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								if (col == 1 || col == 2 && (grid[row][col] == grid[row][col - 1] || grid[row][col] == grid[row][col + 1] || grid[row][col] == grid[row - 1][col]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								if (col == 3 && (grid[row][col] == grid[row - 1][col] || grid[row][col] == grid[row][col] == grid[row][col - 1]))
								{
									flag_lose2 = false;
									cout << row << " " << col;
									break;
								}
								else
								{
									cout << row << " " << col;
									flag_lose2 = true;
								}
							}*/
					if (grid[row - 1][col] == grid[row][col])
					{
						flag_lose2 = false;
						cout << row << "false " << col << " " << row - 1 << " " << col;
						break;

					}
					if (grid[row + 1][col] == grid[row][col])
					{
						flag_lose2 = false;
						cout << row << "false " << col << " " << row + 1 << " " << col;
						break;
					}
					if (grid[row][col + 1] == grid[row][col])
					{
						flag_lose2 = false;
						cout << row << "false " << col << " " << row << " " << col + 1;
						break;
					}
					if (grid[row][col - 1] == grid[row][col])
					{
						flag_lose2 = false;
						cout << row << "false " << col << " " << row << " " << col - 1;
						break;
					}
					else
					{
						flag_lose2 = true;
						cout << row << "TRUe " << col << " ";

					}
				}
				if (flag_lose2 == false)
				{
					break;
				}
			}
		}
		if (flag_lose2 == true)
		{
			cout << "YOU LOSE!!!\nBETTER LUCK NEXT TIME!!! \n";
			break;
		}
		else continue;

	}
}

void random_generator()
{
	srand(time(0));
	bool flag = true;
	int random_row = rand() % 4, random_col = rand() % 4;
	grid[random_row][random_col] = (rand() % 2 + 1);
	while (flag == true)
	{
		random_row = rand() % 4;
		random_col = rand() % 4;
		if (grid[random_row][random_col] == 0)
		{
			grid[random_row][random_col] = (rand() % 2 + 1);
			flag = false;
		}
		else
		{
			continue;
		}
	}

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << grid[row][col] << "    ";
		}
		cout << "\n";
		cout << "\n";
	}
	cout << "SCORE: " << current_score << "\n";
	control_panel();
}

int main()
{
	random_generator();
	cout << "THANKS FOR PLAYING :) \nGOOD BYE! \n";
	return 0;
}