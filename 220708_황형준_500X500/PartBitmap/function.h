#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
typedef unsigned char uchar;
#pragma pack(push, 1)
struct Point
{

    Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
    int x;
    int y;
    int GetX()const { return x; }
    int GetY()const { return y; }
    ~Point() {}
};
struct BITMAPFILEHEADER
{
    char bfType[2] = "";
    int bfSize = 0;
    short bfReserved1 = 0;
    short bfReserved2 = 0;
    int bfOffBits = 0;
} hf;
struct BITMAPINFOHEADER
{
    int biSize = 0;
    int biWidth = 0;
    int biHeight = 0;
    short biPlanes = 0;
    short biBitCount = 0;
    int biCompression = 0;
    int biSizeImage = 0;
    int biXPelsPerMeter = 0;
    int biYPelsPerMeter = 0;
    int biClrUsed = 0;
    int biClrImportant = 0;
} hInfo;
struct RGBQUAD
{
    uchar rgbBlue;
    uchar rgbGreen;
    uchar rgbRed;
    uchar rgbReserved;
};
#pragma pack(pop)
class Bitmap
{
private:
    int width, height;
    uchar* buf;
    string fileName;
    RGBQUAD pa[256];
public:
    Bitmap(int _width = 0, int _height = 0) : buf(nullptr), width(_width), height(_height) {};
    Bitmap(const string& fN) : fileName(fN) { InitReadFile(fN); };
    ~Bitmap() { };
    int GetWidth() { return width; };
    int GetHeight() { return height; };
    int GetbiWidth() { return hInfo.biWidth; };
    int GetbiHeight() { return hInfo.biHeight; };
    int GetSize() { return hInfo.biHeight * hInfo.biWidth; };
    uchar* GetBuf() { return buf; };
    void InitReadFile(string fN);
    void InitWriteFile(string fN);
    void InitWriteFile(uchar* _buf, int a, int b, string fn);
    void SetBuf(uchar* bm);
    void SetPa();
    const Bitmap& operator = (const Bitmap& arg);
    void Pix(uchar* buf2, int size);
    void Pix(uchar* _buf2, const Point& pt, int _width, int _height);
    void Gradation(string fN);
    Bitmap Erosion(Bitmap& bit);
    Bitmap Dilation(Bitmap& bit);
    void PartialSaveImage(Bitmap& bit, const Point& pt, int a, int b, string fn);
    void PartialSaveImage(Bitmap& bit, const Point& pt, const Point& pt2, string fn);
};