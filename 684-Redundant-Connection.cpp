class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
            parent[i] = i; 
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int ans_u = 0;
        int ans_v = 0;

        DSU ds(n);

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if(ds.findUParent(u) == ds.findUParent(v)) {
                ans_u = u;
                ans_v = v;
            } else {
                ds.unionByRank(u, v);
            }
        }

        return {ans_u, ans_v};
    }
};