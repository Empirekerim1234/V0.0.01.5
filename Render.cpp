#include "Render.h"
#include <iostream>
#include <string>
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"
#include "Kamera.h"
#include "Ui.h"
#include "Kirilebilirler.h"

using namespace std;

void EkranaBas(const int y, const int x, const string& txt)
{gotoxy(y, x); cout << txt;}
void oyunEkranaPlayerVeDusmanEkle(vector<vector<char>>& harita, Varliklar& varliklar) {
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++) {
		if (varliklar.dusmanListesi[i]->GetYasiyormu())
			harita[varliklar.dusmanListesi[i]->GetKonumY()][varliklar.dusmanListesi[i]->GetKonumX()] = varliklar.dusmanListesi[i]->GetSembol();
	}
	harita[varliklar.player.GetKonumY()][varliklar.player.GetKonumX()] = varliklar.player.GetSembol();
}
void ConsolEkraninaOyunEkraniEkle(Player& player, vector<vector<char>>& copyTamHatira, const OyunHaritaVeri& oyunHaritaVerisi, EkranVerisi& ekranVerisi) {
	OyunGozukenHaritaVerisi gHarita;//154 30 //154/2=77
	gHarita.harita = vector<vector<char>>(gHarita.yukseklik, vector<char>(gHarita.genislik, ' '));
	int ekranSolUstX = KameraKonumAyarlaX(player, gHarita, oyunHaritaVerisi.genislik);
	int ekranSolUstY = KameraKonumAyarlaY(player, gHarita, oyunHaritaVerisi.yukseklik);
	int yukseklik = gHarita.yukseklik, genislik = gHarita.genislik;
	for (int y = 0; y < yukseklik; y++) 
	{for (int x = 0; x < genislik; x++)gHarita.harita[y][x] = copyTamHatira[ekranSolUstY + y][ekranSolUstX + x];}
	for (int y = 0; y < yukseklik; y++)
	{for (int x = 0; x < genislik; x++)ekranVerisi.consolGoruntu[2 + y][1 + x] = gHarita.harita[y][x];}
}
void CharHaritaDuzenle(vector<vector<char>>& charTamHarita, Varliklar& varliklar, OyunHaritaVeri& oyunHaritaVerisi) {
	OyunGozukenHaritaVerisi gHarita;//154 30 //154/2=77
	int ekranSolUstX = KameraKonumAyarlaX(varliklar.player, gHarita, oyunHaritaVerisi.genislik);
	int ekranSolUstY = KameraKonumAyarlaY(varliklar.player, gHarita, oyunHaritaVerisi.yukseklik);
	int ekranSagAltX = ekranSolUstX + gHarita.genislik;
	int ekranSagAltY = ekranSolUstY + gHarita.yukseklik;
	for (int y = ekranSolUstY; y < ekranSagAltY; y++) {
		for (int x = ekranSolUstX; x < ekranSagAltX; x++) {
			if (oyunHaritaVerisi.tamHarita[y][x] == Duvar) charTamHarita[y][x] = '#';
			else if (oyunHaritaVerisi.tamHarita[y][x] == Agac)
				charTamHarita[y][x] = varliklar.kirilabilenListesi[0]->GetSembol();
			else if (oyunHaritaVerisi.tamHarita[y][x] == Ev) charTamHarita[y][x] = 'E';
			else if (oyunHaritaVerisi.tamHarita[y][x] == Orman) charTamHarita[y][x] = 'O';
			else if (oyunHaritaVerisi.tamHarita[y][x] == Arena) charTamHarita[y][x] = 'A';
			else if (oyunHaritaVerisi.tamHarita[y][x] == Magra) charTamHarita[y][x] = 'M';
			else if (oyunHaritaVerisi.tamHarita[y][x] == Tuccar) charTamHarita[y][x] = 'T';
			else if (oyunHaritaVerisi.tamHarita[y][x] == UstKapi) charTamHarita[y][x] = 'v';
			else if (oyunHaritaVerisi.tamHarita[y][x] == AltKapi) charTamHarita[y][x] = '^';
			else if (oyunHaritaVerisi.tamHarita[y][x] == SolKapi) charTamHarita[y][x] = '>';
			else if (oyunHaritaVerisi.tamHarita[y][x] == SagKapi) charTamHarita[y][x] = '<';
		}
	}
}
void ConsolOyunEkraniKismiEkle(OyunHaritaVeri& oyunHaritaVerisi, Varliklar& varliklar, EkranVerisi& ekranVerisi) {
	vector<vector<char>>copyTamHatira(oyunHaritaVerisi.yukseklik, vector<char>(oyunHaritaVerisi.genislik, '.'));
	CharHaritaDuzenle(copyTamHatira,varliklar,oyunHaritaVerisi);
	oyunEkranaPlayerVeDusmanEkle(copyTamHatira, varliklar);
	ConsolEkraninaOyunEkraniEkle(varliklar.player, copyTamHatira, oyunHaritaVerisi, ekranVerisi);
}
void UpdateConsolEkran(Varliklar& varliklar, int fps, EkranVerisi& ekranVerisi, OyunHaritaVeri& oyunVerisi) {
	ConsolOyunEkraniKismiEkle(oyunVerisi, varliklar, ekranVerisi);
	EkranaUiEkle(varliklar, ekranVerisi, fps);
}
void ConsolEkranRender(EkranVerisi& ekranVerisi) {
	string consolGuruntuString = "";
	gotoxy(0, 0);
	int maxY = ekranVerisi.konsolEkraniBitisY, maxX = ekranVerisi.KonsolEkraniBitisX;
	for (int y = 0; y < maxY; y++) {
		for (int x = 0; x < maxX; x++) {
			consolGuruntuString += ekranVerisi.consolGoruntu[y][x];
			ekranVerisi.consolGoruntu[y][x] = ' ';
		}
	}
	EkranaBas(0, 0, consolGuruntuString);
}