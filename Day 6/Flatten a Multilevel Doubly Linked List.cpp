/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *nd = head;
        while (head != NULL)
        {
            Node *tmp = head->next;
            if (head->child != NULL)
            {
                Node *t2 = head->child;

                while (t2->next != NULL)
                {
                    t2 = t2->next;
                }
                t2->next = tmp;

                if (tmp != NULL)
                    tmp->prev = t2;
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
            }
            head = head->next;
            ;
        }
        return nd;
    }
};