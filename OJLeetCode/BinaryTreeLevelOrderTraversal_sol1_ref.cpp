/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) { 
        //when you are done with your code, please make sure you try a 3-layer tree OK!
        if (!root) return res;
        
        TreeNode *tmp;
        mL.push_back(root);
        mL.push_back(NULL); //layer 1 end
        mLayer = 0;
        makeOutput(NULL); //create res[0]
        
        while(!mL.empty())
        {
            tmp = mL.front(); //front is ref of ele, i.e., address
            mL.pop_front();
            
            if(!tmp)
            {
                if(mL.empty()) break; //traversing done
                //reach the end of the layer
                mL.push_back(NULL);
                mLayer++;
                makeOutput(NULL); //create new vector<int>
                continue;
            }
            
            makeOutput(tmp);
            
            if(tmp->left) mL.push_back(tmp->left);
            if(tmp->right) mL.push_back(tmp->right);
        }
        return res;
    }
    
    void makeOutput(TreeNode* n)
    {
        if (!n)
        {
            vector<int> v;
            res.push_back(v); //for layer+1
        }
        else res[mLayer].push_back(n->val);
    }
    
    list<TreeNode*> mL;
    vector<vector<int>> res;
    int mLayer;
};



/*
Submission Details
34 / 34 test cases passed.
Status: Accepted
Runtime: 8 ms
Submitted: 0 minutes ago
Your runtime beats 7.00% of cpp submissions.
*/