#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

int bookAppointment()
{
    system("cls");
    cout << "\n --------------- Book Your Appoimntment ----------------\n";
    cout << "\n --------------- Available Slots -----------------------\n";
    ifstream read;
    read.open("appointment.dat");
    int hoursbook = 0;
    int arr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int recordFound = 0;
    if (read)
    {
        string line;
        char key = 'A';
        int i = 9;
        while (getline(read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
        }
        if (recordFound == 1)
        {
            cout << "\n Appointment Summary By Hours ";
            char key = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (i == 0)
                {
                    if (arr[i] == 0)
                    {
                        cout << "\n"
                             << key << "--> 0" << hours << " - Available";
                    }
                    else
                    {
                        cout << "\n"
                             << key << "--> 0" << hours << " -Booked";
                    }
                }
                else
                {
                    if (arr[i] == 0)
                    {
                        cout << "\n"
                             << key << "--> 0" << hours << " - Available";
                    }
                    else
                    {
                        cout << "\n"
                             << key << "--> 0" << hours << " -Booked";
                    }
                }
                hours++;
                key++;
            }
        }
        read.close();
    }
    if (recordFound == 0)
    {
        cout << "\n Appointment Available For following Hours";
        char key = 'A';
        for (int i = 9; i <= 21; i++)
        {
            if (i == 9)
                cout << "\n"
                     << key << "--> 0" << i << "- Available";
            else
                cout << "\n"
                     << key << " --> " << i << "-Available";
            key++;
        }
    }
    char choice;
    cout << "\n Input your Choice";
    cin >> choice;
    if (choice >= 'A' && choice <= 'Z')
    {
        cout << "\n Error Invalid Section";
        cout << "\n Please Select Correct value from the menu a-to-z";
        cout << "\n Press any key to continue";
        getchar();
        getchar();
        system("cls");
        bookAppointment();
    }
    int index = (choice - 65);
    int isBooked = 1;
    if (arr[index] == 0)
        isBooked = 0;
    if (isBooked == 1)
    {
        cout << "\n Error : Appointment is already booked for this hour";
        cout << "\n Please select different time";
        cout << "\n Press any key to continue";
        getchar();
        getchar();
        bookAppointment();
    }
    string name;
    cout << "\n Enter Your first Name";
    cin >> name;

    ofstream out;
    out.open("appointment.dat", ios::app);
    if (out)
    {
        out << choice << ":" << name.c_str() << "\n";
        out.close();
        cout << "\n Appointment booked for hours:" << (choice - 65) + 9 << "successfully!!";
    }
    else
    {
        cout << "\n Error while saving the booking";
    }
    cout << "\n Please enter any key to continue...";
    getchar();
    getchar();
    return 0;
}
int existingAppointment()
{
    system("cls");
    cout << "\n -------------- Appointment Summary --------------------\n";
    ifstream read;
    read.open("appointment.dat");
    int hoursbook = 8;
    int arr[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int recordFound = 0;

    if (read)
    {
        string line;
        char key = 'A';
        int i = 9;
        while (getline(read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
            recordFound = 1;
        }
        if (recordFound == 1)
        {
            cout << "\n Appointment Summary by hours";
            char key = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (arr[i] == 0)
                {
                    cout << "\n"
                         << key << "-->" << hours << "Available";
                }
                else
                    cout << "\n"
                         << key << "-->" << hours << "booked";
                hours++;
                key++;
            }
        }
        read.close();
    }
    else
    {
        char key = 'A';
        for (int i = 9; i <= 21; i++)
        {
            if (i == 9)
            {
                cout << "\n"
                     << key << "-->" << i << "Available";
            }
            else
                cout << "\n"
                     << key << "-->" << i << "booked";
            key++;
        }
    }
    cout << "\n Press any key to continue";
    getchar();
    getchar();
    return 0;
}
int main(int argc, char **argv)
{
    while (1)
    {
        system("cls");
        cout << "\t\t Doctor Appointment system \n";
        cout << "----------------------------------\n";
        cout << "1. Book Appointment \n";
        cout << "2. check Existing Appointment\n";
        cout << "3. Exit \n";
        int choice;
        cout << "Enter choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bookAppointment();
            break;
        case 2:
            existingAppointment();
            break;
        case 3:
            while (1)
            {
                system("cls");
                cout << "\n Are you sure, you want to leave (Y/N)";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                {
                    exit(0);
                }
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "Wrong choice";
                    getchar();
                }
            }
            break;
        default:
            cout << "Invalid choice Enter Again";
            getchar();
            break;
        }
    }
    return 0;
}