#pragma once
#include <vector>

enum InputKonumlari
{
	InputYok,OyunuDurdur,OyunuDevapEttir,YukariGit,AsagiyaGit,SolaGit,SagaGit,Saldir,etkilesimeGec
};

enum OyunDurumlari {
	devamet = 1, durdur, kapant
};
enum HucreTipi
{
	Bos, Duvar,Agac,Ev,Orman,Arena,Magra,Tuccar,UstKapi,AltKapi,SolKapi,SagKapi
};
struct EkranVerisi
{
	const int KonsolEkraniBaslangic = 1;
	const int KonsolEkraniBitisX = 156;
	const int konsolEkraniBitisY = 41;
	std::vector<std::vector<char>> consolGoruntu;
};
struct OyunGozukenHaritaVerisi
{
	std::vector<std::vector<char>> harita;
	const int baslangicX = 1;
	const int baslangicY = 1;
	int genislik = 154;
	int yukseklik = 30;
};
struct OyunHaritaVeri {
	std::vector<std::vector<HucreTipi>> tamHarita;
	const int genislik = 500;
	const int yukseklik = 500;
	const int genisliginOrtasi = genislik / 2;
	const int yuksekliginOrtasi = yukseklik / 2;
};
struct FpsBilgileri
{
	const int hedefFPS = 60;
	int hedefFrameMs = 1000 / hedefFPS;
	int fps = 0;
	int frameSayaci = 0;
};
