#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         vector<int> left(nums.size()); left[0] = nums[0];
//         vector<int> right(nums.size()); right[nums.size() - 1] = nums[nums.size() - 1];

//         for (int x : nums) { cout << x << " "; } cout << endl;

//         for (int i = 1;i < nums.size();i++) {
//             left[i] = left[i - 1] + nums[i];
//         }

//         for (int x : left) { cout << x << " "; } cout << endl;

//         for (int i = nums.size() - 2;i >= 0;i--) {
//             right[i] = right[i + 1] + nums[i];
//         }

//         for (int x : right) { cout << x << " "; } cout << endl;

//         if (0 == right[1]) return 0; //index == 0
//         for (int i = 1;i <= nums.size() - 2;i++) {
//             nums[i - 1] += nums[i - 2];
//             if (left[i - 1] == right[i + 1]) return i;
//         }
//         if (left[nums.size() - 2] == 0) return nums.size() - 1; //index === nums.size()
        
//         return -1;
//     }
// };


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int n = nums.size();
        vector<int> dp(n); dp[0] = nums[0];

        for (int i = 1;i < n;i++) {
            dp[i] = dp[i] + nums[i - 1];
        }

        for (int x : nums) { cout << x << " "; } cout << endl;
        for (int x : dp) { cout << x << " "; } cout << endl;

        if (0 == dp[n - 1] - dp[0]) return 0; //index == 0
        for (int i = 1;i <= n - 2;i++) {
            if (i != 1) nums[i - 1] += nums[i - 2];
            if (dp[i - 1] == (dp[n - 1] - dp[i])) return i;
        }
        if (dp[n - 2] == 0) return n - 1; //index == nums.size() - 1 (last index)

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { -1,-1,0,1,0,-1 };
    int ans = sol.pivotIndex(nums);

    cout << "ans : " << ans;
}