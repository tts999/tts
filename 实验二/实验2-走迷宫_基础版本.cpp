#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

char map[100][100]={
"*#*********",
"***###*###*",
"###**#****#",
"*#**###**#*",
"***********",
"#####*##*##",
"**#*****#*E",
"***#*###**#",
"*#*********",
};
int N=9,M;
int curX,curY;
void printPerson()
{
	COORD pos;
	pos.X = curX ;
	pos.Y = curY ;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	printf("A");
}
void printMap()
{
	for(int i=0;i<N;i++)
	{
		printf("%s\n",map[i]);
	}
	printPerson();
}
void Move(char dir)
{
	switch(dir)
	{
		case 'w':
			curY--;
			if(curY<0) curY=0;
			if(map[curY][curX]=='#') curY++;
			break;
		case 's':
			curY++;
			if(curY>=N) curY=N-1;
			if(map[curY][curX]=='#') curY--;
			break;
		case 'a':
			curX--;
			if(curX<0) curX=0;
			if(map[curY][curX]=='#') curX++;
			break;
		case 'd':
			curX++;
			if(curX>=M) curX=M-1;
			if(map[curY][curX]=='#') curX--;
			break;			
	}
}
int main()
{
	char t;
	M=strlen(map[0]);
	while(1)
	{
		system("cls");
		printMap();
		t=getch();
		Move(t);
		if(map[curY][curX]=='E'){
		printf("通过成功\n");
		break; 
		} 
	}
}
