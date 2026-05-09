#include "VarlikDusman.h"
#include <iostream>
#include "Input.h"

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
int Dusman::PlayerlaMesafeyiHesapla(int playerY, int playerX) {
	int playereMesafeX, playerMesafeY;
	int playerMesafeHesaplamaX, playerMesafeHespalamaY;
	double playerMesafe;
	playereMesafeX = playerX - GetKonumX();
	playerMesafeY = playerY - GetKonumY();
	if (playereMesafeX < 0)	playereMesafeX *= -1;
	if (playerMesafeY < 0)	playerMesafeY *= -1;
	playerMesafeHesaplamaX = playereMesafeX * playereMesafeX;
	playerMesafeHespalamaY = playerMesafeY * playerMesafeY;
	playerMesafe = playerMesafeHesaplamaX + playerMesafeHespalamaY;
	playerMesafe = sqrt(playerMesafe);
	return playerMesafe;
}
void Dusman::RandomDusmanHaraketYonetici(InputKonumlari& inputKarar) {
	int karar = (1 + (rand() % 4));
	if (karar == 1)inputKarar = YukariGit;
	else if (karar == 2)inputKarar = AsagiyaGit;
	else if (karar == 3)inputKarar = SolaGit;
	else if (karar == 4)inputKarar = SagaGit;
}
int Dusman::GetSayac() { return sayac; }
void Dusman::SayacSifirla() { sayac = 0; }
void Dusman::AddSayac() { sayac++; }
int Dusman::GetDusmanSayaciSiniri() { return dusmanSayacSiniri; }
void Dusman::PlayereGit(int playerY, int playerX, InputKonumlari& inputKarari) {
	if (GetKonumY() > playerY) inputKarari = YukariGit;
	else if (GetKonumY() < playerY) inputKarari = AsagiyaGit;
	else if (GetKonumX() > playerX) inputKarari = SolaGit;
	else if (GetKonumX() < playerX) inputKarari = SagaGit;
	else inputKarari = InputYok;
}
void Dusman::DusmanMoveYonetici(int playerY, int playerX, InputKonumlari& inputKarari, int gorusMesafesi, int SaldiriMenzili) {
	if (sayac >= dusmanSayacSiniri) {
		int playerMesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (playerMesafe <= gorusMesafesi)
		{
			if (playerMesafe > saldiriMenzili)PlayereGit(playerY, playerX, inputKarari);
		}
		else { sayac = 0; DusmanSayaciSiniriAyarla(); RandomDusmanHaraketYonetici(inputKarari); }
	}
	else { inputKarari = InputYok; sayac++; }
}
BaseStat Dusman::GetStat() { return Stat; }
int Dusman::GetGorusMesafesi() { return gorusMesafesi; }
int Dusman::GetSaldiriMenzili() { return saldiriMenzili; }
void Dusman::SetStat(BaseStat _stats) { Stat = _stats; }
void Dusman::SetGorusMesafesi(int _gorusMesafesi) { gorusMesafesi = _gorusMesafesi; }
void Dusman::SetSaldiriMenzili(int _saldiriMenzili) { saldiriMenzili = _saldiriMenzili; }
int Dusman::GetCan() { return Stat.Can; }
int Dusman::GetMaxCan() { return Stat.MaxCan; }
int Dusman::GetHasar() { return Stat.Hasar; }
void Dusman::SetCan(int _can) { Stat.Can = _can; }
void Dusman::SetMaxCan(int _maxCan) { Stat.MaxCan = _maxCan; }
void Dusman::SetHasar(int _hasar) { Stat.Hasar = _hasar; }
void  Dusman::SetPlayerGiveExp(int _givExp) { playerGiveExp = _givExp; }
void  Dusman::SetRegenCan(int x) { Stat.RegenCan = x; }
int  Dusman::GetRegenCan() { return Stat.RegenCan; }
int  Dusman::GetGiveExp() { return playerGiveExp; }

MenzilliDusman::MenzilliDusman()
{
	SetMaxCan(50); SetCan(50); SetHasar(3); SetGorusMesafesi(30); SetSaldiriMenzili(5); SetPlayerGiveExp(20);
}
void MenzilliDusman::PlayerHizala(int playerY, int playerX, InputKonumlari& inputKarari) {
	int mesafeX = playerX - GetKonumX(), mesafeY = playerY - GetKonumY();
	if (mesafeX < 0)	mesafeX *= -1;
	if (mesafeY < 0)	mesafeY *= -1;
	if (mesafeX < mesafeY) {
		if (GetKonumX() > playerX) inputKarari = SolaGit;
		else if (GetKonumX() < playerX) inputKarari = SagaGit;
		else inputKarari = InputYok;
	}
	else {
		if (GetKonumY() > playerY) inputKarari = YukariGit;
		else if (GetKonumY() < playerY) inputKarari = AsagiyaGit;
		else inputKarari = InputYok;
	}
}
int MenzilliDusman::DusmanSaldirisi() { return GetHasar(); }
void MenzilliDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	if (GetSayac() >= GetDusmanSayaciSiniri()) {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())SetGorusMesafesindeMi(true);
		else SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
		else SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi()) {
			if (playerY == GetKonumY() || playerX == GetKonumX()) saldirabilirMi = true;
			else PlayerHizala(playerY, playerX, inputKarari);
		}
		else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
		else	RandomDusmanHaraketYonetici(inputKarari);
		SayacSifirla();
	}
	else AddSayac();
}
SavasciDusman::SavasciDusman() {
	SetMaxCan(150);
	SetCan(150);
	SetHasar(5);
	SetGorusMesafesi(40);
	SetSaldiriMenzili(1);
	SetPlayerGiveExp(25);
	SetRegenCan(3);
}
int SavasciDusman::DusmanSaldirisi()
{
	return GetHasar();
}
void SavasciDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	if (GetSayac() >= GetDusmanSayaciSiniri()) {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())	SetGorusMesafesindeMi(true);
		else	SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
		else	SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi())	saldirabilirMi = true;
		else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
		else	RandomDusmanHaraketYonetici(inputKarari);
		SayacSifirla();
	}
	else AddSayac();
}
StandartDusman::StandartDusman()
{
	SetMaxCan(100); SetCan(100); SetHasar(4); SetGorusMesafesi(10); SetSaldiriMenzili(1); SetPlayerGiveExp(10);
}
int StandartDusman::DusmanSaldirisi()
{
	return GetHasar();
}
void StandartDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	if (GetSayac() >= GetDusmanSayaciSiniri()) {
		int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
		if (mesafe <= GetGorusMesafesi())	SetGorusMesafesindeMi(true);
		else	SetGorusMesafesindeMi(false);
		if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
		else	SetSaldiriMenzilindeMi(false);
		if (GetSaldiriMenzilindeMi())	saldirabilirMi = true;
		else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
		else	RandomDusmanHaraketYonetici(inputKarari);
		SayacSifirla();
	}
	else AddSayac();
}