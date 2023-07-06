/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // bfs
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();

            for (int i = 0; i < sz; i++)
            {
                auto nd = q.front();
                q.pop();
                if (i != sz - 1)
                    nd->next = q.front();

                if (nd->left != NULL)
                    q.push(nd->left);
                if (nd->right != NULL)
                    q.push(nd->right);
            }
        }

        return root;
    }
};