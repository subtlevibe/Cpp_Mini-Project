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

    void putdata()
    {
        if(tbc==title1)
        {
            cout<<"\n";
            cout<<"Movie:       "<<title1<<endl;
            cout<<"Genre:       "<<gen1<<endl;
            cout<<"Time Lenght: "<<tl1<<endl;
            cout<<"Rating:      "<<rat1<<"/10";
        }

        else if(tbc==title2)
        {
            cout<<"\n";
            cout<<"Movie:       "<<title2<<endl;
            cout<<"Genre:       "<<gen2<<endl;
            cout<<"Time Lenght: "<<tl2<<endl;
            cout<<"Rating:      "<<rat2<<"/10";
        }

        else if(tbc==title3)
        {
            cout<<"\n";
            cout<<"Movie:       "<<title3<<endl;
            cout<<"Genre:       "<<gen3<<endl;
            cout<<"Time Lenght: "<<tl3<<endl;
            cout<<"Rating:      "<<rat3<<"/10";
        }

        else if(tbc==title4)
        {
            cout<<"\n";
            cout<<"Movie:       "<<title4<<endl;
            cout<<"Genre:       "<<gen4<<endl;
            cout<<"Time Lenght: "<<tl4<<endl;
            cout<<"Rating:      "<<rat4<<"/10";
        }
    }
};

class seats
{
    protected:

    int avseats1=30, avseats2=30, avseats3=30, avseats4=30;

    char seats1[200]={'A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'A8', 'A9', 'A10', 'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9', 'B10', 'C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9', 'C10', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9', 'D10'};
    char seats2[30]={'A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'A8', 'A9', 'A10', 'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9', 'B10', 'C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9', 'C10', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9', 'D10'};
    char seats3[30]={'A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'A8', 'A9', 'A10', 'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9', 'B10', 'C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9', 'C10', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9', 'D10'};
    char seats4[30]={'A1', 'A2', 'A3', 'A4', 'A5', 'A6', 'A7', 'A8', 'A9', 'A10', 'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9', 'B10', 'C1', 'C2', 'C3', 'C4', 'C5', 'C6', 'C7', 'C8', 'C9', 'C10', 'D1', 'D2', 'D3', 'D4', 'D5', 'D6', 'D7', 'D8', 'D9', 'D10'};

    public:

    void displayseats(string seatsdis)
    {
        cout<<"Available seats: ";
        cout<<"\n-----------------------------------------";
        cout<<"\t\t\tSCREEN";
        cout<<"\n-----------------------------------------";

        for(int i=0;i<10;i++)
        cout<<seatsdis[i]<<"\t\t\t";
    }
};

class booking: public seats, public info
{
    public:

    int tickets=1;
    string tickname;

    void displaydetails()
    {
        void displaymoviedetails(string title, int avseats, string date, string time)
        {
            cout<<"\n";
            cout<<"Movie:           "<<title<<endl;
            cout<<"Available seats: "<<avseats<<endl;
            cout<<"Date:            "<<date<<endl;
            cout<<"Time:            "<<time;

            cout<<"\nEnter number of teickets: ";
            cin>>tickets;

            if(tickets>avseats)
            cout<<"Insufficient seats!";

            else
            displayseats();
        }

        if(tbc==title1)
        displaymoviedetails(title1, avseats1, date1, time1)

        else if(tbc==title2)
        displaymoviedetails(title2, avseats2, date2, time2)
        

        else if(tbc==title3)
        displaymoviedetails(title3, avseats3, date3, time3)
        

        else if(tbc==title4)
        displaymoviedetails(title4, avseats4, date4, time4)

        else
        cout<<"\nMovie not found!";
    }

    void asktickets()
    {
        cout<<"\n\nHow many tickets do you want to purchase?: ";
        cin>>tickets;

        if()
    }
}
}

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
                b.displaydetails();
            }

            case 3:
            {
                i.titles();
                i.getname();
                i.putdata();
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
