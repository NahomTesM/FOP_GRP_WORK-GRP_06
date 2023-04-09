#include <iostream>

using namespace std;

int main() {
    
   int ticketNumber;
   int ticketCode;
   int i = 0;
   int fee;
   int infant = 0, child = 0, teen = 0, adult = 0;
   int ticketSales = 0;

   do{
    cout << "Enter the ticket number: ";
    cin >> ticketNumber;
    cout << "Enter the ticket code: ";
    cin >> ticketCode;

    if ((ticketCode==1)||(ticketCode==2)||(ticketCode==3)||(ticketCode==4)){
    cout << "Valid ticket code.";
   }else{
       break;
    }

    i++;

   }while((ticketNumber>0)||(ticketCode>0));

   do{
    if(ticketCode==1){
        fee = 10;
        infant++;
    }else if(ticketCode==2){
        fee = 5;
        child++;
    }else if(ticketCode==3){
        fee = 20;
        teen++;
    }else if(ticketCode==4){
        fee = 20;
        adult++;
    }

    ticketSales = ticketSales + fee;
   }while(ticketCode>0);

    cout << "Total number of people attended is: " << i << endl;
    cout << "The total ticket sales is: " << ticketSales << endl;

    cout << "The number of infants is: " << infant << endl;
    cout << "The number of child is: " << child << endl;
    cout << "The number of teenagers is: " << teen << endl;
    cout << "The number of adults is: " << adult << endl;


    return 0;
}
