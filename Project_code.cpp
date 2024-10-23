#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

string actuser;

class User
{
protected:
	static string username[100];
	static string password[100];
};

string User::username[100];
string User::password[100];

class SignIn : virtual public User
{
protected:
	char ch;
	string user, pass;
	int flag = 0;
	static int locator;

public:
	void getuser()
	{
		cout << "\nEnter username: ";
		cin >> user;

		checkuser();
	}

	// Check for existence

	inline void checkuser()
	{
		for (int i = 0; i < 100; i++)
			if (username[i] == user)
			{
				flag = 1;
				break;
			}

		if (flag == 1)
		{
			cout << "\nAn account with the same username is already existing!";
			getuser();
		}

		else
			getpass();
	}

	inline void getpass()
	{
		locator++;
		username[locator] = user;

		cout << "Enter password: ";
		pass.clear();
		ch = getch();

		while (ch != 13)
		{
			if (ch == 8)
			{
				if (!pass.empty())
				{
					pass.pop_back();
					cout<<"\b \b";
				}
			}

			else
			{
				pass.push_back(ch);
				cout << "*";
			}

			ch = getch();
		}


		password[locator] = pass;

		actuser = username[locator];
		display();
	}

	inline void display()
	{
		system("cls");

		cout << "\n\n";
		for (int i = 0; i < (username[locator].length() + 1 + 10 + 2); i++)
			cout << "-";
		cout << "\n\n  Welcome " << username[locator] << "!";
		cout << "\n\n";
		for (int j = 0; j < (username[locator].length() + 1 + 10 + 2); j++)
			cout << "-";
	}
};

int SignIn::locator = -1;

class LogIn : virtual public User
{
protected:
	char ch;
	string user, pass;
	int flag = 0, i = 0;

public:
	void getuser()
	{
		cout << "\nEnter username: ";
		cin >> user;

		checkuser();
	}

	void checkuser()
	{
		for (i = 0; i < 100; i++)
			if (username[i] == user)
			{
				flag = 1;
				break;
			}

		if (flag == 0)
		{
			cout << "\nNo such account with the username" << endl;
			getuser();
		}

		else
			getpass();
	}

	void getpass()
	{
		cout << "Enter password: ";
		pass.clear();
		ch = getch();

		while (ch != 13)
		{
			if (ch == 8)
			{
				if (!pass.empty())
				{
					pass.pop_back();
					cout<<"\b \b";
				}
			}

			else
			{
				pass.push_back(ch);
				cout << "*";
			}
			
			ch = getch();
		}

		checkpass();
	}

	void checkpass()
	{
		// Match

		if (password[i] == pass)
		{
			cout << "\nLogin success!";
			actuser = username[i];
			captcha();
		}

		else
		{
			cout << "\nIncorrect password!" << endl;
			getpass();
		}
	}

	void captcha()
	{
		int captcha, entcap;

		captcha = rand() % 10000 + 100;

		cout << "\n\nCode: " << captcha;
		cout << "\nEnter captcha: ";
		cin >> entcap;

		if (captcha == entcap)
			display();
	}

	void display()
	{
		system("cls");

		cout << "\n\n";
		for (int k = 0; k < (username[i].length() + 1 + 10 + 2); k++)
			cout << "-";
		cout << "\n\n  Welcome " << username[i] << "!";
		cout << "\n\n";
		for (int j = 0; j < (username[i].length() + 1 + 10 + 2); j++)
			cout << "-";
	}
};

class Movies : public SignIn, public LogIn
{
public:
	string title1, title2, title3, title4;
	string time1, time2, time3, time4;
	string gen1, gen2, gen3, gen4;
	string tl1, tl2, tl3, tl4;
	float rat1, rat2, rat3, rat4;
	string date1, date2, date3, date4;
	float p1, p2, p3, p4;

	void showsdisplay()
	{
		cout << "\n\nName\t\t\tTime\t\t   Date" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << title1 << "\t\t" << time1 << "\t\t" << date1 << endl;
		cout << title2 << "\t\t" << time2 << "\t\t" << date2 << endl;
		cout << title3 << "\t\t" << time3 << "\t\t" << date3 << endl;
		cout << title4 << "\t\t" << time4 << "\t\t" << date4 << endl;
	}
};

class details : public Movies
{
protected:
	// Static Data Members

	static int avseats1;
	static int avseats2;
	static int avseats3;
	static int avseats4;

	static string seats1[100];
	static string seats2[100];
	static string seats3[100];
	static string seats4[100];

	// Constant data member

	const string backup[100] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};

public:
	string tbc;

	details()
	{
		title1 = "Fight Club";
		title2 = "The Godfather";
		title3 = "The Dark Knight";
		title4 = "12 Angry Men";

		time1 = "09:30";
		time2 = "20:00";
		time3 = "19:30";
		time4 = "15:45";

		date1 = "27/09/2024";
		date2 = "04/10/2024";
		date3 = "22/10/2024";
		date4 = "01/10/2024";

		gen1 = "Drama";
		gen2 = "Tragedy, Crime, Drama, Epic";
		gen3 = "Action, Thriller, Crime, Drama, Superhero, Epic";
		gen4 = "Crime, Drama";

		tl1 = "2hrs 19mins";
		tl2 = "2hrs 55mins";
		tl3 = "2hrs 32mins";
		tl4 = "1hr 36mins";

		rat1 = 8.8;
		rat2 = 9.2;
		rat3 = 9.0;
		rat4 = 9.0;

		p1 = 1500;
		p2 = 2000;
		p3 = 2500;
		p4 = 1250;
	}

	void titles()
	{
		cout << "\n\nAvailable movies:";
		cout << "\n\nMovie Names\t     Ticket price\n";
		cout << "-------------------------------------\n\n";
		cout << title1 << " \t\t1,500/-" << endl;
		cout << title2 << " \t\t2,000/-" << endl;
		cout << title3 << "\t\t2,500/-" << endl;
		cout << title4 << " \t\t1,250/-" << endl;
	}

	// Virtual function

	virtual void getname()
	{
		cout << "\nEnter name of the movie: ";
		getline(cin >> ws, tbc);

		compfordet();
	}

	void displaydetails(string title, string gen, string t, float r)
	{
		cout << "\n";
		cout << "Movie:           " << title << endl;
		cout << "Genre:           " << gen << endl;
		cout << "Time Length:     " << t << endl;
		cout << "Rating:          " << r << "/10";
	}

	void compfordet()
	{
		if (tbc == title1)
			displaydetails(title1, gen1, tl1, rat1);

		else if (tbc == title2)
			displaydetails(title2, gen2, tl2, rat2);

		else if (tbc == title3)
			displaydetails(title3, gen3, tl3, rat3);

		else if (tbc == title4)
			displaydetails(title4, gen4, tl4, rat4);

		else
		{
			cout << "\nMovie not found!";
			getname();
		}
	}
	friend class seats;
};

void bookseats(string s[], int t);

// Friend Class
class seats
{
public:
	void displayseats(string seatsdis[], int ttickets)
	{
		cout << "\n\nAvailable seats: \t\t\t\t      ('Bk' indicates Booked)";
		cout << "\n\n-----------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\tSCREEN";
		cout << "\n-----------------------------------------------------------------------------" << endl
			 << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << "[" << seatsdis[i * 10 + j] << "]\t";
			cout << "\n";
		}

		cout << "\n";

		for (int i = 5; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << "[" << seatsdis[i * 10 + j] << "]\t";
			cout << "\n";
		}

		if (ttickets > 0)
			bookseats(seatsdis, ttickets);
	}

	friend void bookseats(string s[], int t);
};

// Friend function

void bookseats(string s[], int t)
{
	string seatnum;
	int flag = 0;

	for (int i = 0; i < t; i++)
	{
		cout << "\n\nEnter seat number (A1, C10, D4...): ";
		cin >> seatnum;

		// Linear search

		for (int j = 0; j < 100; j++)
		{
			if (s[j] == seatnum)
			{
				flag = 1;
				s[j] = "Bk";
				cout << "Seat booked!";
				break;
			}
		}

		if (flag == 0)
		{
			cout << "Seat not found! Enter again!";
			i--;
		}

		flag = 0;
	}
}

// Initializing static data members here (Cannot be done inside a class)

int details::avseats1 = 100;
int details::avseats2 = 100;
int details::avseats3 = 100;
int details::avseats4 = 100;

string details::seats1[100] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string details::seats2[100] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string details::seats3[100] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string details::seats4[100] = {"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};

// Global variables, inheritance not working properly

float price;
string name;
int totaltickets = 1;

class booking : public seats, public details
{
protected:
	string tickname;
	string canname;

public:
	void gettickname()
	{
		cout << "\nEnter the name of the movie: ";
		getline(cin >> ws, tickname);
		name = tickname;

		compare(tickname);
	}

	void displaysinfo(string title, int avseats, string date, string time)
	{
		cout << "\n";
		cout << "Movie:           " << title << endl;
		cout << "Available seats: " << avseats << endl;
		cout << "Date:            " << date << endl;
		cout << "Time:            " << time << endl;
	}

	// Function overloading

	void compare(string in)
	{
		if (in == title1)
		{
			price = p1;
			displaysinfo(title1, avseats1, date1, time1);
		}

		else if (in == title2)
		{
			price = p2;
			displaysinfo(title2, avseats2, date2, time2);
		}

		else if (in == title3)
		{
			price = p3;
			displaysinfo(title3, avseats3, date3, time3);
		}

		else if (in == title4)
		{
			price = p4;
			displaysinfo(title4, avseats4, date4, time4);
		}

		else
		{
			cout << "\nMovie not found!";
			gettickname();
		}
	}

	// Function overloading

	void compare()
	{
		if (tickname == title1)
			checkseats(avseats1, seats1);

		else if (tickname == title2)
			checkseats(avseats2, seats2);

		else if (tickname == title3)
			checkseats(avseats3, seats3);

		else if (tickname == title4)
			checkseats(avseats4, seats4);
	}

	void nooftickets(int tickets = 1) // Default argument
	{
		cout << "\nTotal tickets: " << tickets;
		addtickets();
	}

	void addtickets()
	{
		char addmore;

		cout << "\nDo you want to add more tickets?\tYes-(y)    No-(n): ";
		cin >> addmore;

		switch (addmore)
		{
		case 'y':
		{
			getnumber();
			break;
		}

		case 'n':
		{
			compare();
			break;
		}

		default:
			cout << "Incorrect choice!";
		}
	}

	void getnumber()
	{
		cout << "\nEnter total number of tickets: ";
		cin >> totaltickets;

		nooftickets(totaltickets);
	}

	void checkseats(int &s, string seat[])
	{
		if (s < totaltickets)
			cout << "\nInsufficient seats!";

		else
		{
			s = s - totaltickets;
			displayseats(seat, totaltickets);
		}
	}

	void getname()
	{
		cout << "\nEnter name of the movie: ";
		getline(cin >> ws, canname);

		compcan(canname);
	}

	void compcan(string name)
	{
		if (name == title1)
			cancel(avseats1, seats1);

		else if (name == title2)
			cancel(avseats2, seats2);

		else if (name == title3)
			cancel(avseats3, seats3);

		else if (name == title4)
			cancel(avseats4, seats4);

		else
		{
			cout << "\nMovie not found! Enter again!";
			getname();
		}
	}

	void cancel(int &av, string seat[])
	{
		string seatnum;
		int num, flag = 0, i = 0;

		cout << "\nHow many seats do you want to cancel?\t";
		cin >> num;

		for (i = 0; i < num; i++)
		{
			cout << "\n\nEnter seat number (A1, C10, D4...): ";
			cin >> seatnum;

			for (int j = 0; j < 100; j++)
			{
				if ((seat[j] == "Bk") && (backup[j] == seatnum))
				{
					seat[j] = backup[j];
					flag = 1;
					break;
				}
			}
		}

		if (flag == 0)
		{
			cout << "\nSeat not found or seat is not boooked! Enter again!";
			i--;
		}

		else
		{
			av++;
			cout << "\nSeat cancelled successfully!";
		}
	}
};

class snacks
{
public:
	string slist[5] = {"Popcorn", "Nachos", "Soda", "Candy", "Fries"};
	double sprices[5] = {29.9, 40.1, 24.9, 14.9, 50.1};
	int squantity[5] = {0};

	void addsnacks()
	{
		cout << "\n\n--Available Snacks--" << endl;

		for (int i = 0; i < 5; i++)
			cout << i + 1 << ". " << slist[i] << "    \t" << sprices[i] << "/-" << endl;

		int choice, quantity;
		char more;

		do
		{
			cout << "\nEnter the snack number: ";
			cin >> choice;
			cout << "Enter quantity: ";
			cin >> quantity;

			if (choice > 0 && choice <= 5)
				squantity[choice - 1] += quantity;

			else
				cout << "\nInvalid choice!";

			cout << "\nDo you want to add more snacks?\tYes-(y)    No-(n): ";
			cin >> more;
		} while (more == 'y');
	}
};

class billing : public booking, public snacks
{
public:
	char add;
	float gst = 0.18, movietot, totalsnackCost = 0, grand = 0.0;
	int paid = 0;

	void asksnacks()
	{
		cout << "\n\nDo you want to add snacks?\tYes-(y)    No-(n): ";
		cin >> add;

		if (add == 'y')
			addsnacks();
	}

	void pay()
	{
		long long card;
		int expdate;
		float inamt;

		cout << "\n\n\n-----Billing-----" << endl;
		cout << "\n"
			 << "Enter card number (without spaces): ";
		cin >> card;
		cout << "\nEnter expiry:\nDD/MM : \t";
		cin >> expdate;

	label:
		cout << "\nPayable amount: " << grand << "/-";
		cout << "\n\nEnter amount: ";
		cin >> inamt;

		if (fabs((inamt - grand)) < 0.01)
		{
			paid = 1;

			// File handling

			ofstream payment("transactions.txt", ios::app);

			payment << "\nUsername: " << actuser << endl;
			payment << "Card number: " << card << endl;
			payment << "Expiry: " << expdate << endl;
			payment << "Amount: " << inamt << endl;
			payment << "---------------------";

			payment.close();
		}

		else if (inamt < grand)
		{
			cout << "\nInsufficient amount!!";
			goto label;
		}

		else if (inamt > grand)
		{
			cout << "\nAmount exceeded!";
			goto label;
		}

		if (paid == 1)
		{
			for (int i = 0; i < totaltickets; i++)
				cout << "\nTicket " << i + 1 << " code: " << rand() % 999999 + 10000;

			cout << "\n\nKindly note the tickets codes which is required at the time of issuing the tickets at the counter...";

			cout << "\n\nPayment successfull!\n---Thank you for visiting us!---";
		}
	}

	void displaygrand()
	{
		cout << "\n\nName: " << actuser;
		cout << "\nMovie: " << name << endl;
		cout << "Price: " << price << "/- x " << totaltickets << endl;
		movietot = price * totaltickets;
		cout << "Total: " << movietot << "/-";

		cout << "\n\nSnacks :\n";

		for (int i = 0; i < 5; i++)
			if (squantity[i] > 0)
			{
				cout << squantity[i] << "x " << slist[i] << "\t" << squantity[i] * sprices[i] << "/-" << endl;
				totalsnackCost += squantity[i] * sprices[i];
			}
		cout << "Total Snack Cost: " << totalsnackCost << "/-" << endl;

		grand = (movietot + totalsnackCost) + ((movietot + totalsnackCost) * gst);

		cout << "\nGST: " << (movietot + totalsnackCost) * gst << endl;
		cout << "-----------------------------------------\n";
		cout << "Grand total: " << grand << "/-";
	}
};

void header()
{
	int line = 24;
	int space = 2;

	cout << "\n";

	for (int i = 0; i < space; i++)
		cout << ' ';

	for (int i = 0; i < line; i++)
		cout << '-';

	cout << "\n\n";
	cout << " " << "MOVIE TICKET BOOKING SYSTEM"; // Discover new name
	cout << "\n\n ";

	for (int i = 0; i < space - 1; i++)
		cout << ' ';

	for (int i = 0; i < line; i++)
		cout << '-';

	cout << "\n";
}

void account();

void about()
{
	cout << "\n\nNames:\t\t\tKoushik Sharma\t\tJohn Paul Fernandes" << endl;
	cout << "Roll no:\t\t23CE132\t\t\t23CE126" << endl;
	cout << "Class:\t\t\tA1\t\t\tA1" << endl;
	cout << "Batch:\t\t\tB1\t\t\tB1" << endl;
	cout << "Practical batch:\tP12\t\t\tP12" << endl;
}

void mainmenu()
{
	int choice;
	billing i; // Change this to the latest derived class
	details c;
	details *d;

	cout << "\n\n   --Dashboard--\n1. Display Shows\n2. Book a seat\n3. Movie Information\n4. Cancel a booked seat\n5. About us\n6. Log out\nSelect the number corresponding to your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		i.showsdisplay();
		break;
	}

	case 2:
	{
		i.titles();
		i.gettickname();
		i.nooftickets();
		i.asksnacks();
		i.displaygrand();
		i.pay();
		break;
	}

	case 3:
	{
		d = &c;
		d->titles();
		d->getname();
		break;
	}

	case 4:
	{
		booking e;
		d = &e;
		d->getname();
		break;
	}

	case 6:
	{
		header();
		account();
		mainmenu();
		break;
	}

	case 5:
	{
		about();
		break;
	}

	default:
	{
		cout << "\nInvalid choice!!";
		mainmenu();
	}
	}
}

void buttons(char &cho)
{
	cout << "\n\n  [O] - Home\t[X] - Exit" << endl;
	cout << "\n   Select an option: ";
	cin >> cho;
}

void account()
{
	int acc;

	cout << "\nGet started by creating you account!\n\n1. New User? Sign up\n2. Having an account? Log in\n\nSelect the number corresponding to your choice: ";
	cin >> acc;

	switch (acc)
	{
	case 1:
	{
		SignIn s;
		s.getuser();
		break;
	}

	case 2:
	{
		LogIn l;
		l.getuser();
		break;
	}

	default:
	{
		cout << "\nInvalid choice!" << endl;
		account();
	}
	}
}

int main()
{
	char cont;

	header();
	account();

	do
	{
		mainmenu();
		buttons(cont);
	} while (cont == 'O');

	_getch();
	return 0;
}