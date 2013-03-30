/*
                  NAME - MyButami™ Fingers Module
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - Graphical representations of Fingers
		COMPAITIBILITY - Borland Turbo C++ IDE (Compilation)
						 DOS or similar Environment Shell
			 COPYRIGHT - *Not decided by the Authors*
			   VERSION - v0.9.2 BETA (Modular)
			 DATE/TIME -28/03/07 18:44

*/

#include "Header.h"                                 //Custom MyButami™ Source© Header v1.0

void main()
{
 /*Auto-Detect & Initialize Graphics Drivers*/
	 int gdriver = DETECT, gmode;
	 initgraph(&gdriver,&gmode,"");

 int orX=40,orY=80;
 line(orX,orY,orX,orY+60); 		//Pl1hL
 line(orX+30,orY,orX+30,orY+75);
 line(orX,orY+60,orX+30,orY+85);
 line(orX+10,orY+30,orX+20,orY+30);
 line(orX+10,orY+30,orX+10,orY+60);
 line(orX+10,orY+60,orX+30,orY+75);

 orX = 100;
 line(orX,orY,orX,orY+75);		//Pl1hR
 line(orX+30,orY,orX+30,orY+60);
 line(orX+20,orY+30,orX+20,orY+60);
 line(orX+20,orY+60,orX,orY+75);
 line(orX+10,orY+30,orX+20,orY+30);
 line(orX+30,orY+60,orX,orY+85);

 orX=40;
 orY=200;
 line(orX+30,orY+10,orX+30,orY+85);	//Pl2hL
 line(orX,orY+25,orX,orY+85);
 line(orX,orY+25,orX+30,orY);
 line(orX+10,orY+25,orX+30,orY+10);
 line(orX+10,orY+25,orX+10,orY+55);
 line(orX+10,orY+55,orX+20,orY+55);

 orX=100;
 line(orX,orY+10,orX,orY+85);      //Pl2hR
 line(orX+30,orY+25,orX+30,orY+85);
 line(orX,orY,orX+30,orY+25);
 line(orX,orY+10,orX+20,orY+25);
 line(orX+20,orY+25,orX+20,orY+55);
 line(orX+10,orY+55,orX+20,orY+55);

 getch();
 closegraph();
}
