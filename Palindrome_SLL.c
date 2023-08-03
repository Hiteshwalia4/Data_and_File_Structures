// https://leetcode.com/problems/palindrome-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    struct ListNode *slow=head, *fast=head,*temp=head;
    struct ListNode *curr=head,*prev=NULL,*nxt=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    while(curr!=slow){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    if(len%2!=0){
    while(prev!=NULL && curr->next!=NULL){
        if(prev->val!=curr->next->val)
            return false;
        prev=prev->next;    
        curr=curr->next;    
    }
    }
    else{
        while(prev!=NULL && curr!=NULL){
        if(prev->val!=curr->val)
            return false;
        prev=prev->next;    
        curr=curr->next;    
    }
    }
    return true; 
}
