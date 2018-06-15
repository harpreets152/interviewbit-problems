/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode *curr){
    int len=0;
    while(curr){
        len++;
        curr=curr->next;
    }
    return len;
}
ListNode* Solution::rotateRight(ListNode* A, int k) {
    ListNode *curr=A,*head=NULL;
    int n=length(A);
    k=k%n;
    if(k==0) return A;
    ListNode *prev=NULL;
    for(int i=1;i<=n-k;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;head=curr;
    for(int i=1;i<k;i++){
        curr=curr->next;
    }
    curr->next=A;
    return head;
}
