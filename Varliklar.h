#pragma once
#include "Veriler.h"
#include <vector>
#include "Kirilebilirler.h"
#include "VarlikPlayer.h"

struct Varliklar {
	Player player;
	std::vector<Dusman*> dusmanListesi;
	std::vector<Kirilebilirler*> kirilabilenListesi;
};