#include "Input.h"
#include <iostream>
#include "Veriler.h"
#include <conio.h>

void OyunDurmuskenInput(OyunDurumlari& oyunDurum, const char tus) {
	const char kapatmaTus = ' ', devamEttirmeTus = '"';
	if (tus == kapatmaTus)oyunDurum = kapant;
	else if (tus == devamEttirmeTus)oyunDurum = devamet;
}
void OyunDevamEderkenInput(OyunDurumlari& oyunDurum, const char tus,InputKonumlari& InputKarar) {
	//27 = esc
	const char durdurTus = 27, yukariGitTus = 'w', asagiGitTus = 's', solaGitTus = 'a', sagaGitTus = 'd',saldiriTus = 'r';
	const char etkilseimTus = 'e';
	if (tus == durdurTus)oyunDurum = durdur;
	else if (tus == yukariGitTus)InputKarar = YukariGit;
	else if (tus == asagiGitTus)InputKarar = AsagiyaGit;
	else if (tus == solaGitTus)InputKarar = SolaGit;
	else if (tus == sagaGitTus)InputKarar = SagaGit;
	else if (tus == saldiriTus)InputKarar = Saldir;
	else if (tus == etkilseimTus)InputKarar = etkilesimeGec;
}
void OyunDurumunaGoreInputOku(OyunDurumlari& oyunDurum,InputKonumlari& InputKarar) {
	int InputTusKod = 0;
	const char esc = 27;
	if (_kbhit()) {
		char tus = _getch();
		if (oyunDurum == devamet)
			OyunDevamEderkenInput(oyunDurum, tus,InputKarar);
		else if (oyunDurum == durdur)
			OyunDurmuskenInput(oyunDurum, tus);
	}
}