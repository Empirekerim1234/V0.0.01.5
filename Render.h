#pragma once
#include <string>
#include "Veriler.h"
#include "Varliklar.h"
#include "YardimciFonksiyonlar.h"
#include <vector>
void EkranaBas(const int y, const int x, const std::string& txt);
void oyunEkranaPlayerVeDusmanEkle(std::vector<std::vector<char>>& harita, Varliklar& varliklar);
void ConsolEkraninaOyunEkraniEkle(Player& player, std::vector<std::vector<char>>& copyTamHatira, const OyunHaritaVeri& oyunHaritaVerisi, EkranVerisi& ekranVerisi);
void CharHaritaDuzenle(std::vector<std::vector<char>>& charTamHarita, Varliklar& varliklar, OyunHaritaVeri& oyunHaritaVerisi);
void ConsolOyunEkraniKismiEkle(OyunHaritaVeri& oyunHaritaVerisi, Varliklar& varliklar, EkranVerisi& ekranVerisi);
void UpdateConsolEkran(Varliklar& varliklar, int fps, EkranVerisi& ekranVerisi, OyunHaritaVeri& oyunVerisi);
void ConsolEkranRender(EkranVerisi& ekranVerisi);