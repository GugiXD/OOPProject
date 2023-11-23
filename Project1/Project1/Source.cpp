#include <iostream>
using namespace std;


class Football {
	int ticketsSold = 0;
	int stand = 0;
	int row = 0;
	int place = 0;	
	static int MINSTAND;
	static int MAXSTAND;
	static int MINROW;
	static int MAXROW;
	static int MINPLACE;
	static int MAXPLACE;
public:
	void setTicket(int STAND, int ROW, int PLACE) {
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
	}

	int generateRandomID() {
		return 1000 + rand() % 9000;
	}

	void matchInfo() {
		cout << endl << "Rows: 5; Seats: 100; Match: Real Madrid VS Liverpool; Date: 12/15/2023; Time: 13:00";
	}

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->stand;
		cout << endl << this->row;
		cout << endl << this->place;
		cout << endl << this->generateRandomID();
		};

};

int Football::MAXPLACE = 20;
int Football::MAXROW = 5;
int Football::MAXSTAND = 2;
int Football::MINPLACE = 1;
int Football::MINSTAND = 1;
int Football::MINROW = 1;

class Movie {
	int ticketsSold = 0;
	string type = "Normal";
	int row = 0;
	int place = 0;
	static string TYPE1;
	static string TYPE2;
	static int MINROW;
	static int MAXROW;
	static int MINPLACE;
	static int MAXPLACE;
public:
	void setTicket(string TYPE, int ROW, int PLACE) {
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
	}

	int generateRandomID() {
		return 1000 + rand() % 9000;
	}

	void movieInfo() {
		cout << endl << "Rows: 5; Seats: 100; Movie: Five Nights at Freddy's; Date: 11/23/2023; Time: 16:00";
	}

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->type;
		cout << endl << this->row;
		cout << endl << this->place;
		cout << endl << this->generateRandomID();
	};

};

int Movie::MAXPLACE = 20;
int Movie::MAXROW = 5;
string Movie::TYPE1 = "Normal";
int Movie::MINPLACE = 1;
string Movie::TYPE2 = "VIP";
int Movie::MINROW = 1;

class Theater {
	int ticketsSold = 0;
	string type = "Normal";
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

	int generateRandomID() {
		return 1000 + rand() % 9000;
	}

	void playInfo() {
		cout << endl << "Rows: 5; Seats: 100; Play: What the Butler Saw; Date: 11/27/2023; Time: 12:00";
	}

	void printInfo() {
		cout << endl << ".......................................";
		cout << endl << this->type;
		cout << endl << this->row;
		cout << endl << this->place;
		cout << endl << this->generateRandomID();
	};

};

int Theater::MAXPLACE = 20;
int Theater::MAXROW = 5;
string Theater::CATEGORY1 = "Category 1";
int Theater::MINPLACE = 1;
string Theater::CATEGORY2 = "Category 2";
int Theater::MINROW = 1;
string Theater::CATEGORY3 = "Box";

	int main() {
		const int maxFootballTickets = 100;

		Football ticket;
		Football ticket2;
		ticket.setTicket(1, 2, 3);
		ticket2.setTicket(1, 2, 3);

		ticket.printInfo();
		ticket2.printInfo();

		Movie ticketA;
		Movie ticketB;
		ticketA.setTicket("Normal", 1, 2);
		ticketB.setTicket("VIP", 3, 10);

		ticketA.printInfo();
		ticketB.printInfo();

		Theater ticketAlfa;
		Theater ticketBeta;
		ticketAlfa.setTicket("Category 1", 1, 2);
		ticketBeta.setTicket("Box", 3, 10);

		ticketAlfa.printInfo();
		ticketBeta.printInfo();

		ticket.matchInfo();
		ticketA.movieInfo();
		ticketAlfa.playInfo();
		
		return 0;
	}