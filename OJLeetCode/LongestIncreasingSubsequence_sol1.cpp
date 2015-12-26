class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lenArr(nums.size(), 1); // initialize to be 1
        
        for (int i=1; i<nums.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[j]<nums[i])
                {
                    lenArr[i] = max(lenArr[i], lenArr[j]+1);
                }
            }
            // lenArr[i]++; <-- cannot put here, consider the case that inner for-loop never runs
        }
        
        int maxLen=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (lenArr[i]>maxLen)
            {
                maxLen = lenArr[i];
            }
        }
        return maxLen;
    }
};


/*
Submission Details
22 / 22 test cases passed.
Status: Accepted
Runtime: 116 ms
Submitted: 0 minutes ago
Your runtime beats 18.62% of cpp submissions.
*/