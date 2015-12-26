#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i=0; i<n; i++)
        {
            checkList(A[i]);
        }
        if (L.size() != 1) cout << "wrong size = " << L.size() << endl;
        return L.front();
    }
    void checkList(int ele)
    {
        list<int>::iterator it = L.begin();
        for (; it!=L.end(); it++)
        {
            if (*it == ele)
            {
                L.erase(it);
                return;
            }
        }
        if (it == L.end()) L.push_front(ele);
        
    }
    
    list<int> L;
    
};


//result:
//Submission Result: Time Limit Exceeded