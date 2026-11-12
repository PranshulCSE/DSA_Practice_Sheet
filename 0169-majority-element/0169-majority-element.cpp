class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate,count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count+=1;
                candidate=nums[i];
            }
            else
            {
                if(candidate==nums[i])
                    count++;
                 else
                   count--; 
            }
        
        }
        return candidate;
    }
};