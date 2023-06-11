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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;

        while (head != NULL)
        {
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {

        // find middle reverse
        // the right part and chk

        ListNode *s = head;
        ListNode *f = head;
        ListNode *prev = NULL;

        while (f != NULL && f->next != NULL)
        {
            f = f->next->next;
            // 1 2 3 4
            // sf s  f
            if (f == NULL)
                break;
            prev = s;
            s = s->next;
        }

        //    cout<<s->next->val;
        // prev->next=NULL;
        f = reverse(s->next);

        s = head;
        while (f != NULL)
        {
            cout << s->val << " " << f->val << endl;

            if (s->val != f->val)
                return false;
            f = f->next;
            s = s->next;
        }

        return true;
    }
};