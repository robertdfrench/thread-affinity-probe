thread-affinity-benchmark.titan.exe: main.c
	cc -mp -o thread-affinity-benchmark.titan.exe main.c

thread-affinity-benchmark.eos.exe: main.c
	cc -fopenmp -o thread-affinity-benchmark.eos.exe main.c
	cp thread-affinity-benchmark.eos.exe $(MEMBERWORK)/stf007

thread-affinity-benchmark.rhea.exe: main.c
	mpicc -fopenmp -o thread-affinity-benchmark.rhea.exe main.c
	cp thread-affinity-benchmark.rhea.exe $(MEMBERWORK)/stf007

clean:
	rm -f thread-affinity-benchmark.rhea.exe
	rm -f thread-affinity-benchmark.eos.exe
	rm -f thread-affinity-benchmark.titan.exe
	rm -f $(MEMBERWORK)/stf007/thread-affinity-benchmark.rhea.exe
	rm -f $(MEMBERWORK)/stf007/thread-affinity-benchmark.eos.exe
	rm -f $(MEMBERWORK)/stf007/thread-affinity-benchmark.titan.exe
