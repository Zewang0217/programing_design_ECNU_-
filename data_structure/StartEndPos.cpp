#include <iostream>
#include <vector>
using namespace std;

// ´ÓÓÒÍù×óËõ
int findFirst(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else {
            if (nums[mid] == target) res = mid;
            right = mid - 1;
        }
    }
    return res;
}

// ´Ó×óÍùÓÒËõ
int findLast(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, res = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > target)
            right = mid - 1;
        else {
            if (nums[mid] == target) res = mid;
            left = mid + 1;
        }
    }
    return res;
}
/*

int main() {
    int target, x;
    cin >> target;

    vector<int> nums;
    while (cin >> x && x != -1) {
        nums.push_back(x);
    }

    int start = findFirst(nums, target);
    int end = findLast(nums, target);

    cout << "[" << start << "," << end << "]" << endl;
    return 0;
}
*/