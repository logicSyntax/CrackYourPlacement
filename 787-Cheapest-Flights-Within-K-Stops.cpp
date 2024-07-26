class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, list<pair<int,int>>> adjList;
        for(const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adjList[u].push_back({v, w});
        }

        vector<int> prices(n, 1e8);

        //<stop,<cost,node>>
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0, src}});

        while(!q.empty()) {
            int stop = q.front().first;
            int cost = q.front().second.first;
            int frontNode = q.front().second.second;
            q.pop();

            if(stop > k)
                continue;
            
            for(auto neighbour : adjList[frontNode]) {
                if(prices[neighbour.first] > cost + neighbour.second && stop<=k) {
                    prices[neighbour.first] = cost + neighbour.second;
                    q.push({stop+1, {prices[neighbour.first], neighbour.first}});
                }
            }
        }

        return prices[dst] == 1e8 ? -1 : prices[dst];
    }
};
