/*
                  NAME - MyButami™
               AUTHORS - Omkar Ekbote & Swaroop Bhonde
           DESCRIPTION - Simple Butami Game
             COPYRIGHT - *Not decided by the Authors*
               VERSION - v0.7.5 ALPHA Release
             DATE/TIME - 05/02/07 21:17
VERSION SPECIFICATIONS - Added Main Menu (Improved UI)
                         Improved pre-procedure
                         Added ActvPlayer() (ara AP)
                         * ActvPl for name of AP
                         * ActvhR and ActvhL for hands of AP
                         * Cancellation() and \Splitting()\
            KNOWN BUGS - Splitting() does not work!!!
                         Cancellation() condition is buggy!
                         Quit() does not return to Main Menu when prompted 'N'
        NEXT BIG THING - Truncate Player1() & Player2() to ActvPlayer();

*/

#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <dos.h>
#include <string.h>

short unsigned int Pl1hL=1,Pl1hR=1,Pl2hL=1,Pl2hR=1; //No. of fingers of each hand of each player
short unsigned int ActvhL, ActvhR;                  //No. of fingers of each hand of Active Player
char SelIN,SelOUT;                                  //Sectect Input hand (L/R) & Output hand (a/b/c)
short unsigned int chance;                          //Chance goes to: values 1 & 2
char CharChoice;                                    //Character type Choice to opt for different fn()s
char Pl1Name[15]="Player 1";                        //Player1 Name
char Pl2Name[15]="Player 2";                        //Player2 Name
char ActvPl[15];                                    //Name of the active player
//***************************End Of Global Variables
void Intro();                                       //Main-menu of the Game for Intro and Help
void process();                                     //Game Play till End Condition is reached
void status();                                      //Defualt DISPLAY with clrscr()
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
//***************************End Of Function Prototypes

//***************************End of Preprocessor Directives

void main()
{
  clrscr();
	 cout<<"Butami v0.7.4 ALPHA Release";
	 cout<<"\n\nWelcome to MyButami: A game of intellect, logic and combination!\nThe version of MyButami you are running is in ALPHA Development mode and it may contain several bugs. Kindly co-operate by reporting these bugs to us!";
     cout<<"\n\nPress any key to start the game NOW or press Q to exit!";
     if(getche()=='Q')
        Quit();
     else
        Intro();
     cout<<"\n\n\t***Player names***\n\n";
 	 cout<<"\n\t\t(If you can't wait to Play, press Esc.: Default names will be selected)";
	 if(getch()==27)
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
	  delay(1000);
	  cout<<"\nThank you!\n";
	 }
start:
	 cout<<"\nPress Q any time in the game-play to Quit";
     cout<<"\n\n\nLoading MyButami...";
     delay(750);
     //status();
	 chance=1;
     ActvPlayer();
	 process();
	 getch();
}

//***************************End Of main() Function

//***************************Function: Intro()   <----
void Intro()
{
 clrscr();
 cout<<"\t\t\t\t\t*** MAIN MENU ***";
 cout<<"\n\n1.START Game\n2.Instructions\n3.Credits\n4.Quit\n\nPlease select your choice: ";
 cin>>CharChoice;
 switch(CharChoice)
    {
     case '1':cout<<"\n\n\nYou may press 'Q' at anytime during gameplay to quit!\n\nStarting game, please wait...";
              delay(2000);
              clrscr();
              IntroCase1:
              cout<<"\n\nPlease take note that you are running an ALPHA Release of MyButami and are subject to its obligations. We cannot guaruntee compaitibility with your hardware, and this software may crash with non-standard configurations. We expect for better compaitibility in future versions. If you accept, please type Y or type Q to EXIT now...";
              cin>>CharChoice;
              if(CharChoice=='Q')
                Quit();
              else if(CharChoice=='Y')
                break;
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
              cout<<"Each player starts with 1 finger on each hand. When its your chance, you can give fingers of any hand (of yours) to any other hand (of yours or opponent's). When you do that, the no. of fingers that were present on the selected hand will get added to the next hand.";
              cout<<"\n\n--->Any of the hands get barred if it holds 5 or more fingers at any time! <---";
              cout<<"\n\n--->The OBJECT of the game is to bar both hands of your opponent before he does! <---";
              cout<<"\n\n* Cancellation *\nIf you have even no. of fingers on BOTH your hands, then you may opt for cancellation which will reduce them by multiples of 2. Cancellation is optional, and it costs one chance to pass fingers. You will be prompted for Cancellation whenever applicable during Game-Play to which you may accept or deny.";
              cout<<"*\n\n* Splitting *\nIn case you have only 1 hand left (the other has been barred), and it holds EVEN no. of fingers, then you may opt for splitting, which will revive your other hand, each having half the no. of fingers available. Splitting is optional, and it costs one chance to pass fingers. You will be prompted for Splitting whenever applicable during Game-Play to which you may accept or deny.";
              cout<<"\n\n\nWe hope you will enjoy playing MyButami - you may bring up this HELP screen anytime during Game-Play by pressing F1";
              cout<<"\n\n\nPress any key to continue to Main Menu...";
              getch();
              Intro();
              break;
     case '3':          //Credits Scrolling Pending!!!
              break;
     case '4':Quit();
              break;
     default:cout<<"\n\nInvalid option! Try Again...";
             delay(1500);
             Intro();
    }
}


//***************************Function: process()   <----
void process()
{
 for(EndGame();EndGame()==1;)
     {
        if(chance==1)
           {
            Player1();
            Barring();
           }
         else
           {
            Player2();
            Barring();
           }
        status();
     }
}

//***************************Function: ActvPlayer()    <----

void ActvPlayer()
{
 if(chance==1)
    {
     strcpy(ActvPl, Pl1Name);
     ActvhL=Pl1hL;
     ActvhR=Pl1hR;

    }
 else
    {
     strcpy(ActvPl, Pl2Name);
     ActvhL=Pl2hL;
     ActvhR=Pl2hR;
    }

 status();
 if((ActvhL==0 && ActvhR==4) || (ActvhL==4 && ActvhR==0) || (ActvhL==2 && ActvhR==0) || (ActvhL==0 && ActvhR==2))
    Splitting();
 if((ActvhL=ActvhR==2) || (ActvhL=ActvhR==4))
    Cancellation();


}

//***************************Function: status()    <----

void status()
{
 clrscr();
 cout<<"    "<<Pl1Name<<"\nLEFT\tRIGHT\n"<<Pl1hL<<"\t"<<Pl1hR;
 cout<<"\n\n"<<Pl2hL<<"\t"<<Pl2hR<<"\nLEFT\tRIGHT\n    "<<Pl2Name;
 cout<<"\n\nChance of ---> "<<ActvPl;
}

//***************************Function: Player1()   <----

void Player1()
{
 //cout<<"\n\nChance of ---> "<<Pl1Name<<Pl1;
 /*if((Pl1hR==2 && Pl1hL==2) || (Pl1hR==4 && Pl1hL==4))
     Cancellation();
 if((Pl1hR==0 && Pl1hL==4) || (Pl1hR==4 && Pl1hL==0) || (Pl1hR==2 && Pl1hL==0) || (Pl1hR==0 && Pl1hL==2))
    Splitting(); */
 ChoiceMenu();
 switch(SelOUT)
    {
      case 'R':if(SelIN=='L')
                Pl2hR+=Pl1hL;
              else
                Pl2hR+=Pl1hR;
              break;
     case 'L':if(SelIN=='L')
                Pl2hL+=Pl1hL;
              else
                Pl2hL+=Pl1hR;
              break;
     case 'O':if(SelIN=='L')
                Pl1hR+=Pl1hL;
              else
                Pl1hL+=Pl1hR;
              break;
    }
 ChangeChance();
}

//***************************Function: Player2()   <----

void Player2()
{
 //cout<<"\n\nChance of ---> "<<Pl2Name<<Pl2;
 /*if((Pl2hR==2 && Pl2hL==2) || (Pl2hR==4 && Pl2hL==4))
    Cancellation();
 if((Pl2hR==0 && Pl2hL==4) || (Pl2hR==4 && Pl2hL==0) || (Pl2hR==2 && Pl2hL==0) || (Pl2hR==0 && Pl2hL==2))
    Splitting(); */
 ChoiceMenu();
 switch(SelOUT)
    {
     case 'R':if(SelIN=='L')
                Pl1hR+=Pl2hL;
              else
                Pl1hR+=Pl2hR;
              break;
     case 'L':if(SelIN=='L')
                Pl1hL+=Pl2hL;
              else
                Pl1hL+=Pl2hR;
              break;
     case 'O':if(SelIN=='L')
                Pl2hR+=Pl2hL;
              else
                Pl2hL+=Pl2hR;
              break;
    }
 ChangeChance();
}

//***************************Function: ChoiceMenu()   <----

void ChoiceMenu()
{
 cout<<"\n\nCHOICE MENU Function!";
 if(((chance==1) && (Pl1hL==0)) || ((chance==2) && (Pl2hL==0)))
    {
     cout<<"\n\nYour RIGHT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else if(((chance==1) && (Pl1hR==0)) || ((chance==2) && (Pl2hR==0)))
    {
     cout<<"Your LEFT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else
    {
     cout<<"\n\nSelect which hand you wish to play with (L/R) :";
     cin>>SelIN;
     if(SelIN=='Q')
        Quit();
     else
        cout<<"\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
     }
 cin>>SelOUT;
 if(SelOUT=='Q')
    Quit();
 //else
   // return;
}


//***************************Function: Cancellation()   <----

void Cancellation()
{
 cout<<"\n\nDo you want to opt for Cancellation? (Y/N) :";
 cin>>CharChoice;
 if(CharChoice=='Y')
    {
     cout<<"Cancelling...";
     delay(500);
     if(Pl1hR==2 && Pl1hL==2)
        {
         Pl1hR=1;
         Pl1hL=1;
        }
     if(Pl1hR==4 && Pl1hL==4)
        {
         Pl1hR=2;
         Pl1hL=2;
        }
     if(Pl2hR==2 && Pl2hL==2)
        {
         Pl2hR=1;
         Pl2hL=1;
        }
     if(Pl2hR==4 && Pl2hL==4)
        {
         Pl2hR=2;
         Pl2hL=2;
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
 process(); //Return to normal Game Play
}

//***************************Function: ChangeChance()   <----

void ChangeChance()
{
 if(chance==1)
    chance=2;
 else
    chance=1;
 ActvPlayer();
 //status();
}

//***************************Function: Barring()        <----

void Barring()
{
 if(Pl1hL>=5)
    Pl1hL=0;
 if(Pl1hR>=5)
    Pl1hR=0;
 if(Pl2hL>=5)
    Pl2hL=0;
 if(Pl2hR>=5)
    Pl2hR=0;
}

//***************************Function: Splitting()      <---- ADDED NEWLY

void Splitting()
{
 cout<<"\n\nDo you want to opt for Splitting? (Y/N) :";
 cin>>CharChoice;
 if(CharChoice=='Y')
    {
     cout<<"Splitting...";
     delay(500);
     if((Pl1hR==0 && Pl1hL==4) || (Pl1hR==4 && Pl1hL==0))
        {
         Pl1hR=2;
         Pl1hL=2;
        }
     if((Pl1hR==2 && Pl1hL==0) || (Pl1hR==0 && Pl1hL==2))
        {
         Pl1hR=1;
         Pl1hL=1;
        }
     if((Pl2hR==0 && Pl2hL==4) || (Pl2hR==4 && Pl2hL==0))
        {
         Pl2hR=2;
         Pl2hL=2;
        }
     if((Pl2hR==2 && Pl2hL==0) || (Pl2hR==0 && Pl2hL==2))
        {
         Pl2hR=1;
         Pl2hL=1;
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
 process(); //Return to normal Game Play
}
//***************************Function: Quit()        <----
void Quit()
{
 cout<<"\n\nYou chose to Quit the game. Are you sure? (Y/N): ";
 cin>>CharChoice;
 if(CharChoice=='Y')
    {
     cout<<"\n\nThank you for playing Butami!";
     cout<<"\nQuiting...";
     delay(2000);
     exit(0);
    }
 else if(CharChoice=='N')
    {
     status();
     ChoiceMenu();
    }
 else
    {
     cout<<"Invalid choice! Try again!";
     getch();
     Quit();
    }
}

//***************************Function: EndGame()        <----

int EndGame()
{
 if(Pl1hL==0 && Pl1hR==0)
    exit(0);
 if(Pl2hL==0 && Pl2hR==0)
    exit(0);
 return 1;
}

/***************************    END OF PROGRAM */
