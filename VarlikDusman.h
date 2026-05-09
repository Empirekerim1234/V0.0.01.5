#pragma once
#include "HareketEdebilenler.h"
#include "Input.h"

class Dusman : public HareketEdebilenler {
private:
	BaseStat Stat;
	int dusmanSayacSiniri, sayac = 0;
	int gorusMesafesi = 1;
	int saldiriMenzili;
	int playerGiveExp;
	bool playereYeterinceYakin = false;
	bool saldirabilirMi = false;
	bool playeriGorduMu = false;
public:
	virtual void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) = 0;
	virtual int DusmanSaldirisi() = 0;
	void DusmanSayaciSiniriAyarla();
	int GetSayac();
	void SayacSifirla();
	void AddSayac();
	int GetDusmanSayaciSiniri();
	int PlayerlaMesafeyiHesapla(int playerY, int PlayerX);
	void RandomDusmanHaraketYonetici(InputKonumlari& inputKarari);
	void PlayereGit(int playerY, int playerX, InputKonumlari& inputKarari);
	void DusmanMoveYonetici(int playerY, int playerX, InputKonumlari& inputKarari, int gorusMesafesi, int saldiriMenzili);
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
	void SetPlayerGiveExp(int _givExp);
	void SetRegenCan(int x);
	int GetRegenCan();
	int GetGiveExp();
};
class MenzilliDusman : public Dusman {
public:
	MenzilliDusman();
	void PlayerHizala(int playerY, int playerX, InputKonumlari& inputKarari);
	int DusmanSaldirisi()override;
	void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi)override;
};
class SavasciDusman : public Dusman {
private:
public:
	SavasciDusman();
	int DusmanSaldirisi()override;
	void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) override;
};
class StandartDusman : public Dusman {
private:
public:
	StandartDusman();
	int DusmanSaldirisi()override;
	void DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) override;
};