#include <stdio.h>
#include <stdlib.h>

void PrintImage(int row, int col, int** Image)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%2d", Image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Dilation(int row, int col, int** Image) { //팽창
    int** temp = (int**)malloc(sizeof(int*) * col);
    for (int i = 0; i < col; i++) {
        temp[i] = (int*)malloc(sizeof(int) * row);
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            temp[i][j] = 0;
        }
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (Image[i][j] == 1) {
                if (i == 0 && j == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j + 1] = 2;
                }
                else if (i == col - 1 && j == row - 1) {
                    temp[i - 1][j - 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (i == 0 && j == row - 1) {
                    temp[i + 1][j - 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (i == col - 1 && j == 0) {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i][j + 1] = 2;
                }
                else if (i == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i + 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (j == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j + 1] = 2;
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                }
                else if (i == col - 1) {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (j == row - 1) {
                    temp[i + 1][j - 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j - 1] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i - 1][j] = 2;
                }
                else {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i + 1][j - 1] = 2;
                }
            }
        }
    }

    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (temp[i][j] == 2)
                Image[i][j] = 1;
            printf("%2d", Image[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < col; i++) {
        free(temp[i]);
    }
    free(temp);
}
void Erosion(int col, int row, int** Image) //침식
{
    int** temp = (int**)malloc(sizeof(int*) * col);
    for (int i = 0; i < col; i++) {
        temp[i] = (int*)malloc(sizeof(int) * row);
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            temp[i][j] = 0;
        }
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (Image[i][j] == 0) {
                if (i == 0 && j == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j + 1] = 2;
                }
                else if (i == col - 1 && j == row - 1) {
                    temp[i - 1][j - 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (i == 0 && j == row - 1) {
                    temp[i + 1][j - 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (i == col - 1 && j == 0) {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i][j + 1] = 2;
                }
                else if (i == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i + 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (j == 0) {
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j + 1] = 2;
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                }
                else if (i == col - 1) {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                }
                else if (j == row - 1) {
                    temp[i + 1][j - 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i][j - 1] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i - 1][j] = 2;
                }
                else {
                    temp[i - 1][j + 1] = 2;
                    temp[i - 1][j] = 2;
                    temp[i - 1][j - 1] = 2;
                    temp[i][j + 1] = 2;
                    temp[i][j - 1] = 2;
                    temp[i + 1][j + 1] = 2;
                    temp[i + 1][j] = 2;
                    temp[i + 1][j - 1] = 2;
                }
            }
        }
    }

    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (temp[i][j] == 2)
                Image[i][j] = 0;
            printf("%2d", Image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < col; i++) {
        free(temp[i]);
    }
    free(temp);
}
void Menu()
{
    puts("================");
    puts("1. 팽창 ");
    puts("2. 침식 ");
    puts("3. 프로그램 종료 ");
    puts("================");
}
int main()
{
    FILE* pf = NULL;
    fopen_s(&pf, "..\\test.txt", "r");

    //FILE* pf = NULL;
    int op;
    //pf = fopen_s(&pf,"test.txt", "r");
    int n, m;
    fscanf_s(pf, "%d %d", &n, &m);

    int** Image = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        Image[i] = (int*)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            fscanf_s(pf, "%d", &Image[i][j]);
    }

    //초기 상태 출력
    PrintImage(n, m, Image);
    while (1) {
        Menu();
        scanf_s("%d", &op);
        if (op == 1) {
            Dilation(n, m, Image);
        }
        else if (op == 2) {
            Erosion(n, m, Image);
        }
        else if (op == 3) {
            break;
        }
    }
    fclose(pf);
    for (int i = 0; i < n; i++) {
        free(Image[i]);
    }
    free(Image);
}
