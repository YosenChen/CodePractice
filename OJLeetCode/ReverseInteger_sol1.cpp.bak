#include <cmath>

class Solution {
public:
    int reverse(int x) {
        int temp;
        while(x)
        {
            L.push_back(temp = x%10);
            x = (x-temp)/10;
        }
        int sum = 0;
        while(L.size())
        {
            sum += L.front()*pow(10, L.size()-1);
            L.pop_front();
        }
        return sum;
    }
    list<int> L;
};

//Status: Accepted