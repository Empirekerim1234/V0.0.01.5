#include "Render.h"
#include <iostream>
#include <string>
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"
#include "Kamera.h"
#include "Ui.h"

using namespace std;

void EkranaBas(const int y, const int x, const string& txt) {
	gotoxy(y, x);
	cout << txt;
}
void oyunEkranaPlayerVeDusmanEkle(vector<vector<char>>& harita, Varliklar& varliklar) {
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++)
	{
		harita[varliklar.dusmanListesi[i]->GetKonumY()][varliklar.dusmanListesi[i]->GetKonumX()] = varliklar.dusmanListesi[i]->GetSembol();
	}
	harita[varliklar.player.GetKonumY()][varliklar.player.GetKonumX()] = varliklar.player.GetSembol();
}
void ConsolEkraninaOyunEkraniEkle(Player& player, vector<vector<char>>& copyTamHatira, const OyunHaritaVeri& oyunHaritaVerisi, EkranVerisi& ekranVerisi) {
	OyunGozukenHaritaVerisi gHarita;//154 30 //154/2=77
	gHarita.harita = vector<vector<char>>(gHarita.yukseklik, vector<char>(gHarita.genislik, ' '));
	int ekranSolUstX = KameraKonumAyarlaX(player, gHarita, oyunHaritaVerisi.genislik);
	int ekranSolUstY = KameraKonumAyarlaY(player, gHarita, oyunHaritaVerisi.yukseklik);
	for (int y = 0; y < gHarita.yukseklik; y++)
	{
		for (int x = 0; x < gHarita.genislik; x++)gHarita.harita[y][x] = copyTamHatira[ekranSolUstY + y][ekranSolUstX + x];
	}
	for (int y = 0; y < gHarita.yukseklik; y++)
	{
		for (int x = 0; x < gHarita.genislik; x++)
			ekranVerisi.consolGoruntu[2 + y][1 + x] = gHarita.harita[y][x];
	}
}
void CharHaritaDuzenle(vector<vector<char>>&charTamHarita,OyunHaritaVeri& oyunHaritaVeri)
{
	int yukseklik = oyunHaritaVeri.yukseklik;
	int genislik = oyunHaritaVeri.genislik;
	for (int y = 0; y <yukseklik ; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			if (oyunHaritaVeri.tamHarita[y][x] == Duvar) charTamHarita[y][x] = '#';
			if (oyunHaritaVeri.tamHarita[y][x] == Agac) charTamHarita[y][x] = '€';
		}
	}
}
void ConsolOyunEkraniKismiEkle(OyunHaritaVeri& oyunHaritaVerisi, Varliklar& varliklar, EkranVerisi& ekranVerisi) {
	vector<vector<char>>copyTamHatira(oyunHaritaVerisi.yukseklik,vector<char>(oyunHaritaVerisi.genislik,'.'));
	CharHaritaDuzenle(copyTamHatira,oyunHaritaVerisi);
	oyunEkranaPlayerVeDusmanEkle(copyTamHatira, varliklar);
	ConsolEkraninaOyunEkraniEkle(varliklar.player, copyTamHatira, oyunHaritaVerisi, ekranVerisi);
}
void UpdateConsolEkran(Varliklar& varliklar, int fps, EkranVerisi& ekranVerisi, OyunHaritaVeri& oyunVerisi) {
	ConsolOyunEkraniKismiEkle(oyunVerisi, varliklar, ekranVerisi);
	EkranaUiEkle(varliklar,ekranVerisi,fps);
}
void ConsolEkranRender(EkranVerisi& ekranVerisi) {
	string consolGuruntuString = "";
	gotoxy(0, 0);
	for (int y = 0; y < ekranVerisi.konsolEkraniBitisY; y++) {
		for (int x = 0; x < ekranVerisi.KonsolEkraniBitisX; x++) {
			consolGuruntuString += ekranVerisi.consolGoruntu[y][x];
			ekranVerisi.consolGoruntu[y][x] = ' ';
		}
	}
	EkranaBas(0, 0, consolGuruntuString);
}