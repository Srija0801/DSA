class Solution {
public:
    void generateCombinations(vector<string>& ans,string& curr,unordered_map<char,string> mp,int index,string digits){
        if(index==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters=mp[digits[index]];
        for(auto ch:letters){
            curr.push_back(ch);
            generateCombinations(ans,curr,mp,index+1,digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string>ans;
        string curr;
        generateCombinations(ans,curr,mp,0,digits);
        return ans;
    }
};