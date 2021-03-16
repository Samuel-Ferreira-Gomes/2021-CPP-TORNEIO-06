#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        if (!n)
            break;
        int v, maxi = -1, nummax = 1, prenummax = 1, premaxi=-1;
        for (int i = 1; i <= n; i++) {
            cin >> v;
            if (maxi < v) {
                premaxi = maxi;
                maxi = v;
                prenummax = nummax;
                nummax = i;

            }
            else if (premaxi < v) {
                premaxi = v;
                prenummax = i;
            }
        }
        cout << prenummax << "\n";
    }
    return 0;
}
