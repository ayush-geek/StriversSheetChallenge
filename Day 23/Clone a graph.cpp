/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<int, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        Node *tmp = NULL;
        if (node != NULL)
        {
            tmp = new Node(node->val);
            mp[node->val] = tmp;
            for (auto &ele : node->neighbors)
            {
                Node *tt = NULL;
                if (mp.count(ele->val) == 0)
                    tt = cloneGraph(ele);
                else
                    tt = mp[ele->val];

                tmp->neighbors.push_back(tt);
            }
        }
        return tmp;
    }
};