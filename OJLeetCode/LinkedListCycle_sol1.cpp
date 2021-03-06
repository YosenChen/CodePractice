#include <cstdlib>
#include <iostream>
#include <cstdio>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        if (!head->next) return false;
        //at least 2 nodes
        
        run1 = run2 = head;
        while (run1 && run2)
        {
            run1 = run1->next;
            if (run2->next) run2 = run2->next->next;
            else return false;
            
            if (run1 == run2) return true;
        }
        return false;
    }
    ListNode *run1, *run2;
};

int main(void)
{
	  ListNode a(1), b(2), c(3), d(4), e(5);
	  a.next = &b;
	  b.next = &c;
	  c.next = &d;
	  d.next = &e;
	  e.next = NULL;//&c;
	  Solution sln;
	  printf("has cycle: %d\n", sln.hasCycle(&a));
    getchar();
    return 0;
}
//Status: Accepted