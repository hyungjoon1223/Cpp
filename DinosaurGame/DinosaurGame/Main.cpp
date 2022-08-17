#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 17
#define TREE_BOTTOM_X 45
void SetConsoleView() {
    system("mode con:cols=100 lines=35");
    system("title Chrome Dinosaurs. By Joon");
}
void GotoXY(int x, int y) {
    COORD pos;
    pos.X = x * 2;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int GetKeyDown() {
    if (_kbhit() != 0)
        return _getch();
    return 0;
}
void DrawDino(int dinoY) {
    GotoXY(0, dinoY);
    static bool legflag = true;
    printf("          $$$$$$$$ \n");
    printf("         $$-$$$$$$$\n");
    printf("         $$$$$$$$$$\n");
    printf("$       $$$        \n");
    printf("$$      $$$$$$$$   \n");
    printf("$$$    $$$$$       \n");
    printf(" $$   $$$$$$$$$$$  \n");
    printf(" $$$$$$$$$$$       \n");
    printf("  $$$$$$$$$$       \n");
    printf("    $$$$$$$$       \n");
    printf("     $$$$$$        \n");
    if (legflag)
    {
        printf("       $    $$$    \n");
        printf("        $$          ");
        legflag = false;
    }
    else
    {
        printf("       $$$  $     \n");
        printf("             $$    ");
        legflag = true;
    }
}
void DrawTree(int treeX) {
    GotoXY(treeX, TREE_BOTTOM_Y);
    printf("****");
    GotoXY(treeX, TREE_BOTTOM_Y + 1);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 2);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 3);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 4);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 5);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 6);
    printf(" ** ");
    GotoXY(treeX, TREE_BOTTOM_Y + 7);
    printf(" ** ");
}
void DrawGameOver(const int score) {
    system("cls");
    int x = 18;
    int y = 8;
    GotoXY(x, y);

    printf("===========================");
    GotoXY(x, y + 1);
    printf("=========GAME OVER=========");
    GotoXY(x, y + 2);
    printf("===========================");
    GotoXY(x, y + 5);
    printf("Score : %d", score);

    printf("\n\n\n\n\n\n\n\n");
    system("pause");
}

bool checkCollision(const int treeX, const int dinoY) {
    GotoXY(0, 0);
    printf("treeX : %d, dinoY: %d", treeX, dinoY);

    if (treeX <= 8 && treeX >= 4 && dinoY > 5)
        return true;
    return false;
}
void Util()
{
    
}
int main()
{
    std::cout << "Hello World!\n";
    SetConsoleView();

    bool isJumping = false;
    bool isBottom = true;
    int jumpcount = 0;

    const int gravity = 3;


    int dinoY = DINO_BOTTOM_Y;
    int treeX = TREE_BOTTOM_X;

    int score = 50000;
    clock_t start, curr;
    start = clock();


    while (true) {
        if (checkCollision(treeX, dinoY))
            break;

        if (GetKeyDown() == ' ' && jumpcount <= 2) {
            isJumping = true;
            isBottom = false;
            jumpcount++;
        }

        if (isJumping)
        {
            dinoY -= gravity;
        }
        else
            dinoY += gravity;

        if (dinoY >= DINO_BOTTOM_Y) {
            dinoY = DINO_BOTTOM_Y;
            isBottom = true;
            jumpcount = 0;
        }

        if (dinoY <= 3)
        {
            isJumping = false;
        }

        treeX -= 2;
        if (treeX <= 0) {
            treeX = TREE_BOTTOM_X;
        }

        DrawDino(dinoY);
        DrawTree(treeX);


        curr = clock();
        if ((curr - start) / ((CLOCKS_PER_SEC) / 60) >= 1) {
            score++;
            start = clock();
        }

        Sleep(60);
        system("cls");

        GotoXY(22, 0);
        printf("Score : %d ", score);
    }

    DrawGameOver(score);
}

//#include <iostream>
//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
//#define DINO_BOTTOM_Y 12
//#define TREE_BOTTOM_Y 20
//#define TREE_BOTTOM_X 45
//void SetConsoleView() {
//    system("mode con:cols=100 lines=25");
//    system("title Chrome Dinosaurs. By Joon");
//}
//void GotoXY(int x, int y) {
//    COORD pos;
//    pos.X = x * 2;
//    pos.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//int GetKeyDown() {
//    if (_kbhit() != 0)
//        return _getch();
//    return 0;
//}
//void DrawDino(int dinoY) {
//    GotoXY(0, dinoY);
//    static bool legflag = true;
//    printf("          $$$$$$$$ \n");
//    printf("         $$-$$$$$$$\n");
//    printf("         $$$$$$$$$$\n");
//    printf("$       $$$        \n");
//    printf("$$      $$$$$$$$   \n");
//    printf("$$$    $$$$$       \n");
//    printf(" $$   $$$$$$$$$$$  \n");
//    printf(" $$$$$$$$$$$       \n");
//    printf("  $$$$$$$$$$       \n");
//    printf("    $$$$$$$$       \n");
//    printf("     $$$$$$        \n");
//    if (legflag)
//    {
//        printf("       $    $$$    \n");
//        printf("        $$          ");
//        legflag = false;
//    }
//    else
//    {
//        printf("       $$$  $     \n");
//        printf("             $$    ");
//        legflag = true;
//    }
//}
//void DrawTree(int treeX) {
//    GotoXY(treeX, TREE_BOTTOM_Y);
//    printf("****");
//    GotoXY(treeX, TREE_BOTTOM_Y + 1);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 2);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 3);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 4);
//    printf(" ** ");
//}
//void DrawTree(int treeX) {
//    GotoXY(treeX, TREE_BOTTOM_Y);
//    printf("****");
//    GotoXY(treeX, TREE_BOTTOM_Y + 1);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 2);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 3);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 4);
//    printf(" ** ");
//}
//void DrawGameOver(const int score) {
//    system("cls");
//    int x = 18;
//    int y = 8;
//    GotoXY(x, y);
//
//    printf("===========================");
//    GotoXY(x, y + 1);
//    printf("=========GAME OVER=========");
//    GotoXY(x, y + 2);
//    printf("===========================");
//
//    GotoXY(x, y + 5);
//    printf("Score : %d", score);
//
//    printf("\n\n\n\n\n\n\n\n");
//    system("pause");
//}
//
//bool checkCollision(const int treeX, const int dinoY) {
//    GotoXY(0, 0);
//    printf("treeX : %d, dinoY: %d", treeX, dinoY);
//
//    if (treeX <= 8 && treeX >= 4 && dinoY > 8)
//        return true;
//    return false;
//}
//int main()
//{
//    std::cout << "Hello World!\n";
//    SetConsoleView();
//
//    bool isJumping = false;
//    bool isBottom = true;
//    int jumpcount = 0;
//
//    const int gravity = 3;
//
//
//    int dinoY = DINO_BOTTOM_Y;
//    int treeX = TREE_BOTTOM_X;
//
//    int score = 50000;
//    clock_t start, curr;
//    start = clock();
//
//
//    while (true) {
//        if (checkCollision(treeX, dinoY))
//            break;
//
//        if (GetKeyDown() == ' ' && jumpcount <= 2) {
//            isJumping = true;
//            isBottom = false;
//            jumpcount++;
//        }
//
//        if (isJumping)
//        {
//            dinoY -= gravity;
//        }
//        else
//            dinoY += gravity/6;
//
//        if (dinoY >= DINO_BOTTOM_Y) {
//            dinoY = DINO_BOTTOM_Y;
//            isBottom = true;
//            jumpcount = 0;
//        }
//
//        if (dinoY <= 3)
//        {
//            isJumping = false;
//        }
//
//        treeX -= 2;
//        if (treeX <= 0) {
//            treeX = TREE_BOTTOM_X;
//        }
//
//        DrawDino(dinoY);
//        DrawTree(treeX);
//
//
//        curr = clock();
//        if ((curr - start) / ((CLOCKS_PER_SEC)/60) >= 1) {
//            score++;
//            start = clock();
//        }
//
//        Sleep(60);
//        system("cls");
//
//        GotoXY(22, 0);
//        printf("Score : %d ", score);
//    }
//
//    DrawGameOver(score);
//}

//#include <iostream>
//#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>
//#define DINO_BOTTOM_Y 12
//#define TREE_BOTTOM_Y 20
//#define TREE_BOTTOM_X 45
//void SetConsoleView() {
//    system("mode con:cols=100 lines=25");
//    system("title Google Dinosaurs. By amese1225");
//}
//void GotoXY(int x, int y) {
//    COORD pos;
//    pos.X = x * 2;
//    pos.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//int GetKeyDown() {
//    if (_kbhit() != 0)
//        return _getch();
//    return 0;
//}
//void DrawDino(int dinoY) {
//    GotoXY(0, dinoY);
//    static bool legflag = true;
//    printf("          $$$$$$$$ \n");
//    printf("         $$-$$$$$$$\n");
//    printf("         $$$$$$$$$$\n");
//    printf("$       $$$        \n");
//    printf("$$      $$$$$$$$   \n");
//    printf("$$$    $$$$$       \n");
//    printf(" $$   $$$$$$$$$$$  \n");
//    printf(" $$$$$$$$$$$       \n");
//    printf("  $$$$$$$$$$       \n");
//    printf("    $$$$$$$$       \n");
//    printf("     $$$$$$        \n");
//    if (legflag)
//    {
//        printf("       $    $$$    \n");
//        printf("        $$          ");
//        legflag = false;
//    }
//    else
//    {
//        printf("       $$$  $     \n");
//        printf("             $$    ");
//        legflag = true;
//    }
//}
//void DrawTree(int treeX) {
//    GotoXY(treeX, TREE_BOTTOM_Y);
//    printf("****");
//    GotoXY(treeX, TREE_BOTTOM_Y + 1);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 2);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 3);
//    printf(" ** ");
//    GotoXY(treeX, TREE_BOTTOM_Y + 4);
//    printf(" ** ");
//}
//void DrawGameOver(const int score) {
//    system("cls");
//    int x = 18;
//    int y = 8;
//    GotoXY(x, y);
//
//    printf("===========================");
//    GotoXY(x, y + 1);
//    printf("=========GAME OVER=========");
//    GotoXY(x, y + 2);
//    printf("===========================");
//
//    GotoXY(x, y + 5);
//    printf("Score : %d", score);
//
//    printf("\n\n\n\n\n\n\n\n");
//    system("pause");
//}
//
//bool checkCollision(const int treeX, const int dinoY) {
//    GotoXY(0, 0);
//    printf("treeX : %d, dinoY: %d", treeX, dinoY);
//
//    if (treeX <= 8 && treeX >= 4 && dinoY > 8)
//        return true;
//
//    return false;
//}
//int main()
//{
//    std::cout << "Hello World!\n";
//    SetConsoleView();
//
//    bool isJumping = false;
//    bool isBottom = true;
//    const int gravity = 3;
//    int dinoY = DINO_BOTTOM_Y;
//    int treeX = TREE_BOTTOM_X;
//    int score = 0;
//    clock_t start, curr;
//    start = clock();
//
//
//    while (true) {
//        if (checkCollision(treeX, dinoY))
//            break;
//
//        if (GetKeyDown() == 'z' && isBottom) {
//            isJumping = true;
//            isBottom = false;
//        }
//        if (isJumping)
//            dinoY -= gravity;
//        else
//            dinoY += gravity;
//        if (dinoY >= DINO_BOTTOM_Y) {
//            dinoY = DINO_BOTTOM_Y;
//            isBottom = true;
//        }
//        if (dinoY <= 3)
//            isJumping = false;
//
//        treeX -= 2;
//        if (treeX <= 0) {
//            treeX = TREE_BOTTOM_X;
//        }
//        DrawDino(dinoY);
//        DrawTree(treeX);
//        curr = clock();
//        if (((curr - start) / CLOCKS_PER_SEC) >= 1) {
//            score++;
//            start = clock();
//        }
//        Sleep(60);
//        system("cls");
//
//        GotoXY(22, 0);
//        printf("Score : %d ", score);
//    }
//    DrawGameOver(score);
//}
