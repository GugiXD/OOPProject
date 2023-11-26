#pragma once
#include <iostream>
#include <string>
using namespace std;
class Theater {
	int id = 0000;
	string type = "Category_1";
	int row = 0;
	int place = 0;
	static string CATEGORY1;
	static string CATEGORY2;
	static string CATEGORY3;
	static int MINROW;
	static int MAXROW;
	static int MINPLACE;
	static int MAXPLACE;
public:
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
	}

	void setTicketAtBox(int PLACE, int ROW) {
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
	}

	void setTType(string TYPE) {
		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
			this->type = TYPE;
		}
		else {
			throw exception("No such ticket Category");
		}
	}

	void setTRow(int ROW) {
		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
			this->row = ROW;
		}
		else {
			throw exception("No such Row");
		}
	}

	void setTPlace(int PLACE) {
		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
			this->place = PLACE;
		}
		else {
			throw exception("No such Place");
		}
	}

	Theater() {
		this->setTType("Category_1");
		this->setTRow(1);
		this->setTPlace(1);
	}

	int generateRandomID() {
		this->id = 1000 + rand() % 9000;
		return this->id;
	}

	static string playInfo() {
		return "Rows: 5; Seats: 100; Play: What the Butler Saw; Date: 11/27/2023; Time: 12:00";
	}

	string getTType() {
		return this->type;
	}

	int getRow() {
		return this->row;
	}

	int getPlace() {
		return this->place;
	}

	int getRandomId() {
		return this->id;
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

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->type;
		cout << endl << this->row;
		cout << endl << this->place;
		cout << endl << this->generateRandomID();
		cout << endl << ".......................................";
	};
	friend void operator>>(istream& console, Theater& theater);

	bool operator>=(Theater& theater) {
		if (this->row >= theater.row) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!() {
		if (this->type == this->CATEGORY3) {
			return true;
		}
		else {
			return false;
		}
	}

};
