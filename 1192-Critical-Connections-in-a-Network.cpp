class Solution {
private:
    void solve(int node, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adjList, vector<bool> &vis) {
        vis[node] = true;
        disc[node] = low[node] = timer++;

        for(auto neighbour : adjList[node]) {
            if(parent == neighbour)
                continue;
            
            if(!vis[neighbour]) {
                solve(neighbour, node, timer, disc, low, result, adjList, vis);
                low[node] = min(low[node], low[neighbour]);

                if(low[neighbour] > disc[node]) {
                    result.push_back({node, neighbour});
                }
            } else {
                low[node] = min(low[node], disc[neighbour]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result;
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                solve(i, -1, 0, disc, low, result, adjList, vis);
            }
        }

        return result;
    }
};