class Solution {
public:
    int subtractProductAndSum(int n) {
        int rem,sum=0,mul=1;
        while(n!=0){
            rem=n%10;
            n/=10;
            mul=rem*mul;
            sum+=rem;
        }
        return (mul-sum);
    }
};