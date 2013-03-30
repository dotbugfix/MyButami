/*Butami v0.5 ALPHA Release (18/JAN/2007)*/
#include <iostream.h>
#include <conio.h>
#include <process.h>

short unsigned int Pl1hL=1,Pl1hR=1,Pl2hL=1,Pl2hR=1; //No. of fingers of each hand of each player
char SelIN,SelOUT;                                  //Sectect Input hand (L/R) & Output hand (a/b/c)
short unsigned int chance;                          //Chance goes to: values 1 & 2
char ChoiceCan;                                     // Choice to opt for cancellation (See Below)
//***************************End Of Global Variables
void process();                                     // Game Play till End Condition is reached
void status();                                      //Defualt DISPLAY with clrscr()
void Player1();                                     //Chance to Player1
void Player2();                                     //Chance to Player2
void ChangeChance();                                //Inverts Chance for compatibility in main()
void ChoiceMenuPl1();                               //Player1's Menu for selection of Input/Output without clrscr()
void ChoiceMenuPl2();                               //Player2's Menu for selection of Input/Output without clrscr()
int EndGame();                                      //Check ALL Game Over conditions and Exit
void Barring();                                     //Barring of hand having >=5 Fingers
void Cancellation();                                //Cancellation of even no. of fingers to the least
//***************************End Of Function Prototypes

//***************************End of Preprocessor Directives

void main()
{
     clrscr();
     cout<<"Butami v0.5 ALPHA Release";
     status();
     chance=1;
     process();
     getch();
}

//***************************End Of main() Function

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

//***************************Function: status()    <----

void status()
{
 clrscr();
 cout<<"    Player 1\nLEFT\tRIGHT\n"<<Pl1hL<<"\t"<<Pl1hR;
 cout<<"\n\n"<<Pl2hL<<"\t"<<Pl2hR<<"\nLEFT\tRIGHT\n    Player2";
}

//***************************Function: Player1()   <----

void Player1()
{
 cout<<"\n\nChance of ---> PLAYER 1";
 if((Pl1hR==2 && Pl1hL==2) || (Pl1hR==4 && Pl1hL==4))
    Cancellation();
 ChoiceMenuPl1();
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
 cout<<"\n\nChance of ---> PLAYER 2";
 if((Pl2hR==2 && Pl2hL==2) || (Pl2hR==4 && Pl2hL==4))
    Cancellation();
 ChoiceMenuPl2();
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

//***************************Function: ChoiceMenuPl1()   <----

void ChoiceMenuPl1()
{
 cout<<"\n\nCHOICE MENU Function!";
 if(Pl1hL==0)
    {
     cout<<"\n\nYour RIGHT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else if(Pl1hR==0)
    {
     cout<<"Your LEFT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else
    {
     cout<<"\n\nSelect which hand you wish to play with (L/R) :";
     cin>>SelIN;
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 cin>>SelOUT;
}

//***************************Function: ChoiceMenuPl2()   <----

void ChoiceMenuPl2()
{
 cout<<"\n\nCHOICE MENU Function!";
 if(Pl2hL==0)
    {
     cout<<"\n\nYour RIGHT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else if(Pl2hR==0)
    {
     cout<<"Your LEFT hand is selected!";
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 else
    {
     cout<<"\n\nSelect which hand you wish to play with (L/R) :";
     cin>>SelIN;
     cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 cin>>SelOUT;
}

//***************************Function: Cancellation()   <----

void Cancellation()
{
 cout<<"\n\nDo you want to opt for Cancellation? (Y/N) :";
 cin>>ChoiceCan;
 if(ChoiceCan=='Y')
    {
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
 else
    return;
 process(); //Return to normal Game Play
}

//***************************Function: ChangeChance()   <----

void ChangeChance()
{
 if(chance==1)
    chance=2;
 else
    chance=1;
 status();
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
