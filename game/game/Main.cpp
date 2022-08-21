#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
bool gameover;
const int width = 30;
const int height = 20;
int x, y, fx, fy, score, hscore = 0;
int tx[100], ty[100];
int tn;
bool run = true;
enum direction { STOP = 3, LEFT, RIGHT, UP, DOWN };
direction dir;

void setup() 
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}
void draw() 
{
    system("cls");
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "\t\t\t\t\t\t#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fy && j == fx)
                cout << "A";
            else {
                bool print = false;
                for (int k = 0; k < tn; k++) {
                    if (tx[k] == j && ty[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    cout <<"\t\t\t\t\t\t";
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    if (hscore < score)
    {
        hscore = score;
    }
    cout << "\t\t\t\t\t\t\tScore : " << score << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\tHigh Score : " << hscore << endl;
    cout << endl;

}
void logic() 
{

    int prevX = tx[0];
    int prevY = ty[0];
    int prev2X, prev2Y;
    tx[0] = x;
    ty[0] = y;
    for (int i = 1; i < tn; i++) 
    {
        prev2X = tx[i];
        prev2Y = ty[i];
        tx[i] = prevX;
        ty[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) 
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x<0 || x>width || y > height || y < 0)
        gameover = true;

    for (int i = 0; i < tn; i++)
        if (tx[i] == x && ty[i] == y)
            gameover = true;

    if (x == fx && y == fy) 
    {
        score = score + 150;
        fx = rand() % width;
        fy = rand() % height;
        tn++;
    }
}
void input() 
{
    if (_kbhit()) 
    {
        switch (_getch()) 
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'p':
            gameover = true;
            break;
        }
    }
}
int main()
{
    while (run)
    {
        setup();
        while (!gameover)
        {
            draw();
            input();
            logic();
            Sleep(50);
        }
        if (gameover == true)
        {
            draw();
            tn = 0;
            cout << "\t\t\t\t\t재시작 Press Any Key  . . . . . ." << endl;
            cout << endl;
            cout << "\t\t\t\t\t게임종료 Press f      . . . . . .";
            if (_getch() == 'f')
            {
                run = false;
            }
        }
    }
}