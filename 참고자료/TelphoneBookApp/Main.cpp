#pragma warning (disable : 6386)
#include "Main.h" //공통으로 정의되어야 하는 헤더

int main()
{
	TelPhoneBook tpb;
	bool run = true;

	while (run)
	{
		Util::Menu();
		switch (_getch())
		{
		case '1':
			tpb.AddTel();
			break;
		case '2':
			tpb.PrintTel();
			break;
		case '3':
			tpb.SearchTel();
			break;
		case '4':
			tpb.RemoveTel();
			break;
		case '5':
			tpb.WriteTextTel();
			break;
		case '0':
			run = false;
			break;
		default:
			break;
		}
	}
}