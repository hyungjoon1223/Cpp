#include <stdio.h>
int main()
{
	int n;

	printf("¤¡¤¡\n");
	scanf_s("%d", &n);

	for (int i = 1; i < n; ++i)
	{
		for (int j = n-1+1; j < n; j--)
		{
			printf(" ");
		}
		for (int k = 1; k <= (2 + i - 1); k++)
		{
			printf("*");
		}
		printf("\n");
	}
}
//#include <stdio.h>
//int main()
//{
//	for (int i = 1; i < 10; i++) {
//		for (int j = 1; j < 10; j++) {
//			printf(" %d x %d = %d\n", i, j, i * j);
//		}
//	}
//}
//#include <stdio.h>
//
//int main()
//{
//    int i;
//
//    for (i = 0; i < 100; i++) {
//        if (i % 5 == 0) continue;
//
//        printf("%d ", i);
//    }
//
//    return 0;
//}