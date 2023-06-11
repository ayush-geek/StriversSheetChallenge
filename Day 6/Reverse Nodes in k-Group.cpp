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
    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *tm = head;

        while (head != NULL && k)
        {
            head = head->next;
            k--;
        }
        ListNode *nn = head;
        if (k != 0)
            return tm;

        ListNode *prev = NULL;
        head = tm;

        while (head != nn)
        {
            ListNode *tp = head->next;
            head->next = prev;
            prev = head;
            head = tp;
        }

        tm->next = nn;

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {

        // iterativw
        ListNode *prev = NULL;
        ListNode *nh = head;
        while (head != NULL)
        {
            ListNode *cur = head;
            if (prev == NULL)
            {
                nh = reverse(head, k);
                prev = cur;
            }
            else
            {
                prev->next = reverse(head, k);

                if (prev->next == cur)
                    return nh;
                prev = cur;
            }
            head = cur->next;
        }

        return nh;
    }
};