#include <iostream>
#include <time.h>
#include <ctime>

using namespace std;
int calculateage();
int count;
int birthDay, birthMonth, birthYear, ageYears, ageMonths, ageDays;
char alp;

int calculateage()
{
    cout << "\n Please enter your birth date (d/m/Y e.g. 03/12/2020): " << endl;

    cin >> birthDay >> alp >> birthMonth >> alp >> birthYear;

    if (!birthDay)
    {
        return 0;
    }

    cout << "Your birthday date is: " << birthDay << "/" << birthMonth << "/" << birthYear << endl;

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int currentMonth = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
    int prevMonth = currentMonth - 1;

    ageYears = (1900 + aTime->tm_year) - birthYear;
    ageMonths = currentMonth - birthMonth;
    ageDays = aTime->tm_mday - birthDay;

    // If days are in negative then chances are birthday was in last month
    if (ageDays < 0)
    {
        // If previous month has 31 days
        if (prevMonth == 1 || prevMonth == 3 || prevMonth == 5 || prevMonth == 7 || prevMonth == 8 || prevMonth == 10)
        {
            ageDays += 30;
        }
        else if (prevMonth == 2)
        {
            ageDays += 27;
        }
        else
        {
            ageDays += 29;
        }

        ageMonths -= 1;
    }

    // if months were in negative then it means last birthday was in previous year
    if (ageMonths < 0)
    {
        ageMonths += 12;
        ageYears -= 1; // Reduce year by 1 to adjust months
    }

    cout << "\n your age is: " << ageYears << " years  " << ageMonths << " months " << ageDays << " days";

    return 1;
}

int main()
{
    do
    {
        if (!calculateage())
        {
            break;
        }

    } while (true);

    return 0;
}
