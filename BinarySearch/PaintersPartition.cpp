class Solution {
public:
    bool CalculateTime( vector<int>& C,int maxTime,int B,int A){
        long long sum=0;
        int count=1;
        for(int i=0;i<C.size();i++){
            sum+= 1LL * B*C[i];
            if(sum>maxTime){
                count++;
                sum=1LL * B*C[i];
            }
        }
        if(count<=A){
            return true;
        }else{
            return false;
        }

    }
    int paint(int A, int B, vector<int>& C) {
        int maxVal=*max_element(C.begin(),C.end());
        long long low=1LL * B*maxVal;
        int sum=0;
        for(int i=0;i<C.size();i++){
            sum+=C[i];
        }
        long long high= 1LL * B*sum;

        while(low<=high){
            int mid=(low+high)/2;
            bool isPossible=CalculateTime(C,mid,B,A);
            if(isPossible){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return (1LL*low)%10000003;
    }
};