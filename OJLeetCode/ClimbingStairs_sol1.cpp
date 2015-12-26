#include <cmath>
#include <cstdlib>
#include <list>
#include <cstdio>

using namespace std;

class Solution {
public:
    struct Pair
    {
        int num;
        int occ;
        Pair(int n, int o)
            : num(n)
            , occ(o)
        {}
    };
    int climbStairs(int n) {
        if (!n) return 0;
        if (n==1) return 1;
        
        int sum = 0;
        int max_num_of_2 = n/2;
        int num_of_1;
        for (int num_of_2=0; num_of_2<=max_num_of_2; num_of_2++)
        {
            num_of_1 = n-2*num_of_2;
            int temp;
            sum += (temp = combination_of_1_and_2(num_of_1, num_of_2));
            printf("[%s] sum = %d, comb = %d, ones = %d, twos = %d\n", __FUNCTION__, sum, temp, num_of_1, num_of_2);
        }
        return sum;
        
    }
    int combination_of_1_and_2(int ones, int twos)
    {
        int max = (ones >= twos) ? ones : twos;
        int min = (ones < twos) ? ones : twos;
        
        //return factorial(ones+twos, max)/factorial(min); //overflow <-- we need a better way to implement it
        addNumerator(ones+twos, max);
        removeDenominator(min);
        return productOfList();
    }
#if 0
    long long int factorial(int k)
    {
        //iterative is better than recursive, for code optimization
        long long int ret = 1;
        for (int i=2; i<=k; i++)
            ret*=i;
        return ret;   
    }
    long long int factorial(int k, int max_div)
    {
        long long int ret = 1;
        for (int i=max_div+1; i<=k; i++)
            ret*=i;
        return ret;        
    }
#endif
    void addNumerator(int k, int max_div)
    {
        for (int i=max_div+1; i<=k; i++)
        {
            addNum(i);
        }
    }
    void removeDenominator(int k)
    {
        for (int i=2; i<=k; i++)
            remNum(i);
    }
    int productOfList()
    {
        printf("[%s] +\n", __FUNCTION__);
        int ret = 1;
        for (list<Pair>::iterator it=L.begin(); it!=L.end(); it++)
        {
            printf("(it->num, it->occ) = (%d, %d)\n", it->num, it->occ);
            for (int i=0; i<it->occ; i++)
            {
                ret*= (it->num);
            }
        }
        L.clear();
        printf("[%s] -\n", __FUNCTION__);
        return ret;
    }
    void addNum(int i)
    {
        if (i==1) return;
        
        bool bIsPrime = true;
        for (int j=2; j<=(int)sqrt((float)i); j++) //better way: only sweep with prime numbers
        {
            if (!(i%j))
            {
                //j is a factor of i
                bIsPrime = false;
                addEle(j);
                addNum(i/j);
                break;
            }
        }
        if (bIsPrime == true) //create new Pair for i
        {
            addEle(i);
        }
    }
    void remNum(int i)
    {
        if (i==1) return;
        
        bool bIsPrime = true;
        for (int j=2; j<=(int)sqrt((float)i); j++) //better way: only sweep with prime numbers
        {
            if (!(i%j))
            {
                //j is a factor of i
                bIsPrime = false;
                remEle(j);
                remNum(i/j);
                break;
            }
        }
        if (bIsPrime == true) //create new Pair for i
        {
            remEle(i);
        }
    }
    void addEle(int ele)
    {
                bool bNumInList = false;
                for (list<Pair>::iterator it=L.begin(); it!=L.end(); it++)
                {
                    if (it->num == ele)
                    {
                        it->occ++;
                        bNumInList = true;
                        break;
                    }
                    
                }
                if (bNumInList == false) //create new Pair for ele
                {
                    Pair p(ele, 1);
                    L.push_back(p);
                }       
    }
    void remEle(int ele)
    {
                bool bNumInList = false;
                for (list<Pair>::iterator it=L.begin(); it!=L.end(); it++)
                {
                    if (it->num == ele)
                    {
                        it->occ--;
                        bNumInList = true;
                        break;
                    }
                    
                }
                if (bNumInList == false)
                {
                    //impossible
                    return;
                }        
    }
    list<Pair> L;
};

int main(void)
{
    Solution sln;
    printf("sln.climbStairs(4) = %d\n", sln.climbStairs(4));
    printf("sln.climbStairs(5) = %d\n", sln.climbStairs(5));
    getchar();
    return 0;
}
//Utility test ok
//Status: Accepted
//45 / 45 test cases passed., Runtime: 4 ms