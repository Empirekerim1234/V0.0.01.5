#include "WorldSetup.h"
#include <iostream>
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"

using namespace std;

void HaritaniKoseleriniYerlestir(OyunHaritaVeri& oyunHaritaVerisi){
	for (int y = 0; y < oyunHaritaVerisi.yukseklik; y++) 
	{oyunHaritaVerisi.tamHarita[y][0] = Duvar;oyunHaritaVerisi.tamHarita[y][oyunHaritaVerisi.genislik - 1] = Duvar;}
	for (int x = 0; x < oyunHaritaVerisi.genislik; x++) 
	{oyunHaritaVerisi.tamHarita[0][x] = Duvar;oyunHaritaVerisi.tamHarita[oyunHaritaVerisi.yukseklik - 1][x] = Duvar;}
}
void HaritayaAgacYerlestir(OyunHaritaVeri& oyunHarita){//değiştirilecek
	const int ormanGensilik = 150;
	const int ormanGenislikOrta = ormanGensilik / 2;
	const int ormanYukseklik = 150;
	const int ormanYukseklikOrta = ormanYukseklik / 2;
	const int ormanBaslangicX = oyunHarita.genisliginOrtasi - ormanGenislikOrta;
	const int ormanBaslangicY = oyunHarita.yuksekliginOrtasi - ormanGenislikOrta;
	const int ormanBitisX = ormanBaslangicX + ormanGensilik;
	const int ormanBitisY = ormanBaslangicY + ormanYukseklik;
	for (int y = 0; y < ormanYukseklik; y++){
		for (int x = 0; x < ormanGensilik; x++)
		{if (x % 10 == 0 && y % 2 == 0 || x % 4 == 0 && y % 5 == 0)	oyunHarita.tamHarita[ormanBaslangicY + y][ormanBaslangicX + x] = Agac;}
	}
}
void Spawner(Player& player, const int playerSpawnKonum[], const int dusmanSayisi, vector<Dusman*> dusmanListesi) {
	player.SetKonum(playerSpawnKonum);
	for (int i = 0; i < dusmanSayisi; i++){dusmanListesi[i]->SetKonum(1 + i, 50);dusmanListesi[i]->DusmanSayaciSiniriAyarla();}
}
void HaritayaEvYerlestir(OyunHaritaVeri& oyunHaritaVeri) {
	int evKonumX = oyunHaritaVeri.genisliginOrtasi;
	int evKonumY = 1;
	oyunHaritaVeri.tamHarita[evKonumY][evKonumX] = Ev;
	oyunHaritaVeri.tamHarita[evKonumY + 1][evKonumX] = AltKapi;
}
void HariyayaOrmanYerlestir(OyunHaritaVeri& oyunHaritaVeri) {
	int ormanKonumX = 1;
	int ormanKonumY = 1;
	oyunHaritaVeri.tamHarita[ormanKonumY][ormanKonumX] = Orman;
	oyunHaritaVeri.tamHarita[ormanKonumY + 1][ormanKonumX] = AltKapi;
	oyunHaritaVeri.tamHarita[ormanKonumY][ormanKonumX + 1] = SagKapi;
}
void HaritayaArenaYerlestie(OyunHaritaVeri& oyunHaritaVeri) {
	int arenaKonumX = 1;
	int arenaKonumY = oyunHaritaVeri.yukseklik - 2;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX] = Arena;
	oyunHaritaVeri.tamHarita[arenaKonumY - 1][arenaKonumX] = UstKapi;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX + 1] = SagKapi;
}
void HaritayaMagraYerlestir(OyunHaritaVeri& oyunHaritaVeri) {
	int arenaKonumX = oyunHaritaVeri.genislik - 2;
	int arenaKonumY = oyunHaritaVeri.yukseklik - 2;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX] = Magra;
	oyunHaritaVeri.tamHarita[arenaKonumY - 1][arenaKonumX] = UstKapi;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX - 1] = SolKapi;
}
void HaritayaTuccarYerlestir(OyunHaritaVeri& oyunHaritaVeri) {
	int arenaKonumX = oyunHaritaVeri.genislik - 2;
	int arenaKonumY = 1;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX] = Tuccar;
	oyunHaritaVeri.tamHarita[arenaKonumY + 1][arenaKonumX] = AltKapi;
	oyunHaritaVeri.tamHarita[arenaKonumY][arenaKonumX - 1] = SolKapi;
}
void HaritayaTasinmazlariYerlestir(OyunHaritaVeri& oyunHaritaVeri){
	HaritayaEvYerlestir(oyunHaritaVeri);
	HariyayaOrmanYerlestir(oyunHaritaVeri);
	HaritayaArenaYerlestie(oyunHaritaVeri);
	HaritayaMagraYerlestir(oyunHaritaVeri);
	HaritayaTuccarYerlestir(oyunHaritaVeri);
}

void OyunOncesiDunyaAyar(Varliklar& varliklar, OyunHaritaVeri& oyunVerisi) {
	const int playerSpawnKonum[2] = { oyunVerisi.yuksekliginOrtasi, oyunVerisi.genisliginOrtasi };
	CinCoutHizlandir();
	ImleciGorunurluk(false);
	LoadingEkrani(0, 0, 800);

	HaritaniKoseleriniYerlestir(oyunVerisi);
	HaritayaTasinmazlariYerlestir(oyunVerisi);
	HaritayaAgacYerlestir(oyunVerisi);
	Spawner(varliklar.player, playerSpawnKonum, varliklar.dusmanListesi.size(), varliklar.dusmanListesi);
}