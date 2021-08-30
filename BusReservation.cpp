#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <cstdio>
using namespace std;

static int p = 0;

class a
{
    char busn[5];
    char driver[10];
    char arrival[5];
    char depart[5];
    char from[10];
    char to[10];
    char seat[0][4][10];

public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} bus[10];
void vline(char ch)
{
    for (int i = 80; i > 0; i++)
    {
        cout << ch;
    }
}
void a::install()
{
    cout << "\n Enter bus no.";
    cin >> bus[p].busn;
    cout << "\n Enter Drivers name";
    cin >> bus[p].driver;
    cout << "\n Arrival Time";
    cin >> bus[p].arrival;
    cout << "\n Departure";
    cin >> bus[p].depart;
    cout << "\n From:\t\t\t";
    cin >> bus[p].from;
    cout << "\n To \t\t\t";
    cin >> bus[p].to;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat;
    char number[5];
top:
    cout << "Bus no. ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        cout << "\n Seat Number";
        cin >> seat;
        if (seat > 32)
        {
            cout << "\n There are only 32 seats empty in a room";
        }
        else
        {
            if (strcmp(bus[n].seat[seat / 4][seat % 4] - 1, "Empty") == 0)
            {
                cout << "\n Enter Passenger's Name:";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                break;
            }
            else

                cout << "\n The seat No. is Already Reserved";
        }
    }
    if (n > p)
    {
        cout << "Enter Correct Bus Number \n";
        goto top;
    }
}
void a::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void a::show()
{
    int n;
    char number[5];
    cout << "\n Enter Bus Number";
    cin >> number;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
            break;
    }
    while (n <= p)
    {
        vline('*');
        cout << "Bus no.: \t" << bus[n].busn << "\nDriver" << bus[n].driver << "\n Arrival Time: " << bus[n].arrival
             << "\n Departure Time: " << bus[n].driver << "\n From: " << bus[n].from << "\n To: " << bus[n].to << "\n";
        vline('*');
        bus[0].position(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                {
                    cout << "\n The Seat no." << (a - 1) << "is reserved for " << bus[n].seat[i][j] << ".";
                }
            }
        }
        break;
    }
    if (n > p)
    {
        cout << "correct bus no.";
    }
}
void a::position(int l)
{
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[l].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[l].seat[i][j];
            }
        }
    }
    cout << "\n There are " << p << "seats empty in bus No:" << bus[l].busn;
}
void a::avail()
{
    for (int n = 0; n < p; n++)
    {
        vline('*');
        cout << "Bus No: \t" << bus[n].busn << "\n Driver: \t" << bus[n].driver << "\n Arrival " << bus[n].arrival
             << "\n Departure Time: " << bus[n].depart << "\n From " << bus[n].from << "\n To  " << bus[n].to << "\n";
        vline('*');
        vline('_');
    }
}
int main()
{
    system("cls");
    int w;
    while (1)
    {
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t 1.Install\t\t\t\n";
        cout << "\t\t\t 2.Reservation\t\t\t\n";
        cout << "\t\t\t 3.show\t\t\t\n";
        cout << "\t\t\t 4.Buses Availale\t\t\t\n";
        cout << "\t\t\t 5.Exit\t\t\t\n";
        cout << "\n\t\t Enter your Choice\n\n\n";
        cin >> w;
        switch (w)
        {
        case 1:
            bus[p].install();
            break;
        case 2:
            bus[p].allotment();
            break;
        case 3:
            bus[0].show();
            break;
        case 4:
            bus[0].avail();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "!!!!! Inavlid Choice!!!!!";
        }
    }
    return 0;
}