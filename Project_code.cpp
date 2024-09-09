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
    }
};

class seats
{
    protected:

    int avseats1=30, avseats2=30, avseats3=30, avseats4=30;

    string seats1[40]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    string seats2[40]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    string seats3[40]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    string seats4[40]={"A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};

    public:

    void displayseats(string seatsdis[])
    {
        cout<<"Available seats: ";
        cout<<"\n-----------------------------------------";
        cout<<"\t\t\tSCREEN";
        cout<<"\n-----------------------------------------";

        for(int i=0;i<30;i++)
        cout<<seatsdis[i]<<"\t";
    }
};

class booking: public seats, public info
{
    public:

    int tickets=1;
    string tickname;

    void displaydetailsdetails(string title, int avseats, string date, string time, string seats[])
        {
            cout<<"\n";
            cout<<"Movie:           "<<title<<endl;
            cout<<"Available seats: "<<avseats<<endl;
            cout<<"Date:            "<<date<<endl;
            cout<<"Time:            "<<time;

            cout<<"\nEnter number of tickets: ";
            cin>>tickets;

            if(tickets>avseats)
            cout<<"Insufficient seats!";

            else
            displayseats(seats);
        }

    void compare()
    {
        if(tbc==title1)
        displaydetailsdetails(title1, avseats1, date1, time1, seats1);

        else if(tbc==title2)
        displaydetailsdetails(title2, avseats2, date2, time2, seats2);
        

        else if(tbc==title3)
        displaydetailsdetails(title3, avseats3, date3, time3, seats3);
        

        else if(tbc==title4)
        displaydetailsdetails(title4, avseats4, date4, time4, seats4);

        else
        cout<<"\nMovie not found!";
    }

    /*void asktickets()
    {
        cout<<"\n\nHow many tickets do you want to purchase?: ";
        cin>>tickets;

        if()
    }*/
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
                i.getname();
                b.compare();

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
