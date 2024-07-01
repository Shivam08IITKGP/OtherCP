/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* swapPairs(listnode* A) 
{
    if((A==NULL)||(A->next==NULL))
    {
        return A;
    }
    listnode* root = listnode_new(0);
    root->next = A;
    listnode* prev = root;
    listnode* curr = A;
    
    while((curr!=NULL) && (curr->next!=NULL))
    {
        listnode* first = curr;
        listnode* second = curr->next;
        
        first->next = second->next;
        prev->next = second;
        second->next = curr;
        
        prev = first;
        curr= first->next;
        
    }
    
    listnode* newhead= root->next;
    free(root);
    return newhead;
    
}
