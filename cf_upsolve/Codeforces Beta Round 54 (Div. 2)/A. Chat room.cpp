#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int l, a, b;
        cin >> l >> a >> b;
        int g = gcd(b, l);
        cout << l-1-((l-1-a)%g) << "\n";
    }
}