// bitset
bitset<64> a, b(value), c("1011");

b.test(i); b[i]; // test i'th bit

// works on i'th bit or all
b.set(i); b.set(); 
b.reset(i); b.reset();
b.flip(i);b.flip();
b.count(); // counts set bits

b.to_string();
b.to_ulong();b.to_ullong();