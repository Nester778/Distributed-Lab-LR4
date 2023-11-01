#include <iostream>
#include <map>
#include "Tests.h"
using namespace std;

bool monobitTest(string key) {
	bool res = false;
	string binKey = key;
	int quantity = 0;
	for (int i = 0; i < binKey.size(); i++) {
		if (binKey[i] == '1')
			quantity++;
	}

	if (quantity >= 9654 && quantity <= 10346)
		res = true;
	cout << "quantity 1 in key: " << quantity << "(9654 <> 10346)" << endl;
	return res;
}

bool maxSeriesLenthTest(string key) {
	bool res = false;
	string binKey = key;
	int quantity = 0;
	int max0 = 1;
	int max1 = 1;

	for (int i = 0; i < binKey.size(); i++) {
		if (i > 0 && binKey[i] == binKey[i - 1])
		{
			if (binKey[i] == '0') {
				max0++;
			}

			if (binKey[i] == '1') {
				max1++;
			}
		}
		else {
			if (max0 > 36) {
				max0 = 1;
				res = false;
				break;
			}
			else {
				res = true;
				max0 = 1;
			}
			if (max1 > 36) {
				max1 = 1;
				res = false;
				break;
			}
			else {
				res = true;
				max1 = 1;
			}
		}
	}

	if (max0 > 36 || max1 > 36) {
		res = false;
		cout << "max series > 36" << endl;
	}
	else
		cout << "max series < 36" << endl;


	return res;
}

bool pokerTest(string key)
{
	bool res = false;
	string binKey = key;
	map<string, int> colv;
	string mas[16] = { "0000", "0001","0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

	for (int i = 0; i < binKey.size(); i += 4) {
		colv[binKey.substr(i, 4)]++;
	}

	int sum = 0;

	for (int i = 0; i < 16; i++) {
		sum += pow(colv[mas[i]], 2);
	}
	double x3 = static_cast<double>(16) / 5000 * sum - 5000;
	cout << "x3 = " << x3 << "(1.03 <> 57.4)" << endl;

	if (x3 >= 1.03 && x3 <= 57.4) {
		res = true;
	}

	return res;
}

bool seriesLengthTest(string key) {
	bool res = true;

	int tableMin[6] = { 2267, 1079, 502, 223, 90, 90 };
	int tableMax[6] = { 2733, 1421, 748, 402, 223, 223 };

	string binKey = key;
	int serLen0 = 1;
	int serLen1 = 1;
	map<int, int> colvSer0;
	map<int, int> colvSer1;

	for (int i = 0; i < binKey.size() - 1; i++) {

		if (binKey[i] == binKey[i + 1] && binKey[i] == '0')
			serLen0++;

		if (binKey[i] == '0' && binKey[i + 1] == '1') {
			if (i + 1 == binKey.size() - 1)
				colvSer1[1]++;

			if (serLen0 < 6)
				colvSer0[serLen0]++;

			else
				colvSer0[6]++;
			serLen0 = 1;
		}

		if (binKey[i] == binKey[i + 1] && binKey[i] == '1')
			serLen1++;

		if (binKey[i] == '1' && binKey[i + 1] == '0') {
			if (i + 1 == binKey.size() - 1)
				colvSer0[1]++;

			if (serLen1 < 6)
				colvSer1[serLen1]++;

			else
				colvSer1[6]++;
			serLen1 = 1;
		}
	}

	cout << "colv 0" << endl;

	for (int i = 1; i < 7; i++) {
		cout << to_string(i) + ": " << colvSer0[i] << +"(" + to_string(tableMin[i - 1]) + " <> " + to_string(tableMax[i - 1]) + ")" << endl;;
	}

	cout << "colv 1" << endl;

	for (int i = 1; i < 7; i++) {
		cout << to_string(i) + ": " << colvSer1[i] << +"(" + to_string(tableMin[i - 1]) + " <> " + to_string(tableMax[i - 1]) + ")" << endl;;
	}

	if (res) {
		for (int i = 1; i < 7; i++) {
			if (colvSer0[i] < tableMin[i - 1] || colvSer0[i] > tableMax[i - 1]) {
				res = false;
				break;
			}
		}
	}

	if (res) {
		for (int i = 1; i < 7; i++) {
			if (colvSer1[i] < tableMin[i - 1] || colvSer1[i] > tableMax[i - 1]) {
				res = false;
				break;
			}
		}
	}
	return res;
}