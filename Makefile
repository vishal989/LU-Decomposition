CC1=g++


all:
	$(CC1) ser.cpp -o ser
	$(CC1) -fopenmp omp.cpp -o omp
	$(CC1) pthread.cpp -o pt -pthread


