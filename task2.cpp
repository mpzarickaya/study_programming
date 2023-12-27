#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool pair_exists(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (i != j && abs(i - j) <= indexDiff && abs((long long)nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter nums: " << "\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int indexDiff, valueDiff;
    cout << "Enter indexDiff: ";
    cin >> indexDiff;

    cout << "Enter valueDiff: ";
    cin >> valueDiff;

    bool result = pair_exists(nums, indexDiff, valueDiff);

    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}