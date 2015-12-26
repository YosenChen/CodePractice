#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

/* Function: FindMin
 * -----------------
 * find minimum of three numbers
 */
 int FindMin(int a, int b, int c) {
     int min = a;
     if (b < min) min = b;
     if (c < min) min = c;
     return min;
 }

/* Function: FindEditDistance
 * --------------------------
 * This function returns the edit distance between the two strings.
 * Inputs two strings, and the max limit for edit distance. 
 * When the limit is reduced down passed 0, return the current edit
 * distance immediately, since the exact edit distance is of no interest 
 * at that point. 
 * limit: Maximum number of edit distance before returning 
 *        (if more than limit, it will return edit distance over limit)
 */

int FindEditDistance(char *str1, char *str2, int limit)
{
    // Base Case 1: When either strings is at the null characters
    if (str1[0] == '\0' || str2[0] == '\0') {
        return strlen(str1) + strlen(str2);
    }
    // Base Case 2: Optimize recursive function but shortcircuiting
    if (limit < 0) {
        return 0;
    }

    // When first character has a match, return the edit distance from the shorten string
    if (str1[0] == str2[0]) {
        return FindEditDistance(str1 + 1, str2 + 1, limit);
    }
    // When first character has no match, find the smallest edit distance of
    // 3 cases: 1) replace 2) add 3) delete
    int d_rep = FindEditDistance((str1 + 1), (str2 + 1), limit - 1);
    int d_add = FindEditDistance(str1, (str2 + 1), limit - 1);
    int d_del = FindEditDistance((str1 + 1), str2, limit - 1);
    int min = FindMin(d_rep, d_add, d_del);
    return min+1;
}

inline int min(int a, int b, int c)
{
    int tmp;
    return ((tmp = (a<b) ? a : b) < c) ? tmp : c;
}

// limit: Maximum number of edit distance before returning 
// (if dist > limit, it will return edit distance over limit)
int findEditDistance_yosen(char* str1, char* str2, int limit)
{
    // http://www.cplusplus.com/reference/cstring/strlen/
    // The length of a C string is determined by the terminating null-character
    // (without including the terminating null character itself)
    // This should not be confused with the size of the array that holds the string.

    // Passing in char* as const char* is ok
    // ex: size_t strlen ( const char * str );

    if (limit<0) return 0;

    // iterates until encountering mismatches, then split into 3 different recursive cases
    while(str1[0]!='\0' && str2[0]!='\0')
    {
        if (str1[0] != str2[0])
        {
            int d_rep = findEditDistance_yosen(str1+1, str2+1, limit-1); // replace == both shift 1 char
            int d_add = findEditDistance_yosen(str1, str2+1, limit-1); // add 1 char in str1 == shift 1 char in str2
            int d_del = findEditDistance_yosen(str1+1, str2, limit-1); // remove 1 char in str1 == shift 1 char in str1
            return min(d_rep, d_add, d_del) + 1;
            // reduce limit and increment dist at the same time
            // when encountering diff, stop iterating and split into 3 recursive calls
        }

        str1++;
        str2++;
    }
    // here, at least 1 string reaches '\0'
    return strlen(str1) + strlen(str2); // at this recursion, we only have to count our distance
    // it includes 0 distance
}

// note the interface types: "egg" -> char key[20] -> char* str1
void test(char key[20], char misspelled[20], int limit)
{
    printf("(%s, %s): dist=%d, dist_yosen=%d\n", key, misspelled
        , FindEditDistance(key, misspelled, limit)
        , findEditDistance_yosen(key, misspelled, limit));
}


size_t main()
{
    test("egg", "eabgg", 10);
    test("egg", "eab", 10);
    test("eggab", "eab", 10);
    test("egg", "egg", 10);
    test("12345hhhaaa", "eggest", 10);
    test("xxx12345hhhaaa", "eggest", 10);

    
    getchar();

    return 0;
}


/*
self test result: basic OK
*/







