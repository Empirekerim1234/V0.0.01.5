#pragma once
#include <iostream>
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"

void HaritaniKoseleriniYerlestir(OyunHaritaVeri& oyunHaritaVerisi);
void Spawner(Player& player, const int playerSpawnKonum[], const int dusmanSayisi, std::vector<Dusman>& dusmanListesi);
void OyunOncesiAyar(Varliklar& varliklar, OyunHaritaVeri& oyunVerisi);