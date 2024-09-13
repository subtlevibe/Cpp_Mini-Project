//Movie booking system

#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;

class details
{
    public:

    string title1, title2, title3, title4;
    string time1, time2, time3, time4;
    string gen1, gen2, gen3, gen4;
    string tl1, tl2, tl3, tl4;
    float rat1, rat2, rat3, rat4;
    string date1, date2, date3, date4;

    void showsdisplay()
    {
        cout<<"\n\nName\t\t\tTime\t\t   Date"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<title1<<"\t\t"<<time1<<"\t\t"<<date1<<endl;
        cout<<title2<<"\t\t"<<time2<<"\t\t"<<date2<<endl;
        cout<<title3<<"\t\t"<<time3<<"\t\t"<<date3<<endl;
        cout<<title4<<"\t\t"<<time4<<"\t\t"<<date4<<endl;
    }
};

class info: public details
{
    public:

    string tbc;

    info()
    {
        title1 = "Fight Club";
        title2= "The Godfather";
        title3= "The Dark Knight";
        title4= "12 Angry Men";

        time1="09:30";
        time2="20:00";
        time3="19:30";
        time4="15:45";

        date1="27/09/2024";
        date2="04/10/2024";
        date3="22/10/2024";
        date4="01/10/2024";

        gen1="Drama";
        gen2="Tragedy, Crime, Drama, Epic";
        gen3="Action, Thriller, Crime, Drama, Superhero, Epic";
        gen4="Crime, Drama";

        tl1="2hrs 19mins";
        tl2="2hrs 55mins";
        tl3="2hrs 32mins";
        tl4="1hr 36mins";

        rat1=8.8;
        rat2=9.2;
        rat3=9.0;
        rat4=9.0;
    }

    void titles()
    {
        cout<<"\n\nAvailable movies:\n\n";
        cout<<title1<<endl;
        cout<<title2<<endl;
        cout<<title3<<endl;
        cout<<title4<<endl;
    }

    void getname()
    {
        cout<<"\nEnter name of the movie: ";
        getline(cin>>ws, tbc);
    }

    void displaydetails(string title, string gen, string t, float r)
    {
        cout<<"\n";
        cout<<"Movie:           "<<title<<endl;
        cout<<"Genre:           "<<gen<<endl;
        cout<<"Time Length:     "<<t<<endl;
        cout<<"Rating:          "<<r<<"/10";

    }
    
    void compfordet()
    {
        if(tbc==title1)
            displaydetails(title1, gen1, tl1, rat1);

        else if(tbc==title2)
            displaydetails(title2, gen2, tl2, rat2);

        else if(tbc==title3)
            displaydetails(title3, gen3, tl3, rat3);

        else if(tbc==title4)
            displaydetails(title4, gen4, tl4, rat4);

        else
            cout<<"\nMovie not found!";
    }
};

class seats
{
    protected:

    //Static Data Members

    static int avseats1;                                         
    static int avseats2;
    static int avseats3;
    static int avseats4;

    static string seats1[100];
    static string seats2[100];
    static string seats3[100];
    static string seats4[100];

    public:

    void displayseats(string seatsdis[], int ttickets)
    {
        cout<<"\n\nAvailable seats: \t\t\t\t      ('Bk' indicates Booked)";
        cout<<"\n\n-----------------------------------------------------------------------------"<<endl;
        cout<<"\t\t\t\tSCREEN";
        cout<<"\n-----------------------------------------------------------------------------"<<endl<<endl;

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 10; j++)
                cout << "["<<seatsdis[i * 10 + j]<<"]\t";
            cout <<"\n";
        }

        cout<<"\n";

        for (int i = 5; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                cout << "["<<seatsdis[i * 10 + j]<<"]\t";
            cout <<"\n";
        }

        if(ttickets>0)
            bookseats(seatsdis,ttickets);
    }

    void bookseats(string s[], int t)
    {
        string seatnum;
        int flag=0;

        for(int i=0;i<t;i++)
        {
            cout<<"\nEnter seat number (A1, C10, D4...): ";
            cin>>seatnum;

            //Linear search

            for(int j=0; j<100; j++)
            {
                if(s[j]==seatnum)
                {
                    flag=1;
                    s[j]="Bk";
                    break;
                }
            }

            if(flag==0)
                cout<<"\nSeat not found!";
        }
    }
};

//Initializing static data members here (Cannot be done inside a class)

int seats::avseats1=100;
int seats::avseats2=100;
int seats::avseats3=100;
int seats::avseats4=100;

string seats::seats1[100]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string seats::seats2[100]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string seats::seats3[100]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};
string seats::seats4[100]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "E10", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10", "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "J1", "J2", "J3", "J4", "J5", "J6", "J7", "J8", "J9", "J10"};


class booking: public seats, public info
{
    public:
    int addtotickets=1;

    string tickname;

    void gettickname()
    {
        cout<<"\nEnter the name of the movie: ";
        getline(cin>>ws, tickname);
    }

    void displaysinfo(string title, int avseats, string date, string time)
    {
        cout<<"\n";
        cout<<"Movie:           "<<title<<endl;
        cout<<"Available seats: "<<avseats<<endl;
        cout<<"Date:            "<<date<<endl;
        cout<<"Time:            "<<time;
    }

    void compare()
    {
        if(tickname==title1)
            displaysinfo(title1, avseats1, date1, time1);

        else if(tickname==title2)
            displaysinfo(title2, avseats2, date2, time2);

        else if(tickname==title3)
            displaysinfo(title3, avseats3, date3, time3);

        else if(tickname==title4)
            displaysinfo(title4, avseats4, date4, time4);

        else
        cout<<"\nMovie not found!";
    }

    void avs()
    {
        if(tickname==title1)
            checkseats(avseats1, seats1);

        else if(tickname==title2)
            checkseats(avseats2, seats2);

        else if(tickname==title3)
            checkseats(avseats3, seats3);

        else if(tickname==title4)
            checkseats(avseats4, seats4);
    }

    void nooftickets(int tickets=1)      //Default argument
    {
        cout<<"\n\nTotal tickets: "<<tickets;
        addtickets();
    }

    void addtickets()
    {
        char addmore;

        cout<<"\nDo you want to add more tickets?\tYes-(y)    No-(n): ";
        cin>>addmore;

        switch(addmore)
        {
            case 'y':
            {
                getnumber();
                break;
            }

            case 'n':
            {
                avs();
                break;
            }

            default: "Incorrect choice!";
        }
    }

    void getnumber()
    {
        cout<<"\nEnter total number of tickets: ";
        cin>>addtotickets;

        nooftickets(addtotickets);
    }

    void checkseats(int &s, string seat[])
    {
        if(s<addtotickets)
           cout<<"\nInsufficient seats!";

        else
        {
           s=s-addtotickets;
           displayseats(seat, addtotickets);
        }
    }
};

class snacks
{
    public:

    string snackList[5] = {"Popcorn", "Nachos", "Soda", "Candy", "Fries"};
    float snackPrices[5] = {29.9, 40.1, 24.9, 14.9, 50.1};
    int snackQuantity[5] = {0};

    void addsnacks()
    {
        cout<<"\n\n--Available Snacks:"<<endl;

        for(int i=0; i<5; i++)
        cout<<i+1<<". "<<snackList[i]<<"    \t"<<snackPrices[i]<<"/-"<<endl;

        int choice, quantity;
        char more;

        do
        {
            cout<<"\nEnter the snack number: ";
            cin>>choice;
            cout<<"\nEnter quantity: ";
            cin>>quantity;

            if(choice>0 &&choice<=5)
            snackQuantity[choice-1]+=quantity;

            else
            cout<<"\nInvalid choice!";

            cout<<"\n\nDo you want to add more snacks?\tYes-(y)    No-(n): ";
            cin>>more;
        }while(more=='y');
    }

        void displaySnackSummary()
        {
            float totalCost = 0;

            cout << "\nSnack Summary:\n";

            for (int i = 0; i < 5; i++)
                if (snackQuantity[i] > 0)
                {
                    cout <<snackQuantity[i]  << "x " <<snackList[i] <<"\t"<< snackQuantity[i] * snackPrices[i] <<"/-"<< endl;
                    totalCost += snackQuantity[i] * snackPrices[i];
                }
        
        cout << "Total Snack Cost: " << totalCost<<"/-" << endl;
        }
};

class billing: public booking, public snacks
{
    public:

    char add;

    void asksnacks()
    {
        cout<<"\nDo you want to add snacks?\tYes-(y)    No-(n): ";
        cin>>add;

        if(add=='y')
        addsnacks();
        displaySnackSummary();
    }
};

void header()
{
    int line = 24;
    int space = 2;

    for(int i = 0; i < space; i++)
        cout << ' ';
         
    for(int i = 0; i < line; i++)
        cout << '-';

    cout << "\n\n";
    cout << " " << "MOVIE TICKET BOOKING SYSTEM";
    cout << "\n\n ";

    for(int i = 0; i < space-1; i++)
        cout << ' ';
        
    for(int i = 0; i < line; i++)
        cout << '-';

    cout << "\n";
}

void mainmenu()
{
    int choice;
    info i;  //Change this
    booking b;
    billing bill;

    cout<<"\n\n   --Dashboard--\n1. Display Shows\n2. Book a seat\n3. Movie Information\nSelect the number corresponding to your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: 
            {   i.showsdisplay();
                break;
            }

            case 2:
            {
                i.titles();
                b.gettickname();
                b.compare();
                b.nooftickets();
                bill.asksnacks();
                break;
            }

            case 3:
            {
                i.titles();
                i.getname();
                i.compfordet();
                break;
            }

            default: cout<<"\nInvalid choice!!";
        }
}

void buttons(char &cho)
{
    cout << "\n\n  [O] - Home\t[X] - Exit"<<endl;
    cout << "\n   Select an option: ";
    cin>>cho;
}

int main()
{
    char cont;

    header();

    do
    {
        mainmenu();
        buttons(cont);
    } while (cont=='O');
    
    _getch();
    return 0;
}