/*Butami v0.2 ALPHA Release (18/JAN/2007)*/
#include <iostream.h>
#include <conio.h>
#include <process.h>

short unsigned int Pl1hL=1,Pl1hR=1,Pl2hL=1,Pl2hR=1; //No. of fingers of each hand of each player
char SelIN,SelOUT; //Sectect Input hand (L/R) & Output hand (a/b/c)
short unsigned int chance; //Chance goes to: values 1 & 2
void status(); //Defualt DISPLAY with clrscr()
void Player1(); //Chance to Player1
void Player2(); //Chance to Player2
void ChoiceMenu();  //Menu for selection of Input/Output without clrscr()
int EndGame(); //Check ALL Game Over conditions and Exit
void Cancellation(); //Cancellation of hand having >=5 Fingers
void main()
{
     clrscr();
     cout<<"Butami v0.2 ALPHA Release";
     status();
     chance=1;
     for(EndGame();EndGame()==1;)
     {
        if(chance==1)
           {
            Player1();
            Cancellation();
           }
         else
           {
            Player2();
            Cancellation();
           }
        status();
     }
     getch();

}

void status()
{
 clrscr();
 cout<<"Player 1\nLEFT\tRIGHT\n"<<Pl1hL<<"\t"<<Pl1hR;
 cout<<"\n\n"<<Pl2hL<<"\t"<<Pl2hR<<"\nLEFT\tRIGHT\nPlayer2";
}

void Player1()
{
 cout<<"\n\nChance of ---> PLAYER 1";
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
 chance=2;
}

void Player2()
{
 cout<<"\n\nChance of ---> PLAYER 2";
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
 chance=1;
}

void ChoiceMenu()
{
 cout<<"\n\nCHOICE MENU Function!";
 cout<<"\n\nSelect which hand you wish to play with (L/R) :";
 cin>>SelIN;
 cout<<"\n\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
 cin>>SelOUT;
}

int EndGame()
{
 if(Pl1hL==0 && Pl1hR==0)
    exit(0);
 if(Pl2hL==0 && Pl2hR==0)
    exit(0);
 return 1;
}

void Cancellation()
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

