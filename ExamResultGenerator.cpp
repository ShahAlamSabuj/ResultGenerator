#include <iostream>
#include<conio.h>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
 
double ban1, ban2, e1, e2, m, ss, gs, re, ag;
double gpa = 0; double avr, e3, b3;
string name;
int wen = 1;
 
void SubEn ()
{
    cout << "Bangla 1st Paper\t: "; cin >> ban1;
    cout << "Bangla 2nd Paper\t: "; cin >> ban2;
    cout << "English 1st Paper\t: "; cin >> e1;
    cout << "English 2nd Paper\t: "; cin >> e2;
    cout << "Mathematics\t\t: "; cin >> m;
    cout << "Social Science\t\t: "; cin >> ss;
    cout << "General Science\t\t: "; cin >> gs;
    cout << "Religion\t\t: "; cin >> re;
    cout << "Agri / Home Eco.\t: "; cin >> ag;
}
 
void Header ()
{
    ofstream head;
    head.open ("results.txt", ios::app);
    head << "RESULT - " << name << endl << endl;
    head.close();
}
 
void Checker (string x, double p)
{
    ofstream record;
    record.open ("results.txt", ios::app);
    if (record.is_open() )
    {
        if (p == 80 || p > 80)
        {
            cout << x << "\tA+\n";
            gpa += 5.0;
            record << x << "\t" << p << "\tA+\n";
        }
        else if (p == 70 || p > 70)
        {
            cout << x << "\tA\n";
            gpa += 4.0;
            record << x << "\t" << p << "\tA\n";
        }
        else if (p == 60 || p > 60)
        {
            cout << x << "\tA-\n";
            gpa += 3.5;
            record << x << "\t" << p << "\tA-\n";
        }
        else if (p == 50 || p > 50)
        {
            cout << x << "\tB\n";
            gpa += 3.0;
            record << x << "\t" << p << "\tB\n";
        }
        else if (p == 40 || p > 40)
        {
            cout << x << "\tC\n";
            gpa += 2.0;
            record << x << "\t" << p << "\tC\n";
        }
        else if (p == 33 || p > 33)
        {
            cout << x << "\tD\n";
            gpa += 1.0;
            record << x << "\t" << p << "\tD\n";
        }
        else {
            cout << x << "\t(F)\n";
            gpa += 0;
            record << x << "\t" << p << "\tF\n";
        }
        record.close();
    }
    else {
        system("CLS");
        system("msg * Unable to open file");
    }
}
 
double Avr ()
{
    double average;
    average = (ban1 + ban2 + e1 + e2 + m + gs + ss + re + ag) / 9;
    return average;
}
 
double grand ()
{
    double g;
    g = ban1 + ban2 + e1 + e2 + m + gs + ss + re + ag;
    return g;
}
 
double gpaf ()
{
    double gpa_release;
    gpa_release = (gpa - 20) / 7;
    return gpa_release;
}
 
int main ()
{
    while (wen == 1)
    {
        system("title Exam Result Generator 2.0 - By Shah Alam");
        cout << "=======================================================\n";
        cout << "This is able to generate simple exam results. \nIt can also deal with GPA, grand total and average\n";
        cout << "=======================================================\n";
        cout << endl;
        cout << "Student name (one word)\t: ";
        cin >> name;
        cout << endl;
        cout << "Type your achieved marks.\n\n";
        SubEn ();
        system("CLS");
 
        void Checker (string x, double p);
        e3 = (e1 + e2) / 2; b3 = (ban1 + ban2) / 2;
        cout << "RESULT - " << name << endl << endl;
        Header ();
        Checker ("Bangla 1st Paper\t: ", ban1); Checker ("Bangla 2nd Paper\t: ", ban2);
        Checker ("Ban 1st + Ban 2nd\t: ", b3);
        Checker ("English 1st Paper\t: ", e1); Checker ("English 2nd Paper\t: ", e2);
        Checker ("Eng 1st + Eng 2nd\t: ", e3);
        Checker ("Mathematics\t\t: ", m); Checker ("Social Science\t\t: ", ss); Checker ("General Science\t\t: ", gs);
        Checker ("Religion\t\t: ", re); Checker ("Agri / Home Eco.\t: ", ag);
        cout << endl;
 
        string passer;
        bool ps = (ban1 > 32 && ban2 > 32 && e1 > 32 && e2 > 32 && m > 32 && ss > 32 && gs > 32 && re > 32 && ag > 32);
        passer = ps ? "Passed\t: YES\n" : "Passed\t: No\n";
        cout << passer;
        cout << "Average in per subject\t: ";
        cout << Avr () << endl;
        cout << "Grand Total\t: ";
        cout << grand () << endl;
        cout << "Lack from total mark: ";
        cout << 900 - (ban1 + ban2 + e1 + e2 + m + gs + ss + re + ag) << endl;
        if (ps == 0)
        {
            cout << "\nYou have failed in one or more subject(s)\n*****YOUR GPA\t: 0.0 *****\n\n";
            goto WRITE;
        }
        cout << "*****YOUR GPA\t: ";
        cout << gpaf ();
        cout << " *****\n" << endl;
        WRITE:
        ofstream record;
        record.open ("results.txt", ios::app);
        record << endl;
        record << passer;
        record << "Average in per subject : " << Avr () << endl;
        record << "Grand Total : " << grand () << endl;
        record << "Lack of mark : " << 900 - (ban1 + ban2 + e1 + e2 + m + gs + ss + re + ag) << endl << endl;
        if (ps == 0)
        {
            record << "You have failed in one or more subjects.\n" << "Your GPA is : 0.0\n";
        }
        else {
        record << "Your GPA is : " << gpaf () << endl;
        }
        record << "--------------------------------------------------------\n\n";
        record.close();
        cout << "Type 1 to generate a new result or press 2 to exit (+ hit enter)\n";
        cin >> wen;
        if (wen == 1)
        system ("CLS");
        if (wen != 1) {
            system("start results.txt");
            return 0;
        }
    }
    return 0;
	getch();
}