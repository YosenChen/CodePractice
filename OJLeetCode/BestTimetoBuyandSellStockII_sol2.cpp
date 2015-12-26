class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // an important equivalence
        // the max profit is just the sum of all the increasing changes
        // you don't really need to handle the timing of buying and selling
        
        int inc, sum=0;
        for (int i=0; i<(int)(prices.size())-1; i++)
        // don't do prices.size()-1 !!!!!!!!!!!!
        // disasters might happen!!
        // size() is size_t, an unsigned integral type
        // operations on unsigned & signed will convert to unsigned 
        // (since unsigned can accommondate larger (positive) numbers) 
        // (see the language specification, 6.3.1.8). 
        // In your case the "common" type is unsigned int. 
        // This means that int operand will get converted to unsigned int before the comparison, 
        // as well as for the purpose of performing subtraction.
        {
            inc = prices[i+1] - prices[i];
            if (inc>0) sum+=inc;
        }
        return sum;
        // L, B, T, C
        // prices.size() == 1 is also covered, sum=0
    }
    
};


/*
Submission Details
198 / 198 test cases passed.
Status: Accepted
Runtime: 8 ms
Submitted: 0 minutes ago
Your runtime beats 22.85% of cpp submissions.
*/
