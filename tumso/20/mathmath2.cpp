#include <cassert>
#include <cstdio>
#include <numeric>
#include <vector>
#include <string>
#include "mathmath2.h"

static bool call_init = false;
static int queries_count = 0;

static std::vector<int> A;

int init()
{
  if(call_init){
    printf("-1\n");
    printf("Multiple call of init.\n");
    exit(0);
  }
  int N;
  if (scanf("%d", &N) != 1) {
    printf("-1\n");
    printf("Could not read input.\n");
    exit(0);
  }
  A.resize(N);
  for (int i = 0; i < N; i++) {
    if (scanf("%d", &A[i]) != 1) {
      printf("-1\n");
      printf("Could not read input.\n");
      exit(0);
    }
  }
  return N;
}

long long GCD(int i, int j)
{
  ++queries_count;
  return std::gcd(A[i], A[j]);
}

long long LCM(int i, int j, int k)
{
  ++queries_count;
  return std::lcm(std::lcm((long long)A[i], (long long)A[j]), (long long)A[k]);
}

void answer(std::vector<int> ans)
{
  if (ans.size() != A.size()) {
    printf("-1\n");
    printf("Invalid answer size.\n");
  }
  if (ans == A) {
    printf("1");
    printf("%d\n", queries_count);
  } else {
    printf("0");
  }
  exit(0);
}

#include <bits/stdc++.h>
#include "mathmath2.h"

using namespace std;

map <tuple <int, int, int>, long long> alcm, vislcm;
map <tuple <int, int>, long long> agcd, visgcd;

long long llcm(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    if (vislcm[{a, b, c}]) return alcm[{a, b, c}];
    vislcm[{a, b, c}] = 1;
    return alcm[{a, b, c}] = LCM(a, b, c);
}

long long ggcd(int a, int b) {
    if (a > b) swap(a, b);
    if (visgcd[{a, b}]) return agcd[{a, b}];
    visgcd[{a, b}] = 1;
    return agcd[{a, b}] = GCD(a, b);
}

long long GCD3(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    long long ab = ggcd(a, b);
    long long bc = ggcd(b, c);
    return __gcd(ab, bc);
}

int main() {
    int n = init();
    vector <int> ans(n);
    for (int i = 0; i < n; i += 4) {
        int a = i%n, b = (i+1)%n, c = (i+2)%n, d = (i+3)%n;
        long long abc = (llcm(a, b, c) * ggcd(a, b) * ggcd(b, c) * ggcd(a, c))/GCD3(a, b, c);
        long long abd = (llcm(a, b, d) * ggcd(a, b) * ggcd(b, d) * ggcd(a, d))/GCD3(a, b, d);
        long long acd = (llcm(a, c, d) * ggcd(a, c) * ggcd(c, d) * ggcd(a, d))/GCD3(a, c, d);
        long long bcd = (llcm(b, c, d) * ggcd(b, c) * ggcd(c, d) * ggcd(b, d))/GCD3(b, c, d);
        long long aa = ans[a] = cbrt((abc * abd / bcd) * acd / bcd);
        long long bb = ans[b] = sqrt((abc / aa) * (abd / aa) / (acd / aa));
        ans[c] = abc / aa / bb;
        ans[d] = abd / aa / bb;
    }
    answer(ans);
}