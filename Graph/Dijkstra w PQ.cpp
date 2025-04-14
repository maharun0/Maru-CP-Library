// Dijkstra [Starts]
// single source shortest path
// 0-based indexing
// doesn't work for neg edges
const ll INF = 1000000000000;
vector<vector<pair<int, ll>>> adj; // {to, weight}

void dijkstra(int s, vector<ll> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pli = pair<ll, int>; // {to, weight}
    priority_queue<pli, vector<pli>, greater<pli>> q; // min-heap
    q.push({0, s});

    while (!q.empty()) {
        int v = q.top().second; // current vertex
        ll d_v = q.top().first; // dis(source -> v) according to current q top
        q.pop();

        if (d_v != d[v]) // dis(source -> v) has been overwritten by another path
            continue;

        // check all edges from v
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            
            // dis(source -> v) + dis(v -> to) < existing dis(source -> to)
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

vector<int> restore_path(int source, int destination, vector<int> const& p) {
    vector<int> path;

    int v = destination;
    while (v != source) {
        path.push_back(v);
        v = p[v];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}

// int n, m; cin >> n >> m;
// adj.assign(n, vector<pair<int, ll>>());

// while (m--) {
//     int from, to; ll weight;
//     cin >> from >> to >> weight;
//     from--, to--;

//     // check directed or undirected
//     adj[from].push_back({to, weight});
//     adj[to].push_back({from, weight}); // add this line if undirected
// }

// vector<ll> dis;
// vector<int> p; // parent
// dijkstra(0, dis, p);

// if (dis[n-1] == INF) {
//     cout << -1 << endl;
//     return;
// }

// vector<int> path = restore_path(0, n-1, p);
// for (auto& x : path) {
//     cout << x + 1 << " ";
// }
// Dijkstra [Ends]