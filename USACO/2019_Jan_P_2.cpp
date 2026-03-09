#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
}

/*
let x = numbers of non-standard trails

there would be at mose xC2 good routes

if we check k1, k2;

it should overlap

like (u, v), (x, y)

(u -> v) intersect (x -> y) != null

what if we count number of those who doesn't intersect

it should be small to large merging ??? idk
*/