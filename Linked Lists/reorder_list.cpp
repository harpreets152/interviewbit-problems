/*

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

ListNode* Solution::reorderList(ListNode* A) {
    int n=length(A);
    ListNode *curr=A,*head=A,*temp=NULL;
    ListNode *prev=NULL,*newhead=NULL;
    if(n==0 || n==1) return A;
    int i;
    for(i=1;i<=n/2;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    if(n%2==0) newhead=reverse(curr);
    else{
        temp=curr;
        curr=curr->next;
        newhead=reverse(curr);
    }
    ListNode *head1=new ListNode(2);
    curr=head1;
    while(head && newhead){
        curr->next=head;
        curr=curr->next;
        head=head->next;
        curr->next=newhead;
        curr=curr->next;
        newhead=newhead->next;
    }
    if(temp!=NULL){
        curr->next=temp;
        curr=curr->next;
    }
    curr->next=NULL;
    return head1->next;
    /*while(head && newhead){
        if(head->val!=newhead->val) return 0;
        head=head->next;
        newhead=newhead->next;
    }
    return 1;*/
}
