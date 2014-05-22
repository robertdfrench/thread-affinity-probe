hello_world.eos.exe: main.c
	cc -fopenmp -o hello_world.eos.exe main.c
	cp hello_world.eos.exe $(MEMBERWORK)/stf007

hello_world.exe: main.c
	mpicc -fopenmp -o hello_world.exe main.c
	cp hello_world.exe $(MEMBERWORK)/stf007

clean:
	rm -f hello_world.exe
	rm -f $(MEMBERWORK)/stf007/hello_world.exe
	rm -f hello_world.eos.exe
	rm -f $(MEMBERWORK)/stf007/hello_world.eos.exe
