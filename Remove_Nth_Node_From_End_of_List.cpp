/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head==NULL || (head->next)==NULL) return NULL;
        if (head->next->next==NULL) {
            if (n==1) {head->next=NULL; return head;}
            if (n==2) {head=head->next; return head;}
        }
        ListNode *p1=head;
        for(int i=0;i<=n;i++) {
            if(p1==NULL) {head=head->next; return head;}
            else
            p1=p1->next;
        }
        ListNode *p2=head;
        
        while(p1!=NULL){
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;
        return head;
    }
};