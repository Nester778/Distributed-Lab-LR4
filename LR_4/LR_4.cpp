#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <osrng.h>
#include <cryptlib.h>
#include <hex.h>
#include "Tests.h"

using namespace std;


string getKey() {
	CryptoPP::AutoSeededRandomPool prng;
	const int sequenceLength = 20000;
	uint8_t randomBytes[sequenceLength / 8];
	prng.GenerateBlock(randomBytes, sizeof(randomBytes));

	string key = "";

	for (int i = 0; i < sequenceLength; i++) {
		int bit = (randomBytes[i / 8] >> (7 - (i % 8))) & 1;
		key += to_string(bit);
	}

	return key;
}

void test() {
	bool t = false;
	while (!t) {
		string key = getKey();
		t = monobitTest(key);
		if (t) {
			cout << "test 1: true" << endl << endl;
			t = maxSeriesLenthTest(key);
			if (t) {
				cout << "test 2: true" << endl << endl;
				t = pokerTest(key);
				if (t) {
					cout << "test 3: true" << endl << endl;
					t = seriesLengthTest(key);
					if (t) {
						cout << "test 4: true" << endl << endl;
						cout << "key is random, key -" << endl;
						cout << key << endl;
					}
					else {
						cout << "test 4: false" << endl << endl;
					}
				}
				else {
					cout << "test 3: false" << endl << endl;
				}
			}
			else {
				cout << "test 2:false" << endl << endl;
			}
		}
		else
			cout << "test 1: false" << endl << endl;
	}
}

int main()
{
	test();

	return 0;
}

