# Numerical Integration

Monte Carlo method to numerically integrate a function.

Author :
============
Sagar Vishwakarma (svishwa2@binghamton.edu)

State University of New York, Binghamton

File-Info
============

1)	Makefile				  - compile the code
2)	integrate.cpp			- Contains Implementation of Numerical Integration


How to compile and run
============

1)	go to terminal, cd into directory and type 'make' to compile
2)	Run using ./integrate a b n n_threads

  The a and b arguments give the limits of integration. They may be any floating point number, and may be negative. The n arguments gives the total number of samples across all threads. The n_threads arguments gives the number of threads. Thus, each thread should execute approximately n/n_threads samples.

Note:
============

I ran this code on my local machine which has Intel(R) Core(TM) i7-9750H with 6 cores and 12 threads.
I used "chrono" library to measure time to execute the programme with n_threads.
The time noted then used to compute graph for speedup and efficiency with respect to threads.
The graph file is graph.png, graph_1.png

Looking at the graph we can see the speedup increases as the number of threads increases, ie: its directly proportional.
This behaviour changes as we cross the number of threads per cpu core (including hyperthreading)
On my machine i7-9750H which has 6 physical cores with hyperthreading enabled ie: 2 threads per core.

The speedup rises as the thread count increases till it reaches 12 threads then the speedup plummet a little and stays around a constant number.
