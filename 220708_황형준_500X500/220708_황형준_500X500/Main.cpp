// 0708 _ 황형준 _ BITMAP
#pragma warning (disable : 4244 6386 26495)
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cmath>
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
typedef struct BITMAPFILEHEADER
{
    char bfType[2] = "";
    int bfSize = 0;
    short bfReserved1 = 0;
    short bfReserved2 = 0;
    int bfOffBits = 0;
} hf;
typedef struct BITMAPINFOHEADER
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
    hf hf;
    hInfo hInfo;
    RGBQUAD pa[256];
public:
    Bitmap(int _width = 0, int _height = 0) : buf(nullptr), width(_width), height(_height) {}
    Bitmap(const string& fN) { InitReadFile(fN); }
    //Bitmap(const Bitmap& arg, int width , int height) : width(arg.width), height(arg.height)  //복사 생성자
    //{
    //    hf.bfSize = arg.hf.bfSize;
    //    hInfo.biWidth = arg.hInfo.biWidth;
    //    hInfo.biHeight = arg.hInfo.biHeight;

    //    buf = new uchar[arg.hInfo.biHeight * arg.hInfo.biWidth];
    //    for (int i = 0; i < arg.hInfo.biHeight * arg.hInfo.biWidth; ++i)
    //    {
    //        buf[i] = arg.buf[i];
    //    }
    //}
    ~Bitmap() 
    { 
        //delete[] buf;
    }
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
    void InitWriteFile(uchar* _buf, string fn)
    {
        ofstream ofs(fn, ios::binary);
        char bfType[2] = { 'B','M' };
        ofs.write((char*)bfType, sizeof(short));
      
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
        ofs.write((char*)pa, 1024);
      
        ofs.write((char*)_buf, hInfo.biWidth * hInfo.biHeight);
        delete[] buf;
        ofs.close();
    }
    void InitWriteFile(int* _buf, int a, int b, string fn)
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
        for (int x = 0; x < 500; ++x)
        {
            for (int y = 0; y < 500; ++y)
            {
                buf2[500 * x + y] = (x * 256 / 500 + y * 256 / 500) / 2;
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
        ofs.write((char*)&bfSize, sizeof(int));

        int bfReserved1 = 0;
        ofs.write((char*)&bfReserved1, sizeof(short));

        int bfReserved2 = 0;
        ofs.write((char*)&bfReserved2, sizeof(short));

        int bfOffBits = 1078;
        ofs.write((char*)&bfOffBits, sizeof(int));

        int biSize = 40;
        ofs.write((char*)&biSize, sizeof(int));

        int biWidth = 500;
        ofs.write((char*)&biWidth, sizeof(int));

        int biHeight = 500;
        ofs.write((char*)&biHeight, sizeof(int));

        int biPlanes = 1;
        ofs.write((char*)&biPlanes, sizeof(short));

        int biBitCount = 8;
        ofs.write((char*)&biBitCount, sizeof(short));

        int biCompression = 0;
        ofs.write((char*)&biCompression, sizeof(int));

        int biSizeImage = 0;
        ofs.write((char*)&biSizeImage, sizeof(int));

        int biXPelsPerMeter = 2834;
        ofs.write((char*)&biXPelsPerMeter, sizeof(int));

        int biYPelsPerMeter = 2834;
        ofs.write((char*)&biYPelsPerMeter, sizeof(int));

        int biClrUsed = 0;
        ofs.write((char*)&biClrUsed, sizeof(int));

        int biClrImportant = 0;
        ofs.write((char*)&biClrImportant, sizeof(int));
        
        SetPa();
        ofs.write((char*)pa, 1024);
        int size = biHeight * biWidth;
        uchar* buf2 = new uchar[biWidth * biHeight];

        Pix(buf2, size);
        ofs.write((char*)buf2, size * sizeof(uchar));
        delete[] buf;
    }
};
void Util()
{
    cout << "======================== "   << endl;
    cout << "   [1] - Template Matc"  << endl;
    cout << "   [2] - Gaussian"       << endl;
    cout << "   [3] - Laplacian"      << endl;
    cout << "   [4] - Gradation"      << endl;
    cout << "   [5] - Equalization "  << endl;
    cout << "   [6] - otsu"           << endl;
    cout << "   [7] - Cut"            << endl;
    cout << "   [8] - Dilation "      << endl;
    cout << "   [9] - Erosion"        << endl;
    cout << "   [0] - 프로그램 종료"   << endl;
    cout << "========================"   << endl;
}
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
void Cut(Bitmap& bit, const Point& pt, int a, int b, string fn)
{
    uchar* buf2 = new uchar[a * b];
    bit.Pix(buf2, pt, a, b);
    bit.InitWriteFile(buf2, a, b, fn);
    delete[] buf2;
}
void Cut2(Bitmap& bit, const Point& pt, const Point& pt2, string fn)
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
void Equalization(Bitmap& bit, string fn)
{
    int newpa[256] = { 0 };
    int his[256] = { 0 };
    int sum[256] = { 0 };
    int count = 0;

    uchar* buf = bit.GetBuf();
    
    uchar* pix2 = new uchar[bit.GetbiHeight() * bit.GetbiWidth()]{ 0 };
    uchar* sum_new = new uchar[256]{ 0 };
    for (int k = 0; k < 256; ++k)
    {
        for (int i = 0 ; i <bit.GetbiHeight() ; ++i)
            for (int j = 0; j < bit.GetbiWidth(); ++j)
            {
                if (buf[512 * i + j] == k)
                {
                    ++count;
                    his[k] = count;
                }
            }
        count = 0;
    }

    sum[0] = his[0];
    int row = bit.GetbiWidth();
    int col = bit.GetbiHeight();


    for (int i = 1; i < 256; ++i)
    {
        sum[i] = sum[i - 1] + his[i];
        newpa[i] = sum[i] * 255 / (col*row);
    }

    for (int i = 0; i < bit.GetbiHeight(); ++i)
    {
        for (int j = 0; j < bit.GetbiWidth(); ++j)
        {
            pix2[i * bit.GetbiWidth() + j] = newpa[buf[i * bit.GetbiWidth() + j]];
        }
    }
    bit.InitWriteFile(pix2, bit.GetbiHeight(), bit.GetbiWidth(), fn);
    delete[] pix2;
}
int FindThreshold(double* t, int* his)
{
    double totalsum = 0;
    double totalavg;
    double mMax = 0;
    double result = 0;
    double allpixel = 0;

    for (int l = 0; l < 256; ++l)
    {
        allpixel += his[l];
        totalsum += his[l] * l;
    }
    totalavg = totalsum / allpixel;

    for (int i = 0; i < 256; ++i)
    {
        int j;
        double presum = 0;
        double totalpresum = 0;
        double preavg = 0;
        double postsum = 0;
        double totalpostsum = 0;
        double postavg = 0;
        double p1 = 0;
        double p2 = 0;
        for (j = 0; j <= i; ++j)
        {
            presum += his[j];
            totalpresum += his[j] * j;
        }
        if (presum == 0)
            continue;
        else
            preavg = totalpresum / presum;

        for (j = i + 1; j < 256; ++j)
        {
            postsum += his[j];
            totalpostsum += his[j] * j;
        }
        if (postsum == 0)
            continue;
        else
            postavg = totalpostsum / postsum;

        p1 = presum / totalsum;
        p2 = postsum / totalsum;

        t[i] = sqrt(p1 * pow((preavg - totalavg), 2) + p2 * pow((postavg - totalavg), 2));

        if (mMax < t[i])
        {
            mMax = t[i];
            result = i;
        }
    }
    return result;
}
void Otsu(Bitmap& bit, string fn)
{
    int row = bit.GetbiHeight();
    int col = bit.GetbiWidth();
    int his[256] = { 0 };
    double t[256];

    uchar* pa = bit.GetBuf();

    for (int l = 0; l < 256; ++l)
    {
        int count = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (pa[i * col + j] == l)
                {
                    count++;
                    his[l] = count;
                }
            }
        }
    }

    int n = FindThreshold(t, his);
    cout << n;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (pa[i * col + j] < n)
                pa[i * col + j] = 0;
            else
                pa[i * col + j] = 255;
        }
    }
    bit.InitWriteFile(pa, bit.GetbiHeight(), bit.GetbiWidth(), fn);
}
//void Gaussian(Bitmap& bit)
//{
//    uchar* C = new uchar[bit.GetSize()]{ 0 };
//    uchar* C2 = bit.GetBuf();
//    bit.GetSize();
//    int h = hInfo.biHeight;
//    int w = hInfo.biWidth;
//
//
//    for (int i = 0; i < bit.GetSize(); ++i)
//    {
//        for (int i = 0; i < bit.GetbiHeight(); ++i)
//            for (int j = 0; j < bit.GetbiWidth(); ++j)
//            {
//                for (int x = -1; x < 2; ++x);
//                {
//                    if (i == j)
//                        j--;
//                    else if( j == i)
//                    {
//
//                    }
//                }
//            }
//    }
//}
//void Laplacian(Bitmap& bit)
//{
//
//}
void TemplateMatching(Bitmap& bit, Bitmap& bit2, string fn)
{
    uchar* TM = bit.GetBuf();
    uchar* TM2 = bit2.GetBuf();
    
    int row = bit.GetbiHeight();
    int col = bit.GetbiWidth();

    int rrow = bit2.GetbiHeight();
    int ccol = bit2.GetbiWidth();

    int score;
    int sx = 0;
    int sy = 0;
    int Min = 100000;   //Min값은 원래 큰값으로 초기화하는데 Min[0] 하고 for문을 1번으로 시작

    for (int x = 0; x < row - rrow; ++x)
    {
        for (int y = 0; y < col - ccol; ++y)
        {
            score = 0;
            for (int i = 0; i < rrow; ++i)
            {
                for (int j = 0; j < ccol; ++j)
                {
                    score += pow(TM2[i*ccol+j] - TM[(x+i)*col + y + j] , 2);
                }
                    
            }
            if (Min > score)
            {
                Min = score;

                sx = x;
                sy = y;
            }
        }
    }
            for (int k = sx; k < rrow + sx; ++k)
            {
                for (int u = sy; u < ccol + sy; ++u)
                {
                    if(k==sx||u==sy||k==rrow+sx-1||u==ccol+sy-1)
                    TM[k * col + u] = 255;
                }
            }
            bit.InitWriteFile(TM, fn);
}
int main()
{
    //Bitmap bm;
    //bm.Bitmapopen("lena_gray.bmp");

    //bm.InitReadFile("lena_gray.bmp");
    //bm.InitWriteFile("lena_gray1.bmp");

    Bitmap G("lena_gray.bmp");
    Bitmap EQ("lena_gray.bmp");
    Bitmap C1("lena_gray.bmp");
    Bitmap C2("lena_gray.bmp");
    Bitmap D("lena_gray.bmp");
    Bitmap E("lena_gray.bmp");
    Bitmap TM("or.bmp");
    Bitmap TM2("C1.bmp");
    Bitmap OT("lena_gray.bmp");

    int run = 1;
    while (run)
    {
        Util();
        switch (_getch())
        {
        case '1':
        {
            TemplateMatching(TM,TM2,"ff.bmp");
            
        }
        break;
        case '2':
        {
            //Gaussian();
        }
        case '3':
        {
            //Laplacian();
        }
        break;
        case '4':
        {
            G.Gradation("gradation.bmp");
        }

        break;

        case '5':
        {
            Equalization(EQ,"Equalization.bmp");
        }
        break;
        
        case '6':
        {
            Otsu(OT,"otsu.bmp");
        }

        case '7':
        {
            Cut(C1, Point(0, 0), 64, 64, "C1.bmp");
            Cut2(C2, Point(0, 0), Point(100, 100), "C2.bmp");
        }
        break;

        case '8':
        {
            int dcount = 0;
            string Dil = "D";
            string typebmp = " .bmp";
            Dilation(D);
            Dil.append(to_string(dcount));
            Dil.append(typebmp);
            D.InitWriteFile(Dil);
            ++dcount;
        }
        break;

        case '9':
        {
            int ccount = 0;
            string Ero = "E";
            string typebmp = " .bmp";
            Erosion(E);
            Ero.append(to_string(ccount));
            Ero.append(typebmp);
            E.InitWriteFile(Ero);
            ++ccount;
        }
        break;
        case '0':
        {
            run = 0;
        }
        break;
        default:
            break;
        }
    }
}
