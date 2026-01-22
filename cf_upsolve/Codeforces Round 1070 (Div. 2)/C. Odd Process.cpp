#include <bits/stdc++.h>
namespace staring
{
    using namespace std;
    using LL = long long;
    using ULL = unsigned long long;

    static constexpr auto& vzip = views::zip;
    static constexpr auto& vtake = views::take;
    static constexpr auto& vdrop = views::drop;
    static constexpr auto& viota = views::iota;
    static constexpr auto& vreve = views::reverse;
    static constexpr auto& vfilt = views::filter;
    static constexpr auto& vtran = views::transform;
    static constexpr auto& rsort = ranges::sort;
    static constexpr auto& rfill = ranges::fill;
    static constexpr auto& rreve = ranges::reverse;
    static constexpr auto& rmaxe = ranges::max_element;
    static constexpr auto& rmine = ranges::min_element;
    static constexpr auto& rlowb = ranges::lower_bound;
    static constexpr auto& ruppb = ranges::upper_bound;

    template <typename TYPE>
    int gmax(TYPE &x, const TYPE &y) {return x < y ? x = y, 1 : 0;}
    template <typename TYPE>
    int gmin(TYPE &x, const TYPE &y) {return y < x ? x = y, 1 : 0;}

    static constexpr int SIZE = 1 << 20;
    static char buffin[SIZE]{}, *pin1{}, *pin2{};
    static char buffout[SIZE]{}, *pout{buffout};
    static FILE *fin = stdin, *fout = stdout;

    #define GETC (pin1 == pin2 && (pin2 = (pin1 = buffin) + fread(buffin, 1, SIZE, fin), pin1 == pin2) ? EOF : *pin1++)
    #define PUTC (pout - buffout == SIZE && (fwrite(buffout, SIZE, 1, fout), pout = buffout), *pout++)

    void fileO(string file)
    {
        if (file.empty()) return;
        fin = fopen((file + ".in").c_str(), "r");
        fout = fopen((file + ".out").c_str(), "w");
    }
    int fileC()
    {
        fwrite(buffout, pout - buffout, 1, fout);
        return fclose(fin), fclose(fout), 0;
    }
    
    template <typename TYPE>
    void read(TYPE &x)
    {
        #define isdigit(c) (c >= 48 && c <= 57)
        static int signf{0}, chin{0};
        x = signf = 0, chin = GETC;
        while (!isdigit(chin)) signf |= chin == '-', chin = GETC;
        while (isdigit(chin)) x = (x << 3) + (x << 1) + (chin ^ 48), chin = GETC;
        if (signf) x = -x;
        #undef isdigit
    }
    template <>
    void read(string &s)
    {
        #define isspace(c) (c <= 31 || c == 127)
        static char chin{0}; s = "";
        while (isspace(chin)) chin = GETC;
        while (!isspace(chin)) s += chin, chin = GETC;
        #undef isspace
    }
    template <typename TYPE, typename... TYPEs>
    void read(TYPE &x, TYPEs &...xs)
    {
        read(x), read(xs...);
    }

    template <typename TYPE>
    void write(TYPE x, char ch = '\n')
    {
        static int stack[64]{}, top{0};
        if (x < 0) x = -x, PUTC = '-';
        do stack[top ++] = x % 10, x /= 10; while(x);
        while (top) PUTC = stack[--top] | 48;
        if (ch) PUTC = ch;
    }
    template <>
    void write(const char* s, char ch)
    {
        for (char c : span(s, strlen(s))) PUTC = c;
        if (ch) PUTC = ch;
    }
    template <>
    void write(string s, char ch)
    {
        for (char c : s) PUTC = c;
        if (ch) PUTC = ch;
    }
    template <typename TYPE, typename... TYPEs>
    void write(TYPE x, TYPEs ...xs)
    {
        write(x, ' '), write(xs...);
    }

    #undef GETC
    #undef PUTC

    void initialize();
    void mainSolve();

}using namespace staring;
int main()
{
    fileO("");
    int testId = 0, testCount = 1;
    read(testCount);
    // initialize();
    while (testCount --)
        mainSolve();
    return fileC();
}

void staring::mainSolve()
{
    int n; read(n);
    vector arr(2, vector (0, 0));
    for (int x; int i : viota(0, n))
        read(x), arr[x & 1].push_back(x);
    
    rsort(arr[0] | vreve), rsort(arr[1] | vreve);
    if (arr[1].empty())
    {
        for (int i : viota(0, n)) write(0, ' ');
        return write("");
    }
    if (arr[0].empty())
    {
        for (int i : viota(1, n + 1))
            write(i & 1 ? arr[1][0] : 0, ' ');
        return write("");
    }
    int i = 1; LL res = arr[1][0];
    write(res, ' ');
    while (i <= arr[0].size())
        res += arr[0][i - 1], write(res, ' '), ++i;
    for (int u = 1, j = arr[1].size() - 1; j; j --, u ^= 1)
        if (j > 1) write(u ? res - arr[0].back() : res, ' ');
        else write(u ? 0 : res, ' ');
    write("");
}
