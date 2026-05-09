#pragma once
#include "HareketEdebilenler.h"
#include "VarlikDusman.h"
#include "Kirilebilirler.h"

class Player : public HareketEdebilenler {
private:
	BaseStat playerStat;
	int xp = 0;
	int level = 0;
	int nextLevelExp;
	int BaseKirmaHasar = 2;
	int LevelExpTablosu[20];
public:
	Player();
	int GetPlayerCan();
	int GetPLayerMaxCan();
	int GetPlayerHasar();
	void SetPLayerCan(int _can);
	void SetPlayerMaxCan(int _maxCan);
	void SetPlayerHasar(int _hasar);
	BaseStat GetPlayerSatas();
	void SetPLayerSatas(int _can, int _maxCan, int _hasar);
	void PlayerHasarAl(int _hasar);
	void PlayerSaldir(Dusman* dusman);
	void LevelTablosuDoldur();
	int GetLevelTablosuEleman(int i);
	bool LevelAtlayabilirMi();
	void AddMaxCan();
	void AddCan();
	void PlayerRegenCan(int x);
	void AddPlayerRegenCan();
	void LevelAdd();
	int GetPlayerRegenCan();
	void SetPlayerRegenCan(int x);
	int GetLevel();
	void AddExp(int _xp);
	int GetExp();
	void GiveXp(int _xp);
	void SetKirmaHasari(int x);
	int GetKirmaHasari();
	void Kirma(Kirilebilirler*& kirilabilen);
};