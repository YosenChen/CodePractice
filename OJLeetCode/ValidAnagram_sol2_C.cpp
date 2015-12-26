
int compare (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b ); //put the smaller front
}

class Solution {
public:
    inline int getLen(char* s)
    {
        int cnt = 1;
        while(*s != '\0')
        {
            cnt++;
            s++;
        }
        return cnt;
    }

    bool isAnagram(string s, string t)
    {
        int sLen=s.length(), tLen=t.length(); //length() doesn't include '\0', the terminating null character
        char* pS = new char[sLen+1]; //+1 for '\0'
        char* pT = new char[tLen+1];
        strcpy(pS, s.c_str());
        strcpy(pT, t.c_str());
        return isAnagramC(pS, pT, sLen, tLen);
    }
    bool isAnagramC(char* s, char* t, int sLen, int tLen) 
    {
        if (sLen!=tLen) return false;
        
        qsort(s, sLen/*sLen doesn't include \0*/, 1/*char*/, compare);
        qsort(t, tLen, 1, compare);
        return !strcmp(s, t);
    }
};



/*
Submission Details
32 / 32 test cases passed.
Status: Accepted
Runtime: 52 ms
Submitted: 0 minutes ago
Your runtime beats 42.14% of cpp submissions.
*/