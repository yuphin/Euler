/*
A set of disks numbered 1 through 100 are placed in a line in random order.

What is the probability that we have a partial derangement such that exactly 22 prime number discs are found away from their natural positions ?
(Any number of non - prime disks may also be found in or out of their natural positions.)

Give your answer rounded to 12 places behind the decimal point in the form 0.abcdefghijkl.

*/
#include <iostream>
#include <math.h> 
#include <iomanip>
using ll = long long;
using ld = long double;

ld factorial(int num) {
	if (num == 0) {
		return 1;
	}
	ld res = 1;
	while (num--) {
		res *= (num + 1);
	}
	return res;
}

ld combination(int num, int choose) {
	ld res = 1;
	if (num / 2 < choose) {
		choose = num - choose;
	}
	for (int i = 0; i < choose; i++) {
		res *= (num - i);
	}
	return res / factorial(choose);
}

ld derangement(int num) {
	ld res = 0;
	for (int i = 0; i <= num; i++) {
		res += powl(-1, i) / factorial(i);
	}
	return  factorial(num) * res;
}


ld calc_derangements(int num_disks, int num_primes, int req_primes) {
	auto non_primes = num_disks - num_primes;
	ld res = 0;
	for (int i = non_primes; i >= 0; i--) {
		res += combination(non_primes, i) * combination(num_primes, num_primes - req_primes) *
			derangement(num_disks - i - num_primes + req_primes);
	}
	return res / factorial(num_disks);
}

int main() {
	std::cout << std::setprecision(12) << std::fixed << calc_derangements(100, 25, 22) << "\n";
	return 0;
}
