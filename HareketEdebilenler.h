#pragma once

struct OyunTamKonumlar {
	const int minOyunEkraniSinirKonum[2] = { 1, 1 };
	const int maxOyunHaritasiSinirKonum[2] = { 500,500 };
};
struct BaseStat {
	int MaxCan = 100;
	int Can = 100;
	int RegenCan = 1;
	int Hasar = 5;
};
class HareketEdebilenler {
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