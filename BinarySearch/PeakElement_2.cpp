class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {

            if(m == 1){
                bool top = (i == 0 || mat[i][0] > mat[i-1][0]);
                bool bottom = (i == n-1 || mat[i][0] > mat[i+1][0]);

                if(top && bottom)
                    return {i, 0};

                continue;
            }

            int low = 1;
            int high = m - 2;

            if(mat[i][0] > mat[i][1]){
                bool top = (i == 0 || mat[i][0] > mat[i-1][0]);
                bool bottom = (i == n-1 || mat[i][0] > mat[i+1][0]);

                if(top && bottom)
                    return {i, 0};
            }

            if(mat[i][m-1] > mat[i][m-2]){
                bool top = (i == 0 || mat[i][m-1] > mat[i-1][m-1]);
                bool bottom = (i == n-1 || mat[i][m-1] > mat[i+1][m-1]);

                if(top && bottom)
                    return {i, m-1};
            }

            while(low <= high){

                int mid = (low + high) / 2;

                if(mat[i][mid] > mat[i][mid-1] &&
                   mat[i][mid] > mat[i][mid+1]){

                    bool top = (i == 0 || mat[i][mid] > mat[i-1][mid]);
                    bool bottom = (i == n-1 || mat[i][mid] > mat[i+1][mid]);

                    if(top && bottom){
                        return {i, mid};
                    }

                    break;
                }
                else if(mat[i][mid] > mat[i][mid+1]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }

        return {-1,-1};
    }
};