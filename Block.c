#include<stdio.h>
#include<ncursesw/curses.h>
#include<stdlib.h>
#include<unistd.h>
#include<locale.h>

void ShowBlock(char blockInfo[][4]);


char blockModel[][4][4] =
{
	/*a
  	  aaa*/
	{
	  {0,0,0,0},
	  {1,0,0,0},
	  {1,1,1,0},
	  {0,0,0,0}
	},
	{
	  {0,0,0,0},
	  {1,1,0,0},
	  {1,0,0,0},
	  {1,0,0,0}
	},
	{
	  {0,0,0,0},
	  {1,1,1,0},
	  {0,0,1,0},
	  {0,0,0,0}
	},
	{
	  {0,0,0,0},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,1,1,0}
	}
};

int main(void)
{
	setlocale(LC_CTYPE, "ko.KR.utf-8");
	initscr();
	move(0,0);
	printw("%s","■");
	refresh();
	sleep(1);
	move(3,4);
	ShowBlock(blockModel[0]);
	refresh();
	sleep(1);
	endwin();
	return 0;
}
void ShowBlock(char blockInfo[][4])
{
	int x, y;
	
	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x]==1)
			{
				printw("%s","■");
			}
		}
	}
}
