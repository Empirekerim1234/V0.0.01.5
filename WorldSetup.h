#pragma once
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"

void HaritaniKoseleriniYerlestir(OyunHaritaVeri& oyunHaritaVerisi);
void HaritayaAgacYerlestir(OyunHaritaVeri& oyunHarita);
void Spawner(Player& player, const int playerSpawnKonum[], const int dusmanSayisi, std::vector<Dusman*> dusmanListesi);
void OyunOncesiDunyaAyar(Varliklar & varliklar, OyunHaritaVeri & oyunVerisi);