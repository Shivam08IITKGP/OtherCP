/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    if(A==NULL)
    {
        return A;
    }
    struct ListNode* head = A;
    int curr= A->val;
    struct ListNode* iter = A;
    struct ListNode* iter2= head;
    while(iter->next)
    {
        iter = iter->next;
        if(iter->val != curr)
        {
            iter2->next = iter;
            curr = iter->val;
            iter2 = iter2->next;
        }
    }
    iter2->next = NULL;// Important step
  // Missed while solving this problem
    return head;
}
