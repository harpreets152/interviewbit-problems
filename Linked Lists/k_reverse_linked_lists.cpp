/*

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

 NOTE : The length of the list is divisible by K 
Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *reverse(ListNode *head,int k){
    ListNode *temp=NULL,*prev=NULL,*curr=head;
    int i;
    if(k<=1) return head;
    ListNode *temp2=NULL,*head1=head;
    for(i=1;i<=k;i++){
        temp=prev;
        prev=curr;
        curr=curr->next;
        prev->next=temp;
    }
    head1->next=curr;
    return prev;
}
ListNode* Solution::reverseList(ListNode* A, int k) {
    ListNode *head= new ListNode(2);
    ListNode *curr=NULL,*temp=NULL;
    head->next=A;
    curr=head;
    while(curr->next){
        curr->next=reverse(curr->next,k);
        if(curr==head) head->next=curr->next;
        for(int i=1;i<=k;i++) curr=curr->next;
    }
    return head->next;
}
