#include "Oyun.h"
#include <chrono>
#include "Render.h"
#include "Update.h"
#include "Input.h"
#include "Veriler.h"

void OyunDuraklatildiginda(OyunDurumlari& oyunDurum) {
	InputKonumlari inputKarar;
	OyunDurumunaGoreInputOku(oyunDurum,inputKarar);
	Sleep(32);
}
void OyunuDevamEttir(const int fps, Varliklar& varliklar, OyunDurumlari& oyunDurum, EkranVerisi& ekranVerisi, OyunHaritaVeri& oyunVerisi) {
	Update(varliklar, oyunDurum,oyunVerisi);
	if (oyunDurum == devamet) {
		UpdateConsolEkran(varliklar, fps, ekranVerisi, oyunVerisi);
		ConsolEkranRender(ekranVerisi);
	}
}
void FpsGuncelle(int& fps, int& frameSayaci, std::chrono::steady_clock::time_point& fpsZaman) {
	auto simdi = std::chrono::steady_clock::now();
	auto gecen = std::chrono::duration_cast<std::chrono::milliseconds>(simdi - fpsZaman).count();
	frameSayaci++;
	if (gecen >= 1000) {
		fps = frameSayaci;
		frameSayaci = 0;
		fpsZaman = simdi;
	}
}
int Oyun(Varliklar& varliklar, OyunHaritaVeri& oyunVerisi, EkranVerisi& ekranVerisi) {
	OyunDurumlari oyunDurum = devamet;
	FpsBilgileri fpsBilgi;
	auto fpsZaman = std::chrono::steady_clock::now();
	varliklar.player.SetSembol('&');
	for (int i = 0; i < varliklar.dusmanListesi.size(); i++)
	{
		varliklar.dusmanListesi[i]->SetSembol('@');
	}
	while (true) {
		if (oyunDurum == devamet)OyunuDevamEttir(fpsBilgi.fps, varliklar, oyunDurum, ekranVerisi, oyunVerisi);
		else if (oyunDurum == durdur)OyunDuraklatildiginda(oyunDurum);
		else if (oyunDurum == kapant)return 0;
		FpsGuncelle(fpsBilgi.fps, fpsBilgi.frameSayaci, fpsZaman);
		Sleep(fpsBilgi.hedefFrameMs);
	}
	return 0;
}