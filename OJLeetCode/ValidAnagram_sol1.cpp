class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s.compare(t)==0);
    }
};



/*
Submission Details
32 / 32 test cases passed.
Status: Accepted
Runtime: 76 ms
Submitted: 0 minutes ago
Your runtime beats 20.28% of cpp submissions.
*/