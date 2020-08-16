#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <math.h>
// #include <unistd.h>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;


atomic<double> integral_sum(0.0);


void integral_sum_func(unsigned int idx, double min_num, double max_num, int itr_range) {

	double random_num;
	double integral;
	unsigned int seed = idx;

	srand(time(NULL));

	for (int i = 0; i < itr_range; i++) {
		random_num = min_num + static_cast <double> (rand_r(&seed)) / ( static_cast <double> (RAND_MAX/(max_num-min_num)));
		// cout << "Thread : "<< idx <<", random number : " << random_num << endl;
		integral = sin(random_num)/random_num;
		integral_sum = integral_sum + integral;
		// cout << idx << "::" << integral_sum << endl;
	}
}


int main(int argc, char const* argv[]) {

	if (argc != 5) {
		cerr << "Help : Usage "<< argv[0] << " a b n n_threads" << endl;
		cerr << "Info : a = lower bound, b = upper bound, n = num samples" << endl;
		exit(1);
	}
	else {

		double a, b;
		int n, n_threads, itr_range;

		a	= atof(argv[1]);
		b	= atof(argv[2]);
		n	= atoi(argv[3]);
		n_threads	= atoi(argv[4]);

		if (a > b) {
			cerr << "Error : lower bound (a) cannot be greater than upper bound (b)" << endl;
			exit(1);
		}

		if (n < 0 || n_threads < 1) {
			cerr << "Error : number of samples or number of threads cannot be negative" << endl;
			exit(1);
		}

		double integral_ans;

		itr_range = n/n_threads;

		thread thread_arr[n_threads];

		// Get starting timepoint
    auto start = high_resolution_clock::now();

		for (unsigned int i = 0; i < n_threads; i++) {
			// cout << "THREAD : " << i << " range " << itr_range << endl;
			thread_arr[i] = thread(integral_sum_func, i, a, b, itr_range);
		}

		for (int i = 0; i < n_threads; i++) {
			thread_arr[i].join();
		}

		integral_ans = integral_sum/n*(b-a);

		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(stop - start);

		// cout << duration.count() << ", ";
		cout << integral_ans << endl;

	}
	return 0;
}
