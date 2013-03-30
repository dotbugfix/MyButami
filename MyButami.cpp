/*
                  NAME - MyButami™ Source©
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - Development Source-Code for MyButami™ Game
        COMPAITIBILITY - Borland Turbo C++ IDE (Compilation)
                         DOS or similar Environment Shell
             COPYRIGHT - *Not decided by the Authors*
               VERSION - v0.9.3 BETA
             DATE/TIME - 29/03/07 17:41
VERSION SPECIFICATIONS - Improved Progress Bar
            KNOWN BUGS - Back-compaitible to v0.8.x League
                         Quit() needs attention!
                         Adapting MyButami™ Source© with GUI : IN PROGRESS
        NEXT BIG THING - v0.9.x BETA improves Basic GUI, implementing Graphics Drivers
                         Adapt MainMenu to MyButami™ GUI

*/

#include "Header.h"                                 //Custom MyButami™ Source© Header v1.0

short unsigned int Pl1hL=1,Pl1hR=1,Pl2hL=1,Pl2hR=1; //No. of fingers of each hand of each player
short unsigned int *ActvhL, *ActvhR;                //Virtual: No. of fingers of each hand of Active Player
short unsigned int *nActvhL, *nActvhR;              //Virtual: No. of fingers of each hand of Other Player
char SelIN,SelOUT;                                  //Sectect Input hand (L/R) & Output hand (a/b/c)
short unsigned int Chance;                          //Chance goes to: values 1 & 2
char CharChoice;                                    //Character type Choice to opt for different fn()s
char Pl1Name[15]="Player 1";                        //Player1 Name
char Pl2Name[15]="Player 2";                        //Player2 Name
char ActvPl[15];                                    //Name of the active player
//******************************************************************************End Of Global Variables
void Intro();                                       //Intro Display - Logo & Progress
void MainMenu();                                    //Main-Menu of the game with global options/settings
void Process();                                     //Game Play till End Condition is reached
void Status();                                      //Defualt DISPLAY with clrscr()
void Player1();                                     //Chance to Player1
void Player2();                                     //Chance to Player2
void ActvPlayer();                                  //Decides the active player's name and attributes
void ChangeChance();                                //Inverts Chance for compatibility in main()
void ChoiceMenu();                                  //The Menu for selection of Input/Output without clrscr()
void Barring();                                     //Barring of hand having >=5 Fingers
void Cancellation();                                //Cancellation of even no. of fingers to the least
void Splitting();                                   //Splitting of one hand into two for even no. of fingers
void Quit();                                        //Quit of the game-play by User
int EndGame();                                      //Check ALL Game Over conditions and Exit
//******************************************************************************End Of Function Prototypes

//******************************************************************************End of Preprocessor Directives

void main()
{
  clrscr();
  Intro();
  MainMenu();
  cout<<"\n\n\t***Player names***\n\n";
  cout<<"\n\t\t(If you can't wait to Play, press Esc.: Default names will be selected)";
  if(getch()==27)                                                               //ASCII Code for ESC Key
	 {
      cout<<"\nDefault names selected!\n";
	  delay(1500);
	  goto start;
	 }
 else
     {
	  cout<<"\n\nPlayer 1 : Please enter your name : ";
	  cin>>Pl1Name;
	  cout<<"\nPlayer 2 : Please enter your name : ";
	  cin>>Pl2Name;
  	  cout<<"\nThank you!\n";
      delay(1000);
	 }
 start:
	 cout<<"\nPress Q any time in the game-play to Quit";
     cout<<"\n\n\nLoading MyButami...";
     delay(750);
     Chance=1;                                                                  //Initiating Change to Player1
     ActvPlayer();                                                              //Initiating Game-Play
 	 getch();                                                                   //Prevent Auto-Close in Shell Environment
}

//******************************************************* End Of main() Function

//*********************************************************** Function: Intro() <----
void Intro()
{
 int gdriver = DETECT, gmode;
	 initgraph(&gdriver,&gmode,"");
 settextstyle(2,0,6);
	 outtextxy(520,55,"TM");                                                    //LogoUpperRight TM Sign
 settextstyle(2,0,6);
	outtextxy(418,138,"v0.9.3 BETA");                                           //LogoBottomRight Version
 settextstyle(4,0,9);
	outtextxy(115,40,"MyButami");                                               //MyButami™ Logo (Gothic Font)
							                     /*Begin PseudoLoading Dialog*/
 setviewport(115,200,520,220,0);
 settextjustify(CENTER_TEXT,CENTER_TEXT);
 settextstyle(2,0,6);
	outtextxy(205,10,"Checking System Compaitibility...");
	delay(1250);
	clearviewport();
	outtextxy(205,10,"LOADING... Graphics Drivers");
	delay(1150);
 setviewport(0,0,getmaxx(),getmaxy(),1);                                        //Display REAL Graphics Info
 rectangle(210,260,425,380);
 rectangle(213,263,422,377);
 setviewport(213,263,422,377,0);
 settextjustify(LEFT_TEXT,LEFT_TEXT);
	outtextxy(5,20,"Your Graphics Config:");
	line(5,27,195,27);
	outtextxy(5,50,"Init : ");
	outtextxy(64,50,grapherrormsg(graphresult()));
	outtextxy(5,75,"Driver : ");
	outtextxy(86,75,getdrivername());
	outtextxy(5,100,"Mode : ");
	outtextxy(67,100,getmodename(getgraphmode()));
 setviewport(115,200,520,220,0);
 settextjustify(CENTER_TEXT,CENTER_TEXT);                                       //Continue PseudoLoading
 settextstyle(2,0,6);
	delay(950);
	clearviewport();
	outtextxy(205,10,"LOADING... Core Components");
	delay(1700);
	clearviewport();
	outtextxy(205,10,"LOADING... DLLs");
	delay(600);
	clearviewport();
	outtextxy(205,10,"LOADING... Documentation");
	delay(750);
	clearviewport();
	outtextxy(205,10,"LOADING... User Interface");
	delay(1250);
	clearviewport();
	outtextxy(205,10,"Starting MyButami, Please Wait...");
 setviewport(0,420,getmaxx(),getmaxy(),0);                                      //Display Progress Bar at bottom
 for(int Unit=20;Unit<=600;Unit+=8)
		{
		 randomize();
		 int time=rand()%100;
		 outtextxy(Unit,0,"Û");
		 delay(time);
		}
 getch();
 closegraph();                                                                  //Close Graphics Driver
}

//******************************************************** Function: MainMenu() <----
void MainMenu()
{
 clrscr();
 cout<<"\t\t\t\t*** MAIN MENU ***";
 cout<<"\n\n1.START Game\n2.Instructions\n3.Credits\n4.Quit\n\nPlease select your choice: ";
 cin>>CharChoice;
 switch(CharChoice)
    {
     case '1':cout<<"\n\n\nYou may press 'Q' at anytime during gameplay to quit!\n\nStarting game, please wait...";
              delay(2000);
              clrscr();
              IntroCase1:
              cout<<"\n\nPlease take note that you are running an BETA Release of MyButami and are subject to its obligations. We cannot guaruntee compaitibility with your hardware, and this software may crash with non-standard configurations. We expect for better compaitibility in future versions. If you accept, please type Y or type Q to EXIT now...";
              cin>>CharChoice;
              if(CharChoice=='Q')
                Quit();
              else if(CharChoice=='Y')                                          //User must READ above notice for proper response!
                return;
              else
                goto IntroCase1;
              break;
     case '2':cout<<"\n\nLoading Instructions...";
              delay(1500);
              clrscr();
              cout<<"\n\t\t\t\t*** INSTRUCTIONS ***";
              cout<<"\n\nMyButami is designed to be user-friendly in all possible manners. The default input being your Keyboard, all possible inputs are displayed in the User Interface at any time.\nThe Graphical User Interface (GUI) is applicable for Player Status only, and all functions are displayed in the form of menus. You are expected to enter the corresponding letter for your desired choice as per this menu.";
              cout<<"There are no control keys for MyButami as such, and the game is driven my a Menu-based User Interface.";
              cout<<"\n\n\n\t\t\t\t  *** OBJECTIVE ***";
              cout<<"\nAs mentioned in the Credits, MyButami was originally conceptualized for manual play, and has later been adapted to a Computer Interface. The object of this game can be explain briefly as follows:";
              cout<<"Each Player had 2 hands of 5 fingers each, which is represented in the GUI as follows:";
              cout<<"\n\n<IMAGE>\n\n";
              cout<<"Each player starts with 1 finger on each hand. When its your Chance, you can give fingers of any hand (of yours) to any other hand (of yours or opponent's). When you do that, the no. of fingers that were present on the selected hand will get added to the next hand.";
              cout<<"\n\n--->Any of the hands get barred if it holds 5 or more fingers at any time! <---";
              cout<<"\n\n--->The OBJECT of the game is to bar both hands of your opponent before he does! <---";
              cout<<"\n\n* Cancellation *\nIf you have even no. of fingers on BOTH your hands, then you may opt for cancellation which will reduce them by multiples of 2. Cancellation is optional, and it costs one Chance to pass fingers. You will be prompted for Cancellation whenever applicable during Game-Play to which you may accept or deny.";
              cout<<"\n\n* Splitting *\nIn case you have only 1 hand left (the other has been barred), and it holds EVEN no. of fingers, then you may opt for splitting, which will revive your other hand, each having half the no. of fingers available. Splitting is optional, and it costs one Chance to pass fingers. You will be prompted for Splitting whenever applicable during Game-Play to which you may accept or deny.";
              cout<<"\n\n\nWe hope you will enjoy playing MyButami - you may bring up this HELP screen anytime during Game-Play by pressing F1";
              cout<<"\n\n\nPress any key to continue to Main Menu...";
              getch();
              MainMenu();
              break;
     case '3':getch();                                                          //Credits Scrolling Pending!!!
              break;
     case '4':Quit();
              break;
     default:cout<<"\n\nInvalid option! Try Again...";
             delay(1500);
             MainMenu();
    }
    MainMenu();                                                                 //Keep MainMenu after break;
}


//******************************************************** Function: Process()  <----
void Process()
{
 for(EndGame();EndGame()==1;)                                                   //Continue till EndGame Condition Reached
     {
        if((*ActvhL==0 && *ActvhR==4) || (*ActvhL==4 && *ActvhR==0))
              Splitting();
        else if((*ActvhL==2 && *ActvhR==0) || (*ActvhL==0 && *ActvhR==2))
              Splitting();
        if((*ActvhL==2 && *ActvhR==2) || (*ActvhL==4 && *ActvhR==4))
             Cancellation();
  errorcorrect:
        ChoiceMenu();                                                           //Only DISPLAY the menu
        switch(SelOUT)                                                          //Toggle Input from ChoiceMenu()
                {
                 case 'R':if(SelIN=='L')
					           *nActvhR+=*ActvhL;
                          else
                               *nActvhR+=*ActvhR;
                          break;
                 case 'L':if(SelIN=='L')
                               *nActvhL+=*ActvhL;
                          else
                               *nActvhL+=*ActvhR;
                          break;
                 case 'O':if(SelIN=='L')
                               *ActvhR+=*ActvhL;
                          else
                               *ActvhL+=*ActvhR;
                          break;
                 default:cout<<"\n\nInvalid option! please try again...";
                         delay(950);
                         clrscr();
                         Status();
                         goto errorcorrect;
                }
        Barring();                                                              //Check Hand Barring Condition
        ChangeChance();                                                         //Initialize Next Round
     }
}

//****************************************************** Function: ActvPlayer() <----

void ActvPlayer()
{
 if(Chance==1)                                                                  //Initialize Player1
    {
     strcpy(ActvPl, Pl1Name);
     ActvhL=&Pl1hL;
     ActvhR=&Pl1hR;
     nActvhL=&Pl2hL;
     nActvhR=&Pl2hR;

    }
 else                                                                           //Initialize Player2
    {
     strcpy(ActvPl, Pl2Name);
     ActvhL=&Pl2hL;
     ActvhR=&Pl2hR;
     nActvhL=&Pl1hL;
     nActvhR=&Pl1hR;
    }

 Status();
 Process();

}

//********************************************************** Function: Status() <----

void Status()
{
 clrscr();
 cout<<"    "<<Pl1Name<<"\nLEFT\tRIGHT\n"<<Pl1hL<<"\t"<<Pl1hR;
 cout<<"\n\n"<<Pl2hL<<"\t"<<Pl2hR<<"\nLEFT\tRIGHT\n    "<<Pl2Name;
 cout<<"\n\nChance of ---> "<<ActvPl;
}

//****************************************************** Function: ChoiceMenu() <----

void ChoiceMenu()
{
 cout<<"\n\nCHOICE MENU Function!";
 if(*ActvhL==0)
    {
     cout<<"\n\nYour RIGHT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else if(*ActvhR==0)
    {
     cout<<"Your LEFT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else
    {
     cout<<"\n\nSelect which hand you wish to play with (L/R) :";
     SelIN=getche();                                                            //This input is toggled in Process()
     if(SelIN=='Q')
        Quit();

     else if(SelIN!='R' && SelIN!='L' && SelIN!='Q')
        {
         cout<<"\n\nInvalid option! please try again...";
         delay(1050);
         clrscr();
         Status();
         ChoiceMenu();
        }
     else
        cout<<"\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
     }
 SelOUT=getche();                                                               //This input is toggled in Process()
 if(SelOUT=='Q')
    Quit();
 else if(SelOUT!='R' && SelOUT!='L' && SelOUT!='O' && SelOUT!='Q')
        {
         cout<<"\n\nInvalid option! please try again...";
         delay(1050);
         clrscr();
         Status();
         ChoiceMenu();
        }
}


//**************************************************** Function: Cancellation() <----

void Cancellation()
{
 cout<<"\n\nDo you want to opt for Cancellation? (Y/N) :";
 CharChoice=getche();
 if(CharChoice=='Y')
    {
     cout<<"Cancelling...";
     delay(500);
     if(*ActvhR==2 && *ActvhL==2)
        {
         *ActvhR=1;
         *ActvhL=1;
        }
     if(*ActvhR==4 && *ActvhL==4)
        {
         *ActvhR=2;
         *ActvhL=2;
        }
     cout<<"\nCancellation has been done!";
     ChangeChance();
    }
 else if(CharChoice=='N')
    return;
 else
    {
     cout<<"Invalid choice! Try again!";
     getch();
     Cancellation();
    }
 Process();                                                                     //Return to normal Game Play
}

//**************************************************** Function: ChangeChance() <----

void ChangeChance()
{
 if(Chance==1)
    Chance=2;
 else
    Chance=1;
 ActvPlayer();
}

//********************************************************* Function: Barring() <----

void Barring()
{
 if(*ActvhL>=5)
    *ActvhL=0;
 if(*ActvhR>=5)
    *ActvhR=0;
 if(*nActvhL>=5)
    *nActvhL=0;
 if(*nActvhR>=5)
    *nActvhR=0;
}

//******************************************************* Function: Splitting() <----

void Splitting()
{
 cout<<"\n\nDo you want to opt for Splitting? (Y/N) :";
 CharChoice=getche();
 if(CharChoice=='Y')
    {
     cout<<"Splitting...";
     delay(500);
     if((*ActvhR==0 && *ActvhL==4) || (*ActvhR==4 && *ActvhL==0))
        {
         *ActvhR=2;
         *ActvhL=2;
        }
     if((*ActvhR==0 && *ActvhL==2) || (*ActvhR==2 && *ActvhL==0))
        {
         *ActvhR=1;
         *ActvhL=1;
        }
     cout<<"\n\nSplitting of hands has been done!";
     ChangeChance();
    }
 else if(CharChoice=='N')
    return;
 else
    {
     cout<<"Invalid choice! Try again!";
     getch();
     Splitting();
    }
 Process();                                                                     //Return to normal Game Play
}
//************************************************************ Function: Quit() <----
void Quit()
{
 cout<<"\n\nYou chose to Quit the game. Are you sure? (Y/N): ";
 CharChoice=getche();
 if(CharChoice=='Y')
    {
     cout<<"\n\nThank you for playing MyButami!";
     cout<<"\nQuiting...";
     delay(2000);
     exit(0);
    }
 else if(CharChoice=='N')
    {
     return;
    }
 else
    {
     cout<<"Invalid choice! Try again! quit walla";
     delay(950);
     Quit();
    }
}

//********************************************************* Function: EndGame() <----

int EndGame()
{
 if(Pl1hL==0 && Pl1hR==0)
    exit(0);
 if(Pl2hL==0 && Pl2hR==0)
    exit(0);
 return 1;
}

//****************************************************************************** END OF PROGRAM
