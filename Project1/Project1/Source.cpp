#include <iostream>
#include <string>
using namespace std;
#include "Football.h"
#include "Movie.h"
#include "Theater.h"

//class Football {
//	int id = 0000;
//	int price = 15000;
//	int bets[5] = { 100, 200, 300, 400, 500 };
//	char* supportingTeam = nullptr;
//	const int noTeams = 2;
//	const int teamsSize = 1;
//	int stand = 0;
//	int row = 0;
//	int place = 0;	
//	static int MINSTAND;
//	static int MAXSTAND;
//	static int MINROW;
//	static int MAXROW;
//	static int MINPLACE;
//	static int MAXPLACE;
//	static char TEAM1;
//	static char TEAM2;
//public:
//	void setTicket(int STAND, int ROW, int PLACE, char* TEAM) {
//		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
//			this->stand = STAND;
//		}
//		else {
//			throw exception("No such Stand");
//		}
//
//		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//
//		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//
//		if (TEAM != nullptr) {
//			if (TEAM[0] == Football::TEAM1 || TEAM[0] == Football::TEAM2) {
//				this->supportingTeam = new char[teamsSize + 1];
//				for (int i = 0; i < teamsSize; ++i) {
//					this->supportingTeam[i] = TEAM[i];
//				}
//			}
//			else {
//				throw invalid_argument("Invalid team.");
//			}
//		}
//		else {
//			this->supportingTeam = nullptr;
//		}
//	}
//
//	void setTSupportingTeam(char* TEAM) {
//		if (TEAM != nullptr) {
//			if (TEAM[0] == Football::TEAM1 || TEAM[0] == Football::TEAM2) {
//				this->supportingTeam = new char[teamsSize + 1];
//				for (int i = 0; i < teamsSize; ++i) {
//					this->supportingTeam[i] = TEAM[i];
//				}
//			}
//			else {
//				throw invalid_argument("Invalid team.");
//			}
//		}
//		else {
//			this->supportingTeam = nullptr; 
//		}
//	}
//	
//	void setTRow(int ROW) {
//		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//	}
//
//	void setTPlace(int PLACE) {
//		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//	}
//
//	void setTStand(int STAND) {
//		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
//			this->stand = STAND;
//		}
//		else {
//			throw exception("No such Stand");
//		}
//	}
//
//	int generateRandomID() {
//		this->id = 1000 + rand() % 9000;
//		return this->id;
//	}
//
//	static string matchInfo() {
//		return "Rows: 5; Seats: 100; Match: A:Real Madrid VS B:Liverpool; Date: 12/15/2023; Time: 13:00";
//	}
//
//	void getInfo() {
//		if (supportingTeam != nullptr) {
//			delete[] supportingTeam;
//		}
//
//		supportingTeam = new char[teamsSize + 1];
//		for (int i = 0; i < teamsSize; ++i) {
//			cout << "Enter what team you like:";
//			char team;
//			cin >> team;
//			if (team == Football::TEAM1 || team == Football::TEAM2) {
//				supportingTeam[i] = team;
//			}
//			else {
//				cout << "Please select team A:Real Madrid or team B:Liverpool.";
//				exit(EXIT_FAILURE);
//			}
//		}
//		cout << endl << "Stand:";
//		int STAND;
//		cin >> STAND;
//		if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
//			this->stand = STAND;
//		}
//		else {
//			cout << "No such Stand";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Row:";
//		int ROW;
//		cin >> ROW;
//		if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			cout << "No such Row";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Place:";
//		int PLACE;
//		cin >> PLACE;
//		if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			cout << "No such Place";
//			exit(EXIT_FAILURE);
//		}
//	}
//
//	Football() {
//		this->setTStand(1);
//		this->setTRow(1);
//		this->setTPlace(1);
//		this->setTSupportingTeam(nullptr);
//	}
//
//	int getStand() {
//		return this->stand;
//	}
//
//	int getRow() {
//		return this->row;
//	}
//
//	int getPlace() {
//		return this->place;
//	}
//
//	char* getSupportingTeam() {
//		if (supportingTeam == nullptr) {
//			cout << "No team selected.";
//			return nullptr;  
//		}
//		else {
//			char* copy = new char[teamsSize + 1];
//			for (int i = 0; i < teamsSize; ++i) {
//				copy[i] = supportingTeam[i];
//			}
//			copy[teamsSize] = '\0';
//			return copy;
//		}
//	}
//
//	int getRandomId() {
//		return this->id;
//	}
//
//	explicit operator int() {
//		int price = this->price;
//		price = price / this->getRow();
//		return price;
//	}
//
//	int& operator[](int index) {
//		return bets[index];
//	}
//
//	void printInfo() {
//		cout << endl << ".......................................";
//		cout << endl << this->stand;
//		cout << endl << this->row;
//		cout << endl << this->place << endl;
//		if (supportingTeam == nullptr) {
//			cout << "No team selected.";
//		}
//		else {
//			for (int i = 0; i < 1; ++i) {
//				cout << supportingTeam[i] << " ";
//			}
//		}
//		cout << endl << this->generateRandomID();
//		cout << endl << ".......................................";
//		};
//	friend void operator>>(istream& console, Football& football);
//	friend void operator<<(ostream& console, Football& football);
//};

int Football::MAXPLACE = 20;
int Football::MAXROW = 5;
int Football::MAXSTAND = 2;
int Football::MINPLACE = 1;
int Football::MINSTAND = 1;
int Football::MINROW = 1;
char Football::TEAM1 = 'A';
char Football::TEAM2 = 'B';

void operator>>(istream& console, Football& football) {
	football.supportingTeam = new char[football.teamsSize + 1];
	for (int i = 0; i < football.teamsSize; ++i) {
		cout << "Enter what team you like:";
		char team;
		console >> team;
		if (team == Football::TEAM1 || team == Football::TEAM2) {
			football.supportingTeam[i] = team;
		}
		else {
			cout << "Please select team A:Real Madrid or team B:Liverpool.";
			exit(EXIT_FAILURE);
		}
	}
	cout << endl << "Stand:";
	int STAND;
	console >> STAND;
	if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
		football.stand = STAND;
	}
	else {
		cout << "No such Stand";
		exit(EXIT_FAILURE);
	}
	cout << "Row:";
	int ROW;
	console >> ROW;
	if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
		football.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place:";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
		football.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}
}

void operator<<(ostream& console, Football& football) {
	console << "INFO:" << " " << Football::matchInfo() << endl;
	console << endl << ".........................................................";
	char* team = football.getSupportingTeam();
	console << endl << "Supported team:" << " ";
	for (int i = 0; i < football.teamsSize; i++) {
		console << team[i] << " ";
	}
	console << endl << "Stand:" << football.getStand();
	console << endl << "Row:" << football.getRow();
	console << endl << "Place:" << football.getPlace();
	console << endl << "ID:" << football.generateRandomID();
	console << endl << ".........................................................";
}

//class Movie {
//	int id = 0000;
//	int* Consumables = nullptr;
//	int noConsumables = 0;
//	string type = "Normal";
//	int row = 0;
//	int place = 0;
//	static string TYPE1;
//	static string TYPE2;
//	static int MINROW;
//	static int MAXROW;
//	static int MINPLACE;
//	static int MAXPLACE;
//	static int CONSUMABLE1;
//	static int CONSUMABLE2;
//public:
//	void setTicket(string TYPE, int ROW, int PLACE, int NOCONSUMABLES, int* CONSUMABLES, int CONSUMABLES_SIZE) {
//		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
//			this->type = TYPE;
//		}
//		else {
//			throw exception("No such ticket Type");
//		}
//
//		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//
//		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//		if (NOCONSUMABLES < 0) {
//			throw exception("Invalid number");
//		}
//		else {
//			this->noConsumables = NOCONSUMABLES;
//		}
//		if (noConsumables > 0) {
//			this->Consumables = new int[noConsumables];
//			for (int i = 0; i < noConsumables; i++)
//				if (CONSUMABLES_SIZE != NOCONSUMABLES) {
//					throw exception("Too many");
//				}
//				else {
//					if (CONSUMABLES[i] == CONSUMABLE1 || CONSUMABLES[i] == CONSUMABLE2) {
//						this->Consumables[i] = CONSUMABLES[i];
//					}
//					else {
//						throw exception("Wrong consumable");
//					}
//				}
//		}
//	}
//
//	void setTType(string TYPE) {
//		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
//			this->type = TYPE;
//		}
//		else {
//			throw exception("No such ticket Type");
//		}
//	}
//
//	void setTROW(int ROW) {
//		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//	}
//
//
//	void setTPLACE(int PLACE) {
//		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//	}
//
//	void setTNoConsumables(int NOCONSUMABLES) {
//		if (NOCONSUMABLES < 0) {
//			throw exception("Invalid number");
//		}
//		else {
//			this->noConsumables = NOCONSUMABLES;
//		}
//	}
//
//	void addConsumable(int* CONSUMABLES) {
//		if (CONSUMABLES != nullptr) {
//			if (CONSUMABLES[0] == Movie::CONSUMABLE1 || CONSUMABLES[0] == Movie::CONSUMABLE2) {
//				if (this->Consumables != nullptr) {
//					delete[] this->Consumables;
//				}
//				int* newArray = new int[this->noConsumables + 1];
//				for (int i = 0; i < this->noConsumables; i++) {
//					newArray[i] = CONSUMABLES[i];
//				};
//				this->Consumables = newArray;
//			}
//			else {
//				throw exception("Wrong consumable type");
//			}
//		}
//		else {
//			this->Consumables = nullptr;
//		}
//	}
//	
//	int generateRandomID() {
//		this->id = 1000 + rand() % 9000;
//		return this->id;
//	}
//
//	static string movieInfo() {
//		return "Consumables: 1)Popcorn 2)Nachos   Rows: 5; Seats : 100; Movie: Five Nights at Freddy's; Date: 11/23/2023; Time: 16:00";
//	}
//
//	Movie() {
//		this->setTType("Normal");
//		this->setTROW(1);
//		this->setTPLACE(1);
//		this->setTNoConsumables(0);
//		this->addConsumable(nullptr);
//	}
//
//	void getInfo() {
//		cout << endl << "Ticket type:";
//		string TYPE;
//		cin >> TYPE;
//		if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
//			this->type = TYPE;
//		}
//		else {
//			cout << "No such ticket Type";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Row:";
//		int ROW;
//		cin >> ROW;
//		if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			cout << "No such Row";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Place:";
//		int PLACE;
//		cin >> PLACE;
//		if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			cout << "No such Place";
//			exit(EXIT_FAILURE);
//		}
//		cout << endl << "How many consumable items would you like to purchase:";
//		cin >> noConsumables;
//		if (noConsumables > 0) {
//			delete[] Consumables;
//			Consumables = new int[noConsumables];
//			for (int i = 0; i < noConsumables; ++i) {
//				cout << "Enter a consumable:";
//				int consumable;
//				cin >> consumable;
//				if (consumable == Movie::CONSUMABLE1 || consumable == Movie::CONSUMABLE2) {
//					Consumables[i] = consumable;
//				}
//				else {
//					cout << "No such consumable Type";
//					exit(EXIT_FAILURE);
//				}
//			}
//		}
//	}
//	string getType() {
//		return this->type;
//	}
//
//	int getRow() {
//		return this->row;
//	}
//
//	int getPlace() {
//		return this->place;
//	}
//
//	int* getConsumables() {
//		int* copy = new int[noConsumables];
//		if (noConsumables > 0) {
//			for (int i = 0; i < noConsumables; ++i) {
//				copy[i] = Consumables[i];
//			}
//		}
//		return copy;
//	}
//
//	int getRandomId() {
//		return this->id;
//	}
//
//	int getNoConsumablers() {
//		return this->noConsumables;
//	}
//
//	Movie operator+(int consumable) {
//		Movie copy = *this;
//		copy.Consumables = new int[copy.noConsumables + 1];
//		for (int i = 0; i < copy.noConsumables; ++i) {
//			copy.Consumables[i] = Consumables[i];
//		}
//		if (consumable == CONSUMABLE1 || consumable == CONSUMABLE2) {
//			copy.Consumables[copy.noConsumables] = consumable;
//		}
//		else {
//			throw exception("Wrong consumable");
//		}
//		copy.noConsumables++;
//
//		return copy;
//	}
//
//	Movie operator++(int) {
//		Movie copy = *this;  
//		if (this->noConsumables > 0) {
//			int* newArray = new int[this->noConsumables + 1];
//			for (int i = 0; i < this->noConsumables; ++i) {
//				newArray[i] = this->Consumables[i];
//			}
//			newArray[this->noConsumables] = this->Consumables[this->noConsumables-1];
//			this->noConsumables++;
//
//			delete[] this->Consumables;
//			this->Consumables = newArray;
//		}
//
//		return copy;
//	}
//
//
//	void printInfo() {
//		cout << endl << ".......................................";
//		cout << endl << this->type;
//		cout << endl << this->row;
//		cout << endl << this->place;
//		cout << endl << "Consumables: ";
//		if (noConsumables > 0) {
//			for (int i = 0; i < noConsumables; ++i) {
//				cout << Consumables[i] << " ";
//			}
//		}
//		else {
//			cout << "No consumables";
//		}
//		cout << endl << this->generateRandomID();
//		cout << endl << ".......................................";
//	};
//	friend void operator>>(istream& console, Movie& movie);
//};

int Movie::MAXPLACE = 20;
int Movie::MAXROW = 5;
string Movie::TYPE1 = "Normal";
int Movie::MINPLACE = 1;
string Movie::TYPE2 = "VIP";
int Movie::MINROW = 1;
int Movie::CONSUMABLE1 = 1;
int Movie::CONSUMABLE2 = 2;

void operator<<(ostream& console, Movie& movie) {
	console << "INFO:" << " " << Movie::movieInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket type:" << movie.getType();
	console << endl << "Row:" << movie.getRow();
	console << endl << "Place:" << movie.getPlace();
	if (movie.getNoConsumablers() > 0) {
		int* consumables = movie.getConsumables();
		console << endl << "Consumables:" << " ";
		for (int i = 0; i < movie.getNoConsumablers(); i++) {
			console << consumables[i] << " ";
		}
	}
	else {
		cout << endl << "No consumables";
	}
	console << endl << "ID:" << movie.generateRandomID();
	console << endl << ".........................................................";
}

void operator>>(istream& console, Movie& movie) {
	cout << endl << "Ticket type:";
	string TYPE;
	console >> TYPE;
	if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
		movie.type = TYPE;
	}
	else {
		cout << "No such ticket Type";
		exit(EXIT_FAILURE);
	}
	cout << "Row:";
	int ROW;
	console >> ROW;
	if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
		movie.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place:";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Movie::MINPLACE && PLACE <= Movie::MAXPLACE) {
		movie.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}
	cout << endl << "How many consumable items would you like to purchase:";
	console >> movie.noConsumables;
	movie.Consumables = new int[movie.noConsumables];
	if (movie.noConsumables > 0) {
		for (int i = 0; i < movie.noConsumables; ++i) {
			cout << "Enter a consumable:";
			int consumable;
			cin >> consumable;
			if (consumable == Movie::CONSUMABLE1 || consumable == Movie::CONSUMABLE2) {
				movie.Consumables[i] = consumable;
			}
			else {
				cout << "No such consumable Type";
				exit(EXIT_FAILURE);
			}
		}
	}
}

//class Theater {
//	int id = 0000;
//	string type = "Normal";
//	int row = 0;
//	int place = 0;
//	static string CATEGORY1;
//	static string CATEGORY2;
//	static string CATEGORY3;
//	static int MINROW;
//	static int MAXROW;
//	static int MINPLACE;
//	static int MAXPLACE;
//public:
//	void setTicket(string TYPE, int ROW, int PLACE) {
//		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
//			this->type = TYPE;
//		}
//		else {
//			throw exception("No such ticket Category");
//		}
//
//		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//
//		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//	}
//
//	void setTicketAtBox(int PLACE, int ROW) {
//		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//
//		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//	}
//
//	void setTType(string TYPE) {
//		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
//			this->type = TYPE;
//		}
//		else {
//			throw exception("No such ticket Category");
//		}
//	}
//
//	void setTRow(int ROW) {
//		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			throw exception("No such Row");
//		}
//	}
//
//	void setTPlace(int PLACE) {
//		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			throw exception("No such Place");
//		}
//	}
//
//	Theater() {
//		this->setTType("Category_1");
//		this->setTRow(1);
//		this->setTPlace(1);
//	}
//
//	int generateRandomID() {
//		this->id = 1000 + rand() % 9000;
//		return this->id;
//	}
//
//	static string playInfo() {
//		return "Rows: 5; Seats: 100; Play: What the Butler Saw; Date: 11/27/2023; Time: 12:00";
//	}
//
//	string getTType() {
//		return this->type;
//	}
//
//	int getRow() {
//		return this->row;
//	}
//
//	int getPlace() {
//		return this->place;
//	}
//
//	int getRandomId() {
//		return this->id;
//	}
//
//	void getInfo() {
//		cout << endl << "Ticket category:";
//		string TYPE;
//		cin >> TYPE;
//		if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
//			this->type = TYPE;
//		}
//		else {
//			cout << "No such ticket Category";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Row:";
//		int ROW;
//		cin >> ROW;
//		if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
//			this->row = ROW;
//		}
//		else {
//			cout << "No such Row";
//			exit(EXIT_FAILURE);
//		}
//		cout << "Place:";
//		int PLACE;
//		cin >> PLACE;
//		if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
//			this->place = PLACE;
//		}
//		else {
//			cout << "No such Place";
//			exit(EXIT_FAILURE);
//		}
//	}
//
//	void printInfo() {
//		cout << endl << ".......................................";
//		cout << endl << this->type;
//		cout << endl << this->row;
//		cout << endl << this->place;
//		cout << endl << this->generateRandomID();
//		cout << endl << ".......................................";
//	};
//	friend void operator>>(istream& console, Theater& theater);
//
//	bool operator>=(Theater& theater) {
//		if (this->row >= theater.row) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	bool operator!() {
//		if (this->type == "Box") {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//};

int Theater::MAXPLACE = 20;
int Theater::MAXROW = 5;
string Theater::CATEGORY1 = "Category_1";
int Theater::MINPLACE = 1;
string Theater::CATEGORY2 = "Category_2";
int Theater::MINROW = 1;
string Theater::CATEGORY3 = "Box";

void operator<<(ostream& console, Theater& theater) {
	console << "INFO:" << " " << Theater::playInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket category:" << theater.getTType();
	console << endl << "Row:" << theater.getRow();
	console << endl << "Place:" << theater.getPlace();
	console << endl << "ID:" << theater.generateRandomID();
	console << endl << ".........................................................";
}

void operator>>(istream& console, Theater& theater) {
	cout << endl << "Ticket category:";
	string category;
	string TYPE;
	console >> TYPE;
	if (TYPE == Theater::CATEGORY1 || TYPE == Theater::CATEGORY2 || TYPE == Theater::CATEGORY3) {
		theater.type = TYPE;
	}
	else {
		cout << "No such ticket Category";
		exit(EXIT_FAILURE);
	}
	cout << "Row:";
	int ROW;
	console >> ROW;
	if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
		theater.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place:";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
		theater.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}
}


	int main() {

		/*Football football;
		football.setTRow(2);
		int price = (int)football;
		cout << endl << price << " lei";
		cout << endl << "Bet 2 is: " << football[2] << " lei";*/

		/*int consumables[] = { 1, 1 };

		Movie movie;
		movie.setTicket("VIP", 1, 1, 2, consumables, sizeof(consumables) / sizeof(consumables[0]));
		movie.printInfo();

		movie = movie + 2;
		movie.printInfo();

		movie++;
		movie.printInfo();*/
		
		/*Theater th1;
		Theater th2;
		th1.setTRow(1);
		th1.generateRandomID();
		th1.setTType("Box");
		th2.setTRow(2);
		th2.setTType("Category_1");
		th2.generateRandomID();
		if (th1 >= th2) {
			cout << "Ticket with ID : " << th1.getRandomId() << " is sitting in front of ticket with ID : " << th2.getRandomId();
		}
		else {
			cout << "Ticket with ID : " << th1.getRandomId() << " is sitting behind of ticket with ID : " << th2.getRandomId();
		}

		if (!th1) {
			cout << endl << "Ticket with ID: " << th1.getRandomId() << " is for a Box seat";
		}
		else {
			cout << endl << "Ticket with ID: " << th1.getRandomId() << " is not for a Box seat";
		}
		if (!th2) {
			cout << endl << "Ticket with ID: " << th2.getRandomId() << " is for a Box seat";
		}
		else {
			cout << endl << "Ticket with ID: " << th2.getRandomId() << " is not for a Box seat";
		}*/
		Football football;
		Movie movie;
		Theater theater;
		cout << football.matchInfo() << endl;
		cin >> football;
		cout << football;
		cout << movie.movieInfo() << endl;
		cin >> movie;
		cout << movie;
		cout << theater.playInfo() << endl;
		cin >> theater;
		cout << theater;
	}