#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Ticket.h"
using namespace std;
class Movie : public Ticket {
protected:
	int id = 0000;
	int* Consumables = nullptr;
	int noConsumables = 0;
	string type = "Normal";
	int row = 0;
	int place = 0;
	static string TYPE1;
	static string TYPE2;
	static int MINROW;
	static int MAXROW;
	static int MINPLACE;
	static int MAXPLACE;
	static int CONSUMABLE1;
	static int CONSUMABLE2;
public:

	 virtual void setTicket(string TYPE, int ROW, int PLACE, int NOCONSUMABLES, int* CONSUMABLES, int CONSUMABLES_SIZE) {
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
			for (int i=0; i < noConsumables; i++) {
				outputBinaryFile.write(reinterpret_cast<char*>(&this->Consumables[i]), sizeof(int));
			}
			outputBinaryFile.close();
		}
	}

	void setTType(string TYPE) {
		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
			this->type = TYPE;
		}
		else {
			throw exception("No such ticket Type");
		}
	}

	void setTROW(int ROW) {
		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}
	}


	void setTPLACE(int PLACE) {
		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}
	}

	void setTNoConsumables(int NOCONSUMABLES) {
		if (NOCONSUMABLES < 0) {
			throw exception("Invalid number");
		}
		else {
			this->noConsumables = NOCONSUMABLES;
		}
	}

	void addConsumable(int* CONSUMABLES) {
		if (CONSUMABLES != nullptr) {
			if (CONSUMABLES[0] == Movie::CONSUMABLE1 || CONSUMABLES[0] == Movie::CONSUMABLE2) {
				if (this->Consumables != nullptr) {
					delete[] this->Consumables;
				}
				int* newArray = new int[this->noConsumables + 1];
				for (int i = 0; i < this->noConsumables; i++) {
					newArray[i] = CONSUMABLES[i];
				};
				this->Consumables = newArray;
			}
			else {
				throw exception("Wrong consumable type");
			}
		}
		else {
			this->Consumables = nullptr;
		}
	}

	int generateRandomID() {
		this->id = 1000 + rand() % 9000;
		return this->id;
	}

	static string movieInfo() {
		return "Consumables: 1)Popcorn 2)Nachos   Rows: 5; Seats : 100; Movie: Five Nights at Freddy's; Date: 11/23/2023; Time: 16:00";
	}

	Movie() {
		this->setTType("Normal");
		this->setTROW(1);
		this->setTPLACE(1);
		this->setTNoConsumables(0);
		this->addConsumable(nullptr);
	}

	void getInfo() {
		cout << endl << "Ticket type:";
		string TYPE;
		cin >> TYPE;
		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
			this->type = TYPE;
		}
		else {
			cout << "No such ticket Type";
			exit(EXIT_FAILURE);
		}
		cout << "Row:";
		int ROW;
		cin >> ROW;
		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
			this->row = ROW;
		}
		else {
			cout << "No such Row";
			exit(EXIT_FAILURE);
		}
		cout << "Place:";
		int PLACE;
		cin >> PLACE;
		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			cout << "No such Place";
			exit(EXIT_FAILURE);
		}
		cout << endl << "How many consumable items would you like to purchase:";
		cin >> noConsumables;
		if (noConsumables > 0) {
			delete[] Consumables;
			Consumables = new int[noConsumables];
			for (int i = 0; i < noConsumables; ++i) {
				cout << "Enter a consumable:";
				int consumable;
				cin >> consumable;
				if (consumable == Movie::CONSUMABLE1 || consumable == Movie::CONSUMABLE2) {
					Consumables[i] = consumable;
				}
				else {
					cout << "No such consumable Type";
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	string getType() {
		return this->type;
	}

	int getRow() {
		return this->row;
	}

	int getPlace() {
		return this->place;
	}

	int* getConsumables() {
		int* copy = new int[noConsumables];
		if (noConsumables > 0) {
			for (int i = 0; i < noConsumables; ++i) {
				copy[i] = Consumables[i];
			}
		}
		return copy;
	}

	int getRandomId() {
		return this->id;
	}

	int getNoConsumablers() {
		return this->noConsumables;
	}

	Movie operator+(int consumable) {
		Movie copy = *this;
		copy.Consumables = new int[copy.noConsumables + 1];
		for (int i = 0; i < copy.noConsumables; ++i) {
			copy.Consumables[i] = Consumables[i];
		}
		if (consumable == CONSUMABLE1 || consumable == CONSUMABLE2) {
			copy.Consumables[copy.noConsumables] = consumable;
		}
		else {
			throw exception("Wrong consumable");
		}
		copy.noConsumables++;

		return copy;
	}

	Movie operator++(int) {
		Movie copy = *this;
		if (this->noConsumables > 0) {
			int* newArray = new int[this->noConsumables + 1];
			for (int i = 0; i < this->noConsumables; ++i) {
				newArray[i] = this->Consumables[i];
			}
			newArray[this->noConsumables] = this->Consumables[this->noConsumables - 1];
			this->noConsumables++;

			delete[] this->Consumables;
			this->Consumables = newArray;
		}

		return copy;
	}


	virtual void printInfo() {
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
	friend void operator>>(istream& console, Movie& movie);
};

