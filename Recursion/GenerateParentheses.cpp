class Solution {
public:
    void generate(vector<string>& ans,string curr,int open,int close,int n){
        if(open== n && close==n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            generate(ans,curr,open+1,close,n);
            curr.pop_back();
        }

        if(open>close){
            curr.push_back(')');
            generate(ans,curr,open,close+1,n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string curr;
       generate(ans,curr,0,0,n); 
       return ans;
    }
};