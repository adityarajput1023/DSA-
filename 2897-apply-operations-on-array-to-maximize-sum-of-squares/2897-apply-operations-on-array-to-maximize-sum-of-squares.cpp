class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;
        vector<int> count(32,0);
        for(int &num :nums){
            for(int b=0;b<32;b++){
                if(num&(1<<b)){
                    count[b]++;

                }
            }
        }
        long long result=0;

        while(k--){
            long long c=0;
            for(int b =0;b<32;b++){
                if(count[b]>0){
                    count[b]--;

                    c=(c|(1<<b));

                }
            }
            result=(result+(c*c))%mod;
        }
        return result;
    }
};