#include "Update.h"
#include "Veriler.h"
#include "Varliklar.h"
#include "Input.h"
#include <iostream>
#include "YardimciFonksiyonlar.h"

bool HucreGeceliMi(int hedefY,int hedefX,OyunHaritaVeri& oyunHaritaVerisi){
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Duvar)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Agac)return false;
	return true;
}
bool KonumGecerliMi(int hedefY, int hedefX, HareketEdebilenler& hareketEdecekObje,Varliklar& tumVarliklar,OyunHaritaVeri& oyunHaritaVerisi)
{
	if (oyunHaritaVerisi.genislik <= hedefX||oyunHaritaVerisi.yukseklik <= hedefY)	return false;
	if (hedefX < 0 || hedefY < 0) return false;
	if (&hareketEdecekObje != &tumVarliklar.player) {
		if (tumVarliklar.player.GetKonumY() == hedefY && tumVarliklar.player.GetKonumX() == hedefX) return false;
	}
	for (int i = 0; i < tumVarliklar.dusmanListesi.size(); i++)
	{
		if (&hareketEdecekObje != tumVarliklar.dusmanListesi[i]) {
			if (tumVarliklar.dusmanListesi[i]->GetKonumY() == hedefY && tumVarliklar.dusmanListesi[i]->GetKonumX() == hedefX) return false;
		}
	}
	if (!HucreGeceliMi(hedefY, hedefX, oyunHaritaVerisi)) return false;
	return true;
}
void HareketiDene(HareketEdebilenler& hareketEdecekObje,Varliklar& tumVarliklar,OyunHaritaVeri& oyunHaritaVerisi,InputKonumlari& inputKarar)
{
	int hedefY = hareketEdecekObje.GetKonumY();
	int hedefX = hareketEdecekObje.GetKonumX();

	if (inputKarar == YukariGit) hedefY--;
	else if (inputKarar == AsagiyaGit) hedefY++;
	else if (inputKarar == SolaGit) hedefX--;
	else if (inputKarar == SagaGit) hedefX++;

	if (KonumGecerliMi(hedefY, hedefX, hareketEdecekObje, tumVarliklar,oyunHaritaVerisi))
		hareketEdecekObje.SetKonum(hedefY, hedefX);
}
void PlayerKonumGuncelleVeUygula(Varliklar& varliklar, InputKonumlari&inputKarar,OyunHaritaVeri& oyunHaritaVerisi)
{HareketiDene(varliklar.player, varliklar,oyunHaritaVerisi,inputKarar);}
void DusmanKonumGuncelleVeUygula(Varliklar& varliklar,OyunHaritaVeri& oyunHaritaVerisi)//sonrasında sınıfa al ve iki işi ayır
{
	int playerX = varliklar.player.GetKonumX();
	int playerY = varliklar.player.GetKonumY();
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++)
	{
		bool saldirabilirMi = false;
		InputKonumlari inputKarar = InputYok;
		varliklar.dusmanListesi[i]->DusmanKararMerkezi(playerY,playerX,inputKarar,saldirabilirMi);
		HareketiDene(*varliklar.dusmanListesi[i], varliklar, oyunHaritaVerisi, inputKarar);
		int hasar = varliklar.dusmanListesi[i]->DusmanSaldirisi();
		if (inputKarar == Saldir)
			varliklar.player.PlayerHasarAl(hasar);
	}
}
void PlayerKonumGuncellemeKarari(InputKonumlari&inputKarar, Varliklar& varliklar,OyunHaritaVeri& oyunHaritaVerisi)
{
	if (inputKarar == SagaGit||inputKarar == SolaGit || inputKarar == YukariGit||inputKarar ==AsagiyaGit)
		PlayerKonumGuncelleVeUygula(varliklar, inputKarar,oyunHaritaVerisi);
}
void Update(Varliklar& varliklar, OyunDurumlari& oyunDurum,OyunHaritaVeri& oyunHaritaVerisi) {
	InputKonumlari inputKarar = InputYok;
	OyunDurumunaGoreInputOku(oyunDurum,inputKarar);
	if (oyunDurum == devamet) {
		PlayerKonumGuncellemeKarari(inputKarar, varliklar,oyunHaritaVerisi);
		DusmanKonumGuncelleVeUygula(varliklar,oyunHaritaVerisi);//sonrasında sınıfa al ve iki işi ayır
	}
}