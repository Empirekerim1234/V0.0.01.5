#include "Varliklar.h"
#include "Veriler.h"
#include <vector>

int HareketEdebilenler::GetKonumY() const
{return konumY;}
int HareketEdebilenler::GetKonumX() const
{return konumX;}
void HareketEdebilenler::SetKonum(const int y, const int x)
{konumY = y; konumX = x;}
void HareketEdebilenler::SetKonum(const int konum[])
{konumY = konum[0];	konumX = konum[1];}
void HareketEdebilenler::SetYasiyorMu(bool _yasiyorMu)
{yasiyorMu = _yasiyorMu;}
bool HareketEdebilenler::GetYasiyormu()
{return yasiyorMu;}
char HareketEdebilenler::GetSembol()
{return sembol;}
void HareketEdebilenler::SetSembol(char c)
{sembol = c;}
void Dusman::DusmanSayaciSiniriAyarla()
{dusmanSayacSiniri = 1 + (rand() % 10);}
bool Dusman::GetSaldiriMenzilindeMi()
{return saldirabilirMi;}
bool Dusman::GetPlayeriGorduMu()
{return playeriGorduMu;}
void Dusman::SetGorusMesafesindeMi(bool _gorusMesafesindeMi)
{playeriGorduMu = _gorusMesafesindeMi;}
void Dusman::SetSaldiriMenzilindeMi(bool _saldiriMenzilindeMi)
{saldirabilirMi = _saldiriMenzilindeMi;}
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
void Dusman::RandomDusmanHaraketYonetici(InputKonumlari&inputKarar){
	int karar = (1 + (rand() % 4));
	if (karar == 1)inputKarar = YukariGit;
	else if (karar == 2)inputKarar = AsagiyaGit;
	else if (karar == 3)inputKarar = SolaGit;
	else if (karar == 4)inputKarar = SagaGit;
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
		if (playerMesafe <= gorusMesafesi){
			if (playerMesafe <= saldiriMenzili)	{/*Saldır;*/}
			else PlayereGit(playerY, playerX, inputKarari);
		}
		else
		{sayac = 0;DusmanSayaciSiniriAyarla();RandomDusmanHaraketYonetici(inputKarari);}
	}
	else{inputKarari = InputYok;sayac++;}
}
BaseStat Dusman::GetStat()
{return Stat;}
int Dusman::GetGorusMesafesi()
{return gorusMesafesi;}
int Dusman::GetSaldiriMenzili()
{return saldiriMenzili;}
void Dusman::SetStat(BaseStat _stats)
{Stat = _stats;}
void Dusman::SetGorusMesafesi(int _gorusMesafesi)
{gorusMesafesi = _gorusMesafesi;}
void Dusman::SetSaldiriMenzili(int _saldiriMenzili)
{saldiriMenzili = _saldiriMenzili;}
int Dusman::GetCan()
{return Stat.Can;}
int Dusman::GetMaxCan()
{return Stat.MaxCan;}
int Dusman::GetHasar()
{return Stat.Hasar;}
void Dusman::SetCan(int _can)
{Stat.Can = _can;}
void Dusman::SetMaxCan(int _maxCan)
{Stat.MaxCan = _maxCan;}
void Dusman::SetHasar(int _hasar)
{Stat.Hasar = _hasar;}
void  Dusman::SetPlayerGiveExp(int _givExp)
{playerGiveExp = _givExp;}
void  Dusman::SetRegenCan(int x)
{Stat.RegenCan = x;}
int  Dusman::GetRegenCan()
{return Stat.RegenCan;}
int  Dusman::GetGiveExp()
{return playerGiveExp;}
int Player::GetPlayerCan()
{return playerStat.Can;}
int Player::GetPLayerMaxCan()
{return playerStat.MaxCan;}
int Player::GetPlayerHasar()
{return playerStat.Hasar;}
void Player::SetPLayerCan(int _can)
{playerStat.Can = _can;}
void Player::SetPlayerMaxCan(int _maxCan)
{playerStat.MaxCan = _maxCan;}
void Player::SetPlayerHasar(int _hasar)
{playerStat.Hasar = _hasar;}
BaseStat Player::GetPlayerSatas()
{return playerStat;}
void Player::SetPLayerSatas(int _can,int _maxCan,int _hasar)
{playerStat.Can = _can;playerStat.MaxCan = _maxCan;playerStat.Hasar = _hasar;}
void Player::PlayerHasarAl(int _hasar)
{SetPLayerCan(GetPlayerCan() - _hasar);}
void Player::PlayerSaldir(Dusman* dusman)
{dusman->SetCan(dusman->GetCan() - GetPlayerHasar());}
Player::Player()
{LevelTablosuDoldur();SetPLayerSatas(100, 100, 10);}
void Player::LevelTablosuDoldur() {
	LevelExpTablosu[0] = 0;	LevelExpTablosu[1] = 10;
	LevelExpTablosu[2] = LevelExpTablosu[1] * 2;LevelExpTablosu[3] = LevelExpTablosu[2] * 2;
	LevelExpTablosu[4] = LevelExpTablosu[3] * 2;LevelExpTablosu[5] = LevelExpTablosu[4] * 2;
	LevelExpTablosu[6] = LevelExpTablosu[5] * 2;LevelExpTablosu[7] = LevelExpTablosu[6] * 2;
	LevelExpTablosu[8] = LevelExpTablosu[7] * 2;LevelExpTablosu[9] = LevelExpTablosu[8] * 2;
	LevelExpTablosu[10] = LevelExpTablosu[9] * 2;LevelExpTablosu[11] = LevelExpTablosu[10] * 2;
	LevelExpTablosu[12] = LevelExpTablosu[11] * 2;LevelExpTablosu[13] = LevelExpTablosu[12] * 2;
	LevelExpTablosu[14] = LevelExpTablosu[13] * 2;LevelExpTablosu[15] = LevelExpTablosu[14] * 2;
	LevelExpTablosu[16] = LevelExpTablosu[15] * 2;LevelExpTablosu[17] = LevelExpTablosu[16] * 2;
	LevelExpTablosu[18] = LevelExpTablosu[17] * 2;LevelExpTablosu[19] = LevelExpTablosu[18] * 2;
}
int Player::GetLevelTablosuEleman(int i)
{return LevelExpTablosu[i];}
bool Player::LevelAtlayabilirMi(){
	if (level < 19)	return true;
	return false;
}
void Player::AddMaxCan()
{Player::playerStat.MaxCan += 10;}
void Player::AddCan()
{playerStat.Can += 10;}
void Player::PlayerRegenCan(int x){
	playerStat.Can += x;
	if (playerStat.Can >= playerStat.MaxCan)playerStat.Can = playerStat.MaxCan;
}
void Player::AddPlayerRegenCan()
{playerStat.RegenCan++;}
void Player::LevelAdd()
{if (LevelAtlayabilirMi()){level++;AddMaxCan();AddCan();}}
int Player::GetPlayerRegenCan()
{return playerStat.RegenCan;}
void Player::SetPlayerRegenCan(int x)
{playerStat.RegenCan = x;}
int Player::GetLevel()
{return level;}
void Player::AddExp(int _xp)
{xp += _xp;}
int Player::GetExp()
{return xp;}
void Player::GiveXp(int _xp) {
	xp += _xp;
	if (level < 19){
		if (xp >= LevelExpTablosu[level + 1]) {
			do{
				xp -= LevelExpTablosu[level];
				LevelAdd();
			if (xp <= LevelExpTablosu[level])break;
			} while (true);
		}
	}
}
MenzilliDusman::MenzilliDusman() 
{SetMaxCan(50);SetCan(50);SetHasar(3);SetGorusMesafesi(30);SetSaldiriMenzili(5);SetPlayerGiveExp(20);}
void MenzilliDusman::PlayerHizala(int playerY, int playerX, InputKonumlari& inputKarari) {
	int mesafeX = playerX - GetKonumX(),mesafeY = playerY - GetKonumY();
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
int MenzilliDusman::DusmanSaldirisi()
{return GetHasar();}
void MenzilliDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
	if (mesafe <= GetGorusMesafesi())SetGorusMesafesindeMi(true);
	else SetGorusMesafesindeMi(false);
	if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
	else SetSaldiriMenzilindeMi(false);
	if (GetSaldiriMenzilindeMi()){
		if (playerY == GetKonumY() || playerX == GetKonumX()) saldirabilirMi = true;
		else PlayerHizala(playerY, playerX, inputKarari);
	}
	else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
	else	RandomDusmanHaraketYonetici(inputKarari);
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
{return GetHasar();}
void SavasciDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
	if (mesafe <= GetGorusMesafesi())	SetGorusMesafesindeMi(true);
	else	SetGorusMesafesindeMi(false);
	if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
	else	SetSaldiriMenzilindeMi(false);
	if (GetSaldiriMenzilindeMi())	saldirabilirMi = true;
	else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
	else	RandomDusmanHaraketYonetici(inputKarari);
}
StandartDusman::StandartDusman()
{SetMaxCan(100); SetCan(100); SetHasar(4); SetGorusMesafesi(10); SetSaldiriMenzili(1); SetPlayerGiveExp(10);}
int StandartDusman::DusmanSaldirisi()
{return GetHasar();}
void StandartDusman::DusmanKararMerkezi(int playerY, int playerX, InputKonumlari& inputKarari, bool& saldirabilirMi) {
	int mesafe = PlayerlaMesafeyiHesapla(playerY, playerX);
	if (mesafe <= GetGorusMesafesi())	SetGorusMesafesindeMi(true);
	else	SetGorusMesafesindeMi(false);
	if (mesafe <= GetSaldiriMenzili())	SetSaldiriMenzilindeMi(true);
	else	SetSaldiriMenzilindeMi(false);
	if (GetSaldiriMenzilindeMi())	saldirabilirMi = true;
	else if (GetPlayeriGorduMu())	PlayereGit(playerY, playerX, inputKarari);
	else	RandomDusmanHaraketYonetici(inputKarari);
}