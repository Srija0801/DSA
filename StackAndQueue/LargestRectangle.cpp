class Solution {
public:
    vector<int>PreviousSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>prev(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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
    vector<int>nextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int>st;
        vector<int>next(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=PreviousSmaller(heights);
        vector<int>next=nextSmaller(heights);
        int n=heights.size();
        int maxArea=0;

        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            int area=heights[i]*width;
            maxArea=max(maxArea,area);
        }

        return maxArea;
    }
};