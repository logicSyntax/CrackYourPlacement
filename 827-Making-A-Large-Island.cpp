class DSU {
public:
    vector<int> size, parent;

    DSU(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;
        
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v)
            return;
        
        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
private:
    bool isValid(int row, int col, int n) {
        return row>=0 && row<n && col>=0 && col<n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 0)
                    continue;
                
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int i=0; i<4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = row*n + col;
                        int adjNodeNo = nrow*n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int ans = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(grid[row][col] == 1)
                    continue;
                
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for(int i=0; i<4; i++) {
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol, n)) {
                        if(grid[nrow][ncol] == 1) {
                            components.insert(ds.findUParent(nrow*n + ncol));
                        }
                    }    
                }

                int totalSize = 0;
                for(auto element : components) {
                    totalSize += ds.size[element];
                }

                ans = max(ans, totalSize+1);
            }
        }

        for(int nodeNo=0; nodeNo<n*n; nodeNo++) {
            ans = max(ans, ds.size[ds.findUParent(nodeNo)]);
        }

        return ans;
    }
};