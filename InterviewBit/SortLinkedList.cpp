/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::sortList(ListNode* A) 
{
    if(A==NULL)
    {
        return A;
    }
    vector<int>vec;
    struct ListNode* curr= A;
    vec.push_back(A->val);
    while((curr->next))
    {
        curr = curr->next;
        vec.push_back(curr->val);
    }
    
    sort(begin(vec),end(vec));
    struct ListNode* head = new ListNode(vec[0]);
    
    struct ListNode *iter = head;
    for(int i=1;i<vec.size();i++)
    {
        struct ListNode* node = new ListNode(vec[i]);
        iter->next = node;
        iter = node;
    }
    return head;
    
}
