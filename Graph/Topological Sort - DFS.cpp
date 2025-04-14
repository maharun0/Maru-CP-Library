// Topological sort in DAG (using DFS)
#define clear_graph(n) for(int i=0;i<=n;i++){g[i].clear(),vis[i]=false;} path.clear(); nodes = set<int>();
const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

deque<int> path; // path in assending order
set<int> nodes; // all distinct nodes

void dfs(int vertex){
    vis[vertex] = true;

    for (int child : g[vertex]){
        if(!vis[child]) {
            dfs(child);
        }
    }

    path.push_front(vertex);
}

void TopSort() {
    // run dfs from each node
    for (auto& i : nodes) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

// print(path);
