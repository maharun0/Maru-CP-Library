// kmp
// Time Complexity: O(n)
vector<int> compute_prefix_function(const string& s) {
    vector<int> prefix_function(s.size());
    for (int i = 1; i < s.size(); i++) {
        int g = prefix_function[i - 1];
        while (g && s[i] != s[g]) g = prefix_function[g - 1];
        prefix_function[i] = g + (s[i] == s[g]);
    }
    return prefix_function;
}

// Time Complexity: O(n + m)
vector<int> find_string_matches(const string& s, const string& pattern) {
    vector<int> prefix_function = compute_prefix_function(pattern + '\0' + s);
    vector<int> result;
    for (int i = prefix_function.size() - s.size(); i < prefix_function.size(); i++) {
        if (prefix_function[i] == pattern.size()) {
            result.push_back(i - 2 * pattern.size());
        }
    }
    return result;
}
// vector<int> matches = find_string_matches(text, pattern);