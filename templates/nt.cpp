using u64 = uint64_t;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 mod) {
    return (u128)a * b % mod;
}

u64 pow_mod(u64 a, u64 d, u64 mod) {
    u64 res = 1;
    while (d) {
        if (d & 1) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        d >>= 1;
    }
    return res;
}

bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1; int s = 0;
    while ((d & 1) == 0) d >>= 1, s++;
    for (u64 a : {2,325,9375,28178,450775,9780504,1795265022}) {
        if (a % n == 0) continue;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n-1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
