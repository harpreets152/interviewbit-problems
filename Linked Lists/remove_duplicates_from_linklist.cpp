/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *curr=A,*temp=A;
    while(curr){
        temp=curr;
        while(temp && temp->val==curr->val) temp=temp->next;
        curr->next=temp;
        curr=curr->next;
    }
    return A;
}
