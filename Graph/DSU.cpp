struct DSU {
    int cc, maxcc_size;
    vector<int> p, sz;
    
    DSU(int n) : p(n), sz(n, 1), cc(n), maxcc_size(1) { 
        for (int i = 0; i < n; i++) p[i] = i;
        cc = n; maxcc_size = 1;
    }
    int get(int u) { return (p[u] == u)? u : p[u] = get(p[u]); }
    bool isConnected(int u, int v) { return get(u) == get(v); }
    bool unite(int u, int v) {
        u = get(u); v = get(v);
        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v); // swap u to be bigger
        sz[u] += sz[v]; p[v] = u;
        
        cc--; maxcc_size = max(maxcc_size, sz[u]);
        return true;
    }
};
// DSU dsu(n); // 0 based u, v