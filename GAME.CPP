#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
int play();
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();
void main()
{
clrscr();
clrscr();
cout<<"                                                                             \n";
cout<<"  лллллллллллл  ллл     млллллллм                                          \n";
cout<<"  лллллллллллл  ллл    лллллллллп                                           \n";
cout<<"      лллл      ллл   лллл                                                   \n";
cout<<"      лллл      ллл    ллллмммммм                                            \n";
cout<<"      лллл      ллл     ллллллллл                                            \n";
cout<<"                                                                             \n";
cout<<"                   лллллллллллл       ллллм        млллллллллл               \n";
cout<<"                   лллллллллллл      ллллллл      лллллллллллл              \n";
cout<<"                       лллл         ллллллллл    лллллп                      \n";
cout<<"                       лллл        лллл   лллл   лллллм                      \n";
cout<<"                       лллл       лллл     лллл   ллллллмммммм               \n";
cout<<"                       лллл      ллллллллллллллл   плллллллллл               \n";
cout<<"                                                                             \n";
cout<<"                                 ллллллллллл     мллллллллм    лллллллллллл  \n";
cout<<"                                 ллллллллллл   млллллллллллл   лллллппппппп  \n";
cout<<"                                    лллл      лллллп   пллллл  лллллммммммм  \n";
cout<<"                                    лллл      лллллм   мллллл  лллллппппппп  \n";
cout<<"                                    лллл       ллллллллллллл   лллллммммммм \n";
cout<<"                                    лллл        плллллллллп    лллллллллллл  \n";
cout<<"                                                                             \n";

window(15,22,80,25);
cout<<"Loading...";
window(15,23,80,25);
for(int i=0;i<50;i++)
{       delay(60);
	cout<<"л";
}
getch();
menu:
window(1,1,80,25);
int num;
clrscr();
cout<<"\n\n\n\t\t\tMAIN MENU\n";
cout<<"\t\t\t1.\tPlay Game\n";
cout<<"\t\t\t2.\tCredits\n";
cout<<"\t\t\t3.\tExit\n";
cout<<"\n\t\t\tEnter Your Choice\t:\t";
cin>>num;
switch(num){
case 1:
	play();
	break;
case 2:
	clrscr();
	cout<<"\n\n\n\t\t\tCREDITS\n";
	cout<<"\t\t\tVedant Mehta\n";
	cout<<"\t\t\tNikki Sharma\n";
	cout<<"\t\t\tAashna\n";
	cout<<"\t\t\tAnsh Gupta\n";
	getch();
	break;
case 3:
	exit(0);
	break;
default:
	cout<<"\n\n\t\t\tINVALID CHOICE!!!\n\t\t\tEnter again!";
	getch();
	break;
}
goto menu;
/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************/
}

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/

void board()
{
clrscr();
cout << "\n\n\tTic Tac Toe\n\n";
cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
cout << endl;
cout << "     Г     Г     " << endl;
cout << " " << square[1] << "   Г " << square[2] << "   Г " << square[3] << endl;
cout << "_____Г_____Г_____" << endl;
cout << "     Г     Г " << endl;
cout << " " << square[4] << "   Г " << square[5] << "   Г " << square[6] << endl;
cout << "_____Г_____Г_____" << endl;
cout << "     Г     Г " << endl;
cout << " " << square[7] << "   Г " << square[8] << "   Г " << square[9] << endl;
cout << "     Г     Г " << endl << endl;
}
int play()
{
 int player = 1,i,choice;
char mark;

 clrscr();
do
{
board();
player=(player%2)?1:2;
cout << "Player " << player << ", enter a number: ";
cin >> choice;
mark=(player == 1) ? 'X' : 'O';
if (choice == 1 && square[1] == '1')
square[1] = mark;
else if (choice == 2 && square[2] == '2')
square[2] = mark;
else if (choice == 3 && square[3] == '3')
square[3] = mark;
else if (choice == 4 && square[4] == '4')
square[4] = mark;
else if (choice == 5 && square[5] == '5')
square[5] = mark;
else if (choice == 6 && square[6] == '6')
square[6] = mark;
else if (choice == 7 && square[7] == '7')
square[7] = mark;
else if (choice == 8 && square[8] == '8')
square[8] = mark;
else if (choice == 9 && square[9] == '9')
square[9] = mark;
else
{
cout<<"Invalid move ";
player ;
getch();
}

i=checkwin();
player++;
}while(i==-1);
board();
if(i==1)
cout<<"==>\aPlayer "<<--player<<" win ";
else
cout<<"==>\aGame draw";
getch();
return 0;
}
int checkwin()
{
if (square[1] == square[2] && square[2] == square[3])
return 1;
else if (square[4] == square[5] && square[5] == square[6])
return 1;
else if (square[7] == square[8] && square[8] == square[9])
return 1;
else if (square[1] == square[4] && square[4] == square[7])
return 1;
else if (square[2] == square[5] && square[5] == square[8])
return 1;
else if (square[3] == square[6] && square[6] == square[9])
return 1;
else if (square[1] == square[5] && square[5] == square[9])
return 1;
else if (square[3] == square[5] && square[5] == square[7])
return 1;
else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
square[4] != '4' && square[5] != '5' && square[6] != '6' &&
square[7] != '7' && square[8] != '8' && square[9] != '9')
return 0;
else
return -1;


}
/*******************************************************************

END OF PROJECT

********************************************************************/