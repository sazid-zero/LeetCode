class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);

        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            for (Node* nxt : cur->neighbors) {
                if (!mp.count(nxt)) {
                    mp[nxt] = new Node(nxt->val);
                    q.push(nxt);
                }
                mp[cur]->neighbors.push_back(mp[nxt]);
            }
        }

        return mp[node];
    }
};