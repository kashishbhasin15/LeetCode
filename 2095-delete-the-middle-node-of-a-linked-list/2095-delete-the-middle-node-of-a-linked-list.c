/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *temp=head;
    int k=0;
    while(temp!=NULL)
    {
        k++;
        temp=temp->next;
    }

    if (k == 1) 
    {
        free(head);
        return NULL;
    }

    struct ListNode *prev=NULL;
    struct ListNode *tempp=head;

    int i=0,num;
    
    num=(k/2);
    
    
    while(tempp!=NULL && i<num)
    {
        prev=tempp;
        tempp=tempp->next;
        i++;
    }
    if(prev==NULL)
    {
        head=head->next;
        free(tempp);
    }
    else
    {
        prev->next=tempp->next;
        free(tempp);
    }
    return head;
}