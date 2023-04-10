// a simple program that print letter pattern.
#include <iostream>
using namespace std;
int main()
{ 
    for(int i=1; i<=8; i++){
        for(int k=1; k<i; k++){
        cout<<"  ";
        }
        for(int j=8; j>=i; j--){
            cout<<" "<<char(65+8-j);
            }
            for(int j=i; j<=7; j++){
                
                cout<<" "<<char(72-j);
                }
    
        cout<<endl;
    }
    for( int i=1; i<=7; i++){
        
        for(int k=7; k>i; k--){
            cout<<"  ";
        }
            for(int j=1; j<=i; j++){
                cout<<" "<<char(64+j);
            }
                for(int j=i; j>=0; j--){
                    cout<<" "<<char(65+j);
                }
                    cout<<endl;
    }
    
   return 0;
}