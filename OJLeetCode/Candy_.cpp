class Solution {
public:
    int candy(vector<int> &ratings) {
        list<int> slopeSeq;
        vector<int>::iterator it1 = ratings.begin(), it2;
        if (it1 == ratings.end()) return 0;
        if (ratings.size()==1) return 1;
        
        for(;;it1++)
        {
            it2 = it1;
            it2++;
            if (it2 == ratings.end()) break;
            
            if (*it1 < *it2)
            {
                slopeSeq.push_back(1);
            }
            else if (*it1 > *it2)
            {
                slopeSeq.push_back(-1);
            }
            else slopeSeq.push_back(0);
        }
        
        //now let's get 1st, 2nd integral
        int itg1st = 0, itg1stMin, itg2nd = 0, cnt = 0, sumCandy = 0, reset = 1;
        for (list<int>::iterator it = slopeSeq.begin(); it != slopeSeq.end(); it++)
        {
            cnt++;
            
            if (reset)
            {
                itg1stMin = *it;
                reset = 0;
            }
            
            itg1st += *it;
            if (itg1st < itg1stMin) itg1stMin = itg1st;
            itg2nd += itg1st;
            
            if (*it != 0) continue;
            
            //one mountain is created. width = cnt, minimal = itg1stMin
            sumCandy += (itg2nd+(1-itg1stMin)*cnt);
            //reset for next round (mountain estimation)
            cnt = itg1st = itg2nd = 0;
            reset = 1;
        }
        //last mountain
        sumCandy += (itg2nd+(1-itg1stMin)*cnt);
        return sumCandy;
        
        
        
    }
};