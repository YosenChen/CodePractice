#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        int prevState = 0; //1 for increase, 0 for no change and decline
        int rampIdxS, rampIdxE, sum = 0;
        for (int i=0; i<prices.size()-1; i++)
        {
            if (prices[i] < prices[i+1]) //rise
			{
                if (prevState != 1) //start
                {
                    rampIdxS = i;
                    prevState = 1;
                }
            } 
            else //not rise
            {
                if (prevState == 1) //end
                {
                    rampIdxE = i;
                    prevState = 0;
                    sum += (prices[rampIdxE]-prices[rampIdxS]);
                }
            }
			if (i == prices.size()-2) //last point
			{
				if (prevState == 1) //end
				{
                    rampIdxE = i+1;
                    prevState = 0;
                    sum += (prices[rampIdxE]-prices[rampIdxS]);
				}
			}
        }
        return sum;
    }
};

int main(void)
{
    vector<int> stock;
    stock.push_back(1);
    stock.push_back(2);
    stock.push_back(3);
    stock.push_back(1);
    stock.push_back(3);
    stock.push_back(2);
    stock.push_back(5);
    Solution sln;
    printf("max profit = %d\n", sln.maxProfit(stock));
    getchar();
    return 0;
}
//Status: Accepted

