class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int int_right = min(C, G);
        int int_left = max(A, E);
        int int_top = min(D, H);
        int int_bottom = max(B, F);
        
        if ((int_left>=int_right) || (int_bottom>=int_top)) return (C-A)*(D-B)+(G-E)*(H-F);
        
        return (C-A)*(D-B)+(G-E)*(H-F)-(int_right-int_left)*(int_top-int_bottom);
    }
};


/*
Submission Details
3081 / 3081 test cases passed.
Status: Accepted
Runtime: 32 ms
Submitted: 0 minutes ago
Your runtime beats 51.20% of cpp submissions.
*/