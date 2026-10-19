class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count=0;

        for(int&num: nums){
            if(num<target)
            count++;

        }

        vector<int> result;
        for(int&num :nums){
            if(num==target){
                result.push_back(count);
                count++;
            }

        }

        return result;

        
    
        
    }
};