class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> g;
        for(int i = 0;i < edges.size();i++)
        {
            int src = edges[i][0];
            int des = edges[i][1];
            g[src].push_back(des);
            g[des].push_back(src);
        }

        unordered_set<int> visited;
        return dfs(source, destination, g, visited);
    }

    bool dfs(int source, int destination, unordered_map<int,vector<int>>& g, unordered_set<int>& visited)
    {
        if(source == destination) return true;

        visited.insert(source);
        for(int neighbor : g[source])
        {
            if(visited.find(neighbor) == visited.end()){
                if(dfs(neighbor, destination, g, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
