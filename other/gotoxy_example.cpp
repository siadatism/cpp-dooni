#include <stdio.h>

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

using namespace std;

int main()
{
	printf("salam!\n");
	printf("salam!\n");
	printf("salam!\n");

	gotoxy(1, 2);
	printf("xxx");
	//printf("\033[2J");
}
