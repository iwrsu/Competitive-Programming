// returns pair (F(n), F(n+1)) modulo MOD
pair<int64,int64> fib_pair(int64 n) {
    if (n == 0) return {0, 1};
    auto p = fib_pair(n >> 1);
    int64 a = p.first;   // F(k)
    int64 b = p.second;  // F(k+1)

    // c = F(2k) = F(k) * (2*F(k+1) - F(k))
    int64 t = ( (2*b % MOD - a) + MOD ) % MOD;
    __int128 mul = (__int128)a * (__int128)t;
    int64 c = (int64)(mul % MOD);

    // d = F(2k+1) = F(k)^2 + F(k+1)^2
    mul = (__int128)a * a + (__int128)b * b;
    int64 d = (int64)(mul % MOD);

    if ((n & 1) == 0)
        return {c, d};
    else
        return {d, (c + d) % MOD};
}

