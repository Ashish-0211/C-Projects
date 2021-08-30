#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <conio.h>
#define max 100
using namespace std;

class customer
{
public:
    char name[100];
    char address[100];
    char phone[12];
    char from_date[20];
    char to_date[20];
    float payment_advance;
    int booking_id;
};
class Room
{
public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;

    class customer cust;
    class Room addRoom(int);
    void searchRoom(int);
    void deleteRoom(int);
    void displayRoom(Room);
};
int count = 0;
class Room rooms[max];

Room Room ::addRoom(int rno)
{
    class Room room;
    room.roomNumber = rno;
    cout << "\n Type AC/non-AC (A/N):";
    cin >> room.ac;
    cout << "\n Type Comfort (S/N):";
    cin >> room.type;
    cout << "\n Type size (B/S): ";
    cin >> room.stype;
    cout << "\n Daily Rent :";
    cin >> room.rent;
    room.status = 0;
    cout << "\n Room added successfully";
    _getch();
    return room;
}
void Room ::searchRoom(int rno)
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "Room Details \n";
        if (rooms[i].status == 1)
        {
            cout << "\n Room is Reserverd";
        }
        else
        {
            cout << "\n Room is Available";
        }
        displayRoom(rooms[i]);
        _getch();
    }
    else
    {
        cout << "\n Room is not availbale";
        _getch();
    }
}
void Room ::displayRoom(Room tempRoom)
{
    cout << "\n Room Number: \t" << tempRoom.roomNumber;
    cout << "\n Type AC/non-Ac \t" << tempRoom.ac;
    cout << "\n Type Comfort (S/N) " << tempRoom.type;
    cout << "\n Type Size (B/S) :" << tempRoom.stype;
    cout << "\n Rent: " << tempRoom.rent;
}
class HotelMgnt : protected Room
{
public:
    void checkIn();
    void getAvailRoom();
    void searchCustomer(char *);
    void checkout(int);
    void guestSummaryReport();
};
void HotelMgnt ::guestSummaryReport()
{
    if (count == 0)
    {
        cout << "\n No Guest in Hotel";
    }
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "\n Customer First Name: " << rooms[i].cust.name;
            cout << "\n Room Number: " << rooms[i].roomNumber;
            cout << "\n Address (omly City) :" << rooms[i].cust.address;
            cout << "\n Phone: " << rooms[i].cust.phone;
            cout << "\n -----------------------------";
        }
    }
    _getch();
}
void HotelMgnt ::checkIn()
{
    int i, found = 0, rno;
    Room room;
    cout << "\n Enter Room Number: ";
    cin >> rno;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomNumber == rno)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        if (rooms[i].status == 1)
        {
            cout << "\n Room Is Already Booked!";
            _getch();
            return;
        }
        cout << "\n Enter Booking id: ";
        cin >> rooms[i].cust.booking_id;
        cout << "\n Enter Customer Name (first Name) :";
        cin >> rooms[i].cust.name;
        cout << "\n Enter Addresss (only City) ";
        cin >> rooms[i].cust.address;
        cout << "\n Enter Phone: ";
        cin >> rooms[i].cust.phone;
        cout << "\n Enter From Date: ";
        cin >> rooms[i].cust.from_date;
        cout << "\n Enter To Date: ";
        cin >> rooms[i].cust.to_date;
        cout << "\n Enter Advance Payment :";
        cin >> rooms[i].cust.payment_advance;
        rooms[i].status = 1;
        cout << "\n Customer Checked In Successfully...";
        _getch();
    }
}
void HotelMgnt ::getAvailRoom()
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 0)
        {
            displayRoom(rooms[i]);
            cout << "\n Press Enter fornext room";
            found = 1;
            _getch();
        }
    }
    if (found == 0)
    {
        cout << "\n All rooms are rserverd";
        _getch();
    }
}
void HotelMgnt ::searchCustomer(char *pname)
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && strcmpi(rooms[i].cust.name, pname) == 0)
        {
            cout << "\n Customer name :" << rooms[i].cust.name;
            cout << "\n Room Number: " << rooms[i].roomNumber;
            cout << "\n\n Press enter for next record";
            found = 1;
            _getch();
        }
    }
    if (found == 0)
    {
        cout << "\n Person not found";
        _getch();
    }
}
void HotelMgnt ::checkout(int roomNum)
{
    int i, found = 0, days, rno;
    float billAmount = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\n Enter Number of days: \t";
        cin >> days;
        billAmount = days * rooms[i].rent;

        cout << "\n\t #################   CheckOut Details  ###################\n";
        cout << "\n Customer Name: " << rooms[i].cust.name;
        cout << "\n Room Number: " << rooms[i].roomNumber;
        cout << "\n Address :" << rooms[i].cust.address;
        cout << "\n Phone: " << rooms[i].cust.phone;
        cout << "\n Total Amount: " << billAmount << "/";
        cout << "\n Advance Paid: " << rooms[i].cust.payment_advance << "/";
        cout << "\n Total paybale Bill Amount: " << billAmount - rooms[i].cust.payment_advance << "$";
        rooms[i].status = 0;
    }
    _getch();
}
void manageRooms()
{
    Room room;
    int opt, rno, i, flag = 0;
    char ch;
    do
    {
        system("cls");
        cout << "\n ### Manage Rooms ### ";
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Back to main menu";
        cout << "\n\n Enter An option";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\n Enter Room Number: ";
            cin >> rno;
            i = 0;
            for (i = 0; i < count; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    flag = 1;
                }
            }
            if (flag = 1)
            {
                cout << "\n Room number Is Present .\n Please Enter Unique number";
                flag = 0;
                _getch();
            }
            else
            {
                rooms[count] = room.addRoom(rno);
                count++;
            }
            break;
        case 2:
            cout << "\n Enter room Number";
            cin >> rno;
            room.searchRoom(rno);
            break;
        case 3:
            break;
        }
    } while (opt != 3);
}
int main()
{
    HotelMgnt hm;
    int it, j, opt, rno;
    char ch;
    char pname[100];
    system("cls");

    do
    {
        system("cls");
        cout << "######## Hotel Management ##########\n";
        cout << "\n1. Manage/Add Rooms";
        cout << "\n2. Check-In Room";
        cout << "\n3. Available Rooms";
        cout << "\n4. Search Customer";
        cout << "\n5. Check-Out Room";
        cout << "\n6. Guest Summary Report";
        cout << "\n7. Exit";
        cout << "\n\n Enter Option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            manageRooms();
            break;
        case 2:
            if (count == 0)
            {
                cout << "\n Rooms Data is not available. \n Please add the rooms first";
                _getch();
            }
            else
            {
                hm.checkIn();
            }
            break;
        case 3:
            if (count == 0)
            {
                cout << "\n Rooms data is not available. \nPlease add the rooms first";
                _getch();
            }
            else
            {
                hm.getAvailRoom();
            }
            break;
        case 4:
            if (count == 0)
            {
                cout << "\n Rooms data is not available.\nPlease add the rooms first";
                _getch();
            }
            else
            {
                cout << "Enter Customer name:";
                cin >> pname;
                hm.searchCustomer(pname);
            }
            break;
        case 5:
            if (count == 0)
            {
                cout << "\n Rooms data is not available.\nPlease add the rooms first";
                _getch();
            }
            else
            {
                cout << "Enter Room Number";
                cin >> rno;
                hm.checkout(rno);
            }
            break;
        case 6:
            hm.guestSummaryReport();
            break;
        case 7:
            cout << "\n THANK YOU! FOR USING THIS SOFTWARE";
            break;

        default:
            cout << "\n Please enter correct option";
            break;
        }
    } while (opt != 7);
    _getch();
}