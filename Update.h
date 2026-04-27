#pragma once
#include "Veriler.h"
#include "Varliklar.h"
#include "Input.h"

void PlayerKonumGuncelleVeUygula(Varliklar& varliklar, InputKonumlari& inputKarar, OyunHaritaVeri& oyunHaritaVerisi);
void DusmanKonumGuncelleVeUygula(Varliklar& varliklar, OyunHaritaVeri& oyunHaritaVerisi);
void PlayerKonumGuncellemeKarari(InputKonumlari& inputKarar, Varliklar& varliklar, OyunHaritaVeri& oyunHaritaVerisi);
void Update(Varliklar& varliklar, OyunDurumlari& oyunDurum, OyunHaritaVeri& oyunHaritaVerisi);