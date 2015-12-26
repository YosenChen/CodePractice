class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        bool sign = (n>=0);
        n = abs(n);
        
        // try to think n in binary format
        while(n>0)
        {
            if (n%2) ret*=x; // only see LSB
            
            n>>=1;
            x*=x; // x, x^2, x^4, x^8, x^16, ..., so, for x^n, n = 2^?
        }
        
        return (sign) ? ret : 1/ret;
        // this includes x^0 = 1
        
        // complexity = O(logn)
        // since n = 2^?
        // the length of n in binary format
        
        // check L.B.T.C:
        // check n = 1, 0, -1, 5
        
    }
};

/*
Submission Details
299 / 299 test cases passed.
Status: Accepted
Runtime: 4 ms
Submitted: 0 minutes ago
Your runtime beats 8.13% of cpp submissions.
*/
