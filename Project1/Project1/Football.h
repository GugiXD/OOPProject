#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Ticket.h"
using namespace std;
class Football : public Ticket {
protected:
	int id = 0000;
	int price = 15000;
	int bets[5] = { 100, 200, 300, 400, 500 };
	char* supportingTeam = nullptr;
	const int noTeams = 2;
	const int teamsSize = 1;
	int stand = 0;
	int row = 0;
	int place = 0;
	static int MINSTAND;
	static int MAXSTAND;
	static int MINROW;
	static int MAXROW;
	static int MINPLACE;
	static int MAXPLACE;
	static char TEAM1;
	static char TEAM2;
public:
	virtual void setTicket(int STAND, int ROW, int PLACE, char* TEAM) {
		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
			this->stand = STAND;
		}
		else {
			throw exception("No such Stand");
		}

		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}

		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}

		if (TEAM != nullptr) {
			if (TEAM[0] == Football::TEAM1 || TEAM[0] == Football::TEAM2) {
				this->supportingTeam = new char[teamsSize + 1];
				for (int i = 0; i < teamsSize; ++i) {
					this->supportingTeam[i] = TEAM[i];
				}
			}
			else {
				throw exception("Invalid team.");
			}
		}
		else {
			this->supportingTeam = nullptr;
		}
		ofstream outputBinaryFile("FootballData.bin", ios::out | ios::binary | ios::app);

		if (outputBinaryFile.is_open()) {
			outputBinaryFile.write(reinterpret_cast<char*>(&this->stand), sizeof(int));
			outputBinaryFile.write(reinterpret_cast<char*>(&this->row), sizeof(int));
			outputBinaryFile.write(reinterpret_cast<char*>(&this->place), sizeof(int));
			for (int i = 0; i <1; i++) {
				outputBinaryFile.write(this->supportingTeam, strlen(this->supportingTeam)+1);
			}
			outputBinaryFile.close();
		}
	}

	virtual void setTSupportingTeam(char* TEAM) {
		if (TEAM != nullptr) {
			if (TEAM[0] == Football::TEAM1 || TEAM[0] == Football::TEAM2) {
				this->supportingTeam = new char[teamsSize + 1];
				for (int i = 0; i < teamsSize; ++i) {
					this->supportingTeam[i] = TEAM[i];
				}
			}
			else {
				throw exception("Invalid team.");
			}
		}
		else {
			this->supportingTeam = nullptr;
		}
	}

	void setTRow(int ROW) {
		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}
	}

	void setTPlace(int PLACE) {
		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}
	}

	void setTStand(int STAND) {
		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
			this->stand = STAND;
		}
		else {
			throw exception("No such Stand");
		}
	}

	int generateRandomID() {
		this->id = 1000 + rand() % 9000;
		return this->id;
	}

	static string matchInfo() {
		return "Rows: 5; Seats: 100; Match: A:Real Madrid VS B:Liverpool; Date: 12/15/2023; Time: 13:00";
	}

	void getInfo() {
		if (supportingTeam != nullptr) {
			delete[] supportingTeam;
		}

		supportingTeam = new char[teamsSize + 1];
		for (int i = 0; i < teamsSize; ++i) {
			cout << "Enter what team you like:";
			char team;
			cin >> team;
			if (team == Football::TEAM1 || team == Football::TEAM2) {
				supportingTeam[i] = team;
			}
			else {
				cout << "Please select team A:Real Madrid or team B:Liverpool.";
				exit(EXIT_FAILURE);
			}
		}
		cout << endl << "Stand:";
		int STAND;
		cin >> STAND;
		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
			this->stand = STAND;
		}
		else {
			cout << "No such Stand";
			exit(EXIT_FAILURE);
		}
		cout << "Row:";
		int ROW;
		cin >> ROW;
		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
			this->row = ROW;
		}
		else {
			cout << "No such Row";
			exit(EXIT_FAILURE);
		}
		cout << "Place:";
		int PLACE;
		cin >> PLACE;
		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			cout << "No such Place";
			exit(EXIT_FAILURE);
		}
	}

	Football() {
		this->setTStand(1);
		this->setTRow(1);
		this->setTPlace(1);
		this->setTSupportingTeam(nullptr);
	}

	int getStand() {
		return this->stand;
	}

	int getRow() {
		return this->row;
	}

	int getPlace() {
		return this->place;
	}

	char* getSupportingTeam() {
		if (supportingTeam == nullptr) {
			cout << "No team selected.";
			return nullptr;
		}
		else {
			char* copy = new char[teamsSize + 1];
			for (int i = 0; i < teamsSize; ++i) {
				copy[i] = supportingTeam[i];
			}
			copy[teamsSize] = '\0';
			return copy;
		}
	}

	int getRandomId() {
		return this->id;
	}

	explicit operator int() {
		int price = this->price;
		price = price / this->getRow();
		return price;
	}

	int& operator[](int index) {
		return bets[index];
	}

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->stand;
		cout << endl << this->row;
		cout << endl << this->place << endl;
		if (supportingTeam == nullptr) {
			cout << "No team selected.";
		}
		else {
			for (int i = 0; i < 1; ++i) {
				cout << supportingTeam[i] << " ";
			}
		}
		cout << endl << this->generateRandomID();
		cout << endl << ".......................................";
	};
	friend void operator>>(istream& console, Football& football);
	friend void operator<<(ostream& console, Football& football);
};

