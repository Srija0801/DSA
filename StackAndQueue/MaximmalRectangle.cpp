class Solution {
public:
    vector<int> PrevSmaller(vector<int>& width){
        int n=width.size();
        stack<int>st;
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && width[st.top()]>=width[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        return prev;
    }
     vector<int> nextSmaller(vector<int>& width){
        int n=width.size();
        stack<int>st;
        vector<int>next(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && width[st.top()]>width[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }else{
                next[i]=st.top();
            }
            st.push(i);
        }
        return next;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>height(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                  if(matrix[i][j]=='1')
                    height[j]++;
                  else
                    height[j]=0;
            }
             vector<int>next=nextSmaller(height);
        vector<int>prev=PrevSmaller(height);

        for(int i=0;i<m;i++){
            int width=next[i]-prev[i]-1;
            int area=height[i]*width;
            maxArea=max(area,maxArea);
        }

        }

        

        return maxArea;
    }
};