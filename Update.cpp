#include "Update.h"
#include "Veriler.h"
#include "Varliklar.h"
#include "Input.h"
#include "Hareket.h"
#include "Etkilesim.h"
#include "YardimciFonksiyonlar.h"
#include <vector>
#include <iostream>

void DusmanUpdate(Varliklar& varliklar, OyunHaritaVeri& oyunHaritaVerisi)/*sonrasında sınıfa al ve iki işi ayır*/ {
	static int sayac = 0;
	int toplamHasar = 0;
	YasayanDusmanlaricinKarar(varliklar, toplamHasar, oyunHaritaVerisi);
	DusmanSaldiriKarari(sayac, varliklar.player, toplamHasar);
}
void PlayerUpdate(InputKonumlari&inputKarar, Varliklar& varliklar,OyunHaritaVeri& oyunHaritaVerisi){
	static int sayac = 0;
	if (inputKarar == SagaGit||inputKarar == SolaGit || inputKarar == YukariGit||inputKarar ==AsagiyaGit)
		PlayerKonumGuncelleVeUygula(varliklar, inputKarar,oyunHaritaVerisi);
	if (inputKarar == Saldir) PLayerSaldiriKari(varliklar);
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
	if (oyunDurum == devamet) 
	{PlayerUpdate(inputKarar, varliklar,oyunHaritaVerisi);DusmanUpdate(varliklar,oyunHaritaVerisi);/*sonrasında sınıfa al ve iki işi ayır*/}
}