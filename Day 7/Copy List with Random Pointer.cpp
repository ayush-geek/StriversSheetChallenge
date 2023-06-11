/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    map<Node *, int> mp;
    map<int, Node *> mp2;
    Node *copyRandomList(Node *head)
    {
        Node *tmp = head;
        Node *dummy = new Node(0);
        Node *d = dummy;
        int k = 0;
        while (head != NULL)
        {
            mp[head] = k;
            d->next = new Node(head->val);
            mp2[k] = d->next;
            d = d->next;
            k++;

            head = head->next;
        }

        head = tmp;
        d = dummy->next;
        while (head != NULL)
        {
            if (head->random != NULL)
            {
                int ind = mp[head->random];
                d->random = mp2[ind];
            }

            head = head->next;
            d = d->next;
        }

        return dummy->next;
    }
};