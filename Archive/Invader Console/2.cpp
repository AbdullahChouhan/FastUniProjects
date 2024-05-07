#include <iostream>
#include <conio.h> // For kbhit() and getch()
#include <windows.h>
#include <cstdlib>
#include <chrono>
using namespace std;

string PlayArea[25][80];
const string invader = "V", bitch = "🛸", bullet = "◻️", bunker = "█", DEATH = "💥";
int edge = 2, flipped = 1;

    auto start = std::chrono::high_resolution_clock::now();

int Random()
{
    srand(time(0));
    return 1 + rand() % 10;
}

void display() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++)
			cout << PlayArea[i][j];
		cout << '\n';
	}
}

void initPlayArea() {
    for (int i = 0; i < 25; i++) {
		for (int j = 1; j < 80; j++) 
			PlayArea[i][j] = ' ';
    }
	for (int i = 0; i < 15; i+= 3) {
		for (int j = 8; j < 74; j+= 6)
			PlayArea[i][j] = invader;
	}
    for (int h = 20; h < 23; h++) {
        for (int i = 13; i < 80; i += 18) {
            for (int j = i; j < i + 9; j++)
                PlayArea[h][j] = bunker;
        }
    }
    PlayArea[24][36] = bitch;
}

void GameOver() {
    display();
    system("start vlc --intf dummy --play-and-exit 8-bit-explosion-low-resonant-45659.wav");
    cout << "GAME OVER";
        auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Duration: " << duration << " milliseconds\n";

    Sleep(2000);
    exit(0);
}

void enemyMovement() {
    if (flipped == 0) {
        for (int i = 23; i >= 0; i--) {
            for (int j = 78; j >= 0; j -= 2) {
                if (PlayArea[i][j] == invader) {
                    PlayArea[i][j] = ' ';
                    if (PlayArea[i + 1][j] == bitch) {
                        PlayArea[i + 1][j] = DEATH;
                        GameOver();
                    }
                    else
                        PlayArea[i + 1][j] = invader;
                }
            }
        }
        flipped = 1;
    }
    else {
        if (edge == 2) {
            for (int i = 24; i >= 0; i--) {
                for (int j = 78; j >= 0; j -= 2) {
                    if (PlayArea[i][j] == invader) {
                        PlayArea[i][j] = ' ';
                        if (PlayArea[i][j + edge] == bitch)
                            GameOver();
                        else
                            PlayArea[i][j + edge] = invader;
                    }
                }
            }
        }
        if (edge == -2) {
            for (int i = 24; i >= 0; i--) {
                for (int j = 0; j <= 78; j += 2) {
                    if (PlayArea[i][j] == invader) {
                        PlayArea[i][j] = ' ';
                        if (PlayArea[i][j + edge] == bitch)
                            GameOver();
                        else
                            PlayArea[i][j + edge] = invader;
                    }
                }
            }
        }
        for (int i = 0; i < 25; i++) {
            if (PlayArea[i][78] == invader) {
                edge = -2;
                flipped = 0;
                break;
            }
            else if (PlayArea[i][0] == invader) {
                edge = 2;
                flipped = 0;
                break;
            }
        }
    }
}

int main() {
    initPlayArea();
    display();
	printf("\033c");
    int input = 1;

    if (input == 1)
    {
        while (!kbhit()) {    // Loop continuously printing 'Hello, world'
            enemyMovement();
        	printf("\033c");
            display();

        }
        while (kbhit())    // Clear the keyboard buffer
            getch();
    }
    else
        cout << "why";
    cout << "Program stopped by user." << endl;

    return 0;
}