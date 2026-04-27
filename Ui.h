#pragma once
#include "Varliklar.h"
#include <string>

void ConsolEkraninaPlayerXYbilgiEkle(Varliklar& varliklar, EkranVerisi& ekranVerisi);
void ConsolEkraninaSaatiBas(EkranVerisi& ekranVerisi);
void ConsolEkraninaFpsEkle(EkranVerisi& ekranVerisi, int fps);
void ConsolEkranEklenecekOyunEkranAyiraci(EkranVerisi& ekranVerisi);
void ConsolEkraninaEnvanterAlaniEkle(EkranVerisi& ekranVerisi);
void ConsolEkraninaHotBarEkle(EkranVerisi& ekranVerisi);
void ConsolEkraninaAciklamaKismiEkle(EkranVerisi& ekranVerisi);
void ConsolEkraninaPlayerStateEkle(EkranVerisi& ekranVerisi);
void ConsolEkraninaListeVeStatAyiracEkle(EkranVerisi& ekranVerisi);
void ConsolEkraninaGorevListesiEkle(EkranVerisi& ekranVerisi);
void ConsolUstUi(Varliklar& varliklar, EkranVerisi& ekranVerisi, int fps);
void ConsolAltUi(EkranVerisi& ekranVerisi);
void EkranaUiEkle(Varliklar& varliklar, EkranVerisi& ekranVerisi, int fps);