/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // swap the values
        // and make last node -> NULL;

        while (node != NULL)
        {

            swap(node->val, node->next->val);

            if (node->next->next == NULL)
            {
                node->next = NULL;
            }
            node = node->next;
        }
    }
};