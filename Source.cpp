#include "chapten.h"

void sum_file(string& fn) {
	// Sum all the numbers in a file of whitespace seperated integers.
	ifstream ist{ fn };
	int num = 0;
	int sum = 0;
	if (!ist) error("cant open input file: ", fn);
	while (ist >> num) {
		sum += num;
	}
	cout << "Sum: " << sum << "\n";
}