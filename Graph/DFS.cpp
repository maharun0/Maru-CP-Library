// DFS
const int N = 2e5+25;
vector<int> g[N];
vector<bool> vis;

void clear_graph(int n) {
    for (auto& v : g) v.clear();
    vis.assign(n, false);
}

int dfs(int vertex) {
    vis[vertex] = true;

    for (int child : g[vertex]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}