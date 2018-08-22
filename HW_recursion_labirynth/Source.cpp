//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
//#include <algorithm>

using namespace std;

const int n = 6;
const int p = 5;

int arr1[p][n] = { { 1, 0, 0, 0, 0, 0 },
				{ 1, 1, 1, 0, 0, 0 },
				{ 0, 0, 1, 1, 1, 1 },
				{ 1, 0, 0, 0, 0, 1 },
				{ 1, 1, 1, 1, 1, 1 } };

bool flag[p][n] = { 0 };

void maze(int i, int j) {
	if ((j >= 0 && j < n) && (i >= 0 && i < p)) { // проверка диапозона - установка границ матрицы

		if (arr1[p - 1][n - 1] == 1 && flag[p - 1][n - 1] == true)
			return;

		flag[i][j] = true;

		cout << i << " " << j << endl; // вывод координат единиц

		if (arr1[i][j - 1] == 1 && flag[i][j - 1] == false)
			maze(i, j - 1);
		if (arr1[i][j + 1] == 1 && flag[i][j + 1] == false)
			maze(i, j + 1);
		if (arr1[i - 1][j] == 1 && flag[i - 1][j] == false)
			maze(i - 1, j);
		if (arr1[i + 1][j] == 1 && flag[i + 1][j] == false)
			maze(i + 1, j);
	}
}
void maze_answer(int i, int j) {
	cout << endl << "Coordinates:" << endl;
	maze(i, j);
	if (flag[p - 1][n - 1] == true) cout << "There is Escape!" << endl << endl;
	else cout << "There is No Escape :(" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	maze_answer(0, 0);
		
	system("pause");
	return 0;
}