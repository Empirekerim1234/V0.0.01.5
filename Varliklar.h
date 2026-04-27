#pragma once
#include "Veriler.h"
#include <vector>

struct OyunTamKonumlar{
	const int minOyunEkraniSinirKonum[2] = { 1, 1 };
	const int maxOyunHaritasiSinirKonum[2] = { 500,500 };
};
struct BaseStat{
	int MaxCan = 100;
	int Can = 100;
	int Hasar = 5;
};
class HareketEdebilenler{
private:
	bool yasiyorMu = true;
	char sembol;
	int konumY = 0, konumX = 0;
	OyunTamKonumlar SinirKonumlar;
public:
	int GetKonumY() const;
	int GetKonumX() const;
	void SetKonum(const int y, const int x);
	void SetKonum(const int konum[]);
	void SetYasiyorMu(bool _yasiyorMu);
	bool GetYasiyormu();
	void SetSembol(char c);
	char GetSembol();
};
class Dusman : public HareketEdebilenler {
private:
	BaseStat Stat;
	int dusmanSayacSiniri, sayac = 0;
	int gorusMesafesi = 1;
	int saldiriMenzili;
	bool playereYeterinceYakin = false;
	bool saldirabilirMi = false;
	bool playeriGorduMu = false;
public:
	virtual void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) = 0;
	virtual int DusmanSaldirisi() = 0;
	void DusmanSayaciSiniriAyarla();
	int PlayerlaMesafeyiHesapla(int playerY, int PlayerX);
	void RandomDusmanHaraketYonetici(InputKonumlari& inputKarari);
	void PlayereGit(int playerY, int playerX, InputKonumlari& inputKarari);
	void DusmanMoveYonetici(int playerY, int playerX,InputKonumlari&inputKarari,int gorusMesafesi,int saldiriMenzili);
	BaseStat GetStat();
	int GetGorusMesafesi();
	int GetSaldiriMenzili();
	void SetStat(BaseStat _satats);
	void SetGorusMesafesi(int _gorusMesafesi);
	void SetSaldiriMenzili(int _saldiriMenzili);
	int GetCan();
	int GetMaxCan();
	int GetHasar();
	void SetCan(int _can);
	void SetMaxCan(int _maxCan);
	void SetHasar(int _hasar);
	void SetGorusMesafesindeMi(bool _gorusMesafesindeMi);
	void SetSaldiriMenzilindeMi(bool _saldiriMenzilindeMi);
	bool GetSaldiriMenzilindeMi();
	bool GetPlayeriGorduMu();
};
class MenzilliDusman : public Dusman{
public:
	MenzilliDusman(){
		SetMaxCan(50);
		SetCan(50);
		SetHasar(5);
		SetGorusMesafesi(30);
		SetSaldiriMenzili(5);
	}
	void PlayerHizala(int playerY,int playerX,InputKonumlari& inputKarari){
		int mesafeX = playerX - GetKonumX();
		int mesafeY = playerY - GetKonumY();
		if (mesafeX < 0)
			mesafeX *= -1;
		if (mesafeY < 0)
			mesafeY *= -1;
		if (mesafeX < mesafeY){
			if (GetKonumX() > playerX) inputKarari = SolaGit;
			else if (GetKonumX() < playerX) inputKarari = SagaGit;
			else inputKarari = InputYok;
		}
		else{
			if (GetKonumY() > playerY) inputKarari = YukariGit;
			else if (GetKonumY() < playerY) inputKarari = AsagiyaGit;
			else inputKarari = InputYok;
		}
	}
	int DusmanSaldirisi()override
	{
		return GetHasar();
	}
	void DusmanKararMerkezi(int playerY, int playerX,InputKonumlari& inputKarari,bool& saldirabilirMi) override {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())
			SetGorusMesafesindeMi(true);
		else
			SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())
			SetSaldiriMenzilindeMi(true);
		else
			SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi())
		{
			if (playerY == GetKonumY() || playerX == GetKonumX())
				saldirabilirMi = true;
			else
				PlayerHizala(playerY,playerX,inputKarari);
		}
		else if (GetPlayeriGorduMu())
			PlayereGit(playerY,playerX,inputKarari);
		else
			RandomDusmanHaraketYonetici(inputKarari);
	}
};
class SavasciDusman : public Dusman{
private:
public:
	SavasciDusman()	{
		SetMaxCan(150);
		SetCan(150);
		SetHasar(10);
		SetGorusMesafesi(40);
		SetSaldiriMenzili(1);
	}
	int DusmanSaldirisi()override
	{return GetHasar();}
	void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari,bool& saldirabilirMi) override {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())
			SetGorusMesafesindeMi(true);
		else
			SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())
			SetSaldiriMenzilindeMi(true);
		else
			SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi())
			saldirabilirMi = true;
		else if (GetPlayeriGorduMu())
			PlayereGit(playerY, playerX, inputKarari);
		else
			RandomDusmanHaraketYonetici(inputKarari);
	}
};
class StandartDusman : public Dusman{
private:
public:
	StandartDusman(){
		SetMaxCan(100);
		SetCan(100);
		SetHasar(2);
		SetGorusMesafesi(10);
		SetSaldiriMenzili(1);
	}
	int DusmanSaldirisi()override
	{return GetHasar();}
	void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) override {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())
			SetGorusMesafesindeMi(true);
		else
			SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())
			SetSaldiriMenzilindeMi(true);
		else
			SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi())
			saldirabilirMi = true;
		else if (GetPlayeriGorduMu())
			PlayereGit(playerY, playerX, inputKarari);
		else
			RandomDusmanHaraketYonetici(inputKarari);
	}
};
class Player : public HareketEdebilenler {
private:
	BaseStat playerStat;
public:
	int GetPlayerCan();
	int GetPLayerMaxCan();
	int GetPlayerHasar();
	void SetPLayerCan(int _can);
	void SetPlayerMaxCan(int _maxCan);
	void SetPlayerHasar(int _hasar);
	BaseStat GetPlayerSatas();
	void SetPLayerSatas(int _can,int _maxCan,int _hasar);
	void PlayerHasarAl(int _hasar)
	{
		SetPLayerCan(GetPlayerCan() - _hasar);
	}
};
struct Varliklar {
	Player player;
	std::vector<Dusman*> dusmanListesi;
};
