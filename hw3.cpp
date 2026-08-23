#include <iostream>
#include <cmath>

using namespace std;

const int n = 50; // number of buckets and numbers to generate
const int MAX = 1000; // rand % MAX will be 0 to MAX - 1

int main() {
    cout << "Enter the number of trials: ";
    int m;
    cin >> m;

    int bucketCounts[m][n] = {0}; // hold counts for each bucket for each trial
    srand(time(0));
    for (int i = 0; i < m; i++) { // generate numbers
        for (int j = 0; j < n; j++) {
            bucketCounts[i][rand() % MAX * n / MAX] += 1; // add count to bucket number * n / ((MAX - 1) + 1)
        }
    }

    cout << endl << "****** Mean of the count for each bucket across " << m << " trials:" << endl;
    double stdevs[n];
    for (int i = 0; i < n; i++) { // for mean and stdev of each bucket
        int total = 0; // total count in bucket accross all trials
        for (int j = 0; j < m; j++) {
            total += bucketCounts[j][i];
        }
        double mean = (double)total / m;
        cout << "Mean of the count for bucket " << i << ": " << mean << endl;

        total = 0; // total of squared differences
        for (int j = 0; j < m; j++) {
            int diff = bucketCounts[j][i] - mean;
            total += diff * diff;
        }
        stdevs[i] = sqrt((double)total / m); // record stdevs
    }

    cout << endl << "****** Standard deviation of the count for each bucket across " << m << " trials:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Standard deviation of the count for bucket " << i << ": " << stdevs[i] << endl;
    }

    return 0;
}