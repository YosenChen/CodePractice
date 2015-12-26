class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                // how many (i,j) pairs?
                // (n-1)+(n-2)+...+1 = (1+n-1)*(n-1)/2 = n*(n-1)/2 = C(n)(2)
                if (nums[i]+nums[j] == target)
                {
                    vector<int> v;
                    v.push_back(i+1);
                    v.push_back(j+1);
                    return v;
                    // where index1 must be less than index2. 
                    // both index1 and index2 are not zero-based.
                }
            }
        }
        vector<int> v;
        return v;
    }
};

/*
Submission Result: Time Limit Exceeded
Last executed input: 
[0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76, ...
16021
*/

