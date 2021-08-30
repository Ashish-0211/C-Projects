#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void drawline(int n, char symbol);
void rules();
int main()
{
    string playerName;
    int amount;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0));
    drawline(60, '_');
    cout << "\n\n\t\t CASINO GAME \t\t\t\n\n";
    drawline(60, '_');

    cout << "\n\n Enter Your Name";
    getline(cin, playerName);
    cout << "\n\n Enter Deposit Amount to Play The Game: $";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\n Your current balence is $" << amount << "\n";
        do
        {
            cout << playerName << " Enter money to bet :";
            cin >> bettingAmount;
            if (bettingAmount > amount)
            {
                cout << "Your beeting amount is more than the balace";
            }
        } while (bettingAmount > amount);
        do
        {
            cout << "Guess your Number to bet between 1 to 10";
            cin >> guess;
            if (guess <= 0 || guess > 10)
            {
                cout << "Please check the number you have entered";
            }
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\n\n Good Luck! You Won $" << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck This time !! You Lost $" << bettingAmount << "\n";
            amount = amount - bettingAmount;
        }
        cout << "\n The Winning Number was " << dice << "\n";
        cout << "\n"
             << playerName << ", You Have $" << amount << "\n";
        if (amount == 0)
        {
            cout << "Yoiuu have no money"
                 << "\n";
            break;
        }
        cout << "\n\n --> DO yoou want to play again (Y/N)";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    drawline(70, '=');
    cout << "Thanks for playinig game ..............";
    cout << "\n Your balence amount is :" << amount;
    drawline(70, '=');
    return 0;
}

void drawline(int n, char symbol)
{
    for (int i = 0; i < n; i++)
    {
        cout << symbol;
    }
    cout << "\n";
}
void rules()
{
    system("cls");
    cout << "\n\n";
    drawline(80, '-');
    cout << "\n 1. case any number between 1 to 10";
    cout << "\n 2. if you win you will get 10 times the betting amount\n";
    cout << "\n 3. iff you lose the etting amount is reduced from your total amount\n";
    drawline(80, '-');
}
