// 2 Heaps Technique
int K; // size of window
multiset<int> low, up;

void ins(int& val) {
    if (low.empty()) { low.insert(val); return; }

    int a = *low.rbegin();  // current median
    if (a < val) {
        up.insert(val);

        if (up.size() > K / 2) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    } else {
        low.insert(val);

        if (low.size() > (K + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
    }
}

void era(int& val) {  // erase from sets
    auto itr = up.find(val);
    if (itr != up.end()) up.erase(itr);
    else low.erase(low.find(val));

    if (low.empty() and !up.empty()) {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

int getMedian() {
    return *low.rbegin();
}

// K = k; // set window size
// insert first k elements
// low + up = sorted vector
// search whatever you need
// WARNING: first erase, then insert