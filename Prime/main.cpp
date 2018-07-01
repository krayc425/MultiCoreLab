#include <iostream>
#include "Prime.h"
#include <omp.h>

using namespace std;

inline void printLine() {
	cout << "--------------------" << endl;
}

int main(int argc, const char * argv[]) {
	double begin, end;
	printLine();

	// Serial
	begin = omp_get_wtime();
	cout << "Serial Number: " << Prime::compute_serial().size() << endl;
	end = omp_get_wtime();
	cout << "Serial Time: " << end - begin << endl;
	printLine();

	// Parallel
	begin = omp_get_wtime();
	cout << "Parallel Number: " << Prime::compute_parallel().size() << endl;
	end = omp_get_wtime();
	cout << "Parallel Time: " << end - begin << endl;
	printLine();

	// OpenMP
	begin = omp_get_wtime();
	Prime::compute_omp();
	end = omp_get_wtime();
	cout << "OMP Time: " << end - begin << endl;
	printLine();

#ifdef WIN32
	system("pause");
#endif

	return 0;
}
