#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <mmsystem.h>
#include <vector>
#include <conio.h>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector3.hpp>


#pragma comment (lib, "winmm.lib")
using namespace std;
using namespace sf;
int x_coord = 32;
int y_coord = 15;
vector <string> car = { "   ___", " 0=[_]=0", "   /T\\ ", "  |(o)| ", "[]=\\_/=[]", "  __V__", " '-----'" };
string music[] = { "F1soundtrackext.ogg", "F1Mexican.ogg", "F1Theme.ogg" };//wide string
vector <string> START = {
	" _____ _____ _____ _____ _____",
	"|   __|_   _|  _  | __  |_   _|",
	"|__   | | | |     |    -| | |",
	"|_____| |_| |__|__|__|__| |_|",
};
vector <string> FINISH = {
" _____ _____ _______ _____ _____ _____ ",
"|   __|     |    |  |     |   __|  |  |",
"|   __|-   -|  | |  |-   -|__   |     |",
"|__|  |_____|__|____|_____|_____|__|__|",
};
vector<string> one = {
	" ___ ",
	"|_  |",
	" _| |_",
	"|_____|"
};
vector <string> two = {
	" ___ ",
	"|_  |",
	"|  _|",
	"|___|",
};
vector <string> three = {
	" ___ ",
	"|_  |",
	"|_  |",
	"|___|",
};
vector <string> GO = {
	" _____ _____ ",
	"|   __|     |",
	"|  |  |  |  |",
	"|_____|_____|",
};


BOOL cpos(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool isVKpressed(int virtkey) {
	return GetAsyncKeyState(virtkey) & 0x8000;
}

//MUSIC
Music song_m;


/*0 - black
1 - blue
2 - green
3 - navy
4 - red
5 - purple
6 - yellow
7 - white
8 - gray
9 - lightblue
A - light green
B - light navy
C - light red
D - light purple
E - light yellow
F - light white*/

void border_color() {
	HANDLE b_c;
	b_c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(b_c, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

void border_no_color() {
	HANDLE b_c;
	b_c = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(b_c, 0);
}


//Change color(works)
void c_c(int color) {
	HANDLE hcolor;
	hcolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcolor, color);
}

//FIELD BORDERS
void borders() {
	border_color();
	for (int i = 0; i < 38; i++) {
		cout << "  ";
	}
	cout << endl;
	for (int r = 0; r < 22; r++) {
		border_color();
		cout << "  ";
		border_no_color();
		for (int j = 0; j < 36; j++) {
			cout << "  ";
		}
		border_color();
		cout << "  " << endl;
	}
	border_color();
	for (int i = 0; i < 38; i++) {
		cout << "  ";
	}
	border_no_color();
}


//NAME (works)
void name() {
	c_c(7);
	cout << "&&&&&&&&  &&&&&&&&  &&&&&&&&  &&&&&&&&  &&&&&&&&    ";
	c_c(4);
	cout << "&&&&&&&&  &&&&&&" << endl;
	c_c(7);
	cout << "&&&&&&&&  &&&&&&&&  &&&&&&&&  &&&&&&&&  &&&&&&&&    ";
	c_c(4);
	cout << "&&&&&&&&  &&&&&&" << endl;
	c_c(7);
	cout << "&&&&      &&&  &&&  &&&  &&&     &&     &&&  &&&    ";
	c_c(4);
	cout << "&&&         &&&&" << endl;
	c_c(7);
	cout << "  &&&&    &&&  &&&  &&&&&&&&     &&     &&&&&&&&    ";
	c_c(4);
	cout << "&&&&&&      &&&&" << endl;
	c_c(7);
	cout << "    &&&&  &&&  &&&  &&&&&&       &&     &&&&&&&&    ";
	c_c(4);
	cout << "&&&&&&      &&&&" << endl;
	c_c(7);
	cout << "&&&&&&&&  &&&&&&&&  &&& &&&      &&     &&&  &&&    ";
	c_c(4);
	cout << "&&&         &&&&" << endl;
	c_c(7);
	cout << "&&&&&&&&  &&&&&&&&  &&&  &&&     &&     &&&  &&&    ";
	c_c(4);
	cout << "&&&       &&&&&&&&" << endl;
	c_c(7);
	cout << "                           Racing Game" << endl;
}


//MUSIC (works)
int choose_music() {
	int answer = 0, e, track;
	cout << "Soundtracks: " << endl;
	cout << "[ 1 ] F1 movie sountrack" << endl;
	cout << "[ 2 ] Mexican F1 theme" << endl;
	cout << "[ 3 ] F1 theme" << endl;
	c_c(4);
	cout << "[ 4 ] Exit" << endl;
	c_c(7);
	do {
		e = 0;
		answer = _getch();
		switch (answer) {
		case '1':
			track = 0;
			break;
		case '2':
			track = 1;
			break;
		case '3':
			track = 2;
			break;
		case '4':
			track = 3;
			break;
		default:
			cout << "Ooops.. Made a mistake try again";
			Sleep(1000);
			cout << "\r                                                " << "\r";//\r to move to the end of the line
			e = 33;
			break;
		}
	} while (e == 33);
	system("cls");
	return track;
}

//MENU (works)
int menu()
{
	int answer, e/*for error*/, ans;
	c_c(6);
	cout << "    MENU" << endl;//change the color
	c_c(7);
	cout << "[ 1 ] Play" << endl;
	cout << "[ 2 ] Settings" << endl;
	cout << "[ 3 ] Exit" << endl;

	do {
		answer = _getch();
		switch (answer) {
		case '1':
			ans = 1;
			e = 1;
			break;
		case '2':
			cout << "Settings";
			ans = 2;
			e = 67;
			break;
		case '3':
			cout << "BYE!!";
			e = 75;
			ans = 3;
			break;
		default:
			cout << "Oops...You made a mistake. Try again";
			Sleep(1000);
			cout << "\r                                                " << "\r";
			e = 33;
		}
	} while (e == 33);
	system("cls");
	return ans;
}


//SKIN
//Color (works)
int choose_color()
{
	char color; int c_n, e/*in case error*/;

	cout << "Color of your car " << endl;
	cout << "[ y ] "; c_c(6); cout << "Yellow" << endl;
	c_c(7);
	cout << "[ b ] "; c_c(1); cout << "Blue" << endl;
	c_c(7);
	cout << "[ r ] "; c_c(4); cout << "Red" << endl;
	c_c(7);
	cout << "[ p ] "; c_c(5); cout << "Purple" << endl;
	c_c(7);
	cout << "[ o ] "; c_c(12); cout << "Orange" << endl;
	c_c(7);
	cout << "[ n ] "; c_c(11); cout << "Light navy" << endl;
	c_c(7);

	do {
		color = _getch();
		switch (color) {
		case 'y':
			c_n = 6;
			e = 44;
			break;
		case 'b':
			c_n = 1;
			e = 23;
			break;
		case 'p':
			c_n = 5;
			e = 7;
			break;
		case 'o':
			c_n = 12;
			e = 81;
			break;
		case 'n':
			c_n = 11;
			e = 1;
			break;
		case 'r':
			c_n = 4;
			e = 7;
			break;
		default:
			cout << "Oops...You made a mistake. Try again";
			Sleep(1000);
			cout << "\r                                                " << "\r";
			e = 33;
		}
	} while (e == 33);
	system("cls");
	return c_n;
}

//Nickname (works)
string nick()
{
	string name;
	cout << "Enter your nickname: ";
	cin >> name;
	system("cls");
	return name;
}


//PREVIEW (works)
//CAR
void print_car(int color) {
	c_c(color);
	for (int i = 0; i < car.size(); i++)
		cout << car[i] << endl;
}

void draw_car(int x, int y, int color) {
	c_c(color);
	for (int i = 0; i < car.size(); ++i) {
		cpos(x, y + i);
		cout << car[i];
	}
}


char preview(int color, string nickname)
{
	char a;
	cout << "Here's how your car looks: " << endl;
	print_car(color);
	c_c(7);
	cout << nickname;
	cout << endl << "Continue?" << endl;
	c_c(2);
	cout << "[ y ] Yes" << endl;
	c_c(4);
	cout << "[ n ] No" << endl;
	c_c(7);
	a = _getch();
	system("cls");
	return a;
}

//Start(works)
void start() {
	c_c(2);
	for (int i = 0; i < START.size(); i++) {
		cout << START[i] << endl;
	}
	c_c(7);
}

//Finish(works)
void finish() {
	c_c(4);
	for (int i = 0; i < FINISH.size(); i++) {
		cout << FINISH[i] << endl;
	}
	c_c(7);
}

void countdown(int x, int y) {
	int speed = 1000;
	borders();
	c_c(4);
	PlaySound(TEXT("race-start.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < three.size(); i++) {
		cpos(x, y + i);
		cout << three[i] << endl;
	}
	Sleep(speed);
	system("cls");
	borders();
	c_c(6);
	for (int i = 0; i < two.size(); i++) {
		cpos(x, y + i);
		cout << two[i] << endl;
	}
	Sleep(speed);
	system("cls");
	borders();
	c_c(2);
	for (int i = 0; i < one.size(); i++) {
		cpos(x, y + i);
		cout << one[i] << endl;
	}
	Sleep(speed);
	system("cls");
	borders();
	c_c(4);
	for (int i = 0; i < GO.size(); i++) {
		cpos(x - 2, y + i);
		cout << GO[i] << endl;
	}
	Sleep(speed);
	system("cls");
}

//GAME
void game(int color) {
	int moveX = 0, speed = 10;
	int x = 33, y = 9;
	countdown(x, y);
	while (true) {
		Sleep(speed);
		system("cls");
		borders();
		if (isVKpressed(VK_LEFT))
			--moveX;
		else if (isVKpressed(VK_RIGHT))
			++moveX;
		else if (isVKpressed(VK_UP))
			--speed;
		else if (isVKpressed(VK_DOWN))
			++speed;
		else if (isVKpressed(VK_ESCAPE))
			break;
		draw_car(x_coord + moveX, y_coord, color);

	}
}

//MAIN
int main()
{
	int answer, color, n = 0, song; string nickname; char a;
	song_m.openFromFile(music[n]);
	song_m.play();


	do {
		name();
		answer = menu();
		switch (answer) {
		case 1:
			color = choose_color();
			nickname = nick();
			a = preview(color, nickname);
			while (a == 'n') {
				color = choose_color();
				nickname = nick();
				a = preview(color, nickname);
			}
			system("cls");
			game(color);
			system("cls");
			cout << "Play again? " << endl;
			c_c(2);
			cout << "[ y ] Yes" << endl;
			c_c(4);
			cout << "[ n ] No" << endl;
			c_c(7);
			a = _getch();
			if (a == 'y') {
				answer = 1;
				system("cls");
			}
			else {
				answer = 3;
			}
			break;
		case 2:
			do {
				n = choose_music();
				if (n < 3) {
					song = n;
					song_m.openFromFile(music[n]);
					song_m.play();
				}
			} while (n != 3);
			break;
		case 3:
			break;
		}
	} while (answer != 3);
	system("cls");
	cout << "Bye!";
	return 0;
}

