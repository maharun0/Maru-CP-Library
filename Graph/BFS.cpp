// BFS
const int N = 2e5+25;
vector<int> g[N];
vector<bool> vis;

void clear_graph(int n) {
    for (auto& v : g) v.clear();
    vis.assign(n, false);
}

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto& child : g[v]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}