#include<bits/stdc++.h>
#include<conio.h>
#include<Windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#define endl '\n'
using namespace std;
char up[5][255],down[5][255];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void BOOST(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void delay(int n){
	for(int i=1;i<=n;i++);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void build_obstacle_up(int last){
	for(int i=0;i<=3;i++)up[i][last]='л';
}

void build_obstacle_down(int last){
	for(int i=0;i<=3;i++)down[i][last]='л';
}

void obstacle_up(int check,long long distance){
	int last=strlen(up[0])-1;
	if(check==0)up[0][last]=' ',up[1][last]=' ',up[2][last]=' ',up[3][last]=' ';
	else{
		if(((distance-0LL)%30LL==0LL)||((distance-1LL)%30LL==0LL)||((distance-2LL)%30LL==0LL)
		||((distance-3LL)%30LL==0LL)||((distance-4LL)%30LL==0LL))build_obstacle_up(last);
		else up[0][last]=' ',up[1][last]=' ',up[2][last]=' ',up[3][last]=' ';

	}	
}

void obstacle_down(int check,long long distance){
	int last=strlen(up[0])-1;
	if(check==0)down[0][last]=' ',down[1][last]=' ',down[2][last]=' ',down[3][last]=' ';
	else{
		if(((distance-17LL)%30LL==0LL)||((distance-18LL)%30LL==0LL)||((distance-19LL)%30LL==0LL)
		||((distance-20LL)%30LL==0LL)||((distance-21LL)%30LL==0LL))build_obstacle_down(last);
		else down[0][last]=' ',down[1][last]=' ',down[2][last]=' ',down[3][last]=' ';

	}	
}

void change_up(){
	int last=strlen(up[0])-1;
	for(int i=0;i<last;i++){
		up[0][i]=up[0][i+1];
		up[1][i]=up[1][i+1];
		up[2][i]=up[2][i+1];
		up[3][i]=up[3][i+1];
	}
}

void change_down(){
	int last=strlen(down[0])-1;
	for(int i=0;i<last;i++){
		down[0][i]=down[0][i+1];
		down[1][i]=down[1][i+1];
		down[2][i]=down[2][i+1];
		down[3][i]=down[3][i+1];

	}
}

//OUTPUT GAMBAR DARI TULISAN GAME OVER
void game_over(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	gotoxy(25,11);
	printf("лллл  лллл  л   л  лллл     лллл  л л  лллл  лллл\n");
	gotoxy(25,12);
	printf("л     л  л  лл лл  л        л  л  л л  л     л  л\n");
	gotoxy(25,13);
	printf("л     лллл  л л л  лл       л  л  л л  лл    лллл\n");
	gotoxy(25,14);
	printf("л лл  л  л  л   л  л        л  л  л л  л     л л\n");
	gotoxy(25,15);
	printf("лллл  л  л  л   л  лллл     лллл   л   лллл  л  л\n");
	SetConsoleTextAttribute(hConsole, 7);
}

void print_up(){
	SetConsoleTextAttribute(hConsole, 4);
	for(int i=0;i<=3;i++)printf("%s\n",up[i]);
}

void print_down(){
	SetConsoleTextAttribute(hConsole, 4);
	for(int i=3;i>=0;i--)printf("%s\n",down[i]);
}

void reset(){
	strcpy(up[0],"                                                                                                 ");
	strcpy(up[1],"                                                                                                 ");
	strcpy(up[2],"                                                                                                 ");
	strcpy(up[3],"                                                                                                 ");


	strcpy(down[0],"                                                                                                 ");
	strcpy(down[1],"                                                                                                 ");
	strcpy(down[2],"                                                                                                 ");
	strcpy(down[3],"                                                                                                 ");

}

int main(){
	char ch;
	long long distance=-1LL,highscore=0LL;
	int number_up,number_down;
	bool check=true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//SetConsoleTextAttribute(hConsole, 20);
	reset();
	srand(time(0));
	while(check){
		while(!kbhit()&&check){
			BOOST();
			system("CLS");
			distance++;
			
			//MENENTUKAN OBSTACLE
			if((distance-5LL)%14LL==0LL)number_up=1;//SUSPECT
			if((distance-19LL)%14LL==0LL)number_down=1;//SUSPECT
			change_up();
			change_down();
			//obstacle_up(number_up,distance);//SUSPECT
			//obstacle_down(number_down,distance);//SUSCPECT
			obstacle_up(1,distance);//SUSPECT
			obstacle_down(1,distance);//SUSCPECT	
			
			//PRINT OUTPUT
			gotoxy(0,0);
			SetConsoleTextAttribute(hConsole, 14);
			printf("=================================================================================================\n");
			print_up();
			SetConsoleTextAttribute(hConsole, 7);

			SetConsoleTextAttribute(hConsole, 6);
			gotoxy(15,1);
			printf("лллл\n");
			gotoxy(15,2);
			printf("лллл\n");
			//gotoxy(0,3);
			//printf("лллл\n");
			gotoxy(0,21);
			print_down();
			SetConsoleTextAttribute(hConsole, 14);
			printf("=================================================================================================\n");
			SetConsoleTextAttribute(hConsole, 6);
			printf("Distance: %lld       Highscore:%lld\n",distance,highscore);
			
			//CEK APAKAH TERKENA OBSTACLE ATAU TIDAK
			if(up[0][15]=='л'||up[0][18]=='л'){
				check=false;
				//gotoxy(10,11);
				game_over();
				break;
			}
			printf("Press X to Exit\n");
			printf("Press Space to Change Position\n");
			SetConsoleTextAttribute(hConsole, 7);

			//delay(2e+7);
			delay(1e+7);
		}
		//MENENTUKAN APAKAH X ATAU TIDAK
		if(check){
			ch=getch();
			if(ch=='x'||ch=='X')check=false;
		}	
		
		while(!kbhit()&&check){
			BOOST();
			system("CLS");
			//SetConsoleTextAttribute(hConsole, BACKGROUND_PURPLE);

			//MENENTUKAN OBSTACLE
			if((distance-5LL)%14LL==0LL)number_up=1;
			if((distance-19LL)%14LL==0LL)number_down=1;
			change_up();
			change_down();
			//obstacle_up(number_up,distance);
			//obstacle_down(number_down,distance);
			obstacle_up(1,distance);
			obstacle_down(1,distance);			
			
			//PRINT OUTPUT
			distance++;
			gotoxy(0,0);
			SetConsoleTextAttribute(hConsole, 14);
			printf("=================================================================================================\n");
			print_up();
			SetConsoleTextAttribute(hConsole, 7);

			gotoxy(0,21);
			print_down();
			SetConsoleTextAttribute(hConsole, 14);
			printf("=================================================================================================\n");
			SetConsoleTextAttribute(hConsole, 7);
			//gotoxy(0,21);
			//printf("лллл\n");
			SetConsoleTextAttribute(hConsole, 6);
			gotoxy(15,23);
			printf("лллл\n");
			gotoxy(15,24);
			printf("лллл\n");
			
			

			gotoxy(0,26);
			SetConsoleTextAttribute(hConsole, 6);
			printf("Distance: %lld       Highscore:%lld\n",distance,highscore);
			
			//CEK APAKAH TERKENA OBSTACLE ATAU TIDAK
			if(down[0][15]=='л'||down[0][18]=='л'){
				check=false;
				game_over();
				break;
			}
			printf("Press X to Exit\n");
			printf("Press Space to Change Position\n");
			SetConsoleTextAttribute(hConsole, 7);
			//delay(2e+7);
			delay(1e+7);
		}		
		//MENENTUKAN APAKAH X ATAU TIDAK
		if(check){
			ch=getch();
			if(ch=='x'||ch=='X')check=false;
		}
		
		//MASUK KESINI JIKA TERJADI GAME OVER ATAU TERKENA OBSTACLE
		if(check==false){
			gotoxy(0,27);
			SetConsoleTextAttribute(hConsole, 6);
			printf("Press X to Exit\n");
			printf("Press Space Button to Play Again\n");//CLEAR LINE/BERISHINNN
			SetConsoleTextAttribute(hConsole, 7);

			ch=getch();
			if(ch==' '){
				check=true;
				reset();
				highscore=max(highscore,distance);
				distance=0LL;
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 6);
	

}  
