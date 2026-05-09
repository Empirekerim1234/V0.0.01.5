#include "VarlikPlayer.h"
#include "Kirilebilirler.h"


int Player::GetPlayerCan() { return playerStat.Can; }
int Player::GetPLayerMaxCan() { return playerStat.MaxCan; }
int Player::GetPlayerHasar() { return playerStat.Hasar; }
void Player::SetPLayerCan(int _can) { playerStat.Can = _can; }
void Player::SetPlayerMaxCan(int _maxCan) { playerStat.MaxCan = _maxCan; }
void Player::SetPlayerHasar(int _hasar) { playerStat.Hasar = _hasar; }
BaseStat Player::GetPlayerSatas() { return playerStat; }
void Player::SetPLayerSatas(int _can, int _maxCan, int _hasar)
{
	playerStat.Can = _can; playerStat.MaxCan = _maxCan; playerStat.Hasar = _hasar;
}
void Player::PlayerHasarAl(int _hasar) { SetPLayerCan(GetPlayerCan() - _hasar); }
void Player::PlayerSaldir(Dusman* dusman) { dusman->SetCan(dusman->GetCan() - GetPlayerHasar()); }
Player::Player() { LevelTablosuDoldur(); SetPLayerSatas(100, 100, 10); }
void Player::LevelTablosuDoldur() {
	LevelExpTablosu[0] = 0;	LevelExpTablosu[1] = 10;
	LevelExpTablosu[2] = LevelExpTablosu[1] * 2; LevelExpTablosu[3] = LevelExpTablosu[2] * 2;
	LevelExpTablosu[4] = LevelExpTablosu[3] * 2; LevelExpTablosu[5] = LevelExpTablosu[4] * 2;
	LevelExpTablosu[6] = LevelExpTablosu[5] * 2; LevelExpTablosu[7] = LevelExpTablosu[6] * 2;
	LevelExpTablosu[8] = LevelExpTablosu[7] * 2; LevelExpTablosu[9] = LevelExpTablosu[8] * 2;
	LevelExpTablosu[10] = LevelExpTablosu[9] * 2; LevelExpTablosu[11] = LevelExpTablosu[10] * 2;
	LevelExpTablosu[12] = LevelExpTablosu[11] * 2; LevelExpTablosu[13] = LevelExpTablosu[12] * 2;
	LevelExpTablosu[14] = LevelExpTablosu[13] * 2; LevelExpTablosu[15] = LevelExpTablosu[14] * 2;
	LevelExpTablosu[16] = LevelExpTablosu[15] * 2; LevelExpTablosu[17] = LevelExpTablosu[16] * 2;
	LevelExpTablosu[18] = LevelExpTablosu[17] * 2; LevelExpTablosu[19] = LevelExpTablosu[18] * 2;
}
int Player::GetLevelTablosuEleman(int i) { return LevelExpTablosu[i]; }
bool Player::LevelAtlayabilirMi() {
	if (level < 19)	return true;
	return false;
}
void Player::AddMaxCan() { Player::playerStat.MaxCan += 10; }
void Player::AddCan() { playerStat.Can += 10; }
void Player::PlayerRegenCan(int x)
{
	playerStat.Can += x; if (playerStat.Can >= playerStat.MaxCan)playerStat.Can = playerStat.MaxCan;
}
void Player::AddPlayerRegenCan() { playerStat.RegenCan++; }
void Player::LevelAdd() { if (LevelAtlayabilirMi()) { level++; AddMaxCan(); AddCan(); } }
int Player::GetPlayerRegenCan() { return playerStat.RegenCan; }
void Player::SetPlayerRegenCan(int x) { playerStat.RegenCan = x; }
int Player::GetLevel() { return level; }
void Player::AddExp(int _xp) { xp += _xp; }
int Player::GetExp() { return xp; }
void Player::GiveXp(int _xp) {
	xp += _xp;
	if (level < 19) {
		if (xp >= LevelExpTablosu[level + 1]) {
			do {
				xp -= LevelExpTablosu[level];
				LevelAdd();
				if (xp <= LevelExpTablosu[level])break;
			} while (true);
		}
	}
}
void Player::SetKirmaHasari(int x) { BaseKirmaHasar = x; }
int Player::GetKirmaHasari() { return BaseKirmaHasar; }
void Player::Kirma(Kirilebilirler*& kirilabilen) { kirilabilen->HasarAl(GetKirmaHasari()); }