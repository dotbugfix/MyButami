/*
                  NAME - MyButami™ GUI Module
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - GUI Development Module
             COPYRIGHT - *Not decided by the Authors*
               VERSION - v0.9.2 BETA Development
                MODULE - MyButami™ Graphics (GUI)
             DATE/TIME - 28/03/07 18:46
VERSION SPECIFICATIONS - GUI Framework
                         Drawing all 8+8 Fingers
                         Generalizing for Source©
            KNOWN BUGS - Under Active Development!
		NEXT BIG THING - N/A

*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>

unsigned short int Pl1hL = 4, Pl1hR = 4, Pl2hL = 4, Pl2hR = 4;

int orX, orY;
void DrawFingers();
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
	// setlinestyle(3,1,1);
											 //Fingers Module Begins
/*Draw the UPPER_LEFT Finger*/
 /*int orX=30,orY=110;
 for(int count=4 ; count>0 ; orX+=40,count--)
 {
  line(orX,orY,orX,orY+60);
  line(orX+30,orY,orX+30,orY+85);
  line(orX,orY+60,orX+30,orY+85);
  line(orX+10,orY+30,orX+10,orY+60);
  line(orX+10,orY+60,orX+30,orY+75);
 }
 orX+=80;
 for(count=4 ;
 count>0 ; orX+=40,count--)
 {
  line(orX,orY,orX,orY+60);
  line(orX+30,orY,orX+30,orY+85);
  line(orX,orY+60,orX+30,orY+85);
  line(orX+10,orY+30,orX+10,orY+60);
  line(orX+10,orY+60,orX+30,orY+75);
 }
*/
/*Draw fingers*/
DrawFingers();
											 //Fingers Module Ends
/*Create ActvWindows for Console I/O*/
	 window(58,8,77,25);
	 cout<<"Standard Functions";
	 window(58,24,77,25);
	 cout<<"Advanced Functions";
	 getch();
/*Close Graphics Driver*/
	 closegraph();
	}
void DrawFingers()
{
 setviewport(4,96,442,getmaxy()-71,0);
 /*Pl1hL*/
 for(int Count = 1, orX = 171, orY = 25; Count<=Pl1hL; Count++, orX-=45)
 {
  line(orX,orY,orX,orY+60);
  line(orX+30,orY,orX+30,orY+85);
  line(orX,orY+60,orX+30,orY+85);
  line(orX+10,orY+30,orX+10,orY+60);
  line(orX+10,orY+60,orX+30,orY+75);
 }
 /*Pl1hR*/
 for(Count = 1, orX= 221, orY=25; Count<=Pl1hR; Count++, orX+=45)
 {
  line(orX,orY,orX,orY+75);
  line(orX+30,orY,orX+30,orY+60);
  line(orX+20,orY+30,orX+20,orY+60);
  line(orX+20,orY+60,orX,orY+75);
  line(orX+10,orY+30,orX+20,orY+30);
  line(orX+30,orY+60,orX,orY+85);
 }


}
