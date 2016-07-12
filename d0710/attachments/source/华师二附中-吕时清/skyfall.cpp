#include <cstdio>
#include <algorithm>
static const int UPPER_BND = 5000 * 5002;
static const int TOT_PRIMES = 1800000;
static const int THRESHOLD = 20;
static const int THR_PRIMES = 10;
static const int MORE_MAX = 4;

int primes[TOT_PRIMES], prime_ct = 0;
bool not_prime[UPPER_BND] = { false };
int factors[UPPER_BND];

struct pf_info {
    unsigned char p_ct[THR_PRIMES];
    int more[MORE_MAX];
    unsigned char more_ct;
} pf[UPPER_BND] = {{ 0 }};

int N;

inline void insert_factor1(pf_info &u, int p_idx)
{
    ++u.p_ct[p_idx];
}
inline void insert_factor2(pf_info &u, int p_idx)
{
    u.more[u.more_ct++] = p_idx;
}

void sieve()
{
    not_prime[0] = not_prime[1] = true;
    long long t;
    for (int i = 2; i < N; ++i) {
        if (!not_prime[i]) {
            primes[prime_ct] = i;
            if (prime_ct < THR_PRIMES) insert_factor1(pf[i], prime_ct);
            else insert_factor2(pf[i], prime_ct);
            ++prime_ct;
        }
        for (register int j = 0; j < THR_PRIMES && (t = i * primes[j]) < N; ++j) if (!not_prime[t]) {
            not_prime[t] = true;
            pf[t] = pf[i];
            insert_factor1(pf[t], j);
        }
        for (register int j = THR_PRIMES; j < prime_ct && (t = (long long)i * primes[j]) < N; ++j) if (!not_prime[t]) {
            not_prime[t] = true;
            pf[t] = pf[i];
            insert_factor2(pf[t], j);
        }
    }

    for (int x = 0; x < N; ++x) {
        int ans = 1, ct = 0;
        for (register int i = 0; i < THR_PRIMES; ++i) ans *= (pf[x].p_ct[i] + 1);
        //std::sort(pf[x].more, pf[x].more + pf[x].more_ct);
        for (register int i = 0; i < pf[x].more_ct - 1; ++i)
            for (register int j = i + 1; j < pf[x].more_ct; ++j)
                if (pf[x].more[i] > pf[x].more[j]) std::swap(pf[x].more[i], pf[x].more[j]);
        for (register int i = 0; i < pf[x].more_ct; ++i) {
            if (i == 0 || pf[x].more[i] != pf[x].more[i - 1]) {
                ans *= (ct + 1);
                ct = 1;
            } else {
                ++ct;
            }
        }
        factors[x] = ans * (ct + 1);
    }
}

int a, b, c;

int main()
{
    freopen("skyfall.in", "r", stdin);
    freopen("skyfall.out", "w", stdout);

    scanf("%d%d%d", &a, &b, &c);
    N = a * b * c + 2;
    sieve();
    unsigned long long ans = 0;
    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j)
            for (int k = 1; k <= c; ++k)
                ans += factors[i * j * k];
    printf("%llu\n", ans & ((1 << 30) - 1));

    fclose(stdin); fclose(stdout);
    return 0;
}

