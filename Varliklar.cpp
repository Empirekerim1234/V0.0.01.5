#include "Varliklar.h"
#include "Veriler.h"
#include <vector>

int HareketEdebilenler::GetKonumY() const
{
	return konumY;
}
int HareketEdebilenler::GetKonumX() const
{
	return konumX;
}
void HareketEdebilenler::SetKonum(const int y, const int x)
{
	konumY = y; konumX = x;
}
void HareketEdebilenler::SetKonum(const int konum[])
{
	konumY = konum[0];	konumX = konum[1];
}
void HareketEdebilenler::SetYasiyorMu(bool _yasiyorMu)
{
	yasiyorMu = _yasiyorMu;
}
bool HareketEdebilenler::GetYasiyormu()
{
	return yasiyorMu;
}
char HareketEdebilenler::GetSembol()
{
	return sembol;
}
void HareketEdebilenler::SetSembol(char c)
{
	sembol = c;
}
void Dusman::DusmanSayaciSiniriAyarla()
{
	dusmanSayacSiniri = 1 + (rand() % 10);
}
bool Dusman::GetSaldiriMenzilindeMi()
{
	return saldirabilirMi;
}
bool Dusman::GetPlayeriGorduMu()
{
	return playeriGorduMu;
}
void Dusman::SetGorusMesafesindeMi(bool _gorusMesafesindeMi)
{
	playeriGorduMu = _gorusMesafesindeMi;
}
void Dusman::SetSaldiriMenzilindeMi(bool _saldiriMenzilindeMi)
{
	saldirabilirMi = _saldiriMenzilindeMi;
}
int Dusman::PlayerlaMesafeyiHesapla(int playerY, int playerX)
{
	int playereMesafeX;
	int playerMesafeY;
	int playerMesafeHesaplamaX;
	int playerMesafeHespalamaY;
	double playerMesafe;
	playereMesafeX = playerX - GetKonumX();
	playerMesafeY = playerY - GetKonumY();
	if (playereMesafeX < 0)
		playereMesafeX *= -1;
	if (playerMesafeY < 0)
		playerMesafeY *= -1;
	playerMesafeHesaplamaX = playereMesafeX * playereMesafeX;
	playerMesafeHespalamaY = playerMesafeY * playerMesafeY;
	playerMesafe = playerMesafeHesaplamaX + playerMesafeHespalamaY;
	playerMesafe = sqrt(playerMesafe);
	return playerMesafe;
}
void Dusman::RandomDusmanHaraketYonetici(InputKonumlari&inputKarar)
{
	int karar = (1 + (rand() % 4));
	if (karar == 1)
		inputKarar = YukariGit;
	else if (karar == 2)
		inputKarar = AsagiyaGit;
	else if (karar == 3)
		inputKarar = SolaGit;
	else if (karar == 4)
		inputKarar = SagaGit;
}
void Dusman::PlayereGit(int playerY, int playerX,InputKonumlari& inputKarari) {
	if (GetKonumY() > playerY) inputKarari = YukariGit;
	else if (GetKonumY() < playerY) inputKarari = AsagiyaGit;
	else if (GetKonumX() > playerX) inputKarari = SolaGit;
	else if (GetKonumX() < playerX) inputKarari = SagaGit;
	else inputKarari = InputYok;
}
void Dusman::DusmanMoveYonetici(int playerY, int playerX,InputKonumlari& inputKarari,int gorusMesafesi,int SaldiriMenzili) {
	if (sayac >= dusmanSayacSiniri) {
		int playerMesafe = PlayerlaMesafeyiHesapla(playerY,playerX);
		if (playerMesafe <= gorusMesafesi)
		{
			if (playerMesafe <= saldiriMenzili)
			{
				//Saldır;
			}
			else
			{
				PlayereGit(playerY, playerX, inputKarari);
			}
		}
		else
		{
			sayac = 0;
			DusmanSayaciSiniriAyarla();
			RandomDusmanHaraketYonetici(inputKarari);
		}
	}
	else
	{
		inputKarari = InputYok;
		sayac++;
	}
}
BaseStat Dusman::GetStat()
{
	return Stat;
}
int Dusman::GetGorusMesafesi()
{
	return gorusMesafesi;
}
int Dusman::GetSaldiriMenzili()
{
	return saldiriMenzili;
}
void Dusman::SetStat(BaseStat _stats)
{
	Stat = _stats;
}
void Dusman::SetGorusMesafesi(int _gorusMesafesi)
{
	gorusMesafesi = _gorusMesafesi;
}
void Dusman::SetSaldiriMenzili(int _saldiriMenzili)
{
	saldiriMenzili = _saldiriMenzili;
}
int Dusman::GetCan()
{
	return Stat.Can;
}
int Dusman::GetMaxCan()
{
	return Stat.MaxCan;
}
int Dusman::GetHasar()
{
	return Stat.Hasar;
}
void Dusman::SetCan(int _can)
{
	Stat.Can = _can;
}
void Dusman::SetMaxCan(int _maxCan)
{
	Stat.MaxCan = _maxCan;
}
void Dusman::SetHasar(int _hasar)
{
	Stat.Hasar = _hasar;
}
int Player::GetPlayerCan()
{
	return playerStat.Can;
}
int Player::GetPLayerMaxCan()
{
	return playerStat.MaxCan;
}
int Player::GetPlayerHasar()
{
	return playerStat.Hasar;
}
void Player::SetPLayerCan(int _can)
{
	playerStat.Can = _can;
}
void Player::SetPlayerMaxCan(int _maxCan)
{
	playerStat.MaxCan = _maxCan;
}
void Player::SetPlayerHasar(int _hasar)
{
	playerStat.Hasar = _hasar;
}
BaseStat Player::GetPlayerSatas()
{
	return playerStat;
}
void Player::SetPLayerSatas(int _can,int _maxCan,int _hasar)
{
	playerStat.Can = _can;
	playerStat.MaxCan = _maxCan;
	playerStat.Hasar = _hasar;
}