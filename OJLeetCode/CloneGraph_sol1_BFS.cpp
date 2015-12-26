/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
using namespace std;

struct NodeInfo
{
    UndirectedGraphNode* cloneNode;
    bool visited;
    NodeInfo():cloneNode(NULL),visited(false){}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node; // node is NULL
        
        // recursive is not suggested, if the graph is vast or very deep, then stack overflow!
        // for map and other standard library ctnrs, new elements are created by new (in heap memory)?
        // here we use BFS as our basic framework, then extend with cloning and M
        
        // there are 3 cases
        // 1. label L is not in M,
        //    - clone a node with L, add into M
        //    - mark L as visited in M
        //    - finish its neighbors info with M 
        //      (if not found in M, clone them with their labels, add into M)
        //      (keep visited unchanged)
        //    - add all neighbors into queue if not visited yet
        //      (this must be after marking L as visited, otherwise it will queue L itself if self-cycle
        //       but it's still ok, since we will mark L as visited before ending this iteration)
        // 2. label L is in M already, but it's not visited
        //    - all identical to case 1 except for step1
        // 3. label L is in M already, and it's visited
        //    - continue
        // here we use visited flag of each cloneNode to check if we finish its neighbors info
        
        Q.clear();
        M.clear();
        
        UndirectedGraphNode* tmp;
        map<int, NodeInfo>::iterator it;
        
        UndirectedGraphNode* returnNode = NULL;
        
        Q.push_back(node);
        while(!Q.empty())
        {
            tmp = Q.front();
            Q.pop_front();
            
            it = M.find(tmp->label);
            if (it!=M.end() && it->second.visited) continue; // case 3
            
            UndirectedGraphNode* cloneTmp;
            if (it==M.end()) // case 1
            {    
                cloneTmp = new UndirectedGraphNode(tmp->label);
                NodeInfo info; 
                info.cloneNode = cloneTmp;
                info.visited = true;
                M[tmp->label] = info; // add in M
            }
            else // case 2 (not case 3 not case 1 -> must be case 2)
            {
                cloneTmp = it->second.cloneNode;
                it->second.visited = true;
            }
            
            if (!returnNode) returnNode = cloneTmp; // only for 1st iteration
            
            
            for (int i=0; i<tmp->neighbors.size(); i++)
            {
                if (tmp->neighbors[i] != tmp)
                {
                    if ((it = M.find(tmp->neighbors[i]->label)) != M.end())
                    {
                        cloneTmp->neighbors.push_back(it->second.cloneNode);
                        
                        if (!it->second.visited) Q.push_back(tmp->neighbors[i]);
                    }
                    else // not found (of course, not visited)
                    {
                        UndirectedGraphNode* clnNb = new UndirectedGraphNode(tmp->neighbors[i]->label);
                        NodeInfo info;
                        info.cloneNode = clnNb;
                        M[tmp->neighbors[i]->label] = info;
                        
                        cloneTmp->neighbors.push_back(clnNb);
                        
                        Q.push_back(tmp->neighbors[i]);
                    }
                }
                else // self cycle
                {
                    cloneTmp->neighbors.push_back(cloneTmp);
                }
            }
        }
        
        return returnNode;
    }
    
    list<UndirectedGraphNode*> Q; // queue, to perform BFS in the original graph
    map<int, NodeInfo> M; // to store info for labels (visited, cloned node pointer)
    // Nodes are labeled uniquely.
    // map is used to make sure no nodes will be duplicated
};

/*
Submission Details
12 / 12 test cases passed.
Status: Accepted
Runtime: 84 ms
Submitted: 0 minutes ago
Your runtime beats 19.05% of cpp submissions.
*/






