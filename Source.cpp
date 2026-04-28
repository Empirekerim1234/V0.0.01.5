#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Veriler.h"
#include "WorldSetup.h"
#include "Oyun.h"
#include "Varliklar.h"

using namespace std;

int main() {
	srand(time(0));
	const int dusmanSayisi = 30;
	Varliklar varliklar;
	varliklar.player.SetPLayerSatas(100,100,10);
	for (int i = 0; i < dusmanSayisi; i++){
		if (i%3 == 0)		varliklar.dusmanListesi.push_back(new MenzilliDusman());
		else if (i%3==1)	varliklar.dusmanListesi.push_back(new StandartDusman());
		else if (i%3==2)	varliklar.dusmanListesi.push_back(new SavasciDusman());
	}
	OyunHaritaVeri oyunHaritaVerisi;
	oyunHaritaVerisi.tamHarita = vector<vector<HucreTipi>>(oyunHaritaVerisi.yukseklik, vector<HucreTipi>(oyunHaritaVerisi.genislik, Bos));

	EkranVerisi ekranVerisi;
	ekranVerisi.consolGoruntu = vector<vector<char>>(ekranVerisi.konsolEkraniBitisY, vector<char>(ekranVerisi.KonsolEkraniBitisX, ' '));

	OyunOncesiDunyaAyar(varliklar, oyunHaritaVerisi);
	varliklar.player.LevelTablosuDoldur();
	Oyun(varliklar, oyunHaritaVerisi, ekranVerisi);
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++){
		if (varliklar.dusmanListesi[i] != NULL)
			delete varliklar.dusmanListesi[i];
	}
	return 0;
}