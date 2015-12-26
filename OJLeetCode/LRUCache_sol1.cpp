#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>

#define EN_LOG 1

class LRUCache{
public:
    struct cData
    {
        int data, age;
        cData():age(0){}
        cData(int d):age(0),data(d){}
    };
    
    LRUCache(int capacity)
    : mCap(capacity)
    {
    }
    ~LRUCache()
    {
    }
    int get(int key) {
        std::map<int, cData>::iterator it;
        if (mMap.end() != (it=mMap.find(key)))
        {
            //found
            it->second.age = 0;
            for (std::map<int, cData>::iterator i=mMap.begin(); i!=mMap.end(); i++)
            {
                if (i!=it) i->second.age++;
            }
            return it->second.data;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        
        if (EN_LOG) printf("[%s] check1\n", __FUNCTION__);

        std::map<int, cData>::iterator it = mMap.find(key);
        if (it != mMap.end())
        {
            // if matched, update value
            it->second.data = value;
            return;
        }
        // not matched, create one

        if (EN_LOG) printf("[%s] check2\n", __FUNCTION__);
        
        if (mMap.size() < mCap) //still have space
        {
            cData d;
            d.data = value;
            mMap[key] = d;
            return;
        }
        // size = mCap, replace LRU element (the oldest)

        if (EN_LOG) printf("[%s] check3\n", __FUNCTION__);
        
        {
            // find oldest one, erase it, then add new one
            int maxAge = -1;
            std::map<int, cData>::iterator oldest;
            for (it=mMap.begin(); it!=mMap.end(); it++)
            {
                if (it->second.age > maxAge)
                {
                    if (EN_LOG) 
                        printf("[%s] (maxAge, age, it) = (%d, %d, %p)\n"
                            , __FUNCTION__
                            , maxAge
                            , it->second.age
                            , it);
                    maxAge = it->second.age;
                    oldest = it;
                }
            }
            mMap.erase(oldest);
            cData d;
            d.data = value;
            mMap[key] = d;
            return;
        }
        
    }
    
    int mCap;
    std::map<int, cData> mMap;
    
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
    
    return 0;
}



// OJ LeetCode result: Status: Time Limit Exceeded
// self test result: basic test ok

