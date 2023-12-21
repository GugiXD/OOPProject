#pragma once
#include "Football.h"

class FootballPremium : public Football
{
private:
    int premiumPrice = 25000;
    int extraBets[5] = { 100, 150, 200, 250, 300 };
	static int PREMROW;

public:
    FootballPremium() : Football() {}
    void setTicket(int STAND, int ROW, int PLACE, char* TEAM) {
		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
			this->stand = STAND;
		}
		else {
			throw exception("No such Stand");
		}

		if (ROW == PREMROW) {
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
			for (int i = 0; i < 1; i++) {
				outputBinaryFile.write(this->supportingTeam, strlen(this->supportingTeam) + 1);
			}
			outputBinaryFile.close();
		}

    }

	void setTSupportingTeam(char* TEAM) {
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

    int getPremiumPrice() const {
        return premiumPrice;
    }

	int getExtraBet(int index) const {
        return extraBets[index];
    }
	friend void operator>>(istream& console, FootballPremium& football);
	friend void operator<<(ostream& console, FootballPremium& football);
};

