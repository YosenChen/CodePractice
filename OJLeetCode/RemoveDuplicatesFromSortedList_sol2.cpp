/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        //Algorithm development SOP
        //1. loop body (iterative, recursive)
        //2. boundary conditions (init, final) and assumption (for loop body) check
        //3. test (trivial, simple, corner)
        ListNode *temp, *curr;
        if (!head || !head->next) return head; //at least 2 nodes
        //init condition
        curr = head;
        temp = curr->next;
        
        while (temp)
        {
            //loop body
            //assumption:
            //a. temp is in front of curr
            //b. temp & curr exist in this round
            if (temp->val == curr->val)
            {
                temp = temp->next;
            }
            else
            {
                curr->next = temp;
                curr = temp;
                temp = temp->next;
            }
        }
        //reach tail
        curr->next = NULL; //make tail
        
        return head;
        
    }
};
//164 / 164 test cases passed.
//Runtime: 88 ms
//Status: Accepted