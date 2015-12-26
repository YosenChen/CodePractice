/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //observation:
        //1. only top-down connection process, due to TreeLinkNode structure
        //2. get base operation unit, then consider over all recursions
        //3. 2-layer recursion
        if (!root) return;
        if (!root->left || !root->right) return;
        connectLeft2Right(root->left, root->right);
        connect(root->left);
        connect(root->right);
    }
    void connectLeft2Right(TreeLinkNode *left, TreeLinkNode *right)
    {
        left->next = right;
        if (left->right && right->left) connectLeft2Right(left->right, right->left);
    }
};
//Status: Accepted
//14 / 14 test cases passed., Runtime: 104 ms