#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void refreshGrid();
void spawnGoal();
void spawnEnemies();
void spawnPlayer();

const int ROW = 20;
const int COL = 20;
int array2d[ROW][COL];
int playerHealth = 1, points = 0, goalCol = 0, goalRow = 0, enemyCol = 0, enemyRow = 0, playerCol = 0, playerRow = 0, numEnemy = 0;

void main() {
	cout << "Welcome to my console game \n\n\ This game features customisable difficulty \n\n How many enemies would like to spawn (WARNING I HAVE PUT NO LIMIT ON THIS, IF STUFF BREAKS ITS NOT MY FAULT)\n\n";
	cin >> numEnemy;
	srand(time(NULL));

	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			array2d[row][col] = 0;

		}
		cout << "\n";
	}
	for(int i = 0; i < numEnemy; i++){
		spawnEnemies();
		}
	spawnGoal();
	spawnPlayer();
	refreshGrid();

	while (playerHealth == 1) {
		char playerInput;
		cout << "Enter value: ";
		cin >> playerInput;

		switch (playerInput){
		case 'w':
			array2d[playerRow][playerCol] = 0;
			playerRow -= 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 's':
			array2d[playerRow][playerCol] = 0;
			playerRow += 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 'd':
			array2d[playerRow][playerCol] = 0;
			playerCol += 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 'a':
			array2d[playerRow][playerCol] = 0;
			playerCol -= 1;
			array2d[playerRow][playerCol] = 1;
			break;
		}
		refreshGrid();
	}
	
	if (playerHealth == 0) {

	}
}

void refreshGrid() {
	system("cls");
	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			cout << "  " << array2d[row][col];
		}
		cout << "\n";
	}
}

void spawnGoal() {
	array2d[goalRow][goalCol] = 0;
	goalCol = rand() % COL;
	goalRow = rand() % ROW;
	while (array2d[goalRow][goalCol] == 1 || array2d[goalRow][goalCol] == 2 || array2d[goalRow][goalCol] == 3) {
		goalCol = rand() % COL;
		goalRow = rand() % ROW;
		}
		array2d[goalRow][goalCol] = 3;
}

void spawnEnemies() {
	enemyCol = rand() % COL;
	enemyRow = rand() % ROW;
	while (array2d[enemyRow][enemyCol] == 1 || array2d[enemyRow][enemyCol] == 2 || array2d[enemyRow][enemyCol] == 3) {
		enemyCol = rand() % COL;
		enemyRow = rand() % ROW;
	}
	array2d[enemyRow][enemyCol] = 2;
}


void spawnPlayer() {
	array2d[playerRow][playerCol] = 0;
	playerCol = rand() % COL;
	playerRow = rand() % ROW;
	while (array2d[playerRow][playerCol] == 1 || array2d[playerRow][playerCol] == 2 || array2d[playerRow][playerCol] == 3) {
		playerCol = rand() % COL;
		playerRow = rand() % ROW;
	}
	array2d[goalRow][goalCol] = 1;
}