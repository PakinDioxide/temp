#include "hackslex.cpp"

#include <cassert>
#include <cstdio>

namespace public_password {
	long long P;
}

// Private Grader will not use this function
long long my_random() {
	long long r = public_password::P;
	r = r * 6364136223846793005ULL + 1LL;
    return (r >> 33LL) & 0x7FFFFFFFFFFFFFFFULL;
}

long long try_hack() {
	bool fail = (my_random() & 1LL) == 0;
	if(fail) {
		return -1LL;
	}
	return public_password::P;
}

signed main(int argc, char *argv[]) {
	assert(scanf("%lld", &public_password::P) == 1);
	long long password = hack_password();
	if(password == public_password::P) {
		printf("Correct\n");
	}
	else {
		printf("Incorrect\n");
	}
	return 0;
}
