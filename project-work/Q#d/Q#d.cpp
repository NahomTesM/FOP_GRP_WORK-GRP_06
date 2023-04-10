#include <iostream>
using std::cout;
int i, j, range=8;	//control the printed values



int main() {
	
	for (i = 1; i <= range; i++) {
		for (j = 1; j <= i - 1; j++) {
			cout << "  ";
		}
		for (j = i; j <= range; j++) {
			cout << (char)(65 + j - i) << " ";
		}
		for (j = range - 1 - i; j >= 0; j--) {
			cout << (char)(65 + j) << " ";
		}

		cout << "\n";
	}

	for (i = 1; i <= range - 1; i++) {
		for (j = 1; j <= range - 1 - i; j++) {
			cout << "  ";
		}
		for (j = 0; j <= i; j++) {
			cout << (char)(65 + j) << " ";
		}
		for (j = i - 1; j >= 0; j--) {
			cout << (char)(65 + j) << " ";
		}

		cout << "\n";

	}
   
return 0;
}
