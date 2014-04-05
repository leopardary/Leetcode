/*
Sort a linked list in O(n log n) time using constant space complexity.
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
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x){
		val=x;
		next=NULL;
	}
};
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode *p1=head, *p2=head->next;
        while(p2!=NULL && p2->next!=NULL){
            p1=p1->next;
            p2=p2->next->next;
        }
        ListNode *l=p1->next;
        p1->next=NULL;
        ListNode *lSorted=sortList(l);
        return mergeSort(sortList(head),lSorted);
    }
    ListNode *mergeSort(ListNode *p1, ListNode *p2){
        ListNode p3(0);
        ListNode *p4=&p3;
        while(p1!=NULL && p2!=NULL){
            if (p1->val < p2->val) {
                p4->next=p1;
                p1=p1->next;
                p4=p4->next;
            }
            else {
                p4->next=p2;
                p2=p2->next;
                p4=p4->next;
            }
        }
        if (p1==NULL) p4->next=p2;
        else p4->next=p1;
        return p3.next;
    }
};