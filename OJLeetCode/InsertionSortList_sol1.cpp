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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        sortedList = NULL;
        
        ListNode *ele = head; //1st iteration 
        ListNode *next;
        
        while (ele)
        {
            ListNode* next = ele->next;  //keep next
            insertionSort(ele);  //inset
            ele = next;  //for next iteration
        }
        return sortedList;
    }
    void insertionSort(ListNode *ele)
    {
        if (!sortedList) //trivial case
        {
            sortedList = ele;
            sortedList->next = NULL;
            return;
        }
        
        ListNode *temp = sortedList, *prev = NULL;
        //3 possibilities of insertion: new head, in the middle, new tail.
        while(ele->val > temp->val)
        {
            if (temp->next) //move forward
            {
                prev = temp;
                temp = temp->next;
            }
            else //reach the end
            {
                temp->next = ele;
                temp->next->next = NULL; //ele is the new tail
                return;
            }
        };
        // ele is not the new tail ==> ele could be new head or in the middle of sortedList
        ele->next = temp;
        if (prev) prev->next = ele; //this means ele inserted in the middle
        else //this means ele will be the new head
            sortedList = ele;
            
        return;
    }
    
    //member variables
    ListNode *sortedList;
    
};
//Status: Accepted