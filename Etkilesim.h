#pragma once
#include "Varliklar.h"
#include "Hareket.h"
#include "Kirilebilirler.h"


void YasayanDusmanlaricinKarar(Varliklar& varliklar, int& toplamHasar, OyunHaritaVeri& oyunHaritaVerisi) {
	int playerX = varliklar.player.GetKonumX(), playerY = varliklar.player.GetKonumY();
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++) {
		if (varliklar.dusmanListesi[i]->GetYasiyormu()) {
			bool saldirabilirMi = false;
			InputKonumlari inputKarar = InputYok;
			varliklar.dusmanListesi[i]->DusmanKararMerkezi(playerY, playerX, inputKarar, saldirabilirMi);
			HareketiDene(*varliklar.dusmanListesi[i], varliklar, oyunHaritaVerisi, inputKarar);
			if (saldirabilirMi)	toplamHasar += varliklar.dusmanListesi[i]->DusmanSaldirisi();
		}
	}
}
void DusmanSaldiriKarari(int& sayac, Player& player, int toplamHasar)
{if (sayac >= 60) {player.PlayerHasarAl(toplamHasar);sayac = 0;}else sayac++;}
void PLayerDusmanOldurDuyse(Varliklar& varliklar, int index) {
	if (varliklar.dusmanListesi[index]->GetCan() <= 0) 
	{varliklar.dusmanListesi[index]->SetYasiyorMu(false);varliklar.player.GiveXp(varliklar.dusmanListesi[index]->GetGiveExp());}
}
bool PLayerSaldiracakDusmanKontrol(int playerX, int playerY, Varliklar& varliklar, int index){
	int dusmanX = varliklar.dusmanListesi[index]->GetKonumX(), dusmanY = varliklar.dusmanListesi[index]->GetKonumY();
	if (playerX == dusmanX && playerY == dusmanY + 1)								//üst
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX + 1 && playerY == dusmanY + 1)						//sol üst
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX + 1 && playerY == dusmanY)							//sol
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX + 1 && playerY == dusmanY - 1)						//sol alt
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX && playerY == dusmanY - 1)							//alt
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX - 1 && playerY == dusmanY - 1)						//sağ alt
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX - 1 && playerY == dusmanY)							//sağ
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	else if (playerX == dusmanX - 1 && playerY == dusmanY + 1)						//sağ üst
	{varliklar.player.PlayerSaldir(varliklar.dusmanListesi[index]);return true;}
	return false;
}
bool PLayerSaldiracakDusmanKontrol(int playerX, int playerY, Varliklar& varliklar, int index) {
	int kirilabilirX = varliklar.kirilabilenListesi[index]->GetKonumX(), kirilabilirY = varliklar.kirilabilenListesi[index]->GetKonumY();
	if (playerX == kirilabilirX && playerY == kirilabilirY + 1)								//üst
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX + 1 && playerY == kirilabilirY + 1)						//sol üst
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX + 1 && playerY == kirilabilirY)							//sol
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX + 1 && playerY == kirilabilirY - 1)						//sol alt
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX && playerY == kirilabilirY - 1)							//alt
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX - 1 && playerY == kirilabilirY - 1)						//sağ alt
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX - 1 && playerY == kirilabilirY)							//sağ
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	else if (playerX == kirilabilirX - 1 && playerY == kirilabilirY + 1)						//sağ üst
	{
		varliklar.player.Kirma(varliklar.kirilabilenListesi[index]); return true;
	}
	return false;
}
void PLayerSaldiriKari(Varliklar& varliklar) {
	int playerX = varliklar.player.GetKonumX(), playerY = varliklar.player.GetKonumY();
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++) {
		if (varliklar.dusmanListesi[i]->GetYasiyormu())
		{if (PLayerSaldiracakDusmanKontrol(playerX, playerY, varliklar, i)){PLayerDusmanOldurDuyse(varliklar, i);break;}}
	}
}