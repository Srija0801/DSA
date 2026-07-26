class Solution {
public:
    bool checkisExist(vector<vector<char>>& board,
                      string& word,
                      int row,
                      int col,
                      int index) {

        // Boundary check
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size()) {
            return false;
        }

        // Character mismatch
        if(board[row][col] != word[index]) {
            return false;
        }

        // Entire word matched
        if(index == word.size() - 1) {
            return true;
        }

        // Store original character
        char temp = board[row][col];

        // Mark as visited
        board[row][col] = '#';

        bool found =
            checkisExist(board, word, row, col - 1, index + 1) ||
            checkisExist(board, word, row, col + 1, index + 1) ||
            checkisExist(board, word, row - 1, col, index + 1) ||
            checkisExist(board, word, row + 1, col, index + 1);

        // Restore original character (Backtracking)
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                if(checkisExist(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};