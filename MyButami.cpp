/*
                  NAME - MyButami™ GUI Module
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - GUI Development Module
             COPYRIGHT - *Not decided by the Authors*
			   VERSION - v0.9.3.3 BETA Development League
				MODULE - MyButami™ Graphics (GUI)
			 DATE/TIME - 31/03/07 14:20
VERSION SPECIFICATIONS - GUI Framework
						 Drawing all 8+8 Fingers
						 Generalizing for Source©
						 Added player names
                         Drawing Crosshair
			KNOWN BUGS - Under Active Development!
		NEXT BIG THING - N/A

*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>

unsigned short int Pl1hL = 1, Pl1hR = 1, Pl2hL = 1, Pl2hR = 1;
char Pl1Name[15], Pl2Name[15];

int orX, orY;
void DrawFingers();
void main()
	{
	 cout<<"Enter Player1 Name: ";
	 cin>>Pl1Name;
	 cout<<"Enter Player2 Name: ";
	 cin>>Pl2Name;
/*Auto-Detect & Initialize Graphics Drivers*/
	 int gdriver = DETECT, gmode;
	 initgraph(&gdriver,&gmode,"");
/*Draw Screen Border; Style:Double Line*/
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
	 outtextxy(368,49,"v0.9.3 BETA");        //LogoBottomRight Version
	 settextstyle(4,0,7);
	 outtextxy(180,-15,"MyButami");          //Logo
/*Write Player names*/
	 settextstyle(2,0,7);
	 outtextxy(381-(strlen(Pl1Name)*6),69,Pl1Name);                             //Print Player1 Name
	 outtextxy(70-(strlen(Pl2Name)*6),getmaxy()-68,Pl2Name);                    //Print Player2 Name
/*Draw Crosshair*/
     setlinestyle(1,1,1);
     setviewport(4,96,442,getmaxy()-71,0);
     line(219,104,219,206);
     line(168,155,270,155);
     setlinestyle(0,0,0);
/*Draw fingers*/
while(getch()!=27 && Pl1hL<5)
	{
	 DrawFingers();
	 Pl1hL++;
	 Pl1hR++;
	 Pl2hL++;
	 Pl2hR++;
	}
/*Create ActvWindows for Console I/O*/
	 window(58,8,77,25);
	 cout<<"Standard Functions";
	 window(58,24,77,25);
	 cout<<"Advanced Functions";
	 getch();
/*Close Graphics Driver*/
	 closegraph();
	}

void DrawFingers()                                                            //<---Function : DrawFingers()
{
 setviewport(4,96,442,getmaxy()-71,0);
                                                                       /*Pl1hL*/
 for(int Count = 1, orX = 169, orY = 25; Count<=Pl1hL; Count++, orX-=53)
 {
  line(orX,orY,orX,orY+60);
  line(orX+30,orY,orX+30,orY+75);
  line(orX,orY+60,orX+30,orY+85);
  line(orX+10,orY+30,orX+20,orY+30);
  line(orX+10,orY+30,orX+10,orY+60);
  line(orX+10,orY+60,orX+30,orY+75);
 }
                                                                       /*Pl1hR*/
 for(Count = 1, orX= 239, orY=25; Count<=Pl1hR; Count++, orX+=53)
 {
  line(orX,orY,orX,orY+75);
  line(orX+30,orY,orX+30,orY+60);
  line(orX+20,orY+30,orX+20,orY+60);
  line(orX+20,orY+60,orX,orY+75);
  line(orX+10,orY+30,orX+20,orY+30);
  line(orX+30,orY+60,orX,orY+85);
 }
                                                                       /*Pl2hL*/
 for(Count = 1, orX=169, orY=200; Count<=Pl2hL; Count++, orX-=53)
 {
  line(orX+30,orY+10,orX+30,orY+85);
  line(orX,orY+25,orX,orY+85);
  line(orX,orY+25,orX+30,orY);
  line(orX+10,orY+25,orX+30,orY+10);
  line(orX+10,orY+25,orX+10,orY+55);
  line(orX+10,orY+55,orX+20,orY+55);
 }
                                                                       /*Pl2hR*/
 for(Count = 1, orX=239, orY=200; Count<=Pl2hR; Count++, orX+=53)
 {
  line(orX,orY+10,orX,orY+85);
  line(orX+30,orY+25,orX+30,orY+85);
  line(orX,orY,orX+30,orY+25);
  line(orX,orY+10,orX+20,orY+25);
  line(orX+20,orY+25,orX+20,orY+55);
  line(orX+10,orY+55,orX+20,orY+55);
 }

}
