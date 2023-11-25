#include <iostream>
#include <string>
using namespace std;


class Football {
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
	void setTicket(int STAND, int ROW, int PLACE,  char* TEAM) {
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
		this->supportingTeam = new char[teamsSize];
		for (int i = 0; i < 1; i++) {
			if (TEAM[i] == TEAM1 || TEAM[i] == TEAM2) {
				this->supportingTeam[i] = TEAM[i];
			}
			else {
				throw exception("Invalid team");
			}
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

	void setTSupportingTeam(char* TEAM) {
		char* Array = new char[teamsSize];
		for (int i = 0; i < 1; i++) {
			Array[i] = TEAM[i];
		};
		if (this->supportingTeam != nullptr) {
			delete[] this->supportingTeam;
		}
		this->supportingTeam = Array;
	}

	int generateRandomID() {
		return 1000 + rand() % 9000;
	}

	static void matchInfo() {
		cout << endl << "Rows: 5; Seats: 100; Match: A:Real Madrid VS B:Liverpool; Date: 12/15/2023; Time: 13:00" << endl;
	}

	void getInfo() {
		supportingTeam = new char[teamsSize];
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

	void getStand() {
		cout << endl << this->stand;
	}

	void getRow() {
		cout << endl << this->row;
	}

	void getPlace() {
		cout << endl << this->place;
	}

	void getSupportingTeam() {
		if (supportingTeam == nullptr) {
			cout << "No team selected.";
		}
		else {
			for (int i = 0; i < 1; ++i) {
				cout << supportingTeam[i] << " ";
			}
		}
	}

	void getRandomId() {
		cout << endl << this->generateRandomID();
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

};

int Football::MAXPLACE = 20;
int Football::MAXROW = 5;
int Football::MAXSTAND = 2;
int Football::MINPLACE = 1;
int Football::MINSTAND = 1;
int Football::MINROW = 1;
char Football::TEAM1 = 'A';
char Football::TEAM2 = 'B';

class Movie {
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
		int* newArray = new int[this->noConsumables + 1];
		for (int i = 0; i < this->noConsumables; i++) {
			newArray[i] = CONSUMABLES[i];
		};
		if (this->Consumables != nullptr) {
			delete[] this->Consumables;
		}
		this->Consumables = newArray;
	}

	int generateRandomID() {
		return 1000 + rand() % 9000;
	}

	static void movieInfo() {
		cout << endl << "Consumables:" << endl << "1)Popcorn" << endl << "2)Nachos" << endl << "Rows: 5; Seats: 100; Movie: Five Nights at Freddy's; Date: 11/23/2023; Time: 16:00" << endl;
	}

	Movie() {
		this->setTType("VIP");
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
		Consumables = new int[noConsumables];
		if (noConsumables > 0) {
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
	void getType() {
		cout << endl << this->type;
	}

	void getRow() {
		cout << endl << this->row;
	}

	void getPlace() {
		cout << endl << this->place;
	}

	void getConsumables() {
		if (noConsumables > 0) {
			for (int i = 0; i < noConsumables; ++i) {
				cout << Consumables[i] << " ";
			}
		}
		else {
			cout << "No consumables";
		}
	}

	void getRandomId() {
		cout << endl << this->generateRandomID();
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

};

int Movie::MAXPLACE = 20;
int Movie::MAXROW = 5;
string Movie::TYPE1 = "Normal";
int Movie::MINPLACE = 1;
string Movie::TYPE2 = "VIP";
int Movie::MINROW = 1;
int Movie::CONSUMABLE1 = 1;
int Movie::CONSUMABLE2 = 2;

class Theater {
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
		return 1000 + rand() % 9000;
	}

	static void playInfo() {
		cout << endl << "Rows: 5; Seats: 100; Play: What the Butler Saw; Date: 11/27/2023; Time: 12:00" << endl;
	}

	void getTType() {
		cout << endl << this->type;
	}

	void getRow() {
		cout << endl << this->row;
	}

	void getPlace() {
		cout << endl << this->place;
	}

	void getRandomId() {
		cout << endl << this->generateRandomID();
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

};

int Theater::MAXPLACE = 20;
int Theater::MAXROW = 5;
string Theater::CATEGORY1 = "Category_1";
int Theater::MINPLACE = 1;
string Theater::CATEGORY2 = "Category_2";
int Theater::MINROW = 1;
string Theater::CATEGORY3 = "Box";

	int main() {


		//Football footballTicket;
		//footballTicket.matchInfo();
		//footballTicket.getInfo();
		//footballTicket.printInfo();

		//Movie movieTicket;
		//movieTicket.movieInfo();                         // main aplication
		//movieTicket.getInfo();
		//movieTicket.printInfo();

		//Theater theaterTicket;
		//theaterTicket.playInfo();
		//theaterTicket.getInfo();
		//theaterTicket.printInfo();



		/*int consumables[] = { 1, 1 };

		Movie movie;
		movie.setTicket("VIP", 1, 1, 2, consumables, sizeof(consumables) / sizeof(consumables[0]));
		movie.printInfo();
		movie.setTType("VIP");                                             
		movie.setTROW(1);
		movie.setTPLACE(1);
		movie.setTNoConsumables(2);
		movie.addConsumable(consumables);
		movie.printInfo();*/

		/*char team[] = { 'A' };

		Football football;
		football.setTicket(1, 1, 1,  team );
		football.printInfo();
		football.setTStand(1);
		football.setTRow(1);
		football.setTPlace(1);
		football.setTSupportingTeam(team);
		football.printInfo()*/

		int consumables[] = { 1, 1 };

		Movie movie;
		movie.setTicket("VIP", 1, 1, 2, consumables, sizeof(consumables) / sizeof(consumables[0]));


		movie = movie + 2;
		movie.printInfo();

		return 0;
	}