/*

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode *head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
ListNode *reverse(ListNode *head){
    ListNode *temp=NULL,*prev=NULL;
    while(head){
        temp=prev;
        prev=head;
        head=head->next;
        prev->next=temp;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    int n=length(A);
    ListNode *curr=A,*head=A;
    ListNode *prev=NULL,*newhead=NULL;
    if(n==0 || n==1) return 1;
    int i;
    for(i=1;i<=n/2;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    if(n%2==0) newhead=reverse(curr);
    else{
        curr=curr->next;
        newhead=reverse(curr);
    }
    while(head && newhead){
        if(head->val!=newhead->val) return 0;
        head=head->next;
        newhead=newhead->next;
    }
    return 1;
}
