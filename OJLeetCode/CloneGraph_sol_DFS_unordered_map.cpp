/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
using namespace std;

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node; // node is NULL
        
        M.clear();
        // here we use DFS (recursion) as our basic framework, then extend with cloning and M
        return dfs(node);
    }
    
    // input a node of the original graph
    // output a node of the cloned graph
    UndirectedGraphNode* dfs(UndirectedGraphNode* origNode)
    {
        UndirectedGraphNode* cloneNode;
        unordered_map<int, UndirectedGraphNode*>::iterator it = M.find(origNode->label);
        if (it!=M.end())
        {
            cloneNode = it->second;
        }
        else // not found
        {
            cloneNode = new UndirectedGraphNode(origNode->label);
            M[origNode->label] = cloneNode;
            for (int i=0; i<origNode->neighbors.size(); i++)
            {
                cloneNode->neighbors.push_back(dfs(origNode->neighbors[i]));
            }
        }
        
        return cloneNode;
    }
    
    unordered_map<int, UndirectedGraphNode*> M; // map from label to cloned node pointer
    // Nodes are labeled uniquely.
    // map is used to make sure no nodes will be duplicated
};


/*
Submission Details
12 / 12 test cases passed.
Status: Accepted
Runtime: 72 ms
Submitted: 0 minutes ago
Your runtime beats 96.44% of cpp submissions.
*/