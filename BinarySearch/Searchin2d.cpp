class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size();
        int n=matrix.size();
        int row=0;
        int col=m-1;

        while(col>=0 && row<n){
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]>target){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
};