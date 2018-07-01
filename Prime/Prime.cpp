#include <cmath>
#include "Prime.h"
#include <iostream>
#include <sstream>
#include <omp.h>

using namespace std;

bool isPrime(int number) {
	if (number == 2) {
		return true;
	}
	if (number % 2 == 0 || number <= 1) {
		return false;
	}
	for (int j = 3; j <= (int)sqrt(number); j += 2) {
		if (number % j == 0) {
			return false;
		}
	}
	return true;
}

vector<int> Prime::compute_serial() {
	vector<int> primes;
	for (int i = 0; i < N; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<int> Prime::compute_parallel() {
	if (N <= THREAD_NUM) {
		return compute_serial();
	}

	ThreadArg threadArgs[THREAD_NUM];
	vector<int> primes;

#ifdef linux

	pthread_t threads[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; i++) {
		threadArgs[i].thread_id = i;
		pthread_create(&threads[i], NULL, compute_prime, (void *)&threadArgs[i]);
	}

	for (int i = 0; i < THREAD_NUM; i++) {
		pthread_join(threads[i], NULL);
		primes.insert(primes.end(), threadArgs[i].primes.begin(), threadArgs[i].primes.end());
	}

#else

	HANDLE threads[THREAD_NUM];

	for (int i = 0; i < THREAD_NUM; i++) {
		threadArgs[i].thread_id = i;
		threads[i] = CreateThread(NULL, 0, compute_prime, (void *)&threadArgs[i], 0, NULL);
	}

	for (int i = 0; i < THREAD_NUM; i++) {
		WaitForSingleObject(threads[i], INFINITE);
		primes.insert(primes.end(), threadArgs[i].primes.begin(), threadArgs[i].primes.end());
	}

#endif

	return primes;
}

#ifdef linux

void* Prime::compute_prime(void *arg) {

#else

DWORD Prime::compute_prime(void *arg) {

#endif
	ThreadArg *threadArg = (ThreadArg *)arg;
	for (int i = threadArg->thread_id; i <= N; i += THREAD_NUM) {
		if (isPrime(i)) {
			threadArg->primes.push_back(i);
		}
	}
	return 0;
}

void Prime::compute_omp() {
	int prime_num = 0;
	omp_set_num_threads(THREAD_NUM);
#pragma omp parallel for reduction(+:prime_num)
	for (int i = 0; i < N; i++) {
		if (isPrime(i)) {
			prime_num++;
		}
	}
	cout << "OMP Number: " << prime_num << endl;
}