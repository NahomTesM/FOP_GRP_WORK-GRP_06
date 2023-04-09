#include<iostream>
using namespace std;
int main(){
	int i, j;
	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= i - 1; j++) {
			cout << "  ";
		}
		for (j = i; j <= 8; j++) {
			cout << (char)(65 + j - i) << " ";
		}
		for (j = 7 - i; j >= 0; j--) {
			cout << (char)(65 + j) << " ";
		}

		cout << endl;
	}

	for (i = 1; i <= 7; i++) {
		for (j = 1; j <= 7 - i; j++) {
			cout << "  ";
		}
		for (j = 0; j <= i; j++) {
			cout << (char)(65 + j) << " ";
		}
		for (j = i - 1; j >= 0; j--) {
			cout << (char)(65 + j) << " ";
		}

		cout << endl;

	}
   
return 0;
}