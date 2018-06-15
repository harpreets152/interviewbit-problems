/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int n) {
    ListNode *head=A,*curr=A;
    int i=1;
    while(head && i<=n){
        i++;
        head=head->next;
    }
    if(!head) return curr->next;
    while(head->next!=NULL){
        curr=curr->next;
        head=head->next;
    }
    curr->next=curr->next->next;
    return A;
}
