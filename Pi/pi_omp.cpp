#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double STEP = 0.0;
int CALCULATION_STEP = 1000000;
int THREAD_NUM = 11;

void calculate_pi_calculus();
void calculate_pi_probability();

int main(int argc, const char * argv[]) {
	STEP = 1.0 / (CALCULATION_STEP);

	calculate_pi_calculus();
	calculate_pi_probability();

	return 0;
}

void calculate_pi_calculus() {	
	printf("Using Calculus\n");
	omp_set_num_threads(THREAD_NUM);

	double result = 0.0;
#pragma omp parallel for reduction (+:result)
	for (int i = 0; i < CALCULATION_STEP; i++) {
		double x = (i) * STEP;
		result += 1 / (1 + x * x);
	}

	printf("PI = %f\n", 4 * result / CALCULATION_STEP);
}

void calculate_pi_probability() {
	printf("Using Probability\n");
	omp_set_num_threads(THREAD_NUM);

  	float x = 0.0;
  	float y = 0.0;

  	double result = 0.0;
#pragma omp parallel for reduction (+:result)
  	for (int i = 0; i < CALCULATION_STEP; i++) {
		x = (float)rand() / RAND_MAX;
    	y = (float)rand() / RAND_MAX;
		if ((x * x + y * y) <= 1) {
  			result++;
		}
  	}

	printf("PI = %f\n", 4 * result / CALCULATION_STEP);
}