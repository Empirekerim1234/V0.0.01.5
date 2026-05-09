#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Veriler.h"
#include "WorldSetup.h"
#include "Oyun.h"
#include "Varliklar.h"
#include "Kirilebilirler.h"

using namespace std;

int main() {
	srand(time(0));
	const int dusmanSayisi = 30;
	const int agacSayisi = 2145;
	Varliklar varliklar;
	for (int i = 0; i < dusmanSayisi; i++){
		if (i%3 == 0)		varliklar.dusmanListesi.push_back(new MenzilliDusman());
		else if (i%3==1)	varliklar.dusmanListesi.push_back(new StandartDusman());
		else if (i%3==2)	varliklar.dusmanListesi.push_back(new SavasciDusman());
	}
	for (int i = 0; i < agacSayisi; i++) 
	{varliklar.kirilabilenListesi.push_back(new KirilebilirAgacObjesi());}
	OyunHaritaVeri oyunHaritaVerisi;
	oyunHaritaVerisi.tamHarita = vector<vector<HucreTipi>>(oyunHaritaVerisi.yukseklik, vector<HucreTipi>(oyunHaritaVerisi.genislik, Bos));
	oyunHaritaVerisi.kirilabilirHarita = vector<vector<Kirilebilirler*>>(oyunHaritaVerisi.yukseklik, vector<Kirilebilirler*>(oyunHaritaVerisi.genislik, nullptr));
	EkranVerisi ekranVerisi;
	ekranVerisi.consolGoruntu = vector<vector<char>>(ekranVerisi.konsolEkraniBitisY, vector<char>(ekranVerisi.KonsolEkraniBitisX, ' '));

	OyunOncesiDunyaAyar(varliklar, oyunHaritaVerisi);
	Oyun(varliklar, oyunHaritaVerisi, ekranVerisi);
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++)
	{if (varliklar.dusmanListesi[i] != NULL)delete varliklar.dusmanListesi[i];}
	for (int i = 0; i < varliklar.kirilabilenListesi.size(); i++)
	{if (varliklar.kirilabilenListesi[i] != NULL)delete varliklar.kirilabilenListesi[i];}
	return 0;
}