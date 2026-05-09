#include "HareketEdebilenler.h"

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