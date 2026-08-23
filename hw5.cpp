#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prizes;
    int in;
    cout << "Enter the prize values (0 or negative to stop): " << endl;
    while (cin >> in && in > 0) { // stop when number is <= 0
        prizes.push_back(in); // add input numbers into list
    }

    int n = prizes.size();
    vector<bool> available(n, true); // track which buttons are available
    int total = 0;

    while (true) {
        int max_index = -1;
        for (int i = 0; i < n; i++) {
            if (available[i] && (max_index == -1 || prizes[i] > prizes[max_index])) {
                max_index = i; // find maximum available
            }
        }

        if (max_index == -1) {
            break; // no available buttons
        }

        total += prizes[max_index];
        available[max_index] = false; // current buttons and adjacent are unavailable
        if (max_index > 0) {
            available[max_index - 1] = false;
        }
        if (max_index + 1 < n) {
            available[max_index + 1] = false;
        }
    }
    
    cout << "Maximum prize is " << total << endl;
    
    return 0;
}