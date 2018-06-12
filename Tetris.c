#include<stdio.h>
#include<ncursesw/curses.h>
#include<stdlib.h>
#include<unistd.h>
#include<locale.h>
/*Todo list*/

/*블럭 생성*/
void InitNewBlock(char blockInfo[][4]);
/*블럭을 출력*/
void ShowBlock(char blockInfo[][4]);
/*블럭을 삭제*/
void DeleteBlock(char blockInfo[][4]);
/*블럭을 바꿈*/
/*블럭을 멈춤*/
/*가득찬 줄 삭제*/

/*맵그리기*/
void DrowMap(char map[15][27]);

int point_x, point_y; //벽돌을 그려주기 위한 포인트
int cur_x =0;//커서의 위치
int *cur_xPtr=&cur_x;
int cur_y =6;
int *cur_yPtr=&cur_y;
int x,y;
char map[15][27];
char blockModel[][4][4] =
{//Idia 4차원 배열을 이용하면 호출할 때 좀 더 용이하지 않을까??
	/*첫 번째 블럭1,2,3,4
	  ■
  	  ■ ■ ■   */
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
	},
	/*두 번째 블럭5,6,7,8
	      ■
	  ■ ■ ■    */
	{
	  {0,0,0,0},
	  {0,0,1,0},
	  {1,1,1,0},
	  {0,0,0,0}
	},
	{
	  {0,0,0,0},
	  {0,1,1,0},
	  {0,0,1,0},
	  {0,0,1,0}
	},
	{
	  {0,0,0,0},
	  {0,1,1,1},
	  {0,1,0,0},
	  {0,0,0,0}
	},
	{
	  {0,1,0,0},
	  {0,1,0,0},
	  {0,1,1,0},
	  {0,0,0,0}
	},
	/*세 번째 블럭9,10,11,12
		■
		■
		■
		■     */
	{
	  {0,1,0,0},
	  {0,1,0,0},
	  {0,1,0,0},
	  {0,1,0,0}
	},
	{
	  {0,0,0,0},
	  {1,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0}
	},
	{
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0}
	},
	{
	  {0,0,0,0},
	  {0,0,0,0},
	  {1,1,1,1},
	  {0,0,0,0}
	},
	/*네 번째 블럭13,14
	  ■ ■
	    ■ ■  */
	{
	  {0,0,0,0},
	  {0,1,1,0},
	  {0,0,1,1},
	  {0,0,0,0}
	},
	{
	  {0,0,1,0},
	  {0,1,1,0},
	  {0,1,0,0},
	  {0,0,0,0}
	},
	/*다섯 번째 블럭15,16
	   ■ ■
	 ■ ■  */
	{
	  {0,0,0,0},
	  {0,0,1,1},
	  {0,1,1,0},
	  {0,0,0,0}
	},
	{
	  {0,1,0,0},
	  {0,1,1,0},
	  {0,0,1,0},
	  {0,0,0,0}
	},
	/*여섯 번째 블럭17,18,19,20
	   ■
	 ■ ■ ■  */
	{
	  {0,1,0,0},
	  {1,1,1,0},
	  {0,0,0,0},
	  {0,0,0,0}
	},
	{
	  {0,1,0,0},
	  {0,1,1,0},
	  {0,1,0,0},
	  {0,0,0,0}
	},
	{
	  {0,0,0,0},
	  {0,1,1,1},
	  {0,0,1,0},
	  {0,0,0,0}
	},
	{
	  {0,0,0,0},
	  {0,0,1,0},
	  {0,1,1,0},
	  {0,0,1,0}
	},
	/*일곱 번째 블럭 21
	  ■ ■
	  ■ ■
	*/
	{
	  {0,0,0,0},
	  {0,1,1,0},
	  {0,1,1,0},
	  {0,0,0,0}
	}
};

int main(void)
{
	int i,j;//블럭이 내려오게 하기 위해 씀, 블럭 모델을 선택하기 위해 씀
	setlocale(LC_CTYPE, "ko.KR.utf-8");//한글 사용을 위해 사용
	j = rand()%21;
	initscr();
	//맵을 그리고
	while(true){
	i++;
	InitNewBlock(blockModel[j]);
	refresh();
	sleep(1);
	DeleteBlock(blockModel[j]);
	refresh();
	cur_x=+i;
	}
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
				move(point_x+x,point_y+y);
				addch(ACS_CKBOARD);
			}
		}
	}
}
void InitNewBlock(char blockInfo[][4])
{
	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x]==1)
			{
				curs_set(0);
				move(cur_x+x,cur_y+y);
				addch(ACS_CKBOARD);	
			}
		}
	}
}
void DeleteBlock(char blockInfo[][4])
{
	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x]==1)
			{
				curs_set(0);
				move(cur_x+x,cur_y+y);
				printw("%s"," ");
			}
		}
	}
}
