#include "Update.h"
#include "Veriler.h"
#include "Varliklar.h"
#include "Input.h"
#include <vector>
#include <iostream>
#include "YardimciFonksiyonlar.h"

bool HucreGeceliMi(int hedefY,int hedefX,OyunHaritaVeri& oyunHaritaVerisi){
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Duvar)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Agac)return false;
	return true;
}
bool KonumGecerliMi(int hedefY, int hedefX, HareketEdebilenler& hareketEdecekObje,Varliklar& tumVarliklar,OyunHaritaVeri& oyunHaritaVerisi){
	if (oyunHaritaVerisi.genislik <= hedefX||oyunHaritaVerisi.yukseklik <= hedefY)	return false;
	if (hedefX < 0 || hedefY < 0) return false;
	if (&hareketEdecekObje != &tumVarliklar.player) {
		if (tumVarliklar.player.GetKonumY() == hedefY && tumVarliklar.player.GetKonumX() == hedefX) 
			return false;
	}
	for (int i = 0; i < tumVarliklar.dusmanListesi.size(); i++)	{
		if (tumVarliklar.dusmanListesi[i]->GetYasiyormu())	{
			if (&hareketEdecekObje != tumVarliklar.dusmanListesi[i]){
				if (tumVarliklar.dusmanListesi[i]->GetKonumY() == hedefY && tumVarliklar.dusmanListesi[i]->GetKonumX() == hedefX)
					return false;
			}
		}
	}
	if (!HucreGeceliMi(hedefY, hedefX, oyunHaritaVerisi)) return false;
	return true;
}
void HareketiDene(HareketEdebilenler& hareketEdecekObje,Varliklar& tumVarliklar,OyunHaritaVeri& oyunHaritaVerisi,InputKonumlari& inputKarar){
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
void YasayanDusmanlaricinKarar(Varliklar& varliklar,int& toplamHasar,OyunHaritaVeri& oyunHaritaVerisi){
	int playerX = varliklar.player.GetKonumX();
	int playerY = varliklar.player.GetKonumY();
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++){
		if (varliklar.dusmanListesi[i]->GetYasiyormu()) {
			bool saldirabilirMi = false;
			InputKonumlari inputKarar = InputYok;
			varliklar.dusmanListesi[i]->DusmanKararMerkezi(playerY, playerX, inputKarar, saldirabilirMi);
			HareketiDene(*varliklar.dusmanListesi[i], varliklar, oyunHaritaVerisi, inputKarar);
			if (saldirabilirMi)	toplamHasar += varliklar.dusmanListesi[i]->DusmanSaldirisi();
		}
	}
}
void DusmanSaldiriKarari(int& sayac,Player&player,int toplamHasar){
	if (sayac >= 60) {
		player.PlayerHasarAl(toplamHasar);
		sayac = 0;
	}
	else sayac++;
}
void DusmanUpdate(Varliklar& varliklar,OyunHaritaVeri& oyunHaritaVerisi)/*sonrasında sınıfa al ve iki işi ayır*/{
	static int sayac = 0;
	int toplamHasar=0;
	YasayanDusmanlaricinKarar(varliklar,toplamHasar,oyunHaritaVerisi);
	DusmanSaldiriKarari(sayac,varliklar.player,toplamHasar);
}
void PLayerDusmanOldurDuyse(Varliklar& varliklar,int index){
	if (varliklar.dusmanListesi[index]->GetCan() <= 0)	{
		varliklar.dusmanListesi[index]->SetYasiyorMu(false);
		varliklar.player.GiveXp(varliklar.dusmanListesi[index]->GetGiveExp());
	}
}
bool PLayerSaldiracakDusmanKontrol(int playerX,int playerY,Varliklar& varliklar,int index)
{
	if (playerX == varliklar.dusmanListesi[index]->GetKonumX() && playerY == varliklar.dusmanListesi[index]->GetKonumY() + 1)
	{
		varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);
		return true;
	}
	else if (playerX == varliklar.dusmanListesi[index]->GetKonumX() + 1 && playerY == varliklar.dusmanListesi[index]->GetKonumY())
	{
		varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);
		return true;
	}
	else if (playerX == varliklar.dusmanListesi[index]->GetKonumX() && playerY == varliklar.dusmanListesi[index]->GetKonumY() - 1)
	{
		varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);
		return true;
	}
	else if (playerX == varliklar.dusmanListesi[index]->GetKonumX() - 1 && playerY == varliklar.dusmanListesi[index]->GetKonumY())
	{
		varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);
		return true;
	}
	return false;
}
void PLayerSaldiriKari(Varliklar& varliklar) {
	int playerX = varliklar.player.GetKonumX();
	int playerY = varliklar.player.GetKonumY();
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++) {
		if (varliklar.dusmanListesi[i]->GetYasiyormu()) {
			if (PLayerSaldiracakDusmanKontrol(playerX, playerY, varliklar, i))
			{
				PLayerDusmanOldurDuyse(varliklar, i);
				break;
			}
		}
	}
}
void PlayerUpdate(InputKonumlari&inputKarar, Varliklar& varliklar,OyunHaritaVeri& oyunHaritaVerisi){
	static int sayac = 0;
	if (inputKarar == SagaGit||inputKarar == SolaGit || inputKarar == YukariGit||inputKarar ==AsagiyaGit)
		PlayerKonumGuncelleVeUygula(varliklar, inputKarar,oyunHaritaVerisi);
	if (inputKarar == Saldir) 
		PLayerSaldiriKari(varliklar);
	if (sayac >= 480){
		int regen = varliklar.player.GetPlayerRegenCan();
		varliklar.player.PlayerRegenCan(regen);
		sayac = 0;
	}
	else sayac++;
}
void Update(Varliklar& varliklar, OyunDurumlari& oyunDurum,OyunHaritaVeri& oyunHaritaVerisi) {
	InputKonumlari inputKarar = InputYok;
	OyunDurumunaGoreInputOku(oyunDurum,inputKarar);
	if (varliklar.player.GetPlayerCan() <= 0) oyunDurum = kapant;
	if (oyunDurum == devamet) {
		PlayerUpdate(inputKarar, varliklar,oyunHaritaVerisi);
		DusmanUpdate(varliklar,oyunHaritaVerisi);//sonrasında sınıfa al ve iki işi ayır
	}
}