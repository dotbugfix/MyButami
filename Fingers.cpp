#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

void main()
	{
	 clrscr();

	 int gdriver = DETECT, gmode;
	 initgraph(&gdriver, &gmode, "");
	 for(int i = 0;i<=200; i+=45)
		{

		 line(50+i,50,50+i,120);
		 line(90+i,50,90+i,120);
		 arc(70+i,50,0,180,20);
		 arc(70+i,50,0,180,15);
		 arc(70+i,65,210,330,15);
		 line(55+i,50,57+i,73);
		 line(85+i,50,83+i,73);
		}
	  for(i = 250;i<=450; i+=45)
		{

		 line(50+i,50,50+i,120);
		 line(90+i,50,90+i,120);
		 arc(70+i,50,0,180,20);
		 arc(70+i,50,0,180,15);
		 arc(70+i,65,210,330,15);
		 line(55+i,50,57+i,73);
		 line(85+i,50,83+i,73);
		}
	 getch();
	 closegraph();
	}
