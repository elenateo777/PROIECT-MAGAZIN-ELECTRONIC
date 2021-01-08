#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

struct dataComanda
{
	int zi, luna, an;
};

class Comanda {
	int id_comanda;
	dataComanda data;
	string MetodaPlata;
	char* MetodaLivrare;
	float TotalDePlata;

public:

	Comanda() : id_comanda(1000) {
		this->MetodaLivrare = new char[strlen("Nespecificata") + 1];
		strcpy_s(this->MetodaLivrare, strlen("Nespecificata") + 1, "Nespecificata");

	}
	Comanda(int id, struct dataComanda data, string MetodaPlata, const char* MetodaLivrare, float TotalDePlata): id_comanda(id) {
	
		this->data = data;

		if (!MetodaPlata.empty()) {
			throw new exception("Eroare: MetodaPlata este empty.");
		}
		else
			this->MetodaPlata = MetodaPlata;

		if (MetodaLivrare != nullptr) {
			this->MetodaLivrare = new char[strlen(MetodaLivrare) + 1];
			strcpy_s(this->MetodaLivrare, strlen(MetodaLivrare) + 1, MetodaLivrare);
		
		}
		else {
			throw new exception("Eroare: MetodaLivrare este nullptr");
		}
		this->TotalDePlata = TotalDePlata;

	}
 
	~Comanda() {
		cout << "destructor" << endl;

		if (MetodaLivrare != nullptr) {
			delete[] MetodaLivrare;
		}
	}

	Comanda& operator = (const Comanda& cmd) {
		if (this != &cmd) {
			delete[] this->MetodaLivrare;

			this->data = cmd.data;
			this->MetodaPlata = cmd.MetodaPlata;

			this->MetodaLivrare = new char[strlen(cmd.MetodaLivrare) + 1];
			strcpy_s(this->MetodaLivrare, strlen(cmd.MetodaLivrare) + 1,cmd.MetodaLivrare);

			this->TotalDePlata = cmd.TotalDePlata;
			
		}
	}

	Comanda& operator=(const Comanda& cmd) {
		if (this != &cmd) {
			delete[] this->MetodaLivrare;

			this->data = cmd.data;
			this->MetodaPlata = cmd.MetodaPlata;

			this->MetodaLivrare = new char[strlen(cmd.MetodaLivrare) + 1];
			strcpy_s(this->MetodaLivrare, strlen(cmd.MetodaLivrare) + 1, cmd.MetodaLivrare);

			this->TotalDePlata = cmd.TotalDePlata;


		}

		return *this;
	}



};

