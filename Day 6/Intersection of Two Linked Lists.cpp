class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *s1 = headA;
        ListNode *s2 = headB;

        // will two insersect
        // when they cover equal
        // ditsanc and meet

        while (s1 != NULL && s2 != NULL)
        {
            if (s1 == s2)
                return s1;

            s1 = s1->next;

            s2 = s2->next;

            if (s1 == s2)
                break;

            if (s2 == NULL)
                s2 = headA;
            if (s1 == NULL)
                s1 = headB;
        }

        if (s1 == s2)
            return s1;
        return NULL;
    }
};