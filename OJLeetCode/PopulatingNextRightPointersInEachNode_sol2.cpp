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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // for each node, 
        // we connect the rightmost nodes of left subtree to the leftmost nodes of right subtree
        // then pass recursions to its childrens
        if (!root) return;
        connectLeft2Right_Iter(root); // here we can do iteratively or recursively
        connect(root->left);
        connect(root->right);
    }
    void connectLeft2Right_Iter(TreeLinkNode *node)
    {
        // here node is not NULL
        // Populate each next pointer to point to its next right node. 
        // If there is no next right node, the next pointer should be set to NULL.
        // Initially, all next pointers are set to NULL.
        TreeLinkNode *left=node->left, *right=node->right;
        while(left && right) // need both exist
        {
            left->next = right;
            
            left = left->right; // the rightmost nodes of left subtree
            right = right->left; // the leftmost nodes of right subtree
        }
    }
    // L.B.T.C OK
};


/*
Submission Details
14 / 14 test cases passed.
Status: Accepted
Runtime: 24 ms
Submitted: 0 minutes ago
Your runtime beats 40.90% of cpp submissions.
*/