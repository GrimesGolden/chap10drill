#include "std_lib_facilities.h"

void sum_file(string& fn);

struct Reading {
	int hour;
	double temperature;
};

void fill_vector(vector<Reading>& readings);
void store_temps(const vector<Reading>& readings);
void temp_stats(const vector<Reading>& readings);