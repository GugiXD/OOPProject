#pragma once
#include "Theater.h" 

class TheaterWithParking : public Theater {
private:
    bool hasParking = true;
    int parkingSpace = 0; 
	static int MINPARKING;
	static int MAXPARKING;

public:
    TheaterWithParking() : Theater(), hasParking(false) {
    }

    void setTicket(string TYPE, int ROW, int PLACE) {
		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
			this->type = TYPE;
		}
		else {
			throw exception("No such ticket Category");
		}

		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}

		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}
		ofstream outputBinaryFile("TheaterData.bin", ios::out | ios::binary | ios::app);

		if (outputBinaryFile.is_open()) {
			outputBinaryFile.write(this->type.c_str(), this->type.size() + 1);
			outputBinaryFile.write(reinterpret_cast<char*>(&this->row), sizeof(int));
			outputBinaryFile.write(reinterpret_cast<char*>(&this->place), sizeof(int));
			outputBinaryFile.close();
		}
    }

	void setParking(int PLACE) {
		if (PLACE >= TheaterWithParking::MINPARKING && PLACE <= TheaterWithParking::MAXPARKING) {
			this->parkingSpace = PLACE;
		}
		else {
			throw exception("No parking space");
		}
	}

	void getInfo() {
		cout << endl << "Ticket category:";
		string TYPE;
		cin >> TYPE;
		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
			this->type = TYPE;
		}
		else {
			cout << "No such ticket Category";
			exit(EXIT_FAILURE);
		}
		cout << "Row:";
		int ROW;
		cin >> ROW;
		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
			this->row = ROW;
		}
		else {
			cout << "No such Row";
			exit(EXIT_FAILURE);
		}
		cout << "Place:";
		int PLACE;
		cin >> PLACE;
		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			cout << "No such Place";
			exit(EXIT_FAILURE);
		}
	}

    int getParkingSpace() const {
        return parkingSpace;
    }

	int generateParking() {
		this->parkingSpace = 1 + rand() % 30;
		return this->parkingSpace;
	}

	friend void operator>>(istream& console, TheaterWithParking& theater);
	friend void operator<<(ostream& console, TheaterWithParking& theater);
};

