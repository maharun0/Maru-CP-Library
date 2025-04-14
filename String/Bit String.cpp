// bit string katcl
const int MAX = 2e5 + 10;
bitset<MAX> mask[26];
bitset<MAX> ans;
string text;

// Time Complexity: O(n)
void computeMask() {
    for (int i = 0; i < 26; ++i)mask[i].reset();
    for (int i = 0; i < text.size(); ++i) mask[text[i] - 'a'].set(i);
}

// Time Complexity: O(1)
void updateMask(int i, char c) {
    mask[text[i] - 'a'].reset(i); text[i] = c;
    mask[text[i] - 'a'].set(i);
}

// Time Complexity: O(m * n)
int match(string& pattern) {
    if (pattern.size() > text.size()) { return 0; }
    ans.set();
    for (int i = 0; i < pattern.size(); ++i) {
        int c = pattern[i] - 'a';
        ans &= (mask[c] >> i);
    }
    return ans.count();
}

// Time Complexity: O(m * n)
int matchRange(string& pattern, int l, int r) {
    if (r - l + 1 < pattern.size()) { return 0; }
    ans.set();
    for (int i = 0; i < pattern.size(); ++i)
        ans &= (mask[pattern[i] - 'a'] >> i);
    return (ans >> l).count() - (ans >> (r - pattern.size() + 2)).count();
}

// Time Complexity: O((m + k) * n)
vector<int> pos(string& pattern, int l, int r) {
    matchRange(pattern, l, r);
    vector<int> positions;
    for (int i = ans._Find_next(l - 1); i < r - pattern.size() + 2; i = ans._Find_next(i))
        positions.push_back(i);
    return positions;
}

// text = s;
// computeMask();