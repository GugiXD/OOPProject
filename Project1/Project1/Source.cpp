#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Football.h"
#include "Movie.h"
#include "Theater.h"
#include "FootballPremium.h"
#include "TheaterWithParking.h"
#include "AgeRestrictedMovie.h"
#include "Ticket.h"

int FootballPremium::PREMROW = 0;
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
		cout << "Enter what team you like between team A:Real Madrid or team B:Liverpool:";
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
	cout << endl << "Stand (1 or 2):";
	int STAND;
	console >> STAND;
	if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
		football.stand = STAND;
	}
	else {
		cout << "No such Stand";
		exit(EXIT_FAILURE);
	}
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
		football.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
		football.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}
	ofstream outputBinaryFile("FootballData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(reinterpret_cast<char*>(&football.stand), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&football.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&football.place), sizeof(int));
		for (int i = 0; i < 1; i++) {
			outputBinaryFile.write(football.supportingTeam, strlen(football.supportingTeam)+1);
		}
		outputBinaryFile.close();
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
	console << endl << "Available bets:";
	for (int i = 0; i < 5; i++) {
		cout << " " << football[i] << " lei";
	}
	console << endl << "All bets will be done an hour before the event at our betting registers.";
	int price = (int)football;
	console << endl << "Price: " << price;
	console << endl << ".........................................................";
}

void operator>>(istream& console, FootballPremium& football) {
	football.supportingTeam = new char[football.teamsSize + 1];
	for (int i = 0; i < football.teamsSize; ++i) {
		cout << "Enter what team you like between team A:Real Madrid or team B:Liverpool:";
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
	cout << endl << "Stand (1 or 2):";
	int STAND;
	console >> STAND;
	if (STAND >= Football::MINSTAND && STAND <= Football::MAXSTAND) {
		football.stand = STAND;
	}
	else {
		cout << "No such Stand";
		exit(EXIT_FAILURE);
	}
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Football::MINROW && ROW <= Football::MAXROW) {
		football.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Football::MINPLACE && PLACE <= Football::MAXPLACE) {
		football.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}
	ofstream outputBinaryFile("FootballData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(reinterpret_cast<char*>(&football.stand), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&football.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&football.place), sizeof(int));
		for (int i = 0; i < 1; i++) {
			outputBinaryFile.write(football.supportingTeam, strlen(football.supportingTeam) + 1);
		}
		outputBinaryFile.close();
	}
}

void operator<<(ostream& console, FootballPremium& football) {
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
	console << endl << "Available bets:";
	for (int i = 0; i < 5; i++) {
		cout << " " << football[i] << " lei";
	}
	console << endl << "Additional bets:";
	for (int i = 0; i < 5; i++) {
		cout << " " << football.getExtraBet(i) << " lei";
	}
	console << endl << "All bets will be done an hour before the event at our betting registers.";
	console << endl << "Price: " << football.getPremiumPrice();
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
	console << "INFO:" << " " << movie.movieInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket type:" << movie.getType();
	console << endl << "Row:" << movie.getRow();
	console << endl << "Place:" << movie.getPlace();
	if (movie.getNoConsumablers() > 0) {
		int* consumables = movie.getConsumables();
		console << endl << "Consumables:" << " ";
		for (int i = 0; i < movie.getNoConsumablers(); i++) {
			if (consumables[i] = 1) {
				console << "popcorn" << " ";
			}
			else if (consumables[i] = 1) {
				console << "nachos" << " ";
			}
		}
	}
	else {
		cout << endl << "No consumables";
	}
	console << endl << "ID:" << movie.generateRandomID();
	console << endl << ".........................................................";
}

void operator>>(istream& console, Movie& movie) {
	cout << endl << "Ticket type (Please choose between VIP and Normal):";
	string TYPE;
	console >> TYPE;
	if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
		movie.type = TYPE;
	}
	else {
		cout << "No such ticket Type";
		exit(EXIT_FAILURE);
	}
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
		movie.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
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
			cout << "Enter a consumable (enter 1 popcorn, or 2 for nachos):";
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
	ofstream outputBinaryFile("MovieData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(movie.type.c_str(), movie.type.size() + 1);
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.place), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.noConsumables), sizeof(int));
		for (int i = 0; i < movie.noConsumables; i++) {
			outputBinaryFile.write(reinterpret_cast<char*>(&movie.Consumables[i]), sizeof(int));
		}
		outputBinaryFile.close();
	}
}

void operator>>(istream& console, AgeRestrictedMovie& movie) {
	cout << endl << "Ticket type (Please choose between VIP and Normal):";
	string TYPE;
	console >> TYPE;
	if (TYPE == Movie::TYPE1 || TYPE == Movie::TYPE2) {
		movie.type = TYPE;
	}
	else {
		cout << "No such ticket Type";
		exit(EXIT_FAILURE);
	}
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Movie::MINROW && ROW <= Movie::MAXROW) {
		movie.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
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
			cout << "Enter a consumable (enter 1 popcorn, or 2 for nachos):";
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
	ofstream outputBinaryFile("MovieData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(movie.type.c_str(), movie.type.size() + 1);
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.place), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&movie.noConsumables), sizeof(int));
		for (int i = 0; i < movie.noConsumables; i++) {
			outputBinaryFile.write(reinterpret_cast<char*>(&movie.Consumables[i]), sizeof(int));
		}
		outputBinaryFile.close();
	}
}

void operator<<(ostream& console, AgeRestrictedMovie& movie) {
	console << "INFO:" << " " << AgeRestrictedMovie::movieInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket type:" << movie.getType();
	console << endl << "Row:" << movie.getRow();
	console << endl << "Place:" << movie.getPlace();
	if (movie.getNoConsumablers() > 0) {
		int* consumables = movie.getConsumables();
		console << endl << "Consumables:" << " ";
		for (int i = 0; i < movie.getNoConsumablers(); i++) {
			if (consumables[i] = 1) {
				console << "popcorn" << " ";
			}
			else if (consumables[i] = 1) {
				console << "nachos" << " ";
			}
		}
	}
	else {
		cout << endl << "No consumables";
	}
	console << endl << "ID:" << movie.generateRandomID();
	console << endl << ".........................................................";
}

int Theater::MAXPLACE = 20;
int Theater::MAXROW = 5;
string Theater::CATEGORY1 = "Category_1";
int Theater::MINPLACE = 1;
string Theater::CATEGORY2 = "Category_2";
int Theater::MINROW = 1;
string Theater::CATEGORY3 = "Box";

int TheaterWithParking::MINPARKING = 1;
int TheaterWithParking::MAXPARKING = 30;

void operator<<(ostream& console, Theater& theater) {
	console << "INFO:" << " " << Theater::playInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket category:" << theater.getType();
	console << endl << "Row:" << theater.getRow();
	console << endl << "Place:" << theater.getPlace();
	console << endl << "ID:" << theater.generateRandomID();
	console << endl << ".........................................................";
	console << endl << "List of plays that you can watch at our theater:";
	for (const string& play : theater.upcomingPlays) {
		console << endl << " - " << play;
	}
	console << endl << ".........................................................";
}

void operator>>(istream& console, Theater& theater) {
	cout << endl << "Ticket category (Please choose between Box, Category_1, and Category_2):";
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
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
		theater.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
		theater.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}

	theater.upcomingPlays.push_back("What the Butler Saw (Date: 11/27/2023)");
	theater.upcomingPlays.push_back("Death of a Salesman (Date not revealed)");
	theater.upcomingPlays.push_back("Waiting for Godot (Date not revealed)");
	ofstream outputBinaryFile("TheaterData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(theater.type.c_str(), theater.type.size() + 1);
		outputBinaryFile.write(reinterpret_cast<char*>(&theater.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&theater.place), sizeof(int));
		outputBinaryFile.close();
	}
}

void operator>>(istream& console, TheaterWithParking& theater) {
	cout << endl << "Ticket category (Please choose between Box, Category_1, and Category_2):";
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
	cout << "Row (1-5):";
	int ROW;
	console >> ROW;
	if (ROW >= Theater::MINROW && ROW <= Theater::MAXROW) {
		theater.row = ROW;
	}
	else {
		cout << "No such Row";
		exit(EXIT_FAILURE);
	}
	cout << "Place (1-20):";
	int PLACE;
	console >> PLACE;
	if (PLACE >= Theater::MINPLACE && PLACE <= Theater::MAXPLACE) {
		theater.place = PLACE;
	}
	else {
		cout << "No such Place";
		exit(EXIT_FAILURE);
	}

	theater.upcomingPlays.push_back("What the Butler Saw (Date: 11/27/2023)");
	theater.upcomingPlays.push_back("Death of a Salesman (Date not revealed)");
	theater.upcomingPlays.push_back("Waiting for Godot (Date not revealed)");
	ofstream outputBinaryFile("TheaterData.bin", ios::out | ios::binary | ios::app);

	if (outputBinaryFile.is_open()) {
		outputBinaryFile.write(theater.type.c_str(), theater.type.size() + 1);
		outputBinaryFile.write(reinterpret_cast<char*>(&theater.row), sizeof(int));
		outputBinaryFile.write(reinterpret_cast<char*>(&theater.place), sizeof(int));
		outputBinaryFile.close();
	}
}

void operator<<(ostream& console, TheaterWithParking& theater) {
	console << "INFO:" << " " << Theater::playInfo() << endl;
	console << endl << ".........................................................";
	console << endl << "Ticket category:" << theater.getType();
	console << endl << "Row:" << theater.getRow();
	console << endl << "Place:" << theater.getPlace();
	console << endl << "ID:" << theater.generateRandomID();
	console << endl << "Parking space:" << theater.generateParking();
	console << endl << ".........................................................";
	console << endl << "List of plays that you can watch at our theater:";
	for (const string& play : theater.upcomingPlays) {
		console << endl << " - " << play;
	}
	console << endl << ".........................................................";
}

void chooseFootball(int choice) {
	Football football;
	FootballPremium footballp;
	if (choice == 1) {
		cout << endl << "You selected the Premium Ticket." << endl;
		cin >> footballp;
		cout << footballp;
		exit(0); 
	}
	else if (choice == 2) {
		cout << endl << "You selected the normal ticket." << endl;
		cin >> football;
		cout << football;
		exit(0);
	}
	else if (choice == 0) {
		cout << endl << "Exiting aplication." << endl;
		exit(0);
	}
	else {
		cout << endl << "Invalid choice. Please enter 0, 1, or 2." << endl;
	}
}

void chooseMovie(int choice) {
	Movie movie;
	AgeRestrictedMovie movie18;
	if (choice == 1) {
		cout << endl << "You selected the age restricted movie." << endl;
		cin >> movie18;
		cout << movie18;
		exit(0);
	}
	else if (choice == 2) {
		cout << endl << "You selected the normal movie." << endl;
		cin >> movie;
		cout << movie;
		exit(0);
	}
	else if (choice == 0) {
		cout << endl << "Exiting aplication." << endl;
		exit(0);
	}
	else {
		cout << endl << "Invalid choice. Please enter 0, 1, or 2." << endl;
	}
}

void chooseTheater(int choice) {
	Theater theater;
	TheaterWithParking theaterp;
	if (choice == 1) {
		cout << endl << "You selected the ticket with parking." << endl;
		cin >> theaterp;
		cout << theaterp;
		exit(0);
	}
	else if (choice == 2) {
		cout << endl << "You selected the normal ticket." << endl;
		cin >> theater;
		cout << theater;
		exit(0);
	}
	else if (choice == 0) {
		cout << endl << "Exiting aplication." << endl;
		exit(0);
	}
	else {
		cout << endl << "Invalid choice. Please enter 0, 1, or 2." << endl;
	}
}

void chooseTicket() {
	int userInput;
	cout << "Enter 1 to buy a football ticket, 2 for a movie ticket, 3 for a theater ticket, or 0 to stop: ";
	cin >> userInput;

	if (userInput == 0) {
		exit(0);
	}
	else if (userInput == 1) {
		int FootballChoice;

		while (true) {
			Football football;
			cout << football.matchInfo() << endl;
			cout << "Type 1 if you want to buy a Premium ticket, type 2 if you want a Normal ticket, type 0 if you want to close the aplication. ";
			cin >> FootballChoice;

			chooseFootball(FootballChoice);
		}
	}
	else if (userInput == 2) {
		int MovieChoice;

		while (true) {
			int age;
			cout << "Enter your age:";
			cin >> age;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid age. Please enter a valid age." << endl;
				continue;
			}
			if (age >= 18 && age < 100) {
				Movie movie;
				AgeRestrictedMovie movie18;
				cout << movie.movieInfo();
				cout << endl << movie18.movieInfo();
				cout << endl << "Type 1 if you want to buy a ticket to the movie The Nun II, type 2 if you want to buy a ticket to the movie Five Nights at Freddy's, type 0 if you want to close the aplication. " << endl;
				cin >> MovieChoice;

				chooseMovie(MovieChoice);
			}
			else if (age > 100 || age < 0) {
				cout << "Invalid age" << endl;
			}
			else {
				Movie movie;
				cout << movie.movieInfo();
				chooseMovie(2);
			}
		}
	}
	else if (userInput == 3) {
		int TheaterChoice;

		while (true) {
			Theater theater;
			cout << theater.playInfo() << endl;
			cout << "Type 1 if you want to buy a ticket that includes parking, type 2 if you want a normal ticket, type 0 if you want to close the aplication. ";
			cin >> TheaterChoice;

			chooseTheater(TheaterChoice);
		}
	}
	else {
		cout << "Invalid input. Please enter 0, 1, 2, or 3." << endl;
	}
}

	int main() {
		while (true) {
			chooseTicket();
		}
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

		/*int FootballChoice;

		while (true) {
			Football football;
			cout << football.matchInfo() << endl;
			cout << "Type 1 if you want to buy a Premium ticket, type 2 if you want a Normal ticket, type 0 if you want to close the aplication. ";
			cin >> FootballChoice;

			chooseFootball(FootballChoice);
		}*/

		/*int MovieChoice;

		while (true) {
			int age;
			cout << "Enter your age:";
			cin >> age;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid age. Please enter a valid age." << endl;
				continue;
			}
			if (age >= 18 && age < 100) {
				Movie movie;
				AgeRestrictedMovie movie18;
				cout << movie.movieInfo();
				cout << endl << movie18.movieInfo();
				cout << endl << "Type 1 if you want to buy a ticket to the movie The Nun II, type 2 if you want to buy a ticket to the movie Five Nights at Freddy's, type 0 if you want to close the aplication. " << endl;
				cin >> MovieChoice;

				chooseMovie(MovieChoice);
			}
			else if (age > 100 || age < 0) {
				cout << "Invalid age" << endl;
			}
			else {
				Movie movie;
				cout << movie.movieInfo();
				chooseMovie(2);
			}
		}*/
		/*int TheaterChoice;

		while (true) {
			Theater theater;
			cout << theater.playInfo() << endl;
			cout << "Type 1 if you want to buy a ticket that includes parking, type 2 if you want a normal ticket, type 0 if you want to close the aplication. ";
			cin >> TheaterChoice;

			chooseTheater(TheaterChoice);
		}*/


		/*int consumable[] = { 1,2 };

		Movie  movie;
		movie.setTNoConsumables(2);
		movie.addConsumable(consumable);
		cout << movie.getConsumables();*/
		
		/*fstream file;
		ifstream inputFile("TheaterTicket.txt", ios::in);
		if (inputFile.is_open()) {
			string type;
			inputFile >> type;
			int row;
			inputFile >> row;
			int place;
			inputFile >> place;
			Theater theater;
			theater.setTicket(type, row, place);
			cout << theater;
			inputFile.close();
		}*/
		/*fstream file;
		ifstream inputFile("MovieTicket.txt", ios::in);
		if (inputFile.is_open()) {
			string type;
			inputFile >> type;
			int row;
			inputFile >> row;
			int place;
			inputFile >> place;
			int noConsumables;
			inputFile >> noConsumables;
			int* consumables = new int[noConsumables];
			for (int i = 0; i < noConsumables; i++) {
				inputFile >> consumables[i];
			}
			Movie movie;
			movie.setTicket(type, row, place, noConsumables, consumables, sizeof(consumables) / sizeof(consumables[0]));
			cout << movie;
			inputFile.close();
		}*/
		/*fstream file;
		ifstream inputFile("FootballTicket.txt", ios::in);
		if (inputFile.is_open()) {
			int stand;
			inputFile >> stand;
			int row;
			inputFile >> row;
			int place;
			inputFile >> place;
			char* team = new char[1];
			for (int i = 0; i < 1; i++) {
				inputFile >> team[i];
			}
			Football football;
			football.setTicket(stand, row, place, team);
			cout << football;
			inputFile.close();
		}*/
		
		return 0;
	}
	