class Solution {
public:
    void solve(int i, int j,
               vector<vector<int>>& m,
               int n,
               string path,
               vector<string>& ans) {

        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        m[i][j] = 0;

        if (i + 1 < n && m[i + 1][j])
            solve(i + 1, j, m, n, path + 'D', ans);

        if (j - 1 >= 0 && m[i][j - 1])
            solve(i, j - 1, m, n, path + 'L', ans);

        if (j + 1 < n && m[i][j + 1])
            solve(i, j + 1, m, n, path + 'R', ans);

        if (i - 1 >= 0 && m[i - 1][j])
            solve(i - 1, j, m, n, path + 'U', ans);

        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>>& m) {

        vector<string> ans;
        int n = m.size();

        if (m[0][0] == 0)
            return ans;

        solve(0, 0, m, n, "", ans);

        return ans;
    }
};