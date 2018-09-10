#ifndef FIND_NTH_NUMBER_H
#define FIND_NTH_NUMBER_H
#include <stdexcept>
#include <iostream>
#include <cmath>
using namespace std;
int findNthNumber(int n) {
	if (n < 0) throw invalid_argument("The input should be >= 0.");
	if (n == 0) return 0;
	else {
		n--;
		int count = 0;
		while (n >= 0) {
			count++;
			n -= (9 * pow(10, count - 1) * count);
		}
		n += (9 * pow(10, count - 1) * count);
		int quotient = n / count;
		int remainder = n - quotient * count;
		long long int target = pow(10, count - 1) + quotient;
		int index = count - 1 - remainder;
		int tempTarget = 0;
		int result = 0;
		for (auto i = 0; i != index + 1; ++i) {
			tempTarget = target;
			target /= 10;
			result = tempTarget % 10;
		}
//		cout<<n<<" "<<count<<" "<<quotient<<" "<<remainder<<" "<<target<<endl;
		return result;
	}
}
#endif
