#include "Main.h"

int main()
{
    Bitmap D("lena_gray.bmp");
    Bitmap C("lena_gray.bmp");
    Bitmap A("lena_gray.bmp");
    Bitmap B("lena_gray.bmp");
    Bitmap P1("lena_gray.bmp");
    Bitmap P2("lena_gray.bmp");

    int run = 1;
    int dcount = 0;
    int ccount = 0;

    while (run)
    {
        Util();
        switch (_getch())
        {
        case '1':
        {

            string Dil = "∆ÿ√¢ ";
            string typebmp = " .bmp";
            Dilation(D);
            Dil.append(to_string(dcount));
            Dil.append(typebmp);
            D.InitWriteFile(Dil);
            ++dcount;
        }
        break;

        case '2':
        {

            string Ero = "ºˆ√‡ ";
            string typebmp = " .bmp";
            Erosion(C);
            Ero.append(to_string(ccount));
            Ero.append(typebmp);
            C.InitWriteFile(Ero);
            ++ccount;
        }
        break;

        case '3':
        {
            B.Gradation("gradation.bmp");
        }
        break;

        case '4':
        {
            PartialSaveImage(P1, Point(0, 0), 60, 60, "SelectPart.bmp");
        }
        break;

        case '0':
        {
            run = 0;
        }
        break;

        default:
            break;
            //Bitmap bm;
            //bm.Bitmapopen("lena_gray.bmp");

            //bm.InitReadFile("lena_gray.bmp");
            //bm.InitWriteFile("lena_gray1.bmp");
            //bm.Black("11.bmp");
        }

    }
}
