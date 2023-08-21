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

void fill_vector(vector<Reading>& readings) {
	vector<double> temps = { 69.8, 74.3, 68.5, 71.1, 72.9, 76.6, 75.2, 69.7, 73.8, 70.4,
	67.9, 79.5, 81.2, 78.6, 72.0, 68.3, 70.9, 75.7, 77.1, 74.9,
	71.8, 76.3, 68.7, 73.2, 79.8, 80.5, 77.9, 72.4, 69.1, 74.7,
	75.8, 70.2, 67.5, 81.9, 82.6, 78.3, 76.8, 72.6, 71.4, 73.6,
	76.1, 79.1, 81.7, 68.9, 70.6, 74.5, 75.4, 77.5, 80.1, 82.3 };

	// this fills a vector with Reading readings.
	int h = 0;
	for (double temp : temps) {
		if (h >= 24) {
			h = 0;
		}

		Reading r;
		r.hour = h;
		r.temperature = temp;
		readings.push_back(r);
		h++;
	}
}

void store_temps(const vector<Reading>& readings) {
	string fn = "raw_temps.txt";
		ofstream ost{ fn };
	if (!ost) error("Can't open output file", fn);

	for (Reading r : readings) {
		ost << r.hour << " " << r.temperature << "\n";
	}
}

void temp_stats(const vector<Reading>& readings) {

	vector<double> temps;

	for (Reading r : readings) {
		temps.push_back(r.temperature);
	}
	
	sort(temps.begin(), temps.end());
	int n = temps.size();
	double median = 0;
	double sum = 0;
	double mean = 0;

	if (n % 2 == 0) {
		double left = temps[(n / 2) - 1]; 
		double right = temps[(n/2)];
		median = (left + right) / 2;
	}
	else if (n % 2 != 0) {
		//odd
		median = temps[n-1] / 2;
	}

	for (double t : temps) {
		sum += t;
	}

	mean = sum / n;

	cout << "Median: " << median << "\n" << "Mean: " << mean << "\n";
}