#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head);

class Solution {
public:
    void reorderList(ListNode *head) {
        mHead = head;
        if (!head) return;
        int len = listLen(head);
        if (len == 1) return;

        printList(head);
        
        int isOdd = len%2;
        len = (len+1)/2;
        
        ListNode *temp2 = head;
        for (int i=0; i<len; i++) 
        {
            if (i==len-1)
            {
                ListNode * next = temp2->next;
                temp2->next = NULL; 
                //this is how we make the front list (only need to make the tail for it)
                temp2 = next;
                break;
            }
            temp2 = temp2->next;
        }
        
        ListNode *temp = head, *next = NULL, *next2 = NULL;
        backH = backT = NULL;
        for (int i = 0; i<len; i++) 
        //iteration operation design hint: 
        //1. complete the iteration body, 
        //2. then deal with init step, last step
        {
            if ((i == len-1) && (isOdd))
            {
                //insertFrontList(temp);
                break;
            }
            next = temp->next;
            next2 = temp2->next;
            insertBackList(temp2);
            printList(backH);
            temp = next;
            temp2 = next2;
        }
        printf("Front list: \n");
        printList(head);
        printf("Back list: \n");
        printList(backH);
        
        interleaveList();
        
    }
    int listLen(ListNode *head)
    {
       if (!head) return 0;
       ListNode *temp = head;
       int cnt = 0;
       while (temp)
       {
           cnt++;
           temp = temp->next;
       }
       return cnt;
       
    }
/*
    void insertFrontList(ListNode *node) //push_back
    {
        printf("[%s]\n", __FUNCTION__);
        if (!node) return;
        if (!frontH)
        {
            frontT = frontH = node;
            node->next = NULL;
            return;
        }
        frontT->next = node;
        node->next = NULL;
        frontT = node;
    }
*/
    void insertBackList(ListNode *node) //push_front
    {
        printf("[%s]\n", __FUNCTION__);
        if (!node) return;
        if (!backH)
        {
            backT = backH = node;
            node->next = NULL;
            return;
        }
        node->next = backH;
        backH = node;
    }
    void interleaveList()
    {
        printf("[%s]\n", __FUNCTION__);
        //since at least 2 nodes
        //1st iteration
        ListNode *temp1 = mHead, *temp2 = backH, *next1 = mHead->next, *next2 = backH->next;
          
        resT = temp1; //==the input head
        resT->next = temp2;
        resT = temp2;
          
        temp1 = next1;
        temp2 = next2;
          
        while (temp1) //iteration body
        {
            next1 = temp1->next;
            if (temp2) next2 = temp2->next;
            else //last step, isOdd
            {
                resT->next = temp1;
                temp1->next = NULL; //make tail
                return;
            }
            
            resT->next = temp1;
            resT->next->next = temp2;
            resT = temp2;
            
            temp1 = next1;
            temp2 = next2;
        }
        //deal with last step, isEven
        resT->next = NULL; //make tail
    }
    ListNode *frontH, *frontT, *backH, *backT, *resT, *mHead;
};

void printList(ListNode *head)
{
    //printf("[%s]", __FUNCTION__);
    //getchar();
    if (!head) 
    { 
        printf("[%s] reach the end\n", __FUNCTION__);
        return;
    }
    printf("[%s] node val = %d\n", __FUNCTION__, head->val);
    //getchar();
    printList(head->next);
}

int main(void)
{
    ListNode a(1), b(2), c(3), d(4), e(5), f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    //printf("test\n");
    //getchar();

    printList(&a);
    getchar();
    Solution sln;
    sln.reorderList(&a);
    printf("final result\n");
    printList(&a);
    getchar();
    return 0;
}
