#pragma once
#include "Movie.h" 

class AgeRestrictedMovie : public Movie {
private:
    bool hasAgeRestriction;

public:
    AgeRestrictedMovie() : Movie(), hasAgeRestriction(true) {
    }

    void setTicket(string TYPE, int ROW, int PLACE, int NOCONSUMABLES, int* CONSUMABLES, int CONSUMABLES_SIZE) {
		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
			this->type = TYPE;
		}
		else {
			throw exception("No such ticket Type");
		}

		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}

		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}
		if (NOCONSUMABLES < 0) {
			throw exception("Invalid number");
		}
		else {
			this->noConsumables = NOCONSUMABLES;
		}
		if (noConsumables > 0) {
			this->Consumables = new int[noConsumables];
			for (int i = 0; i < noConsumables; i++)
				if (CONSUMABLES_SIZE != NOCONSUMABLES) {
					throw exception("Too many");
				}
				else {
					if (CONSUMABLES[i] == CONSUMABLE1 || CONSUMABLES[i] == CONSUMABLE2) {
						this->Consumables[i] = CONSUMABLES[i];
					}
					else {
						throw exception("Wrong consumable");
					}
				}
		}
		ofstream outputBinaryFile("MovieData.bin", ios::out | ios::binary | ios::app);

		if (outputBinaryFile.is_open()) {
			outputBinaryFile.write(this->type.c_str(), this->type.size() + 1);
			outputBinaryFile.write(reinterpret_cast<char*>(&this->row), sizeof(int));
			outputBinaryFile.write(reinterpret_cast<char*>(&this->place), sizeof(int));
			outputBinaryFile.write(reinterpret_cast<char*>(&this->noConsumables), sizeof(int));
			for (int i = 0; i < noConsumables; i++) {
				outputBinaryFile.write(reinterpret_cast<char*>(&this->Consumables[i]), sizeof(int));
			}
			outputBinaryFile.close();
		}
    }

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->type;
		cout << endl << this->row;
		cout << endl << this->place;
		cout << endl << "Consumables: ";
		if (noConsumables > 0) {
			for (int i = 0; i < noConsumables; ++i) {
				cout << Consumables[i] << " ";
			}
		}
		else {
			cout << "No consumables";
		}
		cout << endl << this->generateRandomID();
		cout << endl << ".......................................";
	};

    bool getRestriction() const {
        return hasAgeRestriction;
    }
 
};


