
int compare (const void * a, const void * b)
{
    return (*(char*)a) - (*(char*)b);
    // < 0: a -> b
    // = 0: a -> b or b -> a
    // > 0: b -> a
}

struct strEle
{
    string* pStr; // ptr to the string in vector
    int idx; // in the vector
    strEle():pStr(NULL), idx(-1){}
};

int compareStrEle (const void * a, const void * b)
{
    strEle & A = (*(strEle*)a);
    strEle & B = (*(strEle*)b);
    return A.pStr->compare(*B.pStr);
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        for (int i=0; i<len; i++)
        {
            string key = sort(strs[i]);
            map<string, vector<string>>::iterator it = M.find(key);
            if (it!=M.end())
            {
                M[key].push_back(strs[i]);
            }
            else //new
            {
                vector<string> v;
                v.push_back(strs[i]);
                M[key] = v;
            }
        }
        
        // convert map<string, vector<string>> to vector<vector<string>>
        // For the return value, each inner list's elements must follow the lexicographic order.
        vector<vector<string>> res;
        vector<string> tmp;
        for (map<string, vector<string>>::iterator it = M.begin(); it!=M.end(); it++)
        {
            tmp = it->second;
            tmp = sort(tmp);
            res.push_back(tmp);
            tmp.clear();
        }
        
        
        return res;
    }
    
    string sort(const string & in)
    {
        int len = in.length(); // \0 is not included
        char* s = new char[len+1];
        strcpy(s, in.c_str());
        qsort(s, len, 1, compare); // not need to sort '\0'
        string res(s);
        delete [] s;
        
        return res;
    }
    
    vector<string> sort(vector<string> & in) // how to sort a vector? qsort only support const-sized ele
    {
        vector<string> res;
        strEle* pSE = new strEle[in.size()];
        strEle* tmp = pSE;
        for (int i=0; i<in.size(); i++)
        {
            tmp->idx = i;
            tmp->pStr = &in[i];
            tmp++;
        }
        qsort(pSE, in.size(), sizeof(strEle), compareStrEle);
        
        for (int i=0; i<in.size(); i++)
        {
            //copy ele of in according to sorted idx
            res.push_back(in[pSE->idx]); // std::vector::operator[], Complexity: Constant.
            pSE++;
        }
        return res;
    }
    
    map<string, vector<string>> M;
};


/*
Submission Details
100 / 100 test cases passed.
Status: Accepted
Runtime: 104 ms
Submitted: 0 minutes ago
Your runtime beats 12.42% of cpp submissions.
*/

/*
complexity analysis: vector size N, max string length A, # of groups G, max group size K
construct map:
    for N sort string & map.find -> N(AlogA + logG)
        sort string: AlogA
        find: logG
construct result vector
    for G sort vector & clear vector -> G(A*KlogK + K)
        sort vector: KlogK
        compare string: A
        clear vector: K
        
REMEMBER to add new/delete together
REMEMBER to add alloc/free together

*/