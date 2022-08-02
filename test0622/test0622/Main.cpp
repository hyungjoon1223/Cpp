// 0622 _황형준 _ 비트맵 팽창 침식 평활화
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
typedef struct _FileHeader
{
	char bfType[2];
	int bfSize;
	short bfReserved1;
	short bfReserved2;
	int bfOffBits;
} FH;
typedef struct _FileInfo
{
	int biSize;
	int biWidth;
	int biHeight;
	short biPlanes;
	short biBitCount;
	int biCompression;
	int biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	int biClrUsed;
	int biClrImportant;
} FI;
void GetPixel(unsigned char** pa, int row, int col, int* n)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			pa[i][j] = n[pa[i][j]];
			/*for (int k = 0; k < 256; ++k)
			{
				if (pa[i][j] == k)
				{
					pa[i][j] = n[k];
					break;
				}
			}*/
		}
	}
}
void NEW(int* n, int* sum, int row, int col)
{
	for (int i = 0; i < 256; ++i)
	{
		n[i] = (sum[i] * 255) / (row * col);
	}
}
void Sum(int* sum, int* hist)
{
	sum[0] = hist[0];
	for (int i = 1; i < 256; ++i)
	{
		sum[i] = sum[i - 1] + hist[i];
	}
}
void Histogram(unsigned char** pa, int row, int col, int* hist)
{
	for (int l = 0; l < 256; ++l)
	{
		int count = 0;

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (pa[i][j] == l)
				{
					count++;
					hist[l] = count;
				}
			}
		}
	}
}
void PrintArray(unsigned char** pa, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			printf("%3d", pa[i][j]);
		printf("\n");
	}
}
unsigned char** AllocMemory(int row, int col)
{
	unsigned char** pa = (unsigned char**)malloc(sizeof(unsigned char*) * row);
	for (int i = 0; i < row; ++i)
		pa[i] = (unsigned char*)malloc(sizeof(unsigned char) * col);

	return pa;
}
void FreeMemory(unsigned char** pa, int row, int col)
{
	for (int i = 0; i < row; ++i)
		free(pa[i]);

	free(pa);
}
void InitArray(unsigned char** pa, int row, int col, FILE* pf)
{
	unsigned char k;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			fscanf_s(pf, "%c", &k);
			pa[i][j] = k;
		}
	}
}
int Max(int a, int b)
{
	if (a < b)
		return b;
	return a;
}
int Min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}
void Menu()
{
	printf("===========================\n");
	printf("[1] 을 누르면 팽창\n");
	printf("[2] 을 누르면 침식\n");
	printf("[3] 을 누르면 평활화\n");
	printf("===========================\n");

}
int ExEdgeline(unsigned char** pa, int nrow, int ncol, int col, int row)
{
	int Mncol = col;
	int Mnrow = row;
	if (nrow < 0 || ncol < 0 || nrow >= Mnrow || ncol >= Mncol)
		return 0;

	return pa[nrow][ncol];
}
void Expansion(unsigned char** pa, int row, int col, unsigned char** pb)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int nMax = 0;

			for (int pi = -1; pi < 2; ++pi)
			{
				for (int pj = -1; pj < 2; ++pj)
				{
					nMax = Max(nMax, ExEdgeline(pa, i + pi, j + pj, col, row));
				}
			}
			pb[i][j] = nMax;
		}
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pa[i][j] = pb[i][j];
}
int ErEdgeline(unsigned char** pa, int nrow, int ncol, int col, int row)
{
	int Mncol = col;
	int Mnrow = row;
	if (nrow < 0 || ncol < 0 || nrow >= Mnrow || ncol >= Mncol)
		return 1;

	return pa[nrow][ncol];
}
void Erosion(unsigned char** pa, int row, int col, unsigned char** pb)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int nMin = 255;

			for (int pi = -1; pi < 2; ++pi)
			{
				for (int pj = -1; pj < 2; ++pj)
				{
					nMin = Min(nMin, ErEdgeline(pa, i + pi, j + pj, col, row));
				}
			}
			pb[i][j] = nMin;
		}
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pa[i][j] = pb[i][j];
}
int main()
{
	FILE* pf = NULL;
	FH Header;
	FI Info;
	RGBQUAD Pallete[256];
	int hist[256];
	int sum[256];
	int newC[256];


	unsigned char** color;
	unsigned char** copy;

	fopen_s(&pf, "lena_gray.bmp", "rb");
	{
		fread(&Header.bfType[0], sizeof(char), 1, pf);
		fread(&Header.bfType[1], sizeof(char), 1, pf);
		fread(&Header.bfSize, sizeof(int), 1, pf);
		fread(&Header.bfReserved1, sizeof(short), 1, pf);
		fread(&Header.bfReserved2, sizeof(short), 1, pf);
		fread(&Header.bfOffBits, sizeof(int), 1, pf);
		fread(&Info.biSize, sizeof(int), 1, pf);
		fread(&Info.biWidth, sizeof(int), 1, pf);
		fread(&Info.biHeight, sizeof(int), 1, pf);
		fread(&Info.biPlanes, sizeof(short), 1, pf);
		fread(&Info.biBitCount, sizeof(short), 1, pf);
		fread(&Info.biCompression, sizeof(int), 1, pf);
		fread(&Info.biSizeImage, sizeof(int), 1, pf);
		fread(&Info.biXPelsPerMeter, sizeof(int), 1, pf);
		fread(&Info.biYPelsPerMeter, sizeof(int), 1, pf);
		fread(&Info.biClrUsed, sizeof(int), 1, pf);
		fread(&Info.biClrImportant, sizeof(int), 1, pf);
		fread(Pallete, sizeof(RGBQUAD) * 256, 1, pf);

		color = AllocMemory(Info.biHeight, Info.biWidth);

		InitArray(color, Info.biHeight, Info.biWidth, pf);

	}
	fclose(pf);

	fopen_s(&pf, "F.bmp", "wb");
	{
		fwrite(Header.bfType, sizeof(char) * 2, 1, pf);
		fwrite(&Header.bfSize, sizeof(int), 1, pf);
		fwrite(&Header.bfReserved1, sizeof(short), 1, pf);
		fwrite(&Header.bfReserved2, sizeof(short), 1, pf);
		fwrite(&Header.bfOffBits, sizeof(int), 1, pf);
		fwrite(&Info.biSize, sizeof(int), 1, pf);
		fwrite(&Info.biWidth, sizeof(int), 1, pf);
		fwrite(&Info.biHeight, sizeof(int), 1, pf);
		fwrite(&Info.biPlanes, sizeof(short), 1, pf);
		fwrite(&Info.biBitCount, sizeof(short), 1, pf);
		fwrite(&Info.biCompression, sizeof(int), 1, pf);
		fwrite(&Info.biSizeImage, sizeof(int), 1, pf);
		fwrite(&Info.biXPelsPerMeter, sizeof(int), 1, pf);
		fwrite(&Info.biYPelsPerMeter, sizeof(int), 1, pf);
		fwrite(&Info.biClrUsed, sizeof(int), 1, pf);
		fwrite(&Info.biClrImportant, sizeof(int), 1, pf);

		for (int i = 0; i < 256; ++i)
		{
			Pallete[i].rgbRed = i;
			Pallete[i].rgbGreen = i;
			Pallete[i].rgbBlue = i;
			Pallete[i].rgbReserved = i;
		}

		fwrite(Pallete, sizeof(RGBQUAD) * 256, 1, pf);

		copy = AllocMemory(Info.biHeight, Info.biWidth);

		int n = Info.biHeight;
		int m = Info.biWidth;
		int run = 1;

		while (run)
		{
			Menu();

			switch (_getch() - '0')
			{
			case 1:
				Expansion(color, n, m, copy);
				break;
			case 2:
				Erosion(color, n, m, copy);
				break;
			case 3:
				Histogram(color, Info.biHeight, Info.biWidth, hist);
				Sum(sum, hist);
				NEW(newC, sum, Info.biHeight, Info.biWidth);
				GetPixel(color, Info.biHeight, Info.biWidth, newC);
				break;
			default:
				run = 0;
				break;
			}
		}
		for (int i = 0; i < Info.biHeight; ++i)
			for (int j = 0; j < Info.biWidth; ++j)
				fwrite(&color[i][j], sizeof(unsigned char), 1, pf);
	}
	fclose(pf);

	FreeMemory(copy, Info.biHeight, Info.biWidth);
	FreeMemory(color, Info.biHeight, Info.biWidth);
}

//#include <stdio.h>
//#include <windows.h>
//#pragma pack(push, 1)
//struct _BITMAPFILEHEADER
//{
//    unsigned short bfType;
//    unsigned int bfSize;
//    unsigned short bfReserved1;
//    unsigned short bfReserved2;
//    unsigned int bfOffBits;
//} hf;
//struct _BITMAPINFOHEADER
//{
//    unsigned int biSize;
//    int biWidth;
//    int biHeight;
//    unsigned short biPlanes;
//    unsigned short biBitCount;
//    unsigned int biCompression;
//    unsigned int biSizeImage;
//    int biXPelsPerMeter;
//    int biYPelsPerMeter;
//    unsigned int biClrUsed;
//    unsigned int biClrImportant;
//} hInfo;
//#pragma pack(pop)
//unsigned char** AllocMemory(int row, int col)  //이차원 배열을 만드는 함수 
//{
//    unsigned char** pa = (unsigned char**)malloc(sizeof(unsigned char*) * row);
//
//    for (int i = 0; i < row; ++i)
//        pa[i] = (unsigned char*)malloc(sizeof(unsigned char) * col);
//
//    return pa;
//}
//void FreeMemory(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//        free(pa[i]);
//
//    free(pa);
//}
//void InitArray(unsigned char** pa, int row, int col, FILE* pf) //2차원 배열에 무슨값을 넣을래?
//{
//    unsigned char k;  //파일에서 하나하나씩 받아와서 파일의 값을 하나씩 넣는다
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//        {
//            fscanf_s(pf, "%c", &k);
//            pa[i][j] = k;
//        }
//    }
//}
//void PrintArray(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//            printf("%3d", pa[i][j]);
//        printf("\n");
//    }
//}
//void UpsideDown(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//            printf("%3d", pa[row - 1 - i][j]);
//        printf("\n");
//    }
//}
//void Gray(RGBQUAD hRGB[])
//{
//    for (int i = 0; i < 256; ++i)
//    {
//        hRGB[i].rgbRed = i;
//        hRGB[i].rgbBlue = i;
//        hRGB[i].rgbGreen = i;
//        hRGB[i].rgbReserved = i;
//    }
//}
//int main()
//{
//    BITMAPFILEHEADER hf;
//    BITMAPINFOHEADER hInfo;
//    unsigned char** pixel;
//    FILE* pf = NULL;
//    fopen_s(&pf, "13.bmp", "rb");
//    RGBQUAD Pallete[256];
//
//    //fread(&hf, sizeof(BITMAPFILEHEADER,1, pf);
//    fread(&hf.bfType, sizeof(short), 1, pf);
//    fread(&hf.bfSize, sizeof(int), 1, pf);
//    fread(&hf.bfReserved1, sizeof(short), 1, pf);
//    fread(&hf.bfReserved2, sizeof(short), 1, pf);
//    fread(&hf.bfOffBits, sizeof(int), 1, pf);
//
//    fread(&hInfo.biSize, sizeof(int), 1, pf);
//    fread(&hInfo.biWidth, sizeof(int), 1, pf);
//    fread(&hInfo.biHeight, sizeof(int), 1, pf);
//    fread(&hInfo.biPlanes, sizeof(short), 1, pf);
//    fread(&hInfo.biBitCount, sizeof(short), 1, pf);
//    fread(&hInfo.biCompression, sizeof(int), 1, pf);
//    fread(&hInfo.biSizeImage, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biClrUsed, sizeof(int), 1, pf);
//    fread(&hInfo.biClrImportant, sizeof(int), 1, pf);
//    fread(Pallete, sizeof(RGBQUAD) * 256, 1, pf);
//
//    pixel = AllocMemory(hInfo.biHeight, hInfo.biWidth);
//    fclose(pf);
//    //InitArray(pixel, hInfo.biHeight, hInfo.biWidth, pf);
//    //PrintArray(pixel, hInfo.biHeight, hInfo.biWidth);
//    //UpsideDown(pixel, hInfo.biHeight, hInfo.biWidth);
//    fopen_s(&pf, "13.bmp", "wb");
//
//    fwrite(&pf, , );
//    fclose(pf);
//
//}

//#include <stdio.h>
//#include <windows.h>
//#pragma pack(push, 1)
//struct _BITMAPFILEHEADER
//{
//    unsigned short bfType;
//    unsigned int bfSize;
//    unsigned short bfReserved1;
//    unsigned short bfReserved2;
//    unsigned int bfOffBits;
//} hf;
//struct _BITMAPINFOHEADER
//{
//    unsigned int biSize;
//    int biWidth;
//    int biHeight;
//    unsigned short biPlanes;
//    unsigned short biBitCount;
//    unsigned int biCompression;
//    unsigned int biSizeImage;
//    int biXPelsPerMeter;
//    int biYPelsPerMeter;
//    unsigned int biClrUsed;
//    unsigned int biClrImportant;
//} hInfo;
//#pragma pack(pop)
//unsigned char** AllocMemory(int row, int col)  //이차원 배열을 만드는 함수 
//{
//    unsigned char** pa = (unsigned char**)malloc(sizeof(unsigned char*) * row);
//
//    for (int i = 0; i < row; ++i)
//        pa[i] = (unsigned char*)malloc(sizeof(unsigned char) * col);
//
//    return pa;
//}
//void FreeMemory(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//        free(pa[i]);
//
//    free(pa);
//}
//void InitArray(unsigned char** pa, int row, int col, FILE* pf) //2차원 배열에 무슨값을 넣을래?
//{
//    unsigned char k;  //파일에서 하나하나씩 받아와서 파일의 값을 하나씩 넣는다
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//        {
//            fscanf_s(pf, "%c", &k);
//            pa[i][j] = k;
//        }
//    }
//}
//void PrintArray(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//            printf("%3d", pa[i][j]);
//        printf("\n");
//    }
//}
//void UpsideDown(unsigned char** pa, int row, int col)
//{
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//            printf("%3d", pa[row -1 - i][j]);
//        printf("\n");
//    }
//}
//void Gray(RGBQUAD hRGB[])
//{
//    for (int i = 0; i < 256; ++i)
//    {
//        hRGB[i].rgbRed = i;
//        hRGB[i].rgbBlue = i;
//        hRGB[i].rgbGreen = i;
//        hRGB[i].rgbReserved = i;
//    }
//}
//int main()
//{
//    BITMAPFILEHEADER hf;
//    BITMAPINFOHEADER hInfo;
//    unsigned char** pixel;
//    FILE* pf = NULL;
//    fopen_s(&pf, "33.bmp", "rb");
//    RGBQUAD Pallete[256];
//
//    //fread(&hf, sizeof(BITMAPFILEHEADER,1, pf);
//    fread(&hf.bfType, sizeof(short), 1, pf);
//    fread(&hf.bfSize, sizeof(int), 1, pf);
//    fread(&hf.bfReserved1, sizeof(short), 1, pf);
//    fread(&hf.bfReserved2, sizeof(short), 1, pf);
//    fread(&hf.bfOffBits, sizeof(int), 1, pf);
//
//    fread(&hInfo.biSize, sizeof(int), 1, pf);
//    fread(&hInfo.biWidth, sizeof(int), 1, pf);
//    fread(&hInfo.biHeight, sizeof(int), 1, pf);
//    fread(&hInfo.biPlanes, sizeof(short), 1, pf);
//    fread(&hInfo.biBitCount, sizeof(short), 1, pf);
//    fread(&hInfo.biCompression, sizeof(int), 1, pf);
//    fread(&hInfo.biSizeImage, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biClrUsed, sizeof(int), 1, pf);
//    fread(&hInfo.biClrImportant, sizeof(int), 1, pf);
//    fread(Pallete, sizeof(RGBQUAD) * 256, 1, pf);
//
//    pixel = AllocMemory(hInfo.biHeight, hInfo.biWidth);
//
//    InitArray(pixel, hInfo.biHeight, hInfo.biWidth, pf);
//    //PrintArray(pixel, hInfo.biHeight, hInfo.biWidth);
//    UpsideDown(pixel, hInfo.biHeight, hInfo.biWidth);
//    //Gray(pixel, );
//    fclose(pf);
//}

//#include <stdio.h>
//#include <windows.h>
//#pragma pack(push, 1)
//struct _BITMAPFILEHEADER
//{
//    unsigned short bfType;
//    unsigned int bfSize;
//    unsigned short bfReserved1;
//    unsigned short bfReserved2;
//    unsigned int bfOffBits;
//} hf;
//struct _BITMAPINFOHEADER
//{
//    unsigned int biSize;
//    int biWidth;
//    int biHeight;
//    unsigned short biPlanes;
//    unsigned short biBitCount;
//    unsigned int biCompression;
//    unsigned int biSizeImage;
//    int biXPelsPerMeter;
//    int biYPelsPerMeter;
//    unsigned int biClrUsed;
//    unsigned int biClrImportant;
//} hInfo;
//#pragma pack(pop)
//unsigned char** AllocMemory(int row, int col)
//{
//    unsigned char** pa = (unsigned char**)malloc(sizeof(unsigned char*) * row);
//
//	for (int i = 0; i < row; ++i)
//		pa[i] = (unsigned char*)malloc(sizeof(unsigned char) * col);
//
//	return pa;
//}
//void FreeMemory(unsigned char** pa, int row, int col)
//{
//	for (int i = 0; i < row; ++i)
//		free(pa[i]);
//
//	free(pa);
//}
//void InitArray(unsigned char** pa, int row, int col, FILE* pf)
//{
//    unsigned char k;
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//        {
//            fscanf_s(pf, "%c", &k);
//            pa[i][j] = k;
//        }
//    }
//}
//void PrintArray(unsigned char** pa, int row, int col)
//{
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//			printf("%3d", pa[i][j]);
//		printf("\n");
//	}
//}
//void Gray(RGBQUAD hRGB[])
//{
//    for (int i = 0; i < 256; ++i)
//    {
//        hRGB[i].rgbRed = i;
//        hRGB[i].rgbBlue = i;
//        hRGB[i].rgbGreen = i;
//        hRGB[i].rgbReserved = i;
//    }
//}
//int main()
//{
//    BITMAPFILEHEADER hf;
//    BITMAPINFOHEADER hInfo;
//
//    FILE* pf = NULL;
//    fopen_s(&pf, "33.bmp", "rb");
//    RGBQUAD Pallete[256];
//
//
//
//    //fread(&hf, sizeof(BITMAPFILEHEADER,1, pf);
//    fread(&hf.bfType, sizeof(short), 1, pf);
//    fread(&hf.bfSize, sizeof(int), 1, pf);
//    fread(&hf.bfReserved1, sizeof(short), 1, pf);
//    fread(&hf.bfReserved2, sizeof(short), 1, pf);
//    fread(&hf.bfOffBits, sizeof(int), 1, pf);
//
//    fread(&hInfo.biSize, sizeof(int), 1, pf);
//    fread(&hInfo.biWidth, sizeof(int), 1, pf);
//    fread(&hInfo.biHeight, sizeof(int), 1, pf);
//    fread(&hInfo.biPlanes, sizeof(short), 1, pf);
//    fread(&hInfo.biBitCount, sizeof(short), 1, pf);
//    fread(&hInfo.biCompression, sizeof(int), 1, pf);
//    fread(&hInfo.biSizeImage, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biXPelsPerMeter, sizeof(int), 1, pf);
//    fread(&hInfo.biClrUsed, sizeof(int), 1, pf);
//    fread(&hInfo.biClrImportant, sizeof(int), 1, pf);
//    fread(Pallete, sizeof(RGBQUAD) * 256, 1, pf);
//    unsigned char** color = AllocMemory(hInfo.biWidth, hInfo.biHeight);
//    //fread(&hInfo, sizeof(BITMAPINFOHEADER), 1, pf);
// /*   if (hf.bfType == 0x4D42)
//        printf("Bmp파일\n");
//    else
//        printf("Bmp파일 아님\n");
//    printf("=====================================\n");
//    printf("hf.bfType= %hx\n", hf.bfType);
//    printf("hf.bfSize= %d byte\n", hf.bfSize);
//    printf("hf.bfStart= %d\n", hf.bfOffBits);
//    printf("======================================\n");
//    printf("hInfo.biSize= %d\n", hInfo.biSize);
//    printf("hInfo.biWidth= %d\n", hInfo.biWidth);
//    printf("hInfo.biHeight= %d\n", hInfo.biHeight);
//    printf("hInfo.biPlanes= %d\n", hInfo.biPlanes);
//    printf("hInfo.biBitCount= %d\n", hInfo.biBitCount);
//    printf("hInfo.biCompression = %d\n", hInfo.biCompression);
//    printf("hInfo.biSizeImage = %d\n", hInfo.biSizeImage);
//    printf("hInfo.biPelsPerMeter = %d\n", hInfo.biXPelsPerMeter);
//    printf("hInfo.biPelsPerMeter = %d\n", hInfo.biXPelsPerMeter);
//    printf("hInfo.biClrUsed= %d\n", hInfo.biClrUsed);
//    printf("hInfo.biClrImportant = %d\n", hInfo.biClrImportant);*/
//
//    InitArray(color, hInfo.biWidth, hInfo.biHeight, pf);
//    PrintArray(color, hInfo.biWidth, hInfo.biHeight);
//
//    fclose(pf);
//}

