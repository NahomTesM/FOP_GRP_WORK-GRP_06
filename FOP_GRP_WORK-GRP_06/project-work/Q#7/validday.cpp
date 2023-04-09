#include <iostream>
#include <string>
using namespace std;

int main()
{

    int *date[3], temp[3];
    int condition = 1; // this is the condition that the user wants to continue or terminate

    while (condition == 1)
    {
        system("cls");
        int validity1 = 1; // this is to check when the input range
        do
        {
            validity1 = 1;
            cout << "enter the day,month and year (DD MM YYYY) separated by space: ";
            for (int i = 0; i < 3; i++)
            {
                cin >> temp[i]; // date[0] is day,date[1] is month and date[2] is year
                date[i] = &temp[i];
                if (cin.fail())
                {
                    cout << "WRONG INPUT!\nyour input is not integer!" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    validity1 = 0;
                    break;
                }
            }
            if (validity1 == 1)
            {
                if (*date[0] <= 0 || *date[0] >= 32)
                {
                    cout << *date[0] << "  IS INVALID DAY\n";
                    validity1 = 0;
                }
                else if (*date[1] <= 0 || *date[1] >= 13)
                {
                    cout << *date[1] << "  IS INVALID MONTH\n";
                    validity1 = 0;
                }
                else if (*date[2] <= 0 || *date[2] >= 10000)
                {
                    cout << *date[2] << "  IS INVALID YEAR\n";
                    validity1 = 0;
                }
            }

        } while (validity1 == 0);
        bool leap = false; // this is to check when the year is leap year
        if (*date[2] % 4 == 0 && (*date[2] % 100 != 0 || *date[2] % 400 == 0))
            leap = true; // check leap year is finished hear

        bool valid = true; // valid number of days
        string invalid;    // this is the message printed if the date is invalid

        switch (*date[1])
        {
        case 2:
            if (leap == true)
            {
                if (*date[0] > 29)
                {
                    valid = false;
                    invalid = to_string(*date[0]) + " is invalid day  in february!";
                }
            }
            else
            {
                if (*date[0] == 29)
                    invalid = to_string(*date[0]) + " is invalid day  in february \nbecause the year is not leap year ";
                else
                    invalid = *date[0] + " is invalid day  in february";
            }
            break;
        case 4:
            if (*date[0] == 31)
            {
                valid = false;
                invalid = to_string(*date[0]) + " is invalid day  in april";
            }
            break;
        case 6:
            if (*date[0] == 31)
            {
                valid = false;
                invalid = to_string(*date[0]) + " is invalid day  in june";
            }
            break;
        case 9:
            if (*date[0] == 31)
            {
                valid = false;
                invalid = to_string(*date[0]) + " is invalid day  in september";
            }
            break;
        case 11:
            if (*date[0] == 31)
            {
                valid = false;
                invalid = to_string(*date[0]) + " is invalid day  in november";
            }
            break;
        }
        string NLyear; // next leap year
        int temp = *date[2] + 4;
        if (valid == true)
        {
            if (leap == true)
            {
                cout << " " + to_string(*date[0]) + "/" + to_string(*date[1]) + "/" + to_string(*date[2]) + " is valid and also leap year.\nhear is below the next twenty Leap years : \n";

                for (int i = 1; i <= 20; i++) // this because if the year is less than 1000
                {
                    if (temp >= 1 && temp <= 9)
                        NLyear = "000" + to_string(temp);
                    else if (temp >= 10 && temp <= 99)
                        NLyear = "00" + to_string(temp);
                    else if (temp >= 100 && temp <= 999)
                        NLyear = "0" + to_string(temp);
                    else
                        NLyear = to_string(temp);
                    cout << NLyear << ", ";
                    temp += 4;
                }
            }
            else
                cout << " " + to_string(*date[0]) + "/" + to_string(*date[1]) + "/" + to_string(*date[2]) + " is valid but not leap year.";
        }
        else
            cout << invalid;

        cout << "\nenter 1 if you want to continue: ";
        cin >> condition;
    }
    return 0;
}
