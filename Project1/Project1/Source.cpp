#include <iostream>
#include <string>
using namespace std;
#include "Football.h"
#include "Movie.h"
#include "Theater.h"


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