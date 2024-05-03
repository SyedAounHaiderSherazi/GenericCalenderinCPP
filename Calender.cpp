#include <iostream>
#include<iomanip>
using namespace std;
//Q1 FUNCTIONS 
// Function to print the name of the month
void printMonth(int month) {
    switch (month) {
    case 1:  cout << "*** January ***"; break;
    case 2:  cout << "*** February ***"; break;
    case 3:  cout << "*** March ***"; break;
    case 4:  cout << "*** April ***"; break;
    case 5:  cout << "*** May ***"; break;
    case 6:  cout << "*** June ***"; break;
    case 7:  cout << "*** July ***"; break;
    case 8:  cout << "*** August ***"; break;
    case 9:  cout << "*** September ***"; break;
    case 10: cout << "*** October ***"; break;
    case 11: cout << "*** November ***"; break;
    case 12: cout << "*** December ***"; break;
    default: cout << "its invalid month"; break;
    }
    cout << endl;
}

// this is the function to get  number of days in  month
int getNoOfDaysInMonth(int month, int year) {
    int daysinthemonth = 0;
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        daysinthemonth = 29; // for leap year
    }
    else {
        switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysinthemonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysinthemonth = 30; break;
        default: daysinthemonth = 0; break; // if invalid month
        }
    }
    return daysinthemonth;
}

// function to get starting day of month   by using the zellers calculations
int getstartingdayofthemonth(int month, int year) {
    if (month < 3) {             //checks if  month is Jan or Feb
        month += 12;              // if they are we add 12 to them
        year -= 1;
    }
    int last2digitsofyear = year % 100;
    int starting2digitsofyear = year / 100;
    int day = 1;      //to startt from frst day
    int c = (day + 13 * (month + 1) / 5 + last2digitsofyear + last2digitsofyear / 4 + starting2digitsofyear / 4 - 2 * starting2digitsofyear) % 7;
    return ((c + 5) % 7) + 1;         //these are calculations
}

// Function to print the calendar of a given month and year
void printCalendar(int month, int year) {
    printMonth(month);
    int daysInMonth = getNoOfDaysInMonth(month, year);
    int startingDay = getstartingdayofthemonth(month, year);

    cout << "Mon Tue Wed Thu Fri Sat Sun" << endl;

    int dayOfWeek = 1; // staart with mmoonday  and rhen 7 day sunday

    for (int i = 1; i < startingDay; ++i) {
        cout << "    "; // printing spaces for days before  first day of the month
        dayOfWeek++;
    }

    for (int day = 1; day <= daysInMonth; ++day) {             // loop through each day of the month
        if (day < 10) {                                          // print a leading zero for single-digit days

            cout << " ";
        }
        cout << day << "  ";

        //ckeck if the week is ended
        if (dayOfWeek == 7) {
            cout << endl;
            dayOfWeek = 0; // then it resets it to Monday
        }

        dayOfWeek++;           //increments the dayy of week
    }


    // If last row is not complete, start a new line

    if (dayOfWeek != 1) {
        cout << endl;
    }
}

int main()

    //q1

    { int year;
    cout << ".......................Q1............................" << endl;
    cout << "Enter the year: ";
    cin >> year;
    if (year <= 0)
    {
        cout << "enter a positive number!";
    }
    else
    {
        for (int month = 1; month <= 12; ++month) {
            printCalendar(month, year);
            cout << endl;
        }
    }


    }
    