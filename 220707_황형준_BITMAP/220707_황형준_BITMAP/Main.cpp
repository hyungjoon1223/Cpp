#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned char uchar;
#pragma pack(push, 1)
struct BITMAPFILEHEADER
{
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} hf;
struct BITMAPINFOHEADER
{
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
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
    RGBQUAD pal[256];
public:
    Bitmap() :width(0), height(0), buf(nullptr) {}

    void  Bitmapopen(string fn)
    {
        InitReadFile(fn);
        /*  ifstream ifs(fileName, ios::binary);*/
    }
    ~Bitmap() {}

    int GetWidth() { return width; }
    int GetHeight() { return height; }
    void InitReadFile(string fileName)
    {
        ifstream ifs(fileName, ios::binary);

        ifs.read((char*)&hf.bfType, sizeof(short));
        //cout << "bfType : " << hf.bfType << endl;
        ifs.read((char*)&hf.bfSize, sizeof(int));
        ifs.read((char*)&hf.bfReserved1, sizeof(short));
        ifs.read((char*)&hf.bfReserved2, sizeof(short));
        ifs.read((char*)&hf.bfOffBits, sizeof(int));

        ifs.read((char*)&hInfo.biSize, sizeof(int));
        ifs.read((char*)&hInfo.biWidth, sizeof(int));
        ifs.read((char*)&hInfo.biHeight, sizeof(int));
        ifs.read((char*)&hInfo.biPlanes, sizeof(short));
        ifs.read((char*)&hInfo.biBitCount, sizeof(short));
        ifs.read((char*)&hInfo.biCompression, sizeof(int));
        ifs.read((char*)&hInfo.biSizeImage, sizeof(int));
        ifs.read((char*)&hInfo.biXPelsPerMeter, sizeof(int));
        ifs.read((char*)&hInfo.biYPelsPerMeter, sizeof(int));
        ifs.read((char*)&hInfo.biClrUsed, sizeof(int));

        ifs.read((char*)&hInfo.biClrImportant, sizeof(int));

        ifs.read((char*)&pal, 1024);

        buf = new uchar[hInfo.biHeight * hInfo.biWidth];
        int size = hInfo.biHeight * hInfo.biWidth;
        ifs.read((char*)buf, size);
    }
    void InitWriteFile(string fileName)
    {
        ofstream ofs(fileName, ios::binary);

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
        ofs.write((char*)&pal, 1024);

        ofs.write((char*)buf, hInfo.biHeight * hInfo.biWidth);
    }
};
int main()
{
    Bitmap bm;
    bm.Bitmapopen("lena_gray.bmp");

    bm.InitReadFile("lena_gray.bmp");
    bm.InitWriteFile("lena_gray1.bmp");
    //ifstream ifs("lena_gray.bmp", ios::binary);
    //ifs.read((char*), ,sizeof(int));
    //ifs.read((char*), ,sizeof(int));
    //char* buf = new char[];
}
//#include <iostream>
//#include <fstream>
//using namespace std;
//typedef unsigned char uchar;
//#pragma pack(push, 1)
//struct BITMAPFILEHEADER
//{
//    unsigned short bfType;
//    unsigned int bfSize;
//    unsigned short bfReserved1;
//    unsigned short bfReserved2;
//    unsigned int bfOffBits;
//} hf;
//struct BITMAPINFOHEADER
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
//struct RGBQUAD 
//{
//    uchar rgbBlue;
//    uchar rgbGreen;
//    uchar rgbRed;
//    uchar rgbReserved;
//};
//#pragma pack(pop)
//class Bitmap
//{
//private:
//    int width, height;
//    uchar* buf;
//    string fileName;
//    RGBQUAD pal[256];
//public:
//    Bitmap ():width(0), height(0), buf(nullptr) {}
//    
//    void  Bitmapopen(string fn)
//    {
//        InitReadFile(fn);
//        /*  ifstream ifs(fileName, ios::binary);*/
//    }
//    ~Bitmap() {}
//
//    int GetWidth() { return width; }
//    int GetHeight() { return height; }
//    void InitReadFile(string fileName)
//    {
//        ifstream ifs(fileName, ios::binary);
//
//        ifs.read((char*)&hf.bfType, sizeof(short));
//        //cout << "bfType : " << hf.bfType << endl;
//        ifs.read((char*)&hf.bfSize, sizeof(int));
//        ifs.read((char*)&hf.bfReserved1, sizeof(short));
//        ifs.read((char*)&hf.bfReserved2, sizeof(short));
//        ifs.read((char*)&hf.bfOffBits, sizeof(int));
//
//        ifs.read((char*)&hInfo.biSize, sizeof(int));
//        ifs.read((char*)&hInfo.biWidth, sizeof(int));
//        ifs.read((char*)&hInfo.biHeight, sizeof(int));
//        ifs.read((char*)&hInfo.biPlanes, sizeof(short));
//        ifs.read((char*)&hInfo.biBitCount, sizeof(short));
//        ifs.read((char*)&hInfo.biCompression, sizeof(int));
//        ifs.read((char*)&hInfo.biSizeImage, sizeof(int));
//        ifs.read((char*)&hInfo.biXPelsPerMeter, sizeof(int));
//        ifs.read((char*)&hInfo.biYPelsPerMeter, sizeof(int));
//        ifs.read((char*)&hInfo.biClrUsed, sizeof(int));
//
//        ifs.read((char*)&hInfo.biClrImportant, sizeof(int));
//        
//        ifs.read((char*)&pal, 1024);
//
//        buf = new uchar[hInfo.biHeight * hInfo.biWidth];
//        int size = hInfo.biHeight * hInfo.biWidth;
//        ifs.read((char*)buf, size);
//    }
//    void InitWriteFile(string fileName)
//    {
//        ofstream ofs(fileName, ios::binary);
//
//        ofs.write((char*)&hf.bfType, sizeof(short));
//        ofs.write((char*)&hf.bfSize, sizeof(int));
//        ofs.write((char*)&hf.bfReserved1, sizeof(short));
//        ofs.write((char*)&hf.bfReserved2, sizeof(short));
//        ofs.write((char*)&hf.bfOffBits, sizeof(int)); 
//
//        ofs.write((char*)&hInfo.biSize, sizeof(int));
//        ofs.write((char*)&hInfo.biWidth, sizeof(int));
//        ofs.write((char*)&hInfo.biHeight, sizeof(int));
//        ofs.write((char*)&hInfo.biPlanes, sizeof(short));
//        ofs.write((char*)&hInfo.biBitCount, sizeof(short));
//        ofs.write((char*)&hInfo.biCompression, sizeof(int));
//        ofs.write((char*)&hInfo.biSizeImage, sizeof(int));
//        ofs.write((char*)&hInfo.biXPelsPerMeter, sizeof(int));
//        ofs.write((char*)&hInfo.biYPelsPerMeter, sizeof(int));
//        ofs.write((char*)&hInfo.biClrUsed, sizeof(int));   
//        ofs.write((char*)&hInfo.biClrImportant, sizeof(int));       
//        ofs.write((char*)&pal, 1024);
//
//        ofs.write((char*)buf, hInfo.biHeight * hInfo.biWidth);
//    }
//};
//int main()
//{
//    Bitmap bm;
//    bm.Bitmapopen("lena_gray.bmp");
//
//    bm.InitReadFile("lena_gray.bmp");
//    bm.InitWriteFile("lena_gray1.bmp");
//    //ifstream ifs("lena_gray.bmp", ios::binary);
//    //ifs.read((char*), ,sizeof(int));
//    //ifs.read((char*), ,sizeof(int));
//    //char* buf = new char[];
//}
