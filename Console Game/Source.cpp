#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Goal.h"
#include "Player.h"
using namespace std;

void refreshGrid();

const int ROW = 20;
const int COL = 20;
int array2d[ROW][COL];
int amount_of_enemy;
int playerHealth = 5;
int goal_distance;
bool start = false;

void refreshGrid() {
	system("cls");
	cout << playerHealth << "\n\n\n";
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			cout << array2d[row][col] << " ";

		}
		cout << "\n";
	}
}

void menu()
{
	cout << "THE GAME: \n\n\n Type Start to start the game \n\n\n Type Options to access the Options";
	string answer = "";
	int num = 0;
	cin >> answer;
	if (answer == "Options" || answer == "options")
	{
		cout << "How many enemies do you want?";
		cin >> num;
		amount_of_enemy = num;
		cout << "How far away do you want the goal?";
		cin >> num;
		goal_distance = num;
		start = true;
	}
	if (answer == "start" || answer == "Start") {
		goal_distance = 10;
		amount_of_enemy = 3;
		start = true;
	}

}

void main() {
	cout << "Welcome to my console game \n\n\ This game features customisable difficulty \n\n How many enemies would like to spawn (WARNING I HAVE PUT NO LIMIT ON THIS, IF STUFF BREAKS ITS NOT MY FAULT)\n\n";
	cin >> numEnemy;
	srand(time(NULL));
	void menu();
	if (start == true) {
		for (int row = 0; row < ROW; row++) {
			for (int col = 0; col < COL; col++) {
				array2d[row][col] = 0;

			}
			cout << "\n";
		}

		Player dude(0, 0);
		int playerRow = rand() % ROW;  dude.set_player_row(playerRow);
		int playerCol = rand() % COL;  dude.set_player_col(playerCol);
		playerCol = dude.get_player_col();
		playerRow = dude.get_player_row();

		array2d[playerRow][playerCol] = 1;

		Enemy bad(0, 0);


		for (int i = 0; i < amount_of_enemy; i++) {
			int enemyCol = rand() % COL;
			int enemyRow = rand() % ROW;
			while (array2d[enemyRow][enemyCol] == 1 || array2d[enemyRow][enemyCol] == 2) {
				enemyCol = rand() % COL;
				enemyRow = rand() % ROW;
			}
			bad.set_enemy_col(enemyCol);
			bad.set_enemy_row(enemyRow);
			array2d[enemyRow][enemyCol] = 2;
		}

		Goal good(0, 0);

		for (int i = 0; i < 1; i++) {
			int goalCol = rand() % COL;
			int goalRow = rand() % ROW;
			while (array2d[goalRow][goalCol] == 1 || array2d[goalRow][goalCol] == 2 || (playerCol + playerRow) - (goalCol + goalRow) != 10) {
				goalCol = rand() % COL;
				goalRow = rand() % ROW;
			}
			good.set_goal_col(goalCol);
			good.set_goal_row(goalRow);
			array2d[goalRow][goalCol] = 3;
		}

		refreshGrid();

	char myVal;
	cout << "Enter value: ";
	cin >> myVal;

	switch (myVal) 
	{		
		case 'w':
			array2d[playerRow][playerCol] = 0;
			playerRow -= 1;
			array2d[playerRow][playerCol] = 1;
			break;
			refreshGrid();
		case 's':
			array2d[playerRow][playerCol] = 0;
			playerRow += 1;
			array2d[playerRow][playerCol] = 1;
			break;
			refreshGrid();
		case 'd':
			array2d[playerRow][playerCol] = 0;
			playerCol += 1;
			array2d[playerRow][playerCol] = 1;
			break;
			refreshGrid();
		case 'a':
			array2d[playerRow][playerCol] = 0;
			playerCol -= 1;
			array2d[playerRow][playerCol] = 1;
			break;
			refreshGrid();
		}

		system("pause");
	}

void refreshGrid() {
	system("cls");
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			cout << "  " << array2d[row][col];
		}
		cout << "\n";
	}

