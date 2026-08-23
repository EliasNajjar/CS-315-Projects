#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prizes;
    int in;
    cout << "Enter the prize values (0 or negative to stop):\n";
    while (cin >> in && in > 0) { // stop when number is <= 0
        prizes.push_back(in); // add input numbers into list
    }

    int n = prizes.size();
    if (n == 0) { // no buttons
        cout << "No buttons to pick\nMaximum prize is 0\n";
        return 0;
    }
    if (n == 1) { // one button, press it
        cout << "Picks are " << prizes[0] << "\nMaximum prize is " << prizes[0] << "\n";
        return 0;
    }

    int possible = prizes[n-1]; // track possible prize if skip current button
    int best; // track best prize if press current button
    vector<bool> picks(n, false); // track picks to display later
    if (prizes[n-1] > prizes[n-2]) { // pick greater of last 2, traverse backwards to display in correct order later
        best = prizes[n-1];
        picks[n-1] = true;
    } else {
        best = prizes[n-2];
        picks[n-2] = true;
    }

    for (int i = n - 3; i >= 0; i--) { // compare best prize if pick current button with possible prize if skip current button
        if (prizes[i] + possible > best) {
            int temp = best;
            best = prizes[i] + possible;
            possible = temp;
            picks[i] = true;
        }
        else {
            possible = best;
        }
    }

    cout << "Picks are ";
    for (int i = 0; i < n; i++) { // traverse picks to display picked buttons
        if (picks[i]) {
            cout << prizes[i] << " ";
            i++; // skip adjacent button that was overridden by better button
        }
    }

    cout << "\nMaximum prize is " << best << "\n";

    return 0;
}