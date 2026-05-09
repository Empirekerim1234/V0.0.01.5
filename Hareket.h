#pragma once
#include "Veriler.h"
#include "Varliklar.h"

bool HucreGeceliMi(int hedefY, int hedefX, OyunHaritaVeri& oyunHaritaVerisi,Varliklar&varliklar) {
	if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Duvar)return false;
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Agac)
	{
		for (int i = 0; i < varliklar.kirilabilenListesi.size(); i++)
		{
			if (varliklar.kirilabilenListesi[i]->GetKonumX() == hedefX && varliklar.kirilabilenListesi[i]->GetKonumY() == hedefY)
			{
				if (varliklar.kirilabilenListesi[i]->GetDurum() == Saglam)
					return false;
			}
		}
	}
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Ev)return false;
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Orman)return false;
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Magra)return false;
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Arena)return false;
	else if (oyunHaritaVerisi.tamHarita[hedefY][hedefX] == Tuccar)return false;
	return true;
}
bool KonumGecerliMi(int hedefY, int hedefX, HareketEdebilenler& hareketEdecekObje, Varliklar& tumVarliklar, OyunHaritaVeri& oyunHaritaVerisi) {
	if (oyunHaritaVerisi.genislik <= hedefX || oyunHaritaVerisi.yukseklik <= hedefY)	return false;
	else if (hedefX < 0 || hedefY < 0) return false;
	else if (&hareketEdecekObje != &tumVarliklar.player)
	{if (tumVarliklar.player.GetKonumY() == hedefY && tumVarliklar.player.GetKonumX() == hedefX)return false;}
	for (int i = 0; i < tumVarliklar.dusmanListesi.size(); i++) {
		if (tumVarliklar.dusmanListesi[i]->GetYasiyormu()) {
			if (&hareketEdecekObje != tumVarliklar.dusmanListesi[i]) {
				if (tumVarliklar.dusmanListesi[i]->GetKonumY() == hedefY && tumVarliklar.dusmanListesi[i]->GetKonumX() == hedefX)
					return false;
			}
		}
	}
	if (!HucreGeceliMi(hedefY, hedefX, oyunHaritaVerisi,tumVarliklar)) return false;
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