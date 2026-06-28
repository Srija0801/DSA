class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> str1;

        for(char ch:s){
            str1[ch]++;
        }

        vector<pair<char,int>> vec1;
        for (auto it : str1) {
             vec1.push_back(it);
        }
        sort(vec1.begin(),vec1.end(),[](pair<char,int>&a ,pair<char,int>&b){
            return a.second>b.second;
        });

        string ans="";

        for(auto it:vec1){
            while(it.second--){
                ans+=it.first;
            }
        }
        return ans;    
    }
};