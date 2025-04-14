// Iterative
template <class T>
struct SegmentTreeItarative{
private:
    int n;
    vector<T> tree;
    
    void buildTree(){
        for (int i = n - 1; i > 0; i--)
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }

public:
    void set(int ind, T val){
        ind+=n;
        for (tree[ind] = val; ind > 1; ind >>= 1){
            tree[ind >> 1] = merge(tree[ind], tree[ind ^ 1]);
        }
    }
    void update(int ind, T val){
        ind+=n;
        for (tree[ind] += val; ind > 1; ind >>= 1){
            tree[ind >> 1] = merge(tree[ind], tree[ind ^ 1]);
        }
    }
    T query(int l, int r){ // closed interval [l,r]
        T ansl = identity;
        T ansr = identity;
        for (l+=n, r+=n+1; l<r; l>>=1, r>>=1)
        {
            if (l&1){
                ansl = merge(ansl, tree[l++]);
            }
            if (r&1){
                ansr = merge(tree[--r], ansr);
            }
        }
        return merge(ansl, ansr);
    }

    SegmentTreeItarative(const vector<T>& input) {
        n = input.size();
        tree.resize(n<<1);
        for(int i=0; i<n; i++)
            tree[i+n] = input[i];
        buildTree();
    }

    T merge(const T& a, const T& b) { return min(a, b); }
    T identity = INT_MAX;
};

/*
    vector<int> v(n); cin >> v;

    SegmentTreeItarative segTree(v);

    segTree.query(left-1, right-1);
    segTree.set(index-1, value);
    segTree.update(index-1, increasingValue);
*/