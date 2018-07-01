#include <vector>

#ifdef linux
#include "pthread.h"
#else
#include <windows.h>
#endif

const int N = 4000000;
const int THREAD_NUM = 11;

using namespace std;

class Prime {

public:

	static vector<int> compute_serial();
	static vector<int> compute_parallel();
	static void compute_omp();

	struct ThreadArg {
		int thread_id;
		vector<int> primes;
	};

private:

#ifdef linux

	static void *compute_prime(void *arg);

#else

	static DWORD WINAPI compute_prime(void *arg);

#endif
};
