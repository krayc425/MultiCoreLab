#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

double SUM = 0.0;
double STEP = 0.0;

const int CALCULATION_STEP = 1000000;
const int THREAD_NUM = 11;

DWORD WINAPI calculate_pi_calculus(void *data);
DWORD WINAPI calculate_pi_probability(void *data);

struct ThreadArg {
	int thread_id;
};

int main(int argc, const char * argv[]) {
	HANDLE thread_array[THREAD_NUM];
	ThreadArg arg_array[THREAD_NUM];

	STEP = 1.0 / (CALCULATION_STEP);

	for (int i = 0; i < THREAD_NUM; i++) {
		arg_array[i].thread_id = i;

		//thread_array[i] = CreateThread(NULL, 0, calculate_pi_probability, (void *)&arg_array[i], 0, NULL);
		// or
		thread_array[i] = CreateThread(NULL, 0, calculate_pi_calculus, (void *)&arg_array[i], 0, NULL);
	}
	for (int i = 0; i < THREAD_NUM; i++) {
		WaitForSingleObject(thread_array[i], INFINITE);
	}

	double PI = STEP * SUM;
	printf("PI = %f\n", PI);

	system("pause");

	return 0;
}

DWORD WINAPI calculate_pi_calculus(void *data) {
	ThreadArg *arg = (ThreadArg *)data;

	printf("Using Calculus %d\n", arg->thread_id);

	double result = 0.0;
	for (int i = arg->thread_id; i < CALCULATION_STEP; i += THREAD_NUM) {
		double x = (i + 0.5) * STEP;
		result += 1 / (1 + x * x);
	}

	SUM += 4 * result;

	return 0;
}

DWORD WINAPI calculate_pi_probability(void *data) {
	ThreadArg *arg = (ThreadArg *)data;

	printf("Using Probability %d\n", arg->thread_id);

	float x = 0.0;
	float y = 0.0;

	double result = 0.0;
	srand((unsigned)0);
	for (int i = 0; i < CALCULATION_STEP; i += THREAD_NUM) {
		x = (float)rand() / RAND_MAX;
		y = (float)rand() / RAND_MAX;
		if ((x * x + y * y) <= 1) {
			result++;
		}
	}

	SUM += 4 * result;

	return 0;
}
