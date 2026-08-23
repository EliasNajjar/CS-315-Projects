#include <iostream>
#include <vector>
using namespace std;

int outOfOrderPairs(vector<int>& nums, int start, int end) {
    if (end - start <= 0) {
        return 0;
    }

    int mid = (start + end) / 2;
    int result = outOfOrderPairs(nums, start, mid); // sort and count both sides
    result += outOfOrderPairs(nums, mid+1, end);

    vector<int> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (nums[i] < nums[j]) {
            temp[k++] = nums[i++];
        } else {
            result += (mid - i + 1); // out of order if right > left
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++]; // add remaining left
    }
    while (j <= end) {
        temp[k++] = nums[j++]; // add remaining right
    }
    for (int k = 0; k < temp.size(); ++k) {
        nums[start + k] = temp[k]; // replace original
    }
    
    return result;
}

int main() {
    cout << "Enter the number of teams: ";
    int num;
    cin >> num;

    srand(time(0)); // set random seed
    vector<int> teamNums(num);
    for (int i = 0; i < num; ++i) {
        teamNums[i] = i + 1;
    }

    cout << "Final competition rankings:";
    vector<int> ranks(num);
    for (int i = 0; i < num; ++i) {
        int index = rand() % teamNums.size();
        ranks[i] = teamNums[index]; // shuffle teams into ranks
        cout << " " << ranks[i];
        teamNums.erase(teamNums.begin() + index); // avoid duplicates
    }
    cout << endl;

    cout << "Number of out-of-order pairs: " << outOfOrderPairs(ranks, 0, num - 1) << endl;
}