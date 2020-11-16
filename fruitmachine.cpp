/*Work done by Mathswiz101*/
#include <iostream>
#include "windows.h"
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include<stdlib.h>
#include <random>
#include <ctime>
using namespace std;

int tokens = 200;
void win(int& one, int& two, int& three, int& tokens, int& bet);


int run = 1;
int run1 = 1;
int run2 = 1;
void rotation(int n, int* one, int* two, int& run);
void rotation1(int n, int& one, int* two, int& run);
void rotation2(int n, int& one, int& two, int*three, int& run, int& bet);


int main()
{
	srand(time(NULL));
	int run = 1;
	const int size = 10;
	int array[10];
	int array1[10];
	int array2[10];

	int bet = 0;
	char input;
	
	cout << "Wlecome to The Fruit Machine! Ready to play?" << endl;
	cout << "First some pointers:" << "   " << endl;
	cout << "1:  There's a 'JACKPOT' when all three values match :) " << endl;
	cout << "2: Worry Not! There is a smaller 'JACKPOT' if you can get 2 values in a row :) " << endl;
	cout << "Good Luck" << endl;
	run = 1;
	do
	{
		cout << "How much do you wish to bet? : " << endl;
		cin >> bet;
		cout << "You have " << tokens << " tokens. Y to Pull or q to quit:  ";
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
						
			for (int i = 0; i < size; i++)
			{
				array[i] = rand() % 9 + 1;
			}
			for (int i = 0; i < size; i++)
			{
				array1[i] = rand() % 9 + 1;
			}
			for (int i = 0; i < size; i++)
			{
				array2[i] = rand() % 9 + 1;
			}
			int n = 1;

			for (int i = 0; i < n; i++)
			{
				rotation(n, &array[i], &array[i + 1], run);

				if (run = 1)  //(GetAsyncKeyState(VK_UP))
				{
					run = 0;
					rotation(n, &array[i], &array[i + 1], run);
										
				}
				run = 1;

				//rotation1(n, *array, array1, run1);
				for (int i = 0; i < n; i++)
				{
					rotation1(n, array[i], &array1[i + 1], run1);

					if (run1 = 1)
					{
						run1 = 0;
						rotation1(n, array[i], &array1[i + 1], run1);
					//	Sleep(10);
						
					}
					run1 = 1;

					if (run2 = 1)
					{

						for (int i = 0; i < n; i++)
						{
							rotation2(n, array[i], array1[i + 1], &array2[i + 1], run2, bet);  // 2nd & 3rd rotation and display
						
						}
					}
				}


			}

		}
		else
		{
			break;
		}

	}
	while (input == 'Y' || input == 'y' && tokens >= 1);
	
	cout << "" << endl;
	if (tokens <= 0)
	{
		cout << "Game Over! You ran out of tokens!" << endl;
	}
	cout << "GAME OVER! " << endl;
	cout << "" << endl;

	return 0;
}
void win(int& one, int& two, int& three, int& tokens, int& bet)
{
	if (one == two && two == three)
	{
		tokens += 100;
		cout << endl << " YOU WIN! You won 100 tokens! : " << tokens << endl;

	}
	else if (one == two || two == three)
	{
		tokens += 20;
		cout << endl << "YOU WIN! you win 20 tokens : " << tokens << endl;
	}
	else
	{
		tokens -= bet;
		cout << endl << "YOU LOST! You have " << tokens << " tokens." << endl;
	}
}
void rotation(int n, int* one, int* two, int& run)
{

	int time = rand() % 15 + 1;
	while (run)
	{
		system("cls");
		cout << "To stop each column Press the 'UP' arrow key:  "<<endl;
		for (int i = 0; i < 1; i++)
		{
			for (int i = 0; i < 1; i++)
			{
				*one = rand() % 9 + 1;

			}
			for (int i = 0; i < 1; i++)
			{
				*two = rand() % 9 + 1;

			}
			int temp;
			temp = *one;
			*one = *two;
			*two = temp;

			for (int i = 0; i < n; i++)
			{
				cout <<"					       " << "   [   " << *one << "  " << *two << "  " << *one << "   ]   ";       // first display
				Sleep(20);
			}

			if (GetAsyncKeyState(VK_UP))
			{  
				run = 0;
			}

		}
	

	}
	for (int i = 0; i < n; i++)
	{
		system("cls");
		cout << "					       "<<"   [   "<<*one << "  "<< "   ]   "; // seperates the first valuse from the second one when stopping the rotation.
		Sleep(20);
	}
}

void rotation1(int n, int& one, int* two, int& run)
{

	int time = rand() % 15 + 1;
	while (run1)
	{
		system("cls");
		cout << "To stop each column Press the 'UP' arrow key:  " << endl;
		for (int i = 0; i < 1; i++)
		{

			for (int i = 0; i < 1; i++)
			{
				*two = rand() % 9 + 1;

			}
			;
			for (int i = 0; i < n; i++)
			{
				cout <<"					       " << "   [   " << one << "  " << *two << "  " << *two << "   ]   "; // intermediate display//  rotation
				Sleep(50);

			}

			if (GetAsyncKeyState(VK_UP))
			{
				run1 = 0;
			}
		}
	
	}

	for (int i = 0; i < n; i++)
	{
		cout << one  << *two;  // "still" display - allowing three to rotate
	

	}

}

void rotation2(int n, int& one, int& two, int*three, int& run, int& bet)
{

	int time = rand() % 15 + 1;
	while (run2)
	{
		system("cls");
		cout << "To stop each column Press the 'UP' arrow key:  " << endl;
		for (int i = 0; i < 1; i++)
		{
			for (int i = 0; i < 1; i++)
			{
				*three = rand() % 9 + 1;

			}


			for (int i = 0; i < n; i++)
			{
				cout << "					       " << "   [   " << one << "  " << two << "  " << *three << "   ]   "; //*three; // THE final display//    one<<"  "<< two <<"   " <<
				Sleep(20);
			}
			if (GetAsyncKeyState(VK_UP))
			{
				run2 = 0;
			}
		}
		
	}

	win(one, two, *three, tokens, bet);
}
