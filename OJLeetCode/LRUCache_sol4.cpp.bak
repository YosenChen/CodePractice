#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>

#define EN_LOG 1

// to make sol1 faster
// 1. don't use find (you cannot do anything in its internal loop...
// 2. don't use map, since the capacity is given in the constructor, 
//    allocating memory at ctor would be much faster than allocating on demand
// 3. the least recently used item: "used" means both set and get
// 4. in sol2, set() and get() both take exact mCap loops for execution, no jump conditions
//    this might be a bad idea, for the case mCap >> current size, waste too much time on empty entries.
//    in sol1, get() takes find + mMap.size() loops for execution (found)
//                      or mMap.size() loops for execution (not found)
//                      PS: if not found, find time = mMap.size() loops
//             set() takes find + const (found)
//                      or mMap.size() + new_op (not found, space are available)
//                      or mMap.size() + delete_op + new_op (not found, full, replace LRU element) 
// 5. in Yu's sol, http://yucoding.blogspot.com/2013/12/leetcode-question-lru-cache.html
//    he defined the double linked list, each node stores both the key and value.
//    list order indicates the 'age' of data
//             get() takes find + const(move_node_to_tail) (found) (faster than sol1 & sol2)
//                      or size (not found)
//             set() takes find + const(move_node_to_tail) (found)
//                      or size + new_op (not found, add new at tail)
//                      or size + delete_op + new_op (not found, remove LRU node, add new at tail)
// 6. in sol3, use std::list to indicate age information (speed up get())
//             we don't initialize all entries at the beginning, 
//             for this case, data scale is more important than memory allocation (just few ints...)
// 7. According to Yu's comment: 
//    map<> data structure in C++, it is implemented using binary search tree and the complexity is logN
//    reference: http://www.cplusplus.com/reference/map/map/find/
//               std::map::find, Complexity: Logarithmic in size.
//    so the correct complexity of sol1-3 become:
//    sol1: get(hit)            = log(mMap.size()) + mMap.size()
//          get(miss)           = log(mMap.size())
//          set(hit)            = log(mMap.size())
//          set(miss, not full) = log(mMap.size()) + new_op
//          set(miss, full)     = log(mMap.size()) + mMap.size() + delete_op + new_op

//    sol2: get(hit)            = MAX_SIZE
//          get(miss)           = MAX_SIZE
//          set(hit)            = MAX_SIZE
//          set(miss, not full) = MAX_SIZE
//          set(miss, full)     = MAX_SIZE

//    sol3: get(hit)            = mList.size() + delete_op + new_op
//          get(miss)           = mList.size()
//          set(hit)            = mList.size()
//          set(miss, not full) = mList.size() + new_op
//          set(miss, full)     = mList.size() + delete_op + new_op

//    sol4: AgeList(doubly-linked list) + map.find; 
//          PS: doubly-linked list can be accessed by map
//    sol4: get(hit)            = log(mMap.size()) + delete_op + new_op
//          get(miss)           = log(mMap.size())
//          set(hit)            = log(mMap.size())
//          set(miss, not full) = log(mMap.size()) + new_op
//          set(miss, full)     = log(mMap.size()) + delete_op + new_op


class LRUCache{
public:
    struct DataNode
    {
        DataNode *prev, *next;
        int data, key;
        DataNode(){}
        DataNode(int d, int k, DataNode* p, DataNode* n):data(d),key(k),prev(p),next(n){}
    };
    int mCap;
    int curSize;
    DataNode *head, *tail;
    std::map<int, DataNode*> mMap;
            
    LRUCache(int capacity)
        : mCap(capacity)
        , curSize(0)
        , head(NULL)
        , tail(NULL)
    {}
    ~LRUCache()
    {
        // delete list and map
        mMap.clear();
        // actually we can delete list by mMap iterator, but I just want to practice linked list
        DataNode *node = head, *tmp;
        while(node)
        {
            tmp = node->next;
            delete node;
            node = tmp;
        }
    }

    int get(int key) {
        std::map<int, DataNode*>::iterator it;
        
        if ((it=mMap.find(key)) != mMap.end())
        {
            if (it->second == tail) return tail->data; //no need to move, it includes the case head=tail
            if (it->second == head) //head != tail, at least 2 nodes
            {
                //move head to the end, modify 6 links
                DataNode *oldTail = tail;
                tail->next = head;
                tail = head;
                head = head->next;
                head->prev = NULL;
                tail->prev = oldTail;
                tail->next = NULL;
                return tail->data;
            }

            int data = it->second->data;
            //move this node to the end, modify 6 links
            DataNode *oldTail = tail;
            tail->next = it->second;
            tail = it->second;
            it->second->prev->next = it->second->next;
            it->second->next->prev = it->second->prev;
            it->second->next = NULL;
            it->second->prev = oldTail;
            
            return data;
        }
        // not found
        return -1;
    }
    
    void set(int key, int value) {
        if (EN_LOG) printf("[%s] check0\n", __FUNCTION__);
        std::map<int, DataNode*>::iterator it;
        if ((it=mMap.find(key)) != mMap.end())
        {
            if (it->second == tail)
            {
                tail->data = value;
                return; //no need to move, it includes the case head=tail
            }
            if (it->second == head) //head != tail, at least 2 nodes
            {
                //move head to the end, modify 6 links
                DataNode *oldTail = tail;
                tail->next = head;
                tail = head;
                head = head->next;
                head->prev = NULL;
                tail->prev = oldTail;
                tail->next = NULL;
                
                tail->data = value;
                return;
            }

            it->second->data = value;
            //move this node to the end, modify 6 links
            DataNode *oldTail = tail;
            tail->next = it->second;
            tail = it->second;
            it->second->prev->next = it->second->next;
            it->second->next->prev = it->second->prev;
            it->second->next = NULL;
            it->second->prev = oldTail;            
            return;
        }
        //not found
        
        if (EN_LOG) printf("[%s] check1\n", __FUNCTION__);
        
        //not full
        if (curSize<mCap)
        {
            // add one node at the end
            // 4 links to be modified
            DataNode* pDn = new DataNode(value, key, tail, NULL);
            tail = pDn;
            if (pDn->prev) pDn->prev->next = pDn;
            if (curSize==0) head = pDn; // T & C in L.B.T.C.
            
            mMap[key] = pDn;
            
            curSize++;
            return;
        }
        
        if (EN_LOG) printf("[%s] check2\n", __FUNCTION__);
            
        //full, curSize == mCap
        if (curSize > 1)
        {
            int head_key = head->key;
            // delete head, 2 links to be modified
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            // add one node at the end
            // 4 links to be modified
            DataNode* pDn = new DataNode(value, key, tail, NULL);
            tail = pDn;
            pDn->prev->next = pDn;
            
            bool found = ((it=mMap.find(head_key)) == (mMap.end()));
            if (EN_LOG) printf("[%s] check2.1 (%d)\n", __FUNCTION__, found);

            mMap.erase(it);
            mMap[key] = pDn;
        }
        else //single node, head = tail <-- found by C in L.B.T.C.
        {
            // don't delete, don't move, just update data
            head->key = key;
            head->data = value;
            
            if (EN_LOG) printf("[%s] check2.2\n", __FUNCTION__);
            mMap.erase(mMap.begin());
            mMap[key] = head;
        }

        if (EN_LOG) printf("[%s] check3\n", __FUNCTION__);
    }
    

    
};

int main(void)
{
    LRUCache cache(3);
    cache.set(1, 100);
    cache.set(2, 200);
    cache.set(3, 300);
    printf("set done\n");
    printf("get(1): %d\n", cache.get(1));
    printf("get(1): %d\n", cache.get(1));
    printf("get(2): %d\n", cache.get(2));
    cache.set(4, 400);
    printf("get(3): %d\n", cache.get(3));
    printf("get(4): %d\n", cache.get(4));
    system("pause");

    printf("OJ LeetCode test case:\n");
    LRUCache cache2(2);
    printf("set(2,1)\n");
    cache2.set(2,1);
    printf("set(1,1)\n");
    cache2.set(1,1);
    printf("set(2,3)\n");
    cache2.set(2,3);
    printf("set(4,1)\n");
    cache2.set(4,1);
    printf("get(1): %d\n", cache2.get(1));
    printf("get(2): %d\n", cache2.get(2));
    system("pause");
    
    return 0;
}



// OJ LeetCode result: Status: Accepted
//                     17 / 17 test cases passed.
//                     Runtime: 96 ms
//                     Your runtime beats 54.18% of cpp submissions.
// self test result: basic test ok

