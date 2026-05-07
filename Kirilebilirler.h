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
	char Sembol;
	int MaxCan;
	int Can;
	int YenidenDogmaSuresi,KirildiktanSonraGecenSure = 0;
	int KonumX;
	int KonumY;
};
enum KirilebilirDurum
{
	Saglam,Kirik,YenidenDoguyor
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
	void SetTur(KirilebilirTurler tur){
		Tur = tur;
	}
	void SetDurum(KirilebilirDurum durum){
		Durum = durum;
	}
	void SetDegerler(KirilebilirDegerleri deger){
		Deger = deger;
	}
	KirilebilirTurler GetTur(){
		return Tur;
	}
	KirilebilirDurum GetDurum(){
		return Durum;
	}
	KirilebilirDegerleri GetDegerler(){
		return Deger;
	}
	void SetSaglamSembol(char sembol)
	{Deger.SaglamSembol = sembol;}
	char GetSaglamSembol()
	{return Deger.SaglamSembol;}
	void SetKirikSembol(char sembol)
	{Deger.KirikSembol = sembol;}
	char GetKirikSembol()
	{return Deger.KirikSembol;}
	void SetSembol(char sembol)
	{Deger.Sembol = sembol;}
	char GetSembol()
	{return Deger.Sembol;}
	int GetCan()
	{return Deger.Can;}
	void SetCan(int x)
	{Deger.Can = x;}
	int GetMaxCan()
	{return Deger.MaxCan;}
	void SetMaxCan(int x)
	{Deger.MaxCan = x;}
	void SetKonumX(int x) { Deger.KonumX = x; }
	int GetKonumX()
	{return Deger.KonumX;}
	void SetKonumY(int y) { Deger.KonumY = y; }
	int GetKonumY()
	{return Deger.KonumY;}
	void SetYenidenDogmaSuresi(int x)
	{Deger.YenidenDogmaSuresi = x;}
	int GetYenidenDogmaSuresi()
	{return Deger.YenidenDogmaSuresi;}
	void GecenSureSifirla()
	{Deger.KirildiktanSonraGecenSure = 0;}
	void AddGecenSure()
	{Deger.KirildiktanSonraGecenSure++;}
	int GetGecenSure()
	{return Deger.KirildiktanSonraGecenSure;}
	void Kir()
	{
		Durum = Kirik;
		Deger.Sembol = GetKirikSembol();
		Deger.Can = 0;
	}
	bool KirildiMi()
	{
		if (Durum == Saglam)
		{
			if (Deger.Can <= 0)
				return true;
			return false;
		}
		return true;
	}
	void HasarAl(int x)
	{
		Deger.Can -= x;
		if (KirildiMi()) Kir();
	}
	void YenidenDog()
	{
		Durum = Saglam;
		Deger.Can = GetMaxCan();
		Deger.Sembol = GetSaglamSembol();
	}
	void YenidenDogmaKontrol()
	{
		if (Durum == Kirik)
		{
			if (GetGecenSure() >= GetYenidenDogmaSuresi())
			{
				YenidenDog();
				GecenSureSifirla();
			}
			else AddGecenSure();
		}
	}
	void SetKaynak(KirildigindeVerilecekKaynek x)
	{
		Deger.Kaynak = x;
	}
	KirildigindeVerilecekKaynek GetKaynak()
	{
		return Deger.Kaynak;
	}
	int RandomKaynakAmount()
	{
		return (1 +(rand() % 4));
	}
	void SetKaynakName(std::string name)
	{
		Deger.Kaynak.Name = name;
	}
	std::string GetKaynakName()
	{
		return Deger.Kaynak.Name;
	}
	void SetKaynakAmount(int x)
	{
		Deger.Kaynak.Amaount = x;
	}
	int GetKaynakAmount()
	{
		return Deger.Kaynak.Amaount;
	}
};
class KirilebilirAgacObjesi : public Kirilebilirler
{
public:
	KirilebilirAgacObjesi()	{
		SetTur(KirilabilirAgac);
		SetYenidenDogmaSuresi(500);
		SetMaxCan(100);
		SetCan(GetMaxCan());
		SetSaglamSembol('€');
		SetKirikSembol('$');
		SetSembol(GetSaglamSembol());
		SetDurum(Saglam);
		SetKaynakName("Odun");
		SetKaynakAmount(RandomKaynakAmount());
	}
};