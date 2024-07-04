#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int idx = 0;
        while (idx < str1.size() && idx < str2.size()) {
            if(str1[idx] != str2[idx]){break;}
            ans += str1[idx];
            idx++;
        }
        while (ans.size() > 0) {
            cout<<"ans : "<<ans<<endl;
            int size = ans.size();
            bool ans1 = true, ans2 = true;
            if (str1.size() % size != 0 || str2.size() % size != 0) { ans.pop_back(); }
            for (int i = 0;i < str1.size();i++) {
                if (ans[i % size] != str1[i]) { ans1 = false; break; }
            }
            for (int i = 0;i < str1.size();i++) {
                if (ans[i % size] != str1[i]) { ans2 = false; break; }
            }
            if(ans1 && ans2) {return ans;}
            else {ans.pop_back();}
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string str1 = "ABCABC";
    string str2 = "ABC";
    string ans = sol.gcdOfStrings(str1, str2);
    cout << "ans : " << ans;
}