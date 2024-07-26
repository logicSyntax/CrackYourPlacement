class DSU {
public:
    unordered_map<string, pair<string, double>> parent;
    unordered_map<string, int> rank;
    DSU(vector<vector<string>> &eq) {
        for(int i=0; i<eq.size(); i++) {
            parent[eq[i][0]] = {eq[i][0], 1.0};
            parent[eq[i][1]] = {eq[i][1], 1.0};
        }
    }

    pair<string, double> findUParent(string node) {
        if(parent[node].first == node)
            return parent[node];
        
        pair<string, double> p = findUParent(parent[node].first);
        parent[node].first = p.first;
        parent[node].second *= p.second;

        return parent[node];
    } 

    void unionByRank(string u, string v, double value) {
        pair<string, double> ulp_u = findUParent(u);
        pair<string, double> ulp_v = findUParent(v);

        if(ulp_u.first == ulp_v.first)
            return;
        
        if(rank[ulp_u.first] > rank[ulp_v.first]) {
            parent[ulp_v.first] = {ulp_u.first, ulp_u.second / (ulp_v.second* value)};
        } else if(rank[ulp_u.first] < rank[ulp_v.first]) {
            parent[ulp_u.first] = {ulp_v.first, (ulp_v.second *value) / ulp_u.second};
        } else {
            parent[ulp_u.first] = {ulp_v.first, (ulp_v.second * value) / ulp_u.second};
            rank[ulp_v.first]++;
        }
    }  
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n = eq.size();
        DSU ds(eq);

        for(int i=0; i<n; i++) {
            string u = eq[i][0];
            string v = eq[i][1];
            double w = values[i];
            ds.unionByRank(u, v, w);
        }

        vector<double> result;
        for(int i=0; i<queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];

            if(ds.parent.find(u) == ds.parent.end() || ds.parent.find(v) == ds.parent.end())
                result.push_back(-1);
            else {
                auto pu = ds.findUParent(u);
                auto pv = ds.findUParent(v);

                if(pu.first != pv.first)
                    result.push_back(-1);
                else 
                    result.push_back(pu.second/pv.second);
            }
        }

        return result;
    }
};