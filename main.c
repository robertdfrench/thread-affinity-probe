#include <stdio.h>
#include <mpi.h>
#include <omp.h>
#include <utmpx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <sched.h>

#define length_of_hostname 64
typedef struct thread_location {
	char hostname[length_of_hostname];
	int thread_id;
	int cpu_id;
	int rank;
} ThreadLocation;

void ThreadLocation_print(ThreadLocation tl) {
	printf("\"hostname\": %s, \"cpu_id\": %d, \"rank\": %d, \"thread_id\": %d\n", tl.hostname, tl.cpu_id, tl.rank, tl.thread_id);
}

ThreadLocation ThreadLocation_create() {
	ThreadLocation tl;
	tl.thread_id = omp_get_thread_num();
	tl.cpu_id = sched_getcpu();
	MPI_Comm_rank(MPI_COMM_WORLD, &(tl.rank));
	gethostname(tl.hostname, length_of_hostname);
	return tl;
}

#define PI 3.1415
void work_unit(double* data, int num_elements) {
	int i;
	double h = 1.0 / (double)num_elements;
	#pragma omp parallel for
	for(i=0; i < num_elements; i++) {
		data[i] = sin(2*PI*i*h);
	}
}

#define KB 1024
#define MB 1024 * KB
int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	#pragma omp parallel
	{
		ThreadLocation tl = ThreadLocation_create();
		ThreadLocation_print(tl);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	int data_size = 1200 * MB;
	int num_elements = data_size / sizeof(double);
	double* data = (double*)malloc(data_size);
	double start_work = MPI_Wtime();
	work_unit(data, num_elements);
	double stop_work = MPI_Wtime();

	printf("\"rank\": %d, \"time\": %f\n",rank,stop_work - start_work);

	MPI_Finalize();
	return 0;
}
