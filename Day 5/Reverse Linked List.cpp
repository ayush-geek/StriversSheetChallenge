/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *ans = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return ans;
    }

    ListNode *reverseList(ListNode *head)
    {

        // ListNode* prev=NULL;

        // while(head!=NULL)
        // {
        //     ListNode* tmp=head->next;
        //     head->next=prev;
        //     prev=head;
        //     head=tmp;
        // }
        return rev(head);
    }
};