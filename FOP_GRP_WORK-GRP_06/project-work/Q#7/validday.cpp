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
        cout << "enter the day,month and year separated by space: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> temp[i]; // date[0] is day,date[1] is month and date[2] is year
            date[i] = &temp[i];
        }
        bool leap = false; // this is to check when the year is leap year
        if (*date[2] % 4 == 0)
            if (*date[2] % 100 == 0)
            {
                if (*date[2] % 400 == 0)
                    leap = true;
            }
            else
                leap = true; // check leap is finished
        bool valid = false;  // valid number of days
        string invalid;      // this the message printed if the date is invalid

        if (*date[1] > 0 && *date[1] <= 12 && *date[0] > 0)

            switch (*date[1])
            {
            case 1:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day!";
                break;
            case 2:
                if (leap == true)
                {
                    if (*date[0] <= 29)
                        valid = true;
                    else if (*date[0] <= 31)
                        invalid = to_string(*date[0]) + " is invalid day  in february!";
                    else
                        invalid = to_string(*date[0]) + " is invalid day!";
                }
                else
                {
                    if (*date[0] <= 28)
                        valid = true;
                    else if (*date[0] == 29)
                        invalid = to_string(*date[0]) + " is invalid day  in february \nbecause the year is not leap year ";
                    else if (*date[0] <= 31)
                        invalid = *date[0] + " is invalid day  in february";
                    else
                        invalid = to_string(*date[0]) + " is invalid day";
                }
                break;
            case 3:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 4:
                if (*date[0] <= 30)
                    valid = true;
                else if (*date[0] == 31)
                    invalid = to_string(*date[0]) + " is invalid day  in april";
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 5:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 6:
                if (*date[0] <= 30)
                    valid = true;
                else if (*date[0] == 31)
                    invalid = to_string(*date[0]) + " is invalid day  in june";
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 7:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 8:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 9:
                if (*date[0] <= 30)
                    valid = true;
                else if (*date[0] == 31)
                    invalid = to_string(*date[0]) + " is invalid day  in june";
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 10:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 11:
                if (*date[0] <= 30)
                    valid = true;
                else if (*date[0] == 31)
                    invalid = to_string(*date[0]) + " is invalid day  in june";
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            case 12:
                if (*date[0] <= 31)
                    valid = true;
                else
                    invalid = to_string(*date[0]) + " is invalid day";
                break;
            }
        else if (*date[0] <= 0)
            invalid = to_string(*date[0]) + " is invalid day";
        else
            invalid = to_string(*date[1]) + " is invalid month";
        string NLyear;
        int temp = *date[2] + 4;
        if (valid == true)
        {
            if (leap == true)
            {
                cout << " " + to_string(*date[0]) + "/" + to_string(*date[1]) + "/" + to_string(*date[2]) + " is valid and also leap year.\nhear is below the next twenty Leap years : \n";

                for (int i = 1; i <= 20; i++)
                {
                    switch (temp)
                    {
                    case 1 ... 9:
                        NLyear = "000" + to_string(temp);
                        break;
                    case 10 ... 99:
                        NLyear = "00" + to_string(temp);
                        break;
                    case 100 ... 999:
                        NLyear = "0" + to_string(temp);
                        break;
                    default:
                        NLyear = to_string(temp);
                        break;
                    }
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