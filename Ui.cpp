#include "Ui.h"
#include "Varliklar.h"
#include <string>

using namespace std;

void ConsolEkraninaPlayerXYbilgiEkle(Varliklar& varliklar, EkranVerisi& ekranVerisi) {
	string playerXYString = "|X:" + to_string(varliklar.player.GetKonumX());
	playerXYString += "|Y:" + to_string(varliklar.player.GetKonumY()) + '|';
	int playerXYStringSize = playerXYString.length();
	const int playerXYtemizlemeSize = 13;
	for (int i = 0; i < playerXYStringSize; i++)ekranVerisi.consolGoruntu[0][i] = playerXYString[i];
	for (int i = 0; i < playerXYtemizlemeSize - playerXYStringSize; i++)ekranVerisi.consolGoruntu[0][i + playerXYStringSize] = ' ';
}
void ConsolEkraninaSaatiBas(EkranVerisi& ekranVerisi) {
	string oyunZamaniString = "|Gunduz||Saati|00:00|| Gun: Pazartesi || Ay: 00 || Yil: 0000|";
	int oyunZamaniSize = oyunZamaniString.length();
	const int oyunZamaniBaslangicKonum = 45;
	for (int i = 0; i < oyunZamaniSize; i++)ekranVerisi.consolGoruntu[0][i + 45] = oyunZamaniString[i];
}
void ConsolEkraninaFpsEkle(EkranVerisi& ekranVerisi, int fps) {
	const int FpsBaslangic = 148;
	string FpsString = "FPS: " + to_string(fps);
	int FpsStringSize = FpsString.length();
	for (int i = 0; i < FpsStringSize; i++)	ekranVerisi.consolGoruntu[0][FpsBaslangic + i] = FpsString[i];
}
void ConsolEkranEklenecekOyunEkranAyiraci(EkranVerisi& ekranVerisi) {
	const int genislik = 156;
	const int yukseklik = 32;
	const int ekranAyiraciBaslangicY = 2;
	const int ekranAyiraciBaslangicX = 0;
	const char yanKose = 186, ustKose = '=', bosluk = ' ';
	for (int i = 0; i < genislik; i++) {
		ekranVerisi.consolGoruntu[1][i + ekranAyiraciBaslangicX] = ustKose;
		ekranVerisi.consolGoruntu[yukseklik][i + ekranAyiraciBaslangicX] = ustKose;
	}
	for (int i = 0; i < yukseklik - 2; i++) {
		ekranVerisi.consolGoruntu[i + ekranAyiraciBaslangicY][0] = yanKose;
		ekranVerisi.consolGoruntu[i + ekranAyiraciBaslangicY][genislik - 1] = yanKose;
	}
}
void ConsolEkraninaEnvanterAlaniEkle(EkranVerisi& ekranVerisi) {
	const char kose = '#';
	const int envanterBaslangicKonumuY = 34;
	const int envanterBaslangicKonumuX = 0;
	const int envanterGesnislik = 52;
	const int envanterYukseklik = 5;
	const int envanterSlotYukseklik = envanterYukseklik - 2;
	for (int i = 0; i < envanterGesnislik; i++) {
		ekranVerisi.consolGoruntu[envanterBaslangicKonumuY][envanterBaslangicKonumuX + i] = kose;
		ekranVerisi.consolGoruntu[envanterBaslangicKonumuY + 3][envanterBaslangicKonumuX + i] = kose;
		ekranVerisi.consolGoruntu[envanterBaslangicKonumuY + 6][envanterBaslangicKonumuX + i] = kose;
	}
	for (int y = 0; y < envanterYukseklik; y++) {
		for (int x = 0; x < envanterGesnislik; x++)
		{
			if (x % envanterSlotYukseklik == 0)ekranVerisi.consolGoruntu[envanterBaslangicKonumuY + 1 + y][envanterBaslangicKonumuX + x] = kose;
		}
	}
}
void ConsolEkraninaHotBarEkle(EkranVerisi& ekranVerisi) {
	const char hotBarCizgi = 176;
	const int hotBarBaslangicKonumuY = 33;
	const int hotBarBaslangicKonumuX = 55;
	const int hotBarYukseklik = 4;
	const int hotBarGenislik = (hotBarYukseklik * 11) + 2;
	const int hotBarSlotGenislik = hotBarYukseklik + 1;
	const int hotBarSlotItemAdIndex = 1;
	const int hotBarSlotItemAdetIndex = hotBarSlotItemAdIndex + 1;
	for (int y = 0; y < hotBarYukseklik; y++) {
		for (int x = 0; x < hotBarGenislik; x++) {
			if (y == 0)	ekranVerisi.consolGoruntu[hotBarBaslangicKonumuY + y][hotBarBaslangicKonumuX + x] = hotBarCizgi;
			else if (y == hotBarSlotItemAdIndex || y == hotBarSlotItemAdetIndex) {
				if (x % hotBarSlotGenislik == 0)	ekranVerisi.consolGoruntu[hotBarBaslangicKonumuY + y][hotBarBaslangicKonumuX + x] = hotBarCizgi;
				else ekranVerisi.consolGoruntu[hotBarBaslangicKonumuY + y][hotBarBaslangicKonumuX + x] = ' ';
			}
			else ekranVerisi.consolGoruntu[hotBarBaslangicKonumuY + y][hotBarBaslangicKonumuX + x] = hotBarCizgi;
		}
	}
}
void ConsolEkraninaAciklamaKismiEkle(EkranVerisi& ekranVerisi) {
	string AciklamaString = "|Ornek Aciklama..............................|";
	int AciklamaStringSize = AciklamaString.length();
	const int AciklamaBaslangicKonumY = 37;
	const int AciklamaBaslangicKonumX = 55;
	const int aciklamaYukseklik = 4;
	for (int y = 0; y < aciklamaYukseklik; y++)
	{
		for (int x = 0; x < AciklamaStringSize; x++)ekranVerisi.consolGoruntu[AciklamaBaslangicKonumY + y][AciklamaBaslangicKonumX + x] = AciklamaString[x];
	}
}
void ConsolEkraninaPlayerStateEkle(EkranVerisi& ekranVerisi,Player& player) {
	const int playerSatetBaslangicY = 33;
	const int playerSatetBaslangicX = 136;
	const string playerstatBaslik = "Player Stat";
	string playerStateleri = "Level:100/100";
	string PLayerCanString = "Can: ";
	PLayerCanString += to_string(player.GetPLayerMaxCan());
	PLayerCanString += '/';
	PLayerCanString += to_string(player.GetPlayerCan());
	int playerStatBaslikSize = playerstatBaslik.length();
	int playerStateleriSize = playerStateleri.length();
	int playerCanStringSize = PLayerCanString.length();
	const int playerStatYukseklik = 7;
	for (int i = 0; i < playerStatBaslikSize; i++)	ekranVerisi.consolGoruntu[playerSatetBaslangicY][playerSatetBaslangicX + i] = playerstatBaslik[i];
	for (int y = 0; y < playerStatYukseklik; y++) {
		if (y == 1)
		{
			for (int x = 0; x < playerCanStringSize; x++)
				ekranVerisi.consolGoruntu[playerSatetBaslangicY + 1 + y][playerSatetBaslangicX + x] = PLayerCanString[x];
		}
		else
		{
			for (int x = 0; x < playerStateleriSize; x++)
			{
				ekranVerisi.consolGoruntu[playerSatetBaslangicY + 1 + y][playerSatetBaslangicX + x] = playerStateleri[x];
			}
		}
	}
}
void ConsolEkraninaListeVeStatAyiracEkle(EkranVerisi& ekranVerisi) {
	const int ayiracBaslangicY = 33;
	const int ayiracBaslangicX = 135;
	const char karakter = 186;
	const int ayiracYukseklik = 8;
	for (int y = 0; y < ayiracYukseklik; y++)	ekranVerisi.consolGoruntu[ayiracBaslangicY + y][ayiracBaslangicX] = karakter;
}
void ConsolEkraninaGorevListesiEkle(EkranVerisi& ekranVerisi) {
	string gorevListesi = ".Orenk Yapmalisin Gorev Metni";
	string gorevListesiBaslik = "Gorev Listesi";
	string gorevListesiSatirDahil;
	int gorevListesiSize = gorevListesi.length();
	int gorevListesiBaslikSize = gorevListesiBaslik.length();
	const int gorevListesiBaslangicY = 33;
	const int gorevListesiBaslangicX = 102;
	const int gorevListesiYukseklik = 7;
	for (int i = 0; i < gorevListesiBaslikSize; i++)ekranVerisi.consolGoruntu[gorevListesiBaslangicY][gorevListesiBaslangicX + i] = gorevListesiBaslik[i];
	for (int y = 0; y < gorevListesiYukseklik; y++) {
		int satirIndex = y + 1;
		gorevListesiSatirDahil = to_string(satirIndex) + gorevListesi;
		int gorevListesiSatirDahilSize = gorevListesiSatirDahil.length();
		for (int x = 0; x < gorevListesiSatirDahilSize; x++)ekranVerisi.consolGoruntu[gorevListesiBaslangicY + 1 + y][gorevListesiBaslangicX + x] = gorevListesiSatirDahil[x];
	}
}
void ConsolUstUi(Varliklar& varliklar, EkranVerisi& ekranVerisi, int fps) {
	ConsolEkraninaPlayerXYbilgiEkle(varliklar, ekranVerisi);
	ConsolEkraninaSaatiBas(ekranVerisi);
	ConsolEkraninaFpsEkle(ekranVerisi, fps);
}
void ConsolAltUi(EkranVerisi& ekranVerisi,Player& player) {
	ConsolEkranEklenecekOyunEkranAyiraci(ekranVerisi);
	ConsolEkraninaEnvanterAlaniEkle(ekranVerisi);
	ConsolEkraninaHotBarEkle(ekranVerisi);
	ConsolEkraninaAciklamaKismiEkle(ekranVerisi);
	ConsolEkraninaGorevListesiEkle(ekranVerisi);
	ConsolEkraninaListeVeStatAyiracEkle(ekranVerisi);
	ConsolEkraninaPlayerStateEkle(ekranVerisi,player);
}
void EkranaUiEkle(Varliklar& varliklar, EkranVerisi& ekranVerisi, int fps)
{
	ConsolUstUi(varliklar, ekranVerisi, fps);
	ConsolAltUi(ekranVerisi,varliklar.player);
}