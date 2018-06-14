/*

Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* curr) {
    ListNode *prev=NULL,*temp=NULL;
    if(curr==NULL || curr->next==NULL) return curr;
    while(curr!=NULL){
        temp=prev;
        prev=curr;
        curr=curr->next;
        prev->next=temp;
    }
    return prev;
}
