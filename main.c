#include <stdio.h>
#include <mpi.h>
#include <omp.h>
#include <utmpx.h>

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	#pragma omp parallel
	{
		int thread_id = omp_get_thread_num();
		printf("Hello from thread %d within rank %d\n", thread_id, rank);
	}
	MPI_Finalize();
	return 0;
}
