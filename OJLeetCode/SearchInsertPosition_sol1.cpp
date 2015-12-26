class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i;
        for (i=0;i<n;i++)
        {
            if (A[i]<target) continue;
            if (A[i]>target) return i;
            //A[i]==target
            return i;
        }
        return n; //target > the whole list
    }
};

//Status: Accepted