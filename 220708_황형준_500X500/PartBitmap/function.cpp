#include "function.h"
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
    Bitmap(int _width = 0, int _height = 0) : buf(nullptr), width(_width), height(_height) {}
    Bitmap(const string& fN) : fileName(fN) { InitReadFile(fN); }
    ~Bitmap() { }
    int GetWidth() { return width; }
    int GetHeight() { return height; }
    int GetbiWidth() { return hInfo.biWidth; }
    int GetbiHeight() { return hInfo.biHeight; }
    int GetSize() { return hInfo.biHeight * hInfo.biWidth; }
    uchar* GetBuf() { return buf; }
    void InitReadFile(string fN)
    {
        ifstream ifs(fN, ios::binary);

        ifs.read((char*)&hf.bfType, sizeof(short));
        cout << "bfType : " << hf.bfType << endl;

        ifs.read((char*)&hf.bfSize, sizeof(int));
        cout << "hf.bfSize : " << hf.bfSize << endl;

        ifs.read((char*)&hf.bfReserved1, sizeof(short));
        cout << "hf.bfReserved1 : " << hf.bfReserved1 << endl;

        ifs.read((char*)&hf.bfReserved2, sizeof(short));
        cout << "hf.bfReserved2 : " << hf.bfReserved2 << endl;

        ifs.read((char*)&hf.bfOffBits, sizeof(int));
        cout << "hf.bfOffBits : " << hf.bfOffBits << endl;

        ifs.read((char*)&hInfo.biSize, sizeof(int));
        cout << "hInfo.biSize : " << hInfo.biSize << endl;

        ifs.read((char*)&hInfo.biWidth, sizeof(int));
        cout << "hInfo.biWidth : " << hInfo.biWidth << endl;

        ifs.read((char*)&hInfo.biHeight, sizeof(int));
        cout << "hInfo.biHeight : " << hInfo.biHeight << endl;

        ifs.read((char*)&hInfo.biPlanes, sizeof(short));
        cout << "hInfo.biPlanes : " << hInfo.biPlanes << endl;

        ifs.read((char*)&hInfo.biBitCount, sizeof(short));
        cout << "hInfo.biBitCount : " << hInfo.biBitCount << endl;

        ifs.read((char*)&hInfo.biCompression, sizeof(int));
        cout << "hInfo.biCompression : " << hInfo.biCompression << endl;

        ifs.read((char*)&hInfo.biSizeImage, sizeof(int));
        cout << "hInfo.biSizeImage : " << hInfo.biSizeImage << endl;

        ifs.read((char*)&hInfo.biXPelsPerMeter, sizeof(int));
        cout << "hInfo.biXPelsPerMeter : " << hInfo.biXPelsPerMeter << endl;

        ifs.read((char*)&hInfo.biYPelsPerMeter, sizeof(int));
        cout << "hInfo.biYPelsPerMeter : " << hInfo.biYPelsPerMeter << endl;

        ifs.read((char*)&hInfo.biClrUsed, sizeof(int));
        cout << "hInfo.biClrUsed : " << hInfo.biClrUsed << endl;

        ifs.read((char*)&hInfo.biClrImportant, sizeof(int));
        cout << "hInfo.biClrImportant : " << hInfo.biClrImportant << endl;

        ifs.read((char*)&pa, 1024);
        cout << "pa : " << pa << endl;

        cout << "====================================================" << endl;
        buf = new uchar[GetSize()];
        int size = hInfo.biHeight * hInfo.biWidth;
        ifs.read((char*)buf, size * sizeof(uchar));
    }
    void InitWriteFile(string fN)
    {
        ofstream ofs(fN, ios::binary);

        ofs.write((char*)&hf.bfType, sizeof(short));
        ofs.write((char*)&hf.bfSize, sizeof(int));
        ofs.write((char*)&hf.bfReserved1, sizeof(short));
        ofs.write((char*)&hf.bfReserved2, sizeof(short));
        ofs.write((char*)&hf.bfOffBits, sizeof(int));

        ofs.write((char*)&hInfo.biSize, sizeof(int));
        ofs.write((char*)&hInfo.biWidth, sizeof(int));
        ofs.write((char*)&hInfo.biHeight, sizeof(int));
        ofs.write((char*)&hInfo.biPlanes, sizeof(short));
        ofs.write((char*)&hInfo.biBitCount, sizeof(short));
        ofs.write((char*)&hInfo.biCompression, sizeof(int));
        ofs.write((char*)&hInfo.biSizeImage, sizeof(int));
        ofs.write((char*)&hInfo.biXPelsPerMeter, sizeof(int));
        ofs.write((char*)&hInfo.biYPelsPerMeter, sizeof(int));
        ofs.write((char*)&hInfo.biClrUsed, sizeof(int));
        ofs.write((char*)&hInfo.biClrImportant, sizeof(int));
        ofs.write((char*)&pa, 1024);

        int size = hInfo.biHeight * hInfo.biWidth;
        ofs.write((char*)GetBuf(), size * sizeof(uchar));
    }

    void InitWriteFile(uchar* _buf, int a, int b, string fn)
    {
        ofstream ofs(fn, ios::binary);
        char bfType[2] = { 'B','M' };
        ofs.write((char*)bfType, sizeof(short));
        int bfsize = 1078 + sizeof(uchar) * (a * b) + 2;
        ofs.write((char*)&bfsize, sizeof(int));
        ofs.write((char*)&hf.bfReserved1, sizeof(short));
        ofs.write((char*)&hf.bfReserved2, sizeof(short));
        ofs.write((char*)&hf.bfOffBits, sizeof(int));
        ofs.write((char*)&hInfo.biSize, sizeof(int));
        int width = a;
        ofs.write((char*)&width, sizeof(int));
        int height = b;
        ofs.write((char*)&height, sizeof(int));
        ofs.write((char*)&hInfo.biPlanes, sizeof(short));
        ofs.write((char*)&hInfo.biBitCount, sizeof(short));
        ofs.write((char*)&hInfo.biCompression, sizeof(int));
        ofs.write((char*)&hInfo.biSizeImage, sizeof(int));
        ofs.write((char*)&hInfo.biXPelsPerMeter, sizeof(int));
        ofs.write((char*)&hInfo.biYPelsPerMeter, sizeof(int));
        ofs.write((char*)&hInfo.biClrUsed, sizeof(int));
        ofs.write((char*)&hInfo.biClrImportant, sizeof(int));
        ofs.write((char*)pa, 1024);
        int size = width * height;
        ofs.write((char*)_buf, size * sizeof(uchar));
        delete[] buf;
    }
    void SetBuf(uchar* bm)
    {
        for (int i = 0; i < hInfo.biHeight * hInfo.biWidth; ++i)
        {
            buf[i] = bm[i];
        }
    }
    void SetPa()
    {
        for (int i = 0; i < 256; ++i)
        {
            pa[i].rgbRed = i;
            pa[i].rgbBlue = i;
            pa[i].rgbGreen = i;
            pa[i].rgbReserved = i;
        }
    }
    const Bitmap& operator = (const Bitmap& arg)
    {
        for (int i = 0; i < hInfo.biHeight * hInfo.biWidth; ++i)
        {
            buf[i] = arg.buf[i];
        }
        return *this;
    }
    void Pix(uchar* buf2, int size)
    {
        int k = 0;
        int s = 0;
        for (int x = 0; x < 512; ++x)
        {
            for (int y = 0; y < 512; ++y)
            {
                buf2[512 * x + y] = (x * 256 / 512 + y * 256 / 512) / 2;
            }
        }
    }
    void Pix(uchar* _buf2, const Point& pt, int _width, int _height)
    {
        for (int y = _height - 1; y >= 0; --y)
        {
            for (int x = _width - 1; x >= 0; --x)
            {
                _buf2[(_height * (_height - 1 - y) + x)] = buf[(512 * (511 - (y + pt.GetY())) + ((x + pt.GetX())))];
            }
        }
    }
    void Gradation(string fN)
    {
        ofstream ofs(fN, ios::binary);
        char bfType[2] = { 'B','M' };
        ofs.write((char*)bfType, sizeof(short));

        int bfSize = 0;
        ofs.write((char*)&hf.bfSize, sizeof(int));

        int bfReserved1 = 0;
        ofs.write((char*)&hf.bfReserved1, sizeof(short));

        int bfReserved2 = 0;
        ofs.write((char*)&hf.bfReserved2, sizeof(short));

        int bf0ffButs = 1078;
        ofs.write((char*)&hf.bfOffBits, sizeof(int));

        int biSize = 40;
        ofs.write((char*)&hInfo.biSize, sizeof(int));

        int biWidth = 500;
        ofs.write((char*)&hInfo.biWidth, sizeof(int));

        int biHeight = 500;
        ofs.write((char*)&hInfo.biHeight, sizeof(int));

        int biPlanes = 1;
        ofs.write((char*)&hInfo.biPlanes, sizeof(short));

        int biBitCount = 8;
        ofs.write((char*)&hInfo.biBitCount, sizeof(short));

        int biCompression = 0;
        ofs.write((char*)&hInfo.biCompression, sizeof(int));

        int biSizeImage = 0;
        ofs.write((char*)&hInfo.biSizeImage, sizeof(int));

        int biXPelsPerMeter = 2834;
        ofs.write((char*)&hInfo.biXPelsPerMeter, sizeof(int));

        int biYPelsPerMeter = 2834;
        ofs.write((char*)&hInfo.biYPelsPerMeter, sizeof(int));

        int biClrUsed = 0;
        ofs.write((char*)&hInfo.biClrUsed, sizeof(int));

        int biClrImportant = 0;
        ofs.write((char*)&hInfo.biClrImportant, sizeof(int));
        SetPa();
        ofs.write((char*)pa, 1024);
        int size = biHeight * biWidth;
        uchar* buf2 = new uchar[biWidth * biHeight];
        Pix(buf2, size);
        ofs.write((char*)buf2, size * sizeof(uchar));
        delete[] buf;
    }
};

Bitmap Erosion(Bitmap& bit)
{
    uchar* C = new uchar[bit.GetSize()]{ 0 };
    uchar* C2 = bit.GetBuf();

    for (int i = 0; i < bit.GetSize(); ++i)
    {
        C[i] = C2[i];
    }

    for (int i = 0; i < bit.GetbiHeight(); ++i)
    {
        for (int j = 0; j < bit.GetbiWidth(); ++j)
        {
            int min = 256;
            for (int x = -1; x < 2; ++x)
            {
                for (int k = i - 1; k < i + 2; ++k)
                {
                    if ((j + x >= 512) || (j + x < 0) || (k < 0) || (k >= 512))
                        continue;
                    else
                    {
                        if (min > C[512 * k + j + x])
                        {
                            min = C[512 * k + j + x];
                        }
                    }
                }
            }
            C2[512 * i + j] = min;
        }
    }
    delete[] C;
    return bit;
}
Bitmap Dilation(Bitmap& bit)
{
    uchar* D = new uchar[bit.GetSize()]{ 0 };
    uchar* D2 = bit.GetBuf();

    for (int i = 0; i < bit.GetSize(); ++i)
    {
        D[i] = D2[i];
    }
    for (int i = 0; i < bit.GetbiHeight(); ++i)
    {
        for (int j = 0; j < bit.GetbiWidth(); ++j)
        {
            int max = 0;
            for (int x = -1; x < 2; ++x)
            {
                for (int k = i - 1; k < i + 2; ++k)
                {
                    if ((j + x >= 512) || (j + x < 0) || (k < 0) || (k >= 512))
                        continue;
                    else {
                        if (max < D[512 * k + j + x])
                        {
                            max = D[512 * k + j + x];
                        }
                    }
                }
            }
            D2[512 * i + j] = max;
        }
    }
    delete[] D;
    return bit;
}
void PartialSaveImage(Bitmap& bit, const Point& pt, int a, int b, string fn)
{
    uchar* buf2 = new uchar[a * b];
    bit.Pix(buf2, pt, a, b);
    bit.InitWriteFile(buf2, a, b, fn);
    delete[] buf2;
}

void PartialSaveImage(Bitmap& bit, const Point& pt, const Point& pt2, string fn)
{
    int width = abs((pt2.GetX() - pt.GetX()));
    int height = abs((pt2.GetY() - pt.GetY()));
    int ptlength = sqrt(pt.GetX() * pt.GetX() + pt.GetY() * pt.GetY());
    int pt2length = sqrt(pt2.GetX() * pt2.GetX() + pt2.GetY() * pt2.GetY());
    uchar* buf2 = new uchar[height * width];
    if (ptlength < pt2length)
        bit.Pix(buf2, pt, width, height);
    else
        bit.Pix(buf2, pt2, width, height);

    bit.InitWriteFile(buf2, width, height, fn);

    delete[] buf2;
}