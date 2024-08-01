#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){ 
                return mid;
            } else if(nums[mid] < nums[mid + 1]){
                cout << "mid : " << mid << ", nums[mid] : " << nums[mid] << endl;
                l = mid + 1;
            } else if(nums[mid - 1] > nums[mid]){
                cout << "mid : " << mid << ", nums[mid] : " << nums[mid] << endl;
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 1,2,3,1 };
    int ans = sol.findPeakElement(nums);

    cout << "ans : " << ans;
}