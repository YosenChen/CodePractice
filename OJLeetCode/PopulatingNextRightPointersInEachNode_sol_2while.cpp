/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
Note:
    You may only use constant extra space.
    You may assume that it is a perfect binary tree 
    (ie, all leaves are at the same level, and every parent has two children).
*/
/*
    reference: highest rated
    https://leetcode.com/discuss/7327/a-simple-accepted-solution
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // constant extra space -> iterative solution
        // 2-direction while-loops, 
        // outer loop iterates along depth (leftmost), inner loop iterates horizontally
        TreeLinkNode *node=root, *iter; // node goes downward (leftmost), iter goes right
        if (!node) return;
        while(node->left) // we operate on children layer
        {
            iter = node;
            while(iter) 
            // for each iteration, we connect 2 nexts, since it's an alternate sequence
            {
                iter->left->next = iter->right;
                if (iter->next) // assigned by its upper layer iteration
                {
                    iter->right->next = iter->next->left;
                }
                iter = iter->next; // iterate until reaching NULL
            }
            node = node->left; // downward
        }
    }
    // L.B.T.C. OK
};



/*
Submission Details
14 / 14 test cases passed.
Status: Accepted
Runtime: 24 ms
Submitted: 0 minutes ago
Your runtime beats 40.90% of cpp submissions.
*/




