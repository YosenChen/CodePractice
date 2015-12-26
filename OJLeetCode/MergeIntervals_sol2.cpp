/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


int compareInt(const void* a, const void* b)
{
    return (*(Interval**)a)->start - (*(Interval**)b)->start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        Interval **pData = new Interval*[intervals.size()], **pTmp = pData;
        // add "new" & "delete" at the same time
        // since we have to merge intervals (modify start/end), so pData should contain elements, not just their pointers
        // --> not necessary! to save memory, I can modify input vector elements
        // since we have to record which Interval elements are still in use, we need a flag for each element
        // --> not necessary! I can use pointer == NULL to tell which is still in use
        
        for (int i=0; i<intervals.size(); i++)
        {
            // pTmp is a ptr running along the array, 
            // *pTmp (or pTmp[i]) means the element of the array, here element is of type Interval*
            *pTmp = &(intervals[i]);
            pTmp++;
        }
        
        // think of qsort(int* pData, size, sizeof(int), compare(int*, int*))
        qsort(pData, intervals.size(), sizeof(Interval*), compareInt); // BNSC
        Interval **p2, **p1;
        for (p1=pData; p1<pData+intervals.size(); /*no increment here*/)
        {
            for (p2=p1+1; p2<pData+intervals.size(); p2++)
            {
                if ((*p1)->end >= (*p2)->start) // overlapping
                {
                    (*p1)->end = max((*p2)->end, (*p1)->end); // consider the case [[1,4],[2,3]]
                    (*p2) = NULL;
                }
                else break;
            }
            p1 = p2;
        }
        
        // now merge done, construct output vector
        vector<Interval> res;
        Interval tmp;
        for (p1=pData; p1<pData+intervals.size(); p1++)
        {
            if (!(*p1)) continue;
            
            res.push_back(*(*p1));
        }
        
        delete [] pData; 
        
        return res;
        
        // L.B.T.C OK
        
    }
};


/*
Submission Details
168 / 168 test cases passed.
Status: Accepted
Runtime: 580 ms
Submitted: 0 minutes ago
Your runtime beats 79.11% of cpp submissions.
*/




