#include <stdio.h>
#include <mpi.h>
#include <omp.h>
#include <utmpx.h>
#include <unistd.h>

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int num_megabytes = atoi(argv[1]);

	char hostname[64];
	gethostname(hostname,64);

	if (rank == 0) printf("Host.cpu => rank.thread\n");
	MPI_Barrier(MPI_COMM_WORLD);

	#pragma omp parallel
	{
		int thread_id = omp_get_thread_num();
		int cpu = sched_getcpu();
		printf("%s.%d => %d.%d\n", hostname, cpu, rank, thread_id);
	}
	MPI_Finalize();
	return 0;
}
