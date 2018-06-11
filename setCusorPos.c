#include <stdio.h>
#include <curses.h>

main(void)
{
	initscr();
	attron(A_BOLD);
	move(0,2);
	//COORD pos1 = {0,2};
	//COORD pos2 = {6,6};
	//COORD pos3 = {15,4};

	//HANDLE hConsoleOut-GetStdHandle(STD_OUTPUT_HANDLE);
	
	//SetConsoleCursorPosition(hConsoleOut, pos1);
	printw("%","첫 번째 인사 : 안녕하세요. ");
	//fflush();
	refresh();
	//SetConsoleCursorPosition(hConsoleOut, pos2);
	move(6,6);
	printf("두 번째 인사 : 안녕하세요. ");
	//fflush();
	refresh();
	move(15,4);
	//SetConsoleCursorPosition(hConsoleOut, pos3);
	printf("세 번째 인사 : 안녕하세요. ");
	//fflush();
	refresh();
	endwin();
	
}
