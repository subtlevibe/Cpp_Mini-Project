// C++ Mini Project

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

string actuser;

void centerText(string text)
{
	int consoleWidth = 170;

	int padding = (consoleWidth - text.size()) / 2;
	cout << setw(padding + text.size()) << text;
}

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
		cout << "\n";
		centerText("Enter username: ");
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
			cout << "\n";
			centerText("An account with the same username is already existing!");
			getuser();
		}

		else
			getpass();
	}

	inline void getpass()
	{
		locator++;
		username[locator] = user;

		cout << "\n";
		centerText("Enter password: ");
		pass.clear();
		ch = getch();

		while (ch != 13)
		{
			if (ch == 8)
			{
				if (!pass.empty())
				{
					pass.pop_back();
					cout << "\b \b";
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
		int length = username[locator].length() + 1 + 10 + 2;

		cout << setw(208 + 21 + 12 + 2) << ' ' << setw(length) << setfill('-') << '-' << "\n\n";
		cout << setw(260 - 6) << setfill(' ') << " Welcome " << username[locator] << "!\n\n";
		cout << setw(208 + 21 + 12 + 2) << ' ' << setw(length) << setfill('-') << '-' << setfill(' ') << "\n";
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
		cout << "\n";
		centerText("Enter username: ");
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
			cout << "\n";
			centerText("No such account with the username");
			cout << endl;
			getuser();
		}

		else
			getpass();
	}

	void getpass()
	{
		cout << "\n";
		centerText("Enter password: ");
		pass.clear();
		ch = getch();

		while (ch != 13)
		{
			if (ch == 8)
			{
				if (!pass.empty())
				{
					pass.pop_back();
					cout << "\b \b";
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
			cout << "\n";
			centerText("Login success!");
			actuser = username[i];
			captcha();
		}

		else
		{
			cout << "\n";
			centerText("Incorrect password!");
			cout << endl;
			getpass();
		}
	}

	void captcha()
	{
		int captcha, entcap;

		captcha = rand() % 10000 + 100;
		cout << "\n\n";
		cout << setw(80 - 3 + 10) << "Code: " << captcha;
		cout << "\n";
		centerText("Enter captcha: ");
		cin >> entcap;

		if (captcha == entcap)
			display();
	}

	void display()
	{
		system("cls");
		cout << "\n\n";
		int length = username[i].length() + 1 + 10 + 2;
		cout << setw(length) << setfill('-') << '-' << setfill(' ') << "\n\n";
		cout << " Welcome " << username[i] << "!\n\n";
		cout << setw(length) << setfill('-') << '-' << setfill(' ') << "\n";
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
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << setw(75 - 8) << "Name" << setw(12 + 8) << "Time" << setw(11 + 9) << "Date" << endl;
		cout << setw(75 - 12 - 3) << setfill(' ') << "" << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
		cout << setw(75 - 4 - 1) << title1 << setw(8 + 5 + 5 - 1 + 1) << time1 << setw(10 + 8 + 4) << date1 << endl;
		cout << setw(75 - 4 - 1 + 3) << title2 << setw(8 + 5 + 5 - 1 + 1 - 3) << time2 << setw(10 + 8 + 4 + 1 - 3 + 2) << date2 << endl;
		cout << setw(75 - 4 - 1 + 5) << title3 << setw(8 + 5 + 5 - 1 + 1 - 5) << time3 << setw(10 + 8 + 4 + 1 - 5 + 4) << date3 << endl;
		cout << setw(75 - 4 - 1 + 2) << title4 << setw(8 + 5 + 5 - 1 + 1 - 2) << time4 << setw(10 + 8 + 4 + 1 - 2 + 1) << date4 << endl;
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
		cout << "\n\n\n\n\n\n";
		centerText("Available movies:");
		cout << "\n\n"
			 << setw(75) << "Movie Names" << setw(9 + 21) << "Ticket price\n";
		cout << setw(75 - 11) << ' ' << setfill('-') << setw(38 + 2) << "-" << setfill(' ') << endl
			 << endl;
		cout << setw(64) << ' ' << title1 << setw(8 + 12) << ' ' << "1,500/-" << endl;
		cout << setw(64) << ' ' << title2 << setw(8 + 12 - 3) << ' ' << "2,000/-" << endl;
		cout << setw(64) << ' ' << title3 << setw(8 + 12 - 5) << ' ' << "2,500/-" << endl;
		cout << setw(64) << ' ' << title4 << setw(8 + 12 - 2) << ' ' << "1,250/-" << endl;
	}

	// Virtual function

	virtual void getname()
	{
		cout << "\n";
		centerText("Enter name of the movie: ");
		getline(cin >> ws, tbc);

		compfordet();
	}

	void displaydetails(string title, string gen, string t, float r)
	{
		cout << "\n";
		cout << setw(75 - 2) << ' ' << "Movie:" << setw(11) << ' ' << title << endl;
		cout << setw(75 - 2) << ' ' << "Genre:" << setw(11) << ' ' << gen << endl;
		cout << setw(75 - 2) << ' ' << "Time Length:" << setw(5) << ' ' << t << endl;
		cout << setw(75 - 2) << ' ' << "Rating:" << setw(11 - 1) << ' ' << r << "/10";
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
		cout << "\n\n";
		cout << setw(65 - 10) << ' ' << "Available seats:" << setw(23) << ' ' << "'Bk' indicates Booked)";
		cout << "\n\n";
		cout << setw(65 - 10 - 10) << ' ' << setw(78) << setfill('-') << '-' << setfill(' ') << ' ' << endl;
		centerText("SCREEN");
		cout << "\n";
		cout << setw(65 - 10 - 10) << ' ' << setw(78) << setfill('-') << '-' << setfill(' ') << endl;

		for (int i = 0; i < 5; i++)
		{
			cout << setw(65 - 15);
			for (int j = 0; j < 10; j++)
				cout << "[" << seatsdis[i * 10 + j] << "]" << setw(4);
			cout << "\n";
		}

		cout << "\n";

		for (int i = 5; i < 10; i++)
		{
			cout << setw(65 - 15);
			for (int j = 0; j < 10; j++)
				cout << "[" << seatsdis[i * 10 + j] << "]" << setw(4);
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
		cout << "\n\n";
		centerText("Enter seat number (A1, C10, D4...): ");
		cin >> seatnum;

		// Linear search

		for (int j = 0; j < 100; j++)
		{
			if (s[j] == seatnum)
			{
				flag = 1;
				s[j] = "Bk";
				centerText("Seat booked!");
				break;
			}
		}

		if (flag == 0)
		{
			centerText("Seat not found! Enter again!");
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
		cout << "\n";
		centerText("Enter the name of the movie: ");
		getline(cin >> ws, tickname);
		name = tickname;

		compare(tickname);
	}

	void displaysinfo(string title, int avseats, string date, string time)
	{
		cout << "\n";
		cout << setw(60 + 4 + 6) << ' ' << "Movie:" << setw(11) << ' ' << title << endl;
		cout << setw(60 + 4 + 6) << ' ' << "Available seats:" << setw(1) << ' ' << avseats << endl;
		cout << setw(60 + 4 + 6) << ' ' << "Date:" << setw(12) << ' ' << date << endl;
		cout << setw(60 + 4 + 6) << ' ' << "Time:" << setw(12) << ' ' << time << endl;
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
		cout << "\n";
		centerText("Total tickets: ");
		cout << tickets;
		addtickets();
	}

	void addtickets()
	{
		char addmore;

		cout << "\n";
		centerText("Do you want to add more tickets?    Yes-(y)    No-(n): ");
		;
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
		cout << "\n";
		centerText("Enter total number of tickets: ");
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
			system("CLS");
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
			cout << "\n";
			centerText("Seat not found or seat is not boooked! Enter again!");
			i--;
		}

		else
		{
			av++;
			cout << "\n";
			centerText("Seat cancelled successfully!");
		}
	}
};

class snacks
{
public:
	string slist[5] = {"Popcorn", "Nachos ", "Soda   ", "Candy  ", "Fries  "};
	double sprices[5] = {29.9, 40.1, 24.9, 14.9, 50.1};
	int squantity[5] = {0};

	void addsnacks()
	{
		system("CLS");

		cout << "\n\n";
		centerText("--Available Snacks--");
		cout << endl;

		for (int i = 0; i < 5; i++)
			cout << setw(65+8) << ' ' << i + 1 << ". " << slist[i] << setw(8) << ' ' << sprices[i] << "/-" << endl;

		int choice, quantity;
		char more;

		do
		{
			cout << "\n";
			centerText("Enter the snack number: ");
			cin >> choice;
			centerText("Enter quantity: ");
			cin >> quantity;

			if (choice > 0 && choice <= 5)
				squantity[choice - 1] += quantity;

			else
			{
				cout << "\n";
				centerText("Invalid choice!");
			}

			cout << "\n\n\n";
			centerText("Do you want to add more snacks?    Yes-(y)    No-(n): ");
			cin >> more;
		} while (more == 'y');
	}

	char add;

	void asksnacks()
	{
		cout << "\n\n\n\n";
		centerText("Do you want to add snacks?    Yes-(y)    No-(n): ");
		cin >> add;

		if (add == 'y')
			addsnacks();
	}
};

class billing : public booking, public snacks
{
public:
	float gst = 0.18, movietot, totalsnackCost = 0, grand = 0.0;
	int paid = 0;

	void pay()
	{
		long long card;
		string expdate;
		float inamt;

		cout << "\n\n\n";
		centerText("-----Billing-----");
		cout << endl;
		cout << "\n";
			 centerText("Enter card number (without spaces): ");
		cin >> card;
		cout << "\n";
		centerText("Enter expiry:");
		centerText("DD/MM :   ");
		getline(cin>>ws, expdate);

	label:
		cout << "\n";
		centerText("Payable amount: " ); cout<< grand << "/-";
		cout << "\n\n";
		centerText("Enter amount: ");
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
			cout << "\n";
			centerText("Insufficient amount!!");
			goto label;
		}

		else if (inamt > grand)
		{
			cout << "\n";
			centerText("Amount exceeded!");
			goto label;
		}

		if (paid == 1) // Print the ticket from the file
		{
			system("CLs");

			for (int i = 0; i < totaltickets; i++)
			{
				cout << "\n";
				centerText("Ticket ");cout << i + 1 << " code: " << rand() % 999999 + 10000;
				}

			cout << "\n\n";
			centerText("Kindly note the tickets codes which is required at the time of entering the theatre...");
			centerText("The same has been mailed to your email!");

			cout << "\n\n";
			centerText("Payment successfull!");
			cout<<"\n";
			centerText("---Thank you for visiting us!---");
		}
	}

	void displaygrand()
	{
		cout << "\n\n";
		centerText("Name: ");cout << actuser;
		cout << "\n";
		centerText("Movie: " ); cout << name << endl;
		centerText("Price: "); cout << price << "/- x " << totaltickets << endl;
		movietot = price * totaltickets;
		centerText("Total: ");cout << movietot << "/-";

		cout << "\n\n";
		centerText("Snacks :");
		cout<<"\n";

		for (int i = 0; i < 5; i++)
			if (squantity[i] > 0)
			{
				cout <<setw(65)<<' '<< squantity[i] << "x " << slist[i] << "\t" << squantity[i] * sprices[i] << "/-" << endl;
				totalsnackCost += squantity[i] * sprices[i];
			}
		centerText("Total Snack Cost: ");cout << totalsnackCost << "/-" << endl;

		grand = (movietot + totalsnackCost) + ((movietot + totalsnackCost) * gst);

		cout << "\n";
		centerText("GST: ");cout << (movietot + totalsnackCost) * gst << endl;
		centerText("-----------------------------------------");
		cout<<"\n";
		centerText("Grand total: ");cout << grand << "/-";
	}
};

void header()
{
	int line = 24;
	int space = 77;

	cout << "\n";

	cout << setw(space - 3 - 2 + 2) << ' ';
	cout << setw(space) << setw(line) << setfill('-') << '-' << setfill(' ') << "\n\n";

	cout << setw(space + 12 + 2) << "MOVIE HOUSE" << "\n\n ";

	cout << setw(space - 6 + 2) << ' ';
	cout << setw(space) << setw(line) << setfill('-') << '-' << setfill(' ') << "\n";
}

void account();

void about()
{
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << setw(60) << ' ' << "Names:" << setw(12) << ' ' << "Koushik Sharma" << setw(8) << ' ' << "John Paul Fernandes" << endl;
	cout << setw(60) << ' ' << "Roll no:" << setw(8 + 2) << ' ' << "23CE132" << setw(12 + 4 - 1) << ' ' << "23CE126" << endl;
	cout << setw(60) << ' ' << "Class:" << setw(12) << ' ' << "A1" << setw(12 + 9 - 1) << ' ' << "A1" << endl;
	cout << setw(60) << ' ' << "Batch:" << setw(12 + 1 + 1) << "B1" << setw(12 + 9 - 1) << ' ' << "B1" << endl;
	cout << setw(60) << ' ' << "Practical batch:" << setw(1 + 1) << ' ' << "P12" << setw(12 + 8 - 1) << ' ' << "P12" << endl;
}

void mainmenu()
{
	int choice;
	billing i; // Change this to the latest derived class
	details c;
	details *d;

	cout << "\n\n";
	centerText("   --Dashboard");
	cout << "\n";
	centerText("1. Display Shows");
	cout << setw(166) << "2. Book a seat";
	cout << setw(166 + 8) << "3. Movie Information";
	cout << setw(166 + 12 - 7) << "4. Cancel a booked seat";
	cout << setw(166 + 3 - 13) << "5. About us";
	cout << setw(166 + 4 - 5 + 2) << "6. Log out" << endl;
	centerText("Select the number corresponding to your choice: ");
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		system("CLS");
		i.showsdisplay();
		break;
	}

	case 2:
	{
		system("CLS");
		i.titles();
		i.gettickname();
		i.nooftickets();
		i.asksnacks();
		system("CLS");
		i.displaygrand();
		i.pay();
		break;
	}

	case 3:
	{
		system("CLS");
		d = &c;
		d->titles();
		d->getname();
		break;
	}

	case 4:
	{
		system("CLS");
		booking e;
		d = &e;
		d->getname();
		break;
	}

	case 6:
	{
		system("CLS");
		header();
		account();
		mainmenu();
		break;
	}

	case 5:
	{
		system("CLS");
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
	cout << "\n\n";
	centerText("[O] - Home\t[X] - Exit");
	cout << endl;
	cout << "\n";
	centerText("Select an option: ");
	;
	cin >> cho;
}

void account()
{
	int acc;

	cout << "\n\n\n\n\n\n\n\n\n\n";
	centerText("Get started by creating you account!");
	cout << "\n\n";
	centerText("1. New User? Sign up");
	cout << "\n";
	centerText("2. Having an account? Log in");
	cout << "\n\n";
	centerText("Select the number corresponding to your choice: ");
	cin >> acc;

	switch (acc)
	{
	case 1:
	{
		system("CLS");
		header();
		SignIn s;
		s.getuser();
		break;
	}

	case 2:
	{
		system("CLS");
		header();
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
		header();
		mainmenu();
		buttons(cont);
		system("CLS");
	} while (cont == 'O');

	_getch();
	return 0;
}