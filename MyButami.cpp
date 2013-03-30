/*Butami v0.6.5 ALPHA Release 28-01-07 19:44 using delay()*/
/*                                       *** Improving Player Name statement*/

#include <iostream.h>
#include <conio.h>
#include <process.h>
#include <dos.h>

short unsigned int Pl1hL=1,Pl1hR=1,Pl2hL=1,Pl2hR=1; //No. of fingers of each hand of each player
char SelIN,SelOUT;                                  //Sectect Input hand (L/R) & Output hand (a/b/c)
short unsigned int chance;                          //Chance goes to: values 1 & 2
char ChoiceCan;                                     //Choice to opt for cancellation (See Below)
char ChoiceSpl;                                     //Choice to opt for Splitting of hand
char ChoiceQuit;                                    //Choice to Quit the game-play
char *Pl1Name="Player 1", *Pl2Name="Player 2";      //Player Names
char *Pl1=" ", *Pl2=" ";                            //Player Names if not default
//***************************End Of Global Variables
void process();                                     //Game Play till End Condition is reached
void status();                                      //Defualt DISPLAY with clrscr()
void Player1();                                     //Chance to Player1
void Player2();                                     //Chance to Player2
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
	 cout<<"Butami v0.6.5 ALPHA Release";
	 //cout<<"\n\n<ESSAY>";
	 cout<<"\n\n\t***Player names***\n\n";
	 delay(500);
	 cout<<"\n\tPress any key to proceed.";
	 cout<<"\n\t(To ignore this, press Esc. Default names will be selected)";
	 if(getch()==27)
	 {
      cout<<"\nDefault names selected!\n";
	  delay(1500);
	  goto start;
	 }
	 else
	 {
      Pl1=" (Player 1)", Pl2=" (Player 2)";
	  cout<<"\n\nPlayer 1 : Please enter your name : ";
	  cin>>Pl1Name;
	  cout<<"\nPlayer 2 : Please enter your name : ";
	  cin>>Pl2Name;
	  delay(1000);
	  cout<<"\nThank you!\n";
	 }
start:
	 cout<<"\nPress Q any time in the game-play to Quit";
     cout<<"\nThe game begins...";
     delay(750);
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
 cout<<"    "<<Pl1Name<<"\nLEFT\tRIGHT\n"<<Pl1hL<<"\t"<<Pl1hR;
 cout<<"\n\n"<<Pl2hL<<"\t"<<Pl2hR<<"\nLEFT\tRIGHT\n    "<<Pl2Name;
}

//***************************Function: Player1()   <----

void Player1()
{
 cout<<"\n\nChance of ---> "<<Pl1Name<<Pl1;
 if((Pl1hR==2 && Pl1hL==2) || (Pl1hR==4 && Pl1hL==4))
    Cancellation();
 if((Pl1hR==0 && Pl1hL==4) || (Pl1hR==4 && Pl1hL==0) || (Pl1hR==2 && Pl1hL==0) || (Pl1hR==0 && Pl1hL==2))
    Splitting();
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
 cout<<"\n\nChance of ---> "<<Pl2Name<<Pl2;
 if((Pl2hR==2 && Pl2hL==2) || (Pl2hR==4 && Pl2hL==4))
    Cancellation();
 if((Pl2hR==0 && Pl2hL==4) || (Pl2hR==4 && Pl2hL==0) || (Pl2hR==2 && Pl2hL==0) || (Pl2hR==0 && Pl2hL==2))
    Splitting();
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
        return;
        cout<<"\nSelect TO WHICH hand you wish to pass fingers :\na.Your OTHER hand (O)\nb.Other's RIGHT hand (R)\nc.Other's LEFT hand (L)\n\nYour Choice:";
    }
 cin>>SelOUT;
 if(SelOUT=='Q')
    Quit();
 else
    return;
}


//***************************Function: Cancellation()   <----

void Cancellation()
{
 cout<<"\n\nDo you want to opt for Cancellation? (Y/N) :";
 cin>>ChoiceCan;
 if(ChoiceCan=='Y')
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
 else if(ChoiceCan=='N')
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

//***************************Function: Splitting()      <---- ADDED NEWLY

void Splitting()
{
 cout<<"\n\nDo you want to opt for Splitting? (Y/N) :";
 cin>>ChoiceSpl;
 if(ChoiceSpl=='Y')
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
 else if(ChoiceSpl=='N')
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
 cin>>ChoiceQuit;
 if(ChoiceQuit=='Y')
    {
     cout<<"\n\nThank you for playing Butami!";
     cout<<"\nQuiting...";
     delay(2000);
     exit(0);
    }
 else if(ChoiceQuit=='N')
    ChoiceMenu();
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
