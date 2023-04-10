#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    for (int i = -7; i <= 7; i++)
    {
        for (int j = 0; j < 7 - abs(i); j++)
            cout << "  ";
        for (int k = 65; k <= 65 + abs(i); k++)
            cout << char(k) << " ";
        for (int n = 65 + abs(i) - 1; n >= 65; n--)
            cout << char(n) << " ";

        cout
            << endl;
    }

    return 0;
}
return 0;
}
