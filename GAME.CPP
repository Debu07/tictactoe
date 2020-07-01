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
cout<<"  ÛÛÛÛÛÛÛÛÛÛÛÛ  ÛÛÛ     ÜÛÛÛÛÛÛÛÜ                                          \n";
cout<<"  ÛÛÛÛÛÛÛÛÛÛÛÛ  ÛÛÛ    ÛÛÛÛÛÛÛÛÛß                                           \n";
cout<<"      ÛÛÛÛ      ÛÛÛ   ÛÛÛÛ                                                   \n";
cout<<"      ÛÛÛÛ      ÛÛÛ    ÛÛÛÛÜÜÜÜÜÜ                                            \n";
cout<<"      ÛÛÛÛ      ÛÛÛ     ÛÛÛÛÛÛÛÛÛ                                            \n";
cout<<"                                                                             \n";
cout<<"                   ÛÛÛÛÛÛÛÛÛÛÛÛ       ÛÛÛÛÜ        ÜÛÛÛÛÛÛÛÛÛÛ               \n";
cout<<"                   ÛÛÛÛÛÛÛÛÛÛÛÛ      ÛÛÛÛÛÛÛ      ÛÛÛÛÛÛÛÛÛÛÛÛ              \n";
cout<<"                       ÛÛÛÛ         ÛÛÛÛÛÛÛÛÛ    ÛÛÛÛÛß                      \n";
cout<<"                       ÛÛÛÛ        ÛÛÛÛ   ÛÛÛÛ   ÛÛÛÛÛÜ                      \n";
cout<<"                       ÛÛÛÛ       ÛÛÛÛ     ÛÛÛÛ   ÛÛÛÛÛÛÜÜÜÜÜÜ               \n";
cout<<"                       ÛÛÛÛ      ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ   ßÛÛÛÛÛÛÛÛÛÛ               \n";
cout<<"                                                                             \n";
cout<<"                                 ÛÛÛÛÛÛÛÛÛÛÛ     ÜÛÛÛÛÛÛÛÛÜ    ÛÛÛÛÛÛÛÛÛÛÛÛ  \n";
cout<<"                                 ÛÛÛÛÛÛÛÛÛÛÛ   ÜÛÛÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛÛßßßßßßß  \n";
cout<<"                                    ÛÛÛÛ      ÛÛÛÛÛß   ßÛÛÛÛÛ  ÛÛÛÛÛÜÜÜÜÜÜÜ  \n";
cout<<"                                    ÛÛÛÛ      ÛÛÛÛÛÜ   ÜÛÛÛÛÛ  ÛÛÛÛÛßßßßßßß  \n";
cout<<"                                    ÛÛÛÛ       ÛÛÛÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛÛÜÜÜÜÜÜÜ \n";
cout<<"                                    ÛÛÛÛ        ßÛÛÛÛÛÛÛÛÛß    ÛÛÛÛÛÛÛÛÛÛÛÛ  \n";
cout<<"                                                                             \n";

window(15,22,80,25);
cout<<"Loading...";
window(15,23,80,25);
for(int i=0;i<50;i++)
{       delay(60);
	cout<<"Û";
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
cout << "     ³     ³     " << endl;
cout << " " << square[1] << "   ³ " << square[2] << "   ³ " << square[3] << endl;
cout << "_____³_____³_____" << endl;
cout << "     ³     ³ " << endl;
cout << " " << square[4] << "   ³ " << square[5] << "   ³ " << square[6] << endl;
cout << "_____³_____³_____" << endl;
cout << "     ³     ³ " << endl;
cout << " " << square[7] << "   ³ " << square[8] << "   ³ " << square[9] << endl;
cout << "     ³     ³ " << endl << endl;
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
