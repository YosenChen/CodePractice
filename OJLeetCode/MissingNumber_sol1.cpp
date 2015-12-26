class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // use XOR operator, but it cannot detect 0, a^0 = a
        int sum=0;
        // n distinct numbers taken from 0, 1, 2, ..., n -> size = n
        for (int i=1; i<=nums.size(); i++)
        {
            sum^=i;
        }
        
        //now start cancel out all numbers in nums
        for (int i=0; i<nums.size(); i++)
        {
            sum^=nums[i];
        }
        
        return sum; 
        // test [0]->1 ok; [0, 1]->2 ok; [1]->0 ok; [2,1]->0 ok
    }
};


/*
Submission Details
121 / 121 test cases passed.
Status: Accepted
Runtime: 36 ms
Submitted: 0 minutes ago
Your runtime beats 23.51% of cpp submissions.
*/