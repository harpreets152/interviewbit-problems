/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *newnode(){
    ListNode *curr=(ListNode *)malloc(sizeof(ListNode));
    curr->next=NULL;
    curr->val=2;
    return curr;
    
}
ListNode *swapnodes(ListNode *a,ListNode *b){
    ListNode *temp=b->next;
    b->next=a;
    a->next=temp;
    return b;
}
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *curr=A,*front=A;
    if(curr==NULL || curr->next==NULL) return A;
    ListNode *head=newnode();
    ListNode *temp=NULL;
    head->next=A;
    curr=head;
    temp=curr->next;
    while(temp && temp->next){
        curr->next=swapnodes(curr->next,curr->next->next);  
        curr=curr->next->next;
        temp=curr->next;
    }
    
    return head->next;
}
