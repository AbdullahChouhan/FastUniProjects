#include <iostream>
#include <windows.h>

using namespace std;

void displayArray(char arr[15][28]) {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 27; j++)
			cout << arr[i][j];
		cout << endl;
	}
}

void initArray(char arr[15][28]) {
	arr[0][0] = '+', arr[14][0] = '+', arr[0][26] = '+', arr[14][26] = '+';
	
	for (int i = 1; i < 26; i++) {
		arr[0][i] = '-';
		arr[14][i] = '-';
	}
	
	for (int i = 1; i < 14; i++) {
		arr[i][0] = '|';
		arr[i][26] = '|';
	}

	for (int i = 1; i < 14; i++) {
		for (int j = 1; j < 26; j++)
			arr[i][j] = ' ';
	}
	arr[7][13] = '+';
}

void shootUp(char arr[15][28]) {
	for (int i = 6; i > 0; i--) {
		arr[i][13] = '|';
		if (i > 1) {
			arr[i - 1][13] = '^';
		}
		displayArray(arr);
		Sleep(100);
		system("cls");
		arr[i][13] = ' ';
		if (i > 1) {
			arr[i - 1][13] = ' ';
		}

		if (i == 1) {
			displayArray(arr);
			Sleep(100);
		}
	}
}

void shootDown(char arr[15][28]) {
	for (int i = 8; i < 14; i++) {
		if(i<14)
			arr[i][13] = '|';
		if (i < 13) {
			arr[i+1][13] = 'v';
		}
		displayArray(arr);
		Sleep(100);
		system("cls");
		arr[i][13] = ' ';
		if (i < 13) {
			arr[i][13] = ' ';
		}
		if (i == 13) {
			displayArray(arr);
			Sleep(100);
		}
	}
}

void shootLeft(char arr[15][28]) {
	for (int i = 12; i > 0; i--) {
		arr[7][i] = '-';
		if (i > 1) {
			arr[7][i - 1] = '<';
		}
		displayArray(arr);
		Sleep(100);
		system("cls");
		arr[7][i] = ' ';
		if (i > 1) {
			arr[7][i - 1] = ' ';
		}
		if (i == 1) {
			displayArray(arr);
			Sleep(100);
		}
	}
}

void shootRight(char arr[15][28]) {
	for (int i = 14; i < 26; i++) {
		arr[7][i] = '-';
		if (i < 25) {
			arr[7][i + 1] = '>';
		}
		displayArray(arr);
		Sleep(100);
		system("cls");
		arr[7][i] = ' ';
		if (i < 25) {
			arr[7][i + 1] = ' ';
		}
		if (i == 25) {
			displayArray(arr);
			Sleep(100);
		}
	}
}

void shootAll(char arr[15][28]) {
	int k = 6, j = 8, l = 12, m = 14;
	for (int i = 0; i < 13; i++) {
		if(k>0) {
			arr[k][13] = '|';
			if (k > 1)
				arr[k - 1][13] = '^';
		}

		if(j<14) {
			if (j < 14)
				arr[j][13] = '|';
			if (j < 13) {
				arr[j + 1][13] = 'v';
			}
		}

		if (l > 0) {
			arr[7][l] = '-';
			if (l > 1) {
				arr[7][l - 1] = '<';
			}
		}

		if(m < 26) {
			arr[7][m] = '-';
			if (m < 25) {
				arr[7][m + 1] = '>';
			}
		}

		displayArray(arr);
		Sleep(100);
		system("cls");

		if (k > 0) {
			arr[k][13] = ' ';
			if (k > 1)
				arr[k - 1][13] = ' ';
			k--;
		}

		if (j < 14) {
			arr[j][13] = ' ';
			if (j < 13) 
				arr[j][13] = ' ';
			j++;
		}

		if (l > 0) {
			arr[7][l] = ' ';
			if (l > 1)
				arr[7][l - 1] = ' ';
			l--;
		}

		if (m < 26) {
			arr[7][m] = ' ';
			if (m < 25) {
				arr[7][m + 1] = ' ';
			}
			m++;
		}
	}
}

int main() {
	int input;
	char array[15][28];
	initArray(array);
	displayArray(array);
	cout << "\n0: shoot right\n1: shoot left\n2 :shoot up\n3 :shoot bottom\n4 :shoot in all directions\nEnter your choice: ";
	cin >> input;
	system("cls");
	switch (input) {
	case 0:
		shootUp(array);
		break;
	case 1:
		shootDown(array);
		break;
	case 2:
		shootLeft(array);
		break;
	case 3:
		shootRight(array);
		break;
	case 4:
		shootAll(array);
		break;
	default: 
		cout << "Invalid input.";
	}
}