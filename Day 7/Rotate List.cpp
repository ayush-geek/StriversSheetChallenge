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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        // shifting n-k in front
        ListNode *tmp = head;
        int n = 0;
        ListNode *lst = NULL;
        while (tmp != NULL)
        {

            if (tmp->next == NULL)
                lst = tmp;

            tmp = tmp->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        tmp = head;

        ListNode *s = head;
        ListNode *f = head->next;
        while (k--)
            f = f->next;

        while (f != NULL)
        {
            f = f->next;

            s = s->next;
        }
        cout << s->val << endl;
        ListNode *tmp2 = s->next;
        s->next = NULL;
        lst->next = head;
        return tmp2;
    }
};