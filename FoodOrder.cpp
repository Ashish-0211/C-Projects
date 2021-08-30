#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <Windows.h>
#include <unistd.h>
// #include <bits/stdc++.h>
using namespace std;

class one
{
public:
    void menu1();
};

void one::menu1()
{
    cout << "\n\n\n\n\t\t\t\t ======================== WELCOME TO FOOD ORDERING APP ======================" << endl;
    cout << "\n\n\n\n\t\t\t\t ============================= START YOUR ORDER =============================" << endl;
    cout << "\n\n\n\t===============================\t\t\t============================\t\t\t\t=======================================" << endl;
    cout << "\t[1] Veggie Supreme (Rs.480)\t\t\t[2] Exotica Pizza(Rs.440)\t\t\t\t[3] Chicken Sizzler (Rs.580)\n\t[4] Chrispy Chicken (Rs.520)\t\t\t[5] Spaghetti (Rs.350)\t\t\t\t\t[6] Country Feast (Rs.400)\n\t[7] Tetrazzini (Rs.420)\t\t\t\t[8] Double Cheese (Rs.540)\t\t\t\t[9] Makizushi (Rs.548)\n\t[10] Ham Burger (Rs.390)\t\t\t[11] Margherita Pizza(Rs.525)\t\t\t\t[12] Fish 'n' Chips (Rs.425)\n\t[13] Fajitas (Rs.335)\t\t\t\t[14] Tempura (Rs.324)\t\t\t\t\t[15] Hot Dog (Rs.360)\n\t===========================\t\t\t==============================\t\t\t\t===========================\n\n\n\t\t\t\t\t\t\t\t[16] EXIT" << endl;
}
class two : public one
{
protected:
    int pizza, ch, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s = 0;
    string y, ye;

public:
    void menu2()
    {
        ofstream write;
        write.open("order.txt");
        if (!write)
        {
            cout << "File Cannot open " << endl;
            exit(-1);
        }
    a:
    b:
    c:
        cout << "\n\n Enter Your Order (oone order at a time): ";
        cin >> ch;
        cout << "\n\n\t DO you want to update the order (y/n)";
        cin >> ye;
        if (ye == "y" || ye == "Y")
        {
            goto b;
        }
        else
        {
            switch (ch)
            {
            case 1:
                cout << "\n\n\n How many pizza you want";
                cin >> pizza;
                a = 480;
                s = s + a * pizza;
                write << "You ordered veggie supreme:480";
                write << "\n";
                write << "Number of pizza" << pizza;
                write << "\n";
                cout << "\n\n\n You Order vegie supreme" << endl
                     << "your order successfully saved!";
                break;
            case 2:
                cout << "\n\n\n How many pizza you want";
                cin >> pizza;
                b = 440;
                s = s + b * pizza;
                write << "You ordered veggie Exotica:440";
                write << "\n";
                write << "Number of pizza" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Exotica" << endl
                     << "your order successfully saved!";
                break;
            case 3:
                cout << "\n\n\n How many Chiicken Sizzler you want";
                cin >> pizza;
                c = 580;
                s = s + c * pizza;
                write << "You ordered Chicken Sizzler:580";
                write << "\n";
                write << "Number of Sizzler" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Chicken Sizzler" << endl
                     << "your order successfully saved!";
                break;
            case 4:
                cout << "\n\n\n How many Chrispy Chicken you want";
                cin >> pizza;
                d = 520;
                s = s + d * pizza;
                write << "You ordered Chrispy Chiken:520";
                write << "\n";
                write << "Number of Chicken's" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Chrispy Chicken" << endl
                     << "your order successfully saved!";
                break;
            case 5:
                cout << "\n\n\n How many Spaghetti you want";
                cin >> pizza;
                e = 350;
                s = s + e * pizza;
                write << "You ordered Spaghetti: 350";
                write << "\n";
                write << "Number of Spaghetti" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Spaghetti" << endl
                     << "your order successfully saved!";
                break;
            case 6:
                cout << "\n\n\n How many Country Feast you want";
                cin >> pizza;
                f = 400;
                s = s + f * pizza;
                write << "You ordered Country Feast:400";
                write << "\n";
                write << "Number of COuntry Feast" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Country Feast" << endl
                     << "your order successfully saved!";
                break;
            case 7:
                cout << "\n\n\n How many Tetrazzini you want";
                cin >> pizza;
                g = 420;
                s = s + g * pizza;
                write << "You ordered Tetrazzini:420";
                write << "\n";
                write << "Number of Tetrazzini" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Tetrazzini" << endl
                     << "your order successfully saved!";
                break;
            case 8:
                cout << "\n\n\n How many Double Cheese you want";
                cin >> pizza;
                h = 540;
                s = s + h * pizza;
                write << "You ordered Double Cheese:540";
                write << "\n";
                write << "Number of Double Cheese's" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Double Cheese" << endl
                     << "your order successfully saved!";
                break;
            case 9:
                cout << "\n\n\n How many Makizushi you want";
                cin >> pizza;
                i = 548;
                s = s + i * pizza;
                write << "You ordered Makizushi:548";
                write << "\n";
                write << "Number of Makizushi" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Makizushi" << endl
                     << "your order successfully saved!";
                break;
            case 10:
                cout << "\n\n\n How many Ham burger you want";
                cin >> pizza;
                j = 390;
                s = s + j * pizza;
                write << "You ordered HAm Burgers:390";
                write << "\n";
                write << "Number of Ham Burger" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Ham Burger" << endl
                     << "your order successfully saved!";
                break;
            case 11:
                cout << "\n\n\n How many Marghrita you want";
                cin >> pizza;
                k = 525;
                s = s + k * pizza;
                write << "You ordered Marghrita:525";
                write << "\n";
                write << "Number of Marghrita" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Margherita" << endl
                     << "your order successfully saved!";
                break;
            case 12:
                cout << "\n\n\n How many Fish 'n' Chips you want";
                cin >> pizza;
                l = 425;
                s = s + l * pizza;
                write << "You ordered Fish 'n' Chips:425";
                write << "\n";
                write << "Number of Fish 'n' Chips" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Fish 'n' Chips" << endl
                     << "your order successfully saved!";
                break;
            case 13:
                cout << "\n\n\n How many FAjita you want";
                cin >> pizza;
                m = 335;
                s = s + m * pizza;
                write << "You ordered Fajita:335";
                write << "\n";
                write << "Number of Fajita" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Fajita" << endl
                     << "your order successfully saved!";
                break;
            case 14:
                cout << "\n\n\n How many Tempura you want";
                cin >> pizza;
                n = 324;
                s = s + n * pizza;
                write << "You ordered Tempura:324";
                write << "\n";
                write << "Number of Tempura" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Tempura" << endl
                     << "your order successfully saved!";
                break;
            case 15:
                cout << "\n\n\n How many Hot Dog you want";
                cin >> pizza;
                o = 360;
                s = s + o * pizza;
                write << "You ordered Hot Dog:360";
                write << "\n";
                write << "Number of Hot Dog" << pizza;
                write << "\n";
                cout << "\n\n\n You Order Hot Dog" << endl
                     << "your order successfully saved!";
                break;
            case 16:
                exit(0);
                break;
            default:
                cout << "\n\n\n\n You Entered Wrong Choice\n";
                goto c;
                break;
            }
            cout << "\n\n\t Do You Want another order (yes/no):";
            cin >> y;
            if (y == "yes" || y == "YES")
            {
                goto a;
            }
            else
            {
                cout << "\n\n\n\n\n\t\t Thank You For Order :)";
            }
            for (int a = 1; a < 0; a++)
            {
                Sleep(500);
                cout << " ...";
            }
            cout << "\n\t\t\t\t";
            system("PAUSE");
        }
        system("cls");
        cout << "\n\t\t\t\t\t\t =========================================================" << endl;
        cout << "\n\t\t\t\t\t\t                 FOOD ORDERING SYSTEM                    !" << endl;
        cout << "\n\t\t\t\t\t\t =========================================================" << endl;

        cout << endl;
        cout << endl;

        cout << "\t\t\t\t\t\t Bill No: CP51               Order: NB1353" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t\ Cashier: Harry" << endl;
        cout << endl;
        cout << "\n\t\t\t\t\t\t YOUR TOTAL BILL IS Rs." << s << endl;
        write << "\t\t\t\t\t\t\t";
        write << "\t\t\t\t\t\t\tTOTAL BILL IS Rs." << s;
        cout << "\n\t\t\t\t\t\t\t\t==================================================" << endl;

        write.close();
    }
    void showl()
    {
        menu1();
        menu2();
    }
};
class Three : public one, public two
{
public:
    void total()
    {
        long userId;
    d:
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t ---------------------";
        cout << "\n\n\t\t\t\t\t\t\t Enter Login Id =";
        cin >> userId;
        cout << "\t\t\t\t\t\t\t\t\t\t -------------------------------------";
        if (userId != 1353)
        {
            cout << "\n Don't Try To be Smart ...... Enter COrrect id ...";
            goto d;
        }
        else
            cout << "\n\n\n\n\n\t\t\t\t\t Hello Code - Projects,\n";
    z:
        string pwd = "pass";
        string pass = "";
        char c;
        cout << "\n\n\n\n\t\t\t\t\t Password = ";
    p:
        c = _getch();
        cout << "*";
        if (c != 13)
        {
            pass = pass + c;
            goto p;
        }

        {
            if (pass == pwd)
            {
                cout << "\n\n\n\n\n\t\t\t\t\t Access Granted. Welcome To our System \n\n\n\n\n";
                system("PAUSE");
                system("CLS");
                showl();
            }
            else
            {
                cout << "\n Wrong Password\n";
                goto z;
            }
        }
    }
};
int main()
{
    Three obj1;
    obj1.total();
    _getch();
}