#include "Kamera.h"
#include "Varliklar.h"
#include <vector>

using namespace std;

int KameraKonumAyarlaX(const Player& player,const OyunGozukenHaritaVerisi& gHarita,int tamHaritaGenislik)
{
	const int kameraMinSolKoseMesafe = gHarita.genislik / 2;

	int kameraKonumX = player.GetKonumX();

	kameraKonumX = player.GetKonumX();

	int ekranSolUstX = kameraKonumX - kameraMinSolKoseMesafe;
	if (ekranSolUstX < 0)
		ekranSolUstX = 0;

	if (ekranSolUstX > tamHaritaGenislik - gHarita.genislik)ekranSolUstX = tamHaritaGenislik - gHarita.genislik;
	return ekranSolUstX;
}
int KameraKonumAyarlaY(const Player& player,const OyunGozukenHaritaVerisi& gHarita,int tamHaritaYukseklik)
{
	const int kameraMinUstKoseMesafe = gHarita.yukseklik / 2;
	int kameraKonumY = player.GetKonumY();
	kameraKonumY = player.GetKonumY();
	int ekranSolUstY = kameraKonumY - kameraMinUstKoseMesafe;
	if (ekranSolUstY < 0)ekranSolUstY = 0;
	if (ekranSolUstY > tamHaritaYukseklik - gHarita.yukseklik)ekranSolUstY = tamHaritaYukseklik - gHarita.yukseklik;
	return ekranSolUstY;
}
