#include <iostream>
using namespace std;

int main()
{
    int i, j;
    const int n = 10;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << "\t" << i * j;
        cout << endl;
    }
    return 0;
}