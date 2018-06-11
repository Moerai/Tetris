#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
#include<unistd.h>

//이동 삽입 특성 등의 실습 예

int main()
{
	const char witch_one[]="First Witch";
	const char witch_two[]="Second Witch";
	const char*scan_ptr;
	int i,j;

	initscr();

	move(5,15);
	//======문자의 특성을 켠다.
	attron(A_BOLD);// <=== <===
	printw("%s","Macbeth");
	//======문자의 특성을 끄다.
	attroff(A_BOLD);// <=== <===
	refresh();
	sleep(1);
	move(8,15);
	attron(A_STANDOUT);
	printw("%s","Tunder and Lightning");
	attroff(A_STANDOUT);
	refresh();
	sleep(1);
	move(10,10);
	printw("%s","When shall we three meet again");
	move(11,23);
	printw("%s","In thunder, lightning, or in rain?");
	move(13,10);
	printw("%s","When the hurlyburly's done.");
	refresh();
	sleep(1);
	attron(A_DIM);
	scan_ptr=witch_one+strlen(witch_one)-1;
	while(scan_ptr !=witch_one)
	{
	move(10,10);
	insch(*scan_ptr--);//<===<===배우의 이름을 한문자 단위로 삽입
	}
	scan_ptr=witch_two+strlen(witch_two)-1;
	while(scan_ptr !=witch_two)
	{
	move(13,10);
	insch(*scan_ptr--);
	}
	attroff(A_DIM);
	refresh();
	sleep(1);
	//커서를 하위 우측으로 이동시킨다.
	move(LINES-1,COLS-1);
	refresh();
	sleep(1);

	endwin();
	return 0;
}
//출처:blog.naver.com/lvtlvt/80054663689

