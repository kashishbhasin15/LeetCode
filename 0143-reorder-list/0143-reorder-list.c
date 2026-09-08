/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {

   if (head==NULL|| head->next==NULL)
   {
    return ;
   }
   struct ListNode *temp=head;
   struct ListNode *tempp=head;
   int k=0;
   while(temp!=NULL)
   {
    temp=temp->next;
    k++;
   } 
   int num=k/2;
   int i=1;
   
   while(i<=num)
   {
    tempp=tempp->next;
    i++;
   }
   //SPLITTING
   struct ListNode *secHead=tempp->next;
   tempp->next=NULL;
   // reversing half
   struct ListNode *prev=NULL;
   while(secHead!=NULL)
   {
    struct ListNode *nxt=secHead->next;
    secHead->next=prev;
    prev=secHead;
    secHead=nxt;
   }
   //merging
    struct ListNode *firstHead=head;
    secHead=prev;

    while(secHead!=NULL && firstHead!=NULL)
    {
        struct ListNode *nxt1=firstHead->next;
        struct ListNode *nxt2=secHead->next;

        firstHead->next=secHead;
        secHead->next=nxt1;

        firstHead=nxt1;
        secHead=nxt2;
    }
   
}