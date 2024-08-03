class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, list<int>> adjList;
        int CEO = -1;
        for(int i=0; i<n; i++) {
            int u = i;
            int v = manager[i];
            if(v == -1)
                CEO = i;
            adjList[v].push_back(u);
        }

        queue<pair<int,int>> q;
        q.push({CEO, 0});
        
        int ans = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            ans = max(ans, time);

            for(auto neighbour : adjList[node]) {
                q.push({neighbour, time + informTime[node]});
            }
        }

        return ans;
    }
};