class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> M;
        map<int, int>::iterator it;
        vector<int> res;
        for (int i=0; i<nums.size(); i++) // O(NlogN)
        {
            M[nums[i]] = i; // std::map::operator[], Complexity: Logarithmic in size.
            // how about more than 1 index with the same value?
            // You may assume that each input would have exactly one solution.
        }
        for (int i=0; i<nums.size(); i++) // O(NlogN)
        {
            if ((it = M.find(target-nums[i])) != M.end()) // std::map::find, Complexity: Logarithmic in size.
            {
                if (it->second == i) continue; // index1 must be less than index2
                
                // here we can guarantee that i < (it->second), think about why
                res.push_back(i+1);
                res.push_back(it->second+1);
                return res;
            }
        }
        return res;
        
    }
};


/*
Submission Details
16 / 16 test cases passed.
Status: Accepted
Runtime: 36 ms
Submitted: 0 minutes ago
Your runtime beats 8.84% of cpp submissions.
*/