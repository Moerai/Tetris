#include<stdio.h>
#include<ncursesw/curses.h>
#include<stdlib.h>
#include<unistd.h>
#include<locale.h>

void ShowBlock(char blockInfo[][4]);

int point_x,point_y;
int x,y;
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
	addch(ACS_CKBOARD);
	refresh();
	sleep(1);
	point_x = 3; point_y = 4;
	ShowBlock(blockModel[0]);
	refresh();
	sleep(1);
	point_x = 3; point_y = 8;
	ShowBlock(blockModel[1]);
	refresh();
	sleep(1);
	point_x = 3; point_y = 12;
	ShowBlock(blockModel[2]);
	refresh();
	sleep(1);
	point_x = 3; point_y = 16;
	ShowBlock(blockModel[3]);
	refresh();
	sleep(1);
	endwin();
	return 0;
}
void ShowBlock(char blockInfo[][4])
{
	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x]==1)
			{
				curs_set(0);
				move(point_x+y,point_y+x);
				addch(ACS_CKBOARD);
			}
		}
	}
}
