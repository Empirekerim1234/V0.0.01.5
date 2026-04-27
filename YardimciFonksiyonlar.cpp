#include "YardimciFonksiyonlar.h"
#include <windows.h>
#include <string>
#include <iostream>

void ImleciGorunurluk(bool gorunsunmu) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = gorunsunmu;
	SetConsoleCursorInfo(console, &cursorInfo);
}
void gotoxy(int y, int x) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void LoadingEkrani(int x, int y, int hiz) {
	for (int i = 0; i < 3; i++) {
		gotoxy(y, x);
		std::cout << "Yukleniyor";
		for (int j = 0; j <= i; j++)std::cout << ".";
		Sleep(hiz);
	}
	gotoxy(y, x);
	std::cout << "              ";
}
void CinCoutHizlandir() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}