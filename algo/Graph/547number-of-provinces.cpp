class Solution {
private:
    void dfs(int city,
             const vector<vector<int>>& isConnected,
             vector<bool>& visited) {
        visited[city] = true;

        int n = isConnected.size();

        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (isConnected[city][nextCity] == 1 &&
                !visited[nextCity]) {
                dfs(nextCity, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);
        int provinceCount = 0;

        for (int city = 0; city < n; city++) {
            if (!visited[city]) {
                provinceCount++;
                dfs(city, isConnected, visited);
            }
        }

        return provinceCount;
    }
};