#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double SUM = 0.0;
double STEP = 0.0;

int CALCULATION_STEP = 1000000;
int THREAD_NUM = 11;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *calculate_pi_calculus(void *data);
void *calculate_pi_probability(void *data);

int main(int argc, const char * argv[]) {
	pthread_t thread_array[THREAD_NUM];

	STEP = 1.0 / (CALCULATION_STEP);

	for (int i = 0; i < THREAD_NUM; i++) {
		pthread_create(thread_array + i, NULL, calculate_pi_probability, (void *)i);
		// or
		// pthread_create(thread_array + i, NULL, calculate_pi_calculus, (void *)i);
	}
	for (int i = 0; i < THREAD_NUM; i++) {
		pthread_join(thread_array[i], NULL);
	}

   	pthread_mutex_destroy(&mutex);

   	double PI = STEP * SUM;
   	printf("PI = %f\n", PI);

	return 0;
}

void *calculate_pi_calculus(void *data) {
	int num = (int)data;
	
	printf("Using Calculus %d\n", num);

	double result = 0.0;
	for (int i = num; i < CALCULATION_STEP; i += THREAD_NUM) {
		double x = (i + 0.5) * STEP;
		result += 1 / (1 + x * x);
	}

  	pthread_mutex_lock(&mutex);
	SUM += 4 * result;
  	pthread_mutex_unlock(&mutex);
}

void *calculate_pi_probability(void *data){
	int num = (int)data;

	printf("Using Probability %d\n", num);

  	float x = 0.0;
  	float y = 0.0;

  	double result = 0.0;
  	srand((unsigned)time(0));
  	for (int i = 0; i < CALCULATION_STEP; i += THREAD_NUM) {
		x = (float)rand() / RAND_MAX;
    	y = (float)rand() / RAND_MAX;
    	if ((x * x + y * y) <= 1) {
      		result++;
    	}
  	}

	pthread_mutex_lock(&mutex);
	SUM += 4 * result;
	pthread_mutex_unlock(&mutex);
}
