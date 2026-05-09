#pragma once
#include <string>

struct KirildigindeVerilecekKaynek
{
	std::string Name;
	int Amaount;
};

struct KirilebilirDegerleri
{
	KirildigindeVerilecekKaynek Kaynak;
	char KirikSembol = ' ';
	char SaglamSembol;
	char KaynakSembol;
	char Sembol;
	int MaxCan;
	int Can;
	int YenidenDogmaSuresi,KirildiktanSonraGecenSure = 0;
	int KonumX;
	int KonumY;
	bool KaynakToplandiMi = false;
};
enum KirilebilirDurum
{
	Saglam,Kirik,KaynakToplanmadi
};
enum KirilebilirTurler
{
	KirilabilirAgac
};
class Kirilebilirler
{
private:
	KirilebilirTurler Tur;
	KirilebilirDurum Durum;
	KirilebilirDegerleri Deger;
public:
	void SetKaynakSembol(char sembol){Deger.KaynakSembol = sembol;}
	char GetKaynakSembol(){return Deger.KaynakSembol;}
	void SetTur(KirilebilirTurler tur){Tur = tur;}
	void SetDurum(KirilebilirDurum durum){Durum = durum;}
	void SetDegerler(KirilebilirDegerleri deger){Deger = deger;}
	KirilebilirTurler GetTur(){return Tur;}
	KirilebilirDurum GetDurum(){return Durum;}
	KirilebilirDegerleri GetDegerler(){return Deger;}
	void SetSaglamSembol(char sembol){Deger.SaglamSembol = sembol;}
	char GetSaglamSembol(){return Deger.SaglamSembol;}
	void SetKirikSembol(char sembol){Deger.KirikSembol = sembol;}
	char GetKirikSembol(){return Deger.KirikSembol;}
	void SetSembol(char sembol){Deger.Sembol = sembol;}
	char GetSembol(){return Deger.Sembol;}
	int GetCan(){return Deger.Can;}
	void SetCan(int x){Deger.Can = x;}
	int GetMaxCan(){return Deger.MaxCan;}
	void SetMaxCan(int x){Deger.MaxCan = x;}
	void SetKonumX(int x) { Deger.KonumX = x; }
	int GetKonumX(){return Deger.KonumX;}
	void SetKonumY(int y) { Deger.KonumY = y; }
	int GetKonumY(){return Deger.KonumY;}
	void SetYenidenDogmaSuresi(int x){Deger.YenidenDogmaSuresi = x;}
	int GetYenidenDogmaSuresi(){return Deger.YenidenDogmaSuresi;}
	void GecenSureSifirla(){Deger.KirildiktanSonraGecenSure = 0;}
	void AddGecenSure(){Deger.KirildiktanSonraGecenSure++;}
	int GetGecenSure(){return Deger.KirildiktanSonraGecenSure;}
	void SetKaynak(KirildigindeVerilecekKaynek x){Deger.Kaynak = x;}
	KirildigindeVerilecekKaynek GetKaynak(){return Deger.Kaynak;}
	int RandomKaynakAmount(){return (1 + (rand() % 4));}
	void SetKaynakName(std::string name){Deger.Kaynak.Name = name;}
	std::string GetKaynakName(){return Deger.Kaynak.Name;}
	void SetKaynakAmount(int x){Deger.Kaynak.Amaount = x;}
	int GetKaynakAmount(){return Deger.Kaynak.Amaount;}
	void Kir(){
		Durum = KaynakToplanmadi;
		Deger.Sembol = GetKaynakSembol();
		Deger.Can = 0;
	}
	bool KirildiMi(){
		if (Durum == Saglam){
			if (Deger.Can <= 0)	return true;
				return false;
		}
		return true;
	}
	bool KaynakToplandiMi()
	{
		if (Durum == KaynakToplanmadi)
			return false;
		return true;
	}
	void HasarAl(int x){
		Deger.Can -= x;
		if (KirildiMi()) Kir();
	}
	void YenidenDog(){
		Durum = Saglam;
		Deger.Can = GetMaxCan();
		Deger.Sembol = GetSaglamSembol();
	}
	void YenidenDogmaKontrol(){
		if (Durum == Kirik)	{
			if (GetGecenSure() >= GetYenidenDogmaSuresi())
			{YenidenDog();GecenSureSifirla();}
			else AddGecenSure();
		}
	}

};
class KirilebilirAgacObjesi : public Kirilebilirler
{
public:
	KirilebilirAgacObjesi()	{
		SetTur(KirilabilirAgac);
		SetYenidenDogmaSuresi(5000);
		SetMaxCan(200);
		SetCan(GetMaxCan());
		SetSaglamSembol('€');
		SetKirikSembol('$');
		SetKaynakSembol(' ');
		SetSembol(GetSaglamSembol());
		SetDurum(Saglam);
		SetKaynakName("Odun");
		SetKaynakAmount(3);
	}
};