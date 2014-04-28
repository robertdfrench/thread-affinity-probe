hello_world.exe: main.c
	mpicc -fopenmp -o hello_world.exe main.c
	cp hello_world.exe $(MEMBERWORK)/stf007

clean:
	rm -f hello_world.exe
	rm -f $(MEMBERWORK)/stf007/hello_world.exe
