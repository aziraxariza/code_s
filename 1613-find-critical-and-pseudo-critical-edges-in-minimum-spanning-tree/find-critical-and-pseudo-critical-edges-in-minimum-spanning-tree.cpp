class Solution {
public:

    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);

            if (x == y)
                return false;

            if (rank[x] < rank[y])
                swap(x, y);

            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;

            return true;
        }
    };

    int kruskal(int n, vector<vector<int>>& edges, int skip, int force) {

        DSU dsu(n);

        int cost = 0;
        int count = 0;

        // Force this edge first
        if (force != -1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];

            dsu.unite(u, v);

            cost += w;
            count++;
        }

        // Normal Kruskal
        for (int i = 0; i < edges.size(); i++) {

            // Skip this edge
            if (i == skip)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu.unite(u, v)) {
                cost += w;
                count++;
            }
        }

        // MST possible nahi bana
        if (count != n - 1)
            return INT_MAX;

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {

        // Original index store karo
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Weight ke according sort
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        // Original MST cost
        int original = kruskal(n, edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo;

        for (int i = 0; i < edges.size(); i++) {

            // Edge i ko hatao
            int without = kruskal(n, edges, i, -1);

            if (without > original) {
                // Critical
                critical.push_back(edges[i][3]);
            }
            else {
                // Edge i ko force karo
                int with = kruskal(n, edges, -1, i);

                if (with == original) {
                    // Pseudo-critical
                    pseudo.push_back(edges[i][3]);
                }
            }
        }

        return {critical, pseudo};
    }
};