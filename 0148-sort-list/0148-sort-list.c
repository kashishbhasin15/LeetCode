/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //Bubble sort
// struct ListNode* sortList(struct ListNode* head) {

//     struct ListNode *temp;
//     struct ListNode *ptr=NULL;
     
//     int swap,swapped;

//     if(head==NULL)
//        return NULL;
    
//     else
//     {
//         do
//         {
//             temp=head;
//             swapped=0;
//             while(temp->next!=ptr)
//             {
//                 if(temp->val>temp->next->val)
//                 {
//                     swap=temp->val;
//                     temp->val=temp->next->val;
//                     temp->next->val=swap;
//                     swapped=1;
//                 }
//                 temp=temp->next;
//             }
//             ptr=temp;
//         }while(swapped);
//     }
//     return head;
// }





struct ListNode *findMid(struct ListNode *head)
{
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct ListNode *merge(struct ListNode *left,struct ListNode *right)
{
    if(left==NULL)
       return right;
    if(right==NULL)
       return left;

    struct ListNode *ans=(struct ListNode *)malloc (sizeof(struct ListNode));
    ans->next=NULL;
    struct ListNode *temp=ans;
    
    while(left!=NULL && right!=NULL)
    {
        if(left->val < right->val)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else
        {
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    struct ListNode *result=ans->next;
    free(ans);
    return result;
}

//Merge sort
struct ListNode* sortList(struct ListNode* head){

if(head==NULL||head->next==NULL)
{
   return head;
}
struct ListNode *mid=findMid(head);
struct ListNode *left=head;
struct ListNode *right=mid->next;
mid->next=NULL;

left=sortList(left);
right=sortList(right);

struct ListNode *result=merge(left,right);
return result;

}