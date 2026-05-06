#pragma once
#include "Veriler.h"
#include "Varliklar.h"

bool HucreGeceliMi(int hedefY, int hedefX, OyunHaritaVeri& oyunHaritaVerisi) {
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Duvar)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Agac)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Ev)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Orman)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Magra)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Arena)return false;
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Tuccar)return false;
	return true;
}
bool KonumGecerliMi(int hedefY, int hedefX, HareketEdebilenler& hareketEdecekObje, Varliklar& tumVarliklar, OyunHaritaVeri& oyunHaritaVerisi) {
	if (oyunHaritaVerisi.genislik <= hedefX || oyunHaritaVerisi.yukseklik <= hedefY)	return false;
	if (hedefX < 0 || hedefY < 0) return false;
	if (&hareketEdecekObje != &tumVarliklar.player)
	{if (tumVarliklar.player.GetKonumY() == hedefY && tumVarliklar.player.GetKonumX() == hedefX)return false;}
	for (int i = 0; i < tumVarliklar.dusmanListesi.size(); i++) {
		if (tumVarliklar.dusmanListesi[i]->GetYasiyormu()) {
			if (&hareketEdecekObje != tumVarliklar.dusmanListesi[i]) {
				if (tumVarliklar.dusmanListesi[i]->GetKonumY() == hedefY && tumVarliklar.dusmanListesi[i]->GetKonumX() == hedefX)
					return false;
			}
		}
	}
	if (!HucreGeceliMi(hedefY, hedefX, oyunHaritaVerisi)) return false;
	return true;
}
void HareketiDene(HareketEdebilenler& hareketEdecekObje, Varliklar& tumVarliklar, OyunHaritaVeri& oyunHaritaVerisi, InputKonumlari& inputKarar) {
	int hedefY = hareketEdecekObje.GetKonumY();
	int hedefX = hareketEdecekObje.GetKonumX();
	if (inputKarar == YukariGit) hedefY--;
	else if (inputKarar == AsagiyaGit) hedefY++;
	else if (inputKarar == SolaGit) hedefX--;
	else if (inputKarar == SagaGit) hedefX++;

	if (KonumGecerliMi(hedefY, hedefX, hareketEdecekObje, tumVarliklar, oyunHaritaVerisi))
		hareketEdecekObje.SetKonum(hedefY, hedefX);
}
void PlayerKonumGuncelleVeUygula(Varliklar& varliklar, InputKonumlari& inputKarar, OyunHaritaVeri& oyunHaritaVerisi)
{HareketiDene(varliklar.player, varliklar, oyunHaritaVerisi, inputKarar);}