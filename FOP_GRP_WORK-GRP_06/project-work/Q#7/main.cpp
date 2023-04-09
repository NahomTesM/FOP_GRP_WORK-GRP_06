#include<iostream>
using namespace std;

int main(){
    
    int date [8];
    int day[2];
    int month[2];
    int year[4];

    int i;


    cout << "Enter the date: ";

    for (i = 0; i < 8; i++){
        cin >> date[i];
    }
    
    cout << endl;
    for (i = 0; i < 2; i++){
        day[i] = date [i];
    } 
    for (i = 0; i < 2; i++){
        cout << day[i];
    }
    cout << endl;
    for (i = 0; i < 2;i++){
        month[i]=date[i+2];
    }
    for (i = 0; i < 2;i++){
        cout << month[i];
    }
    cout << endl;
    for (i = 0; i < 4;i++){
        year[i]= date[i+4];
    }
    for (i = 0; i < 4;i++){
        cout << year[i];
    }
     int YEAR = (year[0]*1000)+(year[1]*100)+(year[2]*10)+(year[3]*1);
     int MONTH = (month[0]*10)+(month[1]*1);
     int DAY = (day [0]*10)+(day[1]*1);
     bool leapYear = true;

    if (YEAR % 4 ==0){
        if (YEAR % 100 != 0){
            leapYear = true;}
    else if (YEAR % 400 == 0){
                leapYear= true;
    }else if (YEAR % 400 != 0){
        leapYear= false;
       }
    }else{
        leapYear=false;
    }

    if (leapYear){
        cout << "The year is leap year.";
    }else{
        cout << "The year is not leap year.";
    }
    bool valid = true;
     if ((YEAR>=1880)&&(YEAR<=9999)){
        cout << "The year is valid.";
        if((MONTH>=1)&&(MONTH<=12)){
            cout << "The month is valid.";
            if(leapYear){
                if ((MONTH==1)||(MONTH==3)||(MONTH==5)||(MONTH==7)||(MONTH==8)||(MONTH==10)||(MONTH==12)){
                    if ((DAY>=1)&&(DAY>=31)){
                      cout << "The day is valid.";
                      valid;
                    }else{
                      cout << "The day is not valid.";
                    }
                }
                else if((MONTH==4)||(MONTH==6)||(MONTH==9)||(MONTH==11)){
                    if ((DAY>=1)&&(DAY<=30)){
                        cout << "The day is valid.";
                        valid;
                    }else{
                        cout << "The day is not valid.";
                    }
                }
                else if(MONTH==02){
                    if((DAY>=1)&&(DAY<=29)){
                        cout << "The day is valid.";
                        valid;
                    }else{
                        cout << "The day is not valid.";
                    }
                }
            }
        else  { 
            if ((MONTH==1)||(MONTH==3)||(MONTH==5)||(MONTH==7)||(MONTH==8)||(MONTH==10)||(MONTH==12)){
                    if ((DAY>=1)&&(DAY>=31)){
                      cout << "The day is valid.";
                      valid;
                    }else{
                      cout << "The day is not valid.";
                    }
                }
                else if((MONTH==4)||(MONTH==6)||(MONTH==9)||(MONTH==11)){
                    if ((DAY>=1)&&(DAY<=30)){
                        cout << "The day is valid.";
                        valid;
                    }else{
                        cout << "The day is not valid.";
                    }
                }
                else if(MONTH==02){
                    if((DAY>=1)&&(DAY<=28)){
                        cout << "The day is valid.";
                        valid;
                    }else{
                        cout << "The day is not valid.";
                    }
                }
        }
        }else{
            cout << "The month is not valid.";
        }
     }else{
        cout << "The year is not valid.";
     }

     if ((leapYear)&&(valid)){
        for (int j = 0; j < 20; j++){
            YEAR = YEAR + 4;
            cout << YEAR;
        }
     }

   return 0;
}