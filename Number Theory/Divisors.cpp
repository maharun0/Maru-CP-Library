// Returns a vector of divisors of a number.

vector<int> divisors(int n) {
    vector<int> div;
    vector<int> buf;
    for (int i = 1; i * i <= n; ++i) {
       if (n % i == 0) {
           div.push_back(i);
           buf.push_back(n / i);
       }
    }
    int from = buf.front() == div.back();
    for (int i = buf.size() - 1; i >= from; --i) {
        div.push_back(buf[i]);
    }
    return div;
}