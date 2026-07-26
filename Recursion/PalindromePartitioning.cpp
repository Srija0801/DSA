class Solution {
public:
    bool isPalindrome(string s, int l, int r) {

        while (l < r) {

            if (s[l++] != s[r--])
                return false;
        }

        return true;
    }

    void solve(int index,
               string s,
               vector<string>& curr,
               vector<vector<string>>& ans) {

        if (index == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            if (isPalindrome(s, index, i)) {

                curr.push_back(s.substr(index, i - index + 1));

                solve(i + 1, s, curr, ans);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;

        solve(0, s, curr, ans);

        return ans;
    }
};