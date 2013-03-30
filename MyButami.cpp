/*
                  NAME - MyButami™ GUI Module
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - Simple Butami Game            <--- EDIT Required
             COPYRIGHT - *Not decided by the Authors*
               VERSION - v0.9.0 BETA Development
                MODULE - MyButami™ Graphics (GUI)
             DATE/TIME - 11/02/07 19:31
VERSION SPECIFICATIONS - Individual GUI Module
            KNOWN BUGS - Under Active Development!
        NEXT BIG THING - Clock Display (Top Right Corner)

*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
	{
/*Auto-Detect & Initialize Graphics Drivers*/
	 int gdriver = DETECT, gmode;
	 initgraph(&gdriver,&gmode,"");
/*Draw Screen Border; Style:Double LIne*/
	 rectangle(0,0,getmaxx(),getmaxy());     //ScreenBorder Outer
	 rectangle(3,3,getmaxx()-3,getmaxy()-3); //ScreenBorder Inner
/*Draw Other Screen Elements*/
	 line(3,65,getmaxx()-3,65);              //LogoBottom 1
	 line(3,68,getmaxx()-3,68);              //LogoBottom 2
	 line(443,68,443,getmaxy()-3);           //RightMenuBorder Left
	 line(446,68,446,getmaxy()-3);           //RightMenuBorder Right
	 line(323,95,443,95);                    //Player1 StraightLine
	 line(283,68,323,95);                    //Player1 SlantLine
	 line(3,getmaxy()-70,123,getmaxy()-70);  //Player2 StraightLine
	 line(123,getmaxy()-70,163,getmaxy()-43);//Player2 SlantLine
	 line(537,95,getmaxx()-3,95);            //StandardFuncLabel StraightLine
	 line(497,68,537,95);                    //StandardFuncLabel SlantLine
	 settextstyle(2,0,7);
	 outtextxy(540,70,"Standard");           //StandardFunc Label
	 line(446,327,getmaxx()-3,327);          //MenuDivider Upper
	 line(446,330,getmaxx()-3,330);          //MenuDivider Lower
	 line(446,357,547,357);                  //AdvencedFuncLabel StraightLine
	 line(547,357,587,330);                  //AdvancedFuncLabel SlantLine
	 outtextxy(450,331,"Advanced");          //AdvancedFunc Label
	 line(3,getmaxy()-43,443,getmaxy()-43);  //BottomStatus Upper
	 line(3,getmaxy()-40,443,getmaxy()-40);  //BottomStatus Lower
/*Draw MyButami™ LOGO*/
	 settextstyle(2,0,6);
	 outtextxy(450,2,"TM");                  //LogoUpperRight TM Sign
	 settextstyle(2,0,5);
	 outtextxy(368,49,"v0.9.0 BETA");        //LogoBottomRight Version
	 settextstyle(4,0,7);
	 outtextxy(180,-15,"MyButami");          //Logo
	 setlinestyle(3,1,1);
/*Create ActvWindows for Console I/O*/
	 window(58,8,77,25);
	 cout<<"Standard Functions";
	 window(58,24,77,25);
	 cout<<"Advanced Functions";
	 getch();
/*Close Graphics Driver*/
	 closegraph();
    }
