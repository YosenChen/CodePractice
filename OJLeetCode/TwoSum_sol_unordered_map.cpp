class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // first, construct the hash table
        unordered_map<int, int> HT; // in C++ 11
        unordered_map<int, int>::iterator it;
        for (int i=0; i<nums.size(); i++)
        {
            HT[nums[i]] = i; // key = nums[i], val = i
            // std::unordered_map::operator[],
            // Complexity: Average case: constant. Worst case: linear in container size.
            
            // note that it might overwrite the entries, 
            // ex: nums[5] = nums[9] = 100, then finally HT[100] maps to 9
        }
        
        for (int i=0; i<nums.size(); i++)
        {
            // use nums[i] to find its complementary part
            if ((it = HT.find(target-nums[i])) != HT.end())
                // std::unordered_map::find 
                // Complexity: Average case: constant. Worst case: linear in container size.
            {
                // found
                if (it->second == i) continue; // cannot be i itself
                
                // here we can guarantee i < it->second
                // for the case nums[i] != nums[it->second], it's ok, 
                // since we will encounter the smaller index first, then use it to find the larger index
                // for the case nums[i] == nums[it->second], say is equal to K (2K = target), it's still ok
                // since in HT, the entry HT[K] is overwritten by the larger index, 
                // so, i (must be the smaller index) will find a larger index as it->second
                
                vector<int> res;
                res.push_back(i+1);
                res.push_back(it->second+1);
                return res;
            }
        }
        
        // impossible, since: You may assume that each input would have exactly one solution.
        vector<int> res;
        return res;
    }
};


/*
Submission Details
16 / 16 test cases passed.
Status: Accepted
Runtime: 16 ms
Submitted: 0 minutes ago

Your runtime beats 58.82% of cpp submissions.
*/
