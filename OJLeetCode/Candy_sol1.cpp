class Solution {
public:
    int candy(vector<int>& ratings) {
        
        vector<int> tmpV(ratings.size(), 0);
        
        // forward
        int curNum = 0;
        for (int i=0; i<ratings.size()-1; i++)
        {
            if (ratings[i]<ratings[i+1])
            {
                curNum++;
                tmpV[i+1] = curNum;
            }
            else // ratings[i]>=ratings[i+1]
            {
                curNum = 0; // reset
                // tmpV[i+1] = curNum; don't need to write!
            }
        }
        
        // backward
        curNum = 0;
        for (int i=ratings.size()-1; i>0; i--)
        {
            if (ratings[i-1]>ratings[i])
            {
                curNum++;
                tmpV[i-1] = max(curNum, tmpV[i-1]); // won't change curNum, just change tmpV
                // this is how we deal with the central peak problem
                // ex: 
                //    0 1 2 3 4 5 0 0 0
                //    0 0 0 0 0 3 2 1 0
                // -> 0 1 2 3 4 5 2 1 0
            }
            else // ratings[i-1] <= ratings[i]
            {
                curNum = 0;
                // tmpV[i-1] = max(curNum, tmpV[i-1]); don't need to write!
            }
        }
        
        // get sum
        int sum = ratings.size(); // offset for each entry is 1
        for (int i=0; i<ratings.size(); i++)
        {
            sum+=tmpV[i];
        }
        return sum;
    }
};

/*
Submission Details
28 / 28 test cases passed.
Status: Accepted
Runtime: 40 ms
Submitted: 0 minutes ago
Your runtime beats 29.51% of cpp submissions.
*/