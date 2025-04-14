// Topological sort in DAG (using modified BFS)
// aka Kahn's algorithm
#define clear_graph(n) for(int i=0;i<=n;i++){g[i].clear();} nodes = set<int>();
const int N = 1e5+10;
vector<int> g[N];

set<int> nodes; // all distinct nodes

vector<int> topSort() {
    vector<int> path;

    // calculate initial indegree for all nodes
    vector<int> indegree(N, 0);
    for (auto& x : nodes) {
        for (auto& y : g[x]) {
            indegree[y]++;
        }
    }

    // gather all the nodes having 0 indegree
    queue<int> q;
    for (auto& x : nodes) {
        if (indegree[x] == 0) {
            q.push(x);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        path.push_back(v);

        // node in path 
        // so remove it fron indegree
        for (auto& x : g[v]) {
            indegree[x]--;
            if (indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    return path;
}

// print(path);