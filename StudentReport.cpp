#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class student
{
    int rollno;
    char name[50];
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    float per;
    char grade;
    int std;
    void calculate()
    {
        per = (p_marks + c_marks + m_marks + cs_marks + e_marks) / 5.0;
        if (per >= 60)
        {
            grade = 'A';
        }
        else if (per >= 50 && per < 60)
        {
            grade = 'B';
        }
        else if (per < 50)
        {
            grade = 'C';
        }
        else
        {
            grade = 'D';
        }
    }

public:
    void getdata()
    {
        cout << "\nEnter Roll Number of a student";
        cin >> rollno;
        cout << "\nEnter the Name of the studunt";
        cin >> name;
        cout << "\nEnter Physics Marks Out of 100: ";
        cin >> p_marks;
        cout << "\nEnter Chemistry Marks Out of 100: ";
        cin >> c_marks;
        cout << "\nEnter Maths Marks Out of 100: ";
        cin >> m_marks;
        cout << "\nEnter English Marks Out of 100: ";
        cin >> e_marks;
        cout << "\nEnter Computer Science Marks Out of 100: ";
        cin >> cs_marks;
        calculate();
    }
    void showdata()
    {
        cout << "\nRoll number of Student: " << rollno;
        cout << "\nName Of the students: " << name;
        cout << "\nPhysics marks: " << p_marks;
        cout << "\nChemistry marks: " << c_marks;
        cout << "\nMaths marks: " << m_marks;
        cout << "\nEnglish marks: " << e_marks;
        cout << "\nComputer Science marks: " << cs_marks;
        cout << "\nPrecentage Of student is: " << setprecision(2) << per;
        cout << "\n/Grades of student: " << grade;
    }
    void show_tabular()
    {
        cout << rollno << setw(12) << name << setw(10) << p_marks << setw(3)
             << c_marks << setw(3) << m_marks << setw(3) << e_marks
             << setw(3) << cs_marks << setw(6) << setprecision(3) << per << "  " << grade << endl;
    }
    int retrollno()
    {
        return rollno;
    }
};
fstream fp;
student st;

void write_student()
{
    fp.open("student.dat", ios::out | ios::app);
    st.getdata();
    fp.write((char *)&st, sizeof(student));
    fp.close();
    cout << "\n\nStudent record has been created";
    _getch();
}
void display_all()
{
    system("cls");
    cout << "\n\n\n\t\t Display All Records!!!\n\n";
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&st, sizeof(student)))
    {
        st.showdata();
        cout << "\n\n ===================================\n";
        _getch();
    }
    fp.close();
    _getch();
}
void display_sp(int n)
{
    int flag = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if (st.retrollno() == n)
        {
            system("cls");
            st.showdata();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
    {
        cout << "\n\nRecord does not exist";
    }
    _getch();
}
void modify_student()
{
    int no, found = 0;
    system("cls");
    cout << "\n\nTo Modify ";
    cout << "\n\n\tPlease Enter roll no of a student";
    cin >> no;
    fp.open("student.dat", ios::in | ios::out);
    while (fp.read((char *)&st, sizeof(student)) && found == 0)
    {
        if (st.retrollno() == no)
        {
            st.showdata();
            cout << "\nPlease Enter The new details of the student" << endl;
            st.getdata();
            int pos = -1 * sizeof(st);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&st, sizeof(student));
            cout << "\n\n\t Record Is Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
    {
        cout << "\n Record Not Found ";
    }
    _getch();
}
void delete_student()
{
    int no;
    system("cls");
    cout << "\n\n\nDelete Record";
    cout << "\n\n Please Enter the roll number of student you want to delete: ";
    cin >> no;
    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&st, sizeof(student)))
    {
        if (st.retrollno() != no)
        {
            fp2.write((char *)&st, sizeof(student));
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout << "\n\n\tRecord Deleted!...";
    _getch();
}
void class_result()
{
    system("cls");
    fp.open("student.dat", ios::in);
    if (!fp)
    {
        cout << "Error!!! File Could Not Be Open \n\n\n Go to Entry menu to create file";
        cout << "\n\n\n Program Is Closing...........";
        _getch();
        exit(0);
    }
    cout << "\n\n\n\t ALL STUDENTS RESULT \n\n";
    cout << "=================================================================================\n";
    cout << "Roll no. Name                                         P  C  M  E  CS  %age Grade\n";
    cout << "=================================================================================\n";
    while (fp.read((char *)&st, sizeof(student)))
    {
        st.show_tabular();
    }
    fp.close();
    _getch();
}
void result()
{
    int ans, rno;
    char ch;
    system("cls");
    cout << "\n\n\nRESULT MENU";
    cout << "\n\n\n1. CLASS RESULT\n\n2. STUDENT REPORT CARD\n\n3. BACK TO MAIN MENU";
    cout << "\n\n\nEnter Choice (1/2)? ";
    cin >> ans;
    switch (ans)
    {
    case 1:
        class_result();
        break;
    case 2:
    {
        do
        {
            system("cls");
            char ans;
            cout << "\n\n Enter Roll Number of student: ";
            cin >> rno;
            display_sp(rno);
            cout << "\n\n Do you want to see more result (y/n)? ";
            cin >> ans;
        } while (ans == 'Y' || ans == 'y');
        break;
    }
    case 3:
        break;
    default:
        cout << "\a";
    }
}
void intro()
{
    system("cls");
    gotoxy(35, 11);
    cout << "STUDENT";
    gotoxy(33, 14);
    cout << "REPORT CARD";
    gotoxy(35, 17);
    _getch();
}
void entry_menu()
{
    system("cls");
    char ch2;
    cout << "\n\n\n\t ENTRY MENU";
    cout << "\n\n\n\t1. CREATE STUDENT RECORD";
    cout << "\n\n\n\t2. DISPLAY ALL STUDENTS RECORDS";
    cout << "\n\n\n\t3. SEARCH STUDENT RECORD";
    cout << "\n\n\n\t4. MODIFY STUDENT RECORD";
    cout << "\n\n\n\t5. DELETE STUDENT RECORD";
    cout << "\n\n\n\t5. BACK TO MAIN MENU";
    cout << "\n\n\n\t please enter your choice (1-6) ";
    ch2 = getche();
    switch (ch2)
    {
    case '1':
        system("cls");
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        int num;
        system("cls");
        cout << "\n\n\tPlease Enter roll Number: ";
        cin >> num;
        display_sp(num);
        break;
    case 5:
        delete_student();
        break;
    case 6:
        break;
    default:
        cout << "\a";
        entry_menu();
    }
}
int main()
{
    char ch;
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\t MAIN MENU";
        cout << "\n\n\n\t1. RESULT MENU";
        cout << "\n\n\n\t2. ENTRY/EDIT MENU";
        cout << "\n\n\n\t3. EXIT";
        cout << "\n\n\n\tPlease select your option (1-3) ";
        ch = getche();
        switch (ch)
        {
        case '1':
            system("cls");
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '3');
}