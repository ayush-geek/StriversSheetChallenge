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

        ListNode *nhead = rev(head->next);
        head->next->next = head;
        head->next = NULL;

        return nhead;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *tmp = l1;
        int carry = 0;
        ListNode *prev = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            int num = (l1->val + l2->val + carry);
            carry = num / 10;
            l1->val = num % 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            int num = (l1->val + carry);
            carry = num / 10;
            l1->val = num % 10;
            prev = l1;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int num = (l2->val + carry);
            carry = num / 10;
            l2->val = num % 10;
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }

        if (carry == 1)
        {
            prev->next = new ListNode(1);
            prev = prev->next;
        }

        return tmp;
    }
};