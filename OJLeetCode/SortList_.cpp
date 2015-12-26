/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        mergesort(head, NULL);
    }
    void mergesort(ListNode* &st, ListNode* end) //include end
    {
        ListNode* mid1 = getMidPoint(st, end);
        ListNode* mid2 = mid1->next;
        mergesort(st, mid1);
        mergesort(mid2, end);
        merge2SortedList(st, , mid2);
    }
};

