/*

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

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
    ListNode *a=(ListNode *)malloc(sizeof(ListNode));
    a->val=4;
    a->next=NULL;
    return a;
}
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head=newnode();
    ListNode *curr=head;
    while(A || B){
        //int min=INT_MAX;
        if(A && B){
            if(A->val<=B->val){
                curr->next=A;
                A=A->next;
                curr=curr->next;
            }
            else{
                curr->next=B;
                B=B->next;
                curr=curr->next;
            }
        }
        else if(A){
            curr->next=A;
            A=A->next;
            curr=curr->next;
        }
        else{
            curr->next=B;
            B=B->next;
            curr=curr->next;
        }
    }
    return head->next;
}
