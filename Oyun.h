#pragma once
#include <chrono>
#include "Veriler.h"
#include "Varliklar.h"

void OyunDuraklatildiginda(OyunDurumlari& oyunDurum);
void OyunuDevamEttir(const int fps, Varliklar& varliklar, OyunDurumlari& oyunDurum, EkranVerisi& ekranVerisi, OyunHaritaVeri& oyunVerisi);
void FpsGuncelle(int& fps, int& frameSayaci, std::chrono::steady_clock::time_point& fpsZaman);
int Oyun(Varliklar& varliklar, OyunHaritaVeri& oyunVerisi, EkranVerisi& ekranVerisi);