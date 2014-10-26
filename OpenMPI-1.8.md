Rhea Task Affinity with OpenMPI 1.8
===================================


To Launch 16 single-thread MPI ranks:

`$ mpirun 


## Performance Comparisons

Below are the results of running the included code in the following configurations

### OpenMPI 1.6

Launched using `$ mpirun --bind-to-core ./a.out`.

#### 1 Thread per Rank

* Intel 13: 8.9s
* Intel 14: 6.5s
* GNU  4.7: 14.6s

#### 2 Threads per Rank

* Intel 13: 3.1s
* Intel 14: 3s
* GNU  4.7: 6.2s

### OpenMPI 1.8


#### 1 Thread per Rank

Launched using `$ mpirun --map-by core --bind-to hwthread ./a.out`
* Intel 13: 5.4s
* Intel 14: 3.9s
* GNU  4.7: 8.9s

#### 2 Threads per Rank

Launched using `$ mpirun --map-by core --bind-to core ./a.out`
* Intel 13: 3.1s
* Intel 14: 3.0s
* GNU  4.7: 7.0s
