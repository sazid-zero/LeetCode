class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &e : prerequisites) {
            int a = e[0], b = e[1];
            adj[b].push_back(a);
            indeg[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> order;
        order.reserve(numCourses);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                if (--indeg[v] == 0) q.push(v);
            }
        }

        if ((int)order.size() != numCourses) return {};
        return order;
    }
};