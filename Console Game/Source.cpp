#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void refreshGrid();

const int ROW = 20;
const int COL = 20;
int array2d[ROW][COL];
int playerHealth = 1;

void main() {
	srand(time(NULL));

	for (int row = 0; row < ROW; row++) {
		for (int col = 0; col < COL; col++) {
			array2d[row][col] = 0;

		}
		cout << "\n";
	}

	int playerRow = rand() % ROW;
	int playerCol = rand() % COL;
	array2d[playerRow][playerCol] = 1;

	int enemyCol = 0;
	int enemyRow = 0;

	for (int i = 0; i < 3; i++) {
		enemyCol = rand() % COL;
		enemyRow = rand() % ROW;
		while (array2d[enemyRow][enemyCol] == 1 || array2d[enemyRow][enemyCol] == 2) {
			enemyCol = rand() % COL;
			enemyRow = rand() % ROW;
		}
		array2d[enemyRow][enemyCol] = 2;
	}

	refreshGrid();

	char myVal;
	cout << "Enter value: ";
	cin >> myVal;

	switch (myVal) 
	{		
		case 'w':
			playerCol + 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 's':
			playerCol - 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 'd':
			playerRow + 1;
			array2d[playerRow][playerCol] = 1;
			break;
		case 'a':
			playerRow - 1;
			array2d[playerRow][playerCol] = 1;
			break;
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

}