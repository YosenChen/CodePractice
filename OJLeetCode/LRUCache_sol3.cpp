#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <list>

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



class LRUCache{
public:
    struct cData
    {
        int data, key;
        cData(){}
        cData(int d, int k):data(d),key(k){}
    };
    
    LRUCache(int capacity)
    : mCap(capacity)
    {}
    ~LRUCache()
    {}

    int get(int key) {
        std::list<cData>::iterator it;
        cData tmp;
        {
            for (it=mList.begin(); it!=mList.end(); it++)
            {
                if (it->key == key)
                {
                    // move from current position to the tail
                    tmp.data = it->data;
                    tmp.key = it->key;
                    mList.erase(it);
                    mList.push_back(tmp); //youngest
                    return tmp.data;
                }
            }
            
        }
        // not found
        return -1;
    }
    
    void set(int key, int value) {
        std::list<cData>::iterator it;
        
        for (it=mList.begin(); it!=mList.end(); it++)
        {
            if (it->key == key)
            {
                // if found, update value and move to tail
                cData data(value, key);
                mList.erase(it);
                mList.push_back(data);
                return;
            }
        }
        if (EN_LOG) printf("[%s] check1\n", __FUNCTION__);
        //not found
        if (mList.size() < mCap)
        {
            // space is available, add one at tail
            cData data(value, key);
            mList.push_back(data); // youngest
            return;
        }
        
        //full, remove head, add one at tail
        mList.pop_front();
        cData data(value, key);
        mList.push_back(data); //youngest
                
        if (EN_LOG) printf("[%s] check2\n", __FUNCTION__);
            
    }
    
    int mCap;
    std::list<cData> mList;
    
};

int main(void)
{
    LRUCache cache(3);
    cache.set(1, 100);
    cache.set(2, 200);
    cache.set(3, 300);
    printf("get(1): %d\n", cache.get(1));
    printf("get(1): %d\n", cache.get(1));
    printf("get(2): %d\n", cache.get(2));
    cache.set(4, 400);
    printf("get(3): %d\n", cache.get(3));
    printf("get(4): %d\n", cache.get(4));
    system("pause");

    printf("OJ LeetCode test case:\n");
    LRUCache cache2(2);
    cache2.set(2,1);
    cache2.set(1,1);
    cache2.set(2,3);
    cache2.set(4,1);
    printf("get(1): %d\n", cache2.get(1));
    printf("get(2): %d\n", cache2.get(2));
    system("pause");
    
    return 0;
}



// OJ LeetCode result: Status: Time Limit Exceeded
// self test result: basic test ok

