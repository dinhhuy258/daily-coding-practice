#include <iostream>
#include <vector>

#define MAX 1000000

int main() {
    std::vector<int> primeNumbers(MAX + 1, 0);
    primeNumbers[1] = 1;
    for (int i = 2; i * i <= MAX; ++i) {
        if (!primeNumbers[i]) {
            // if i is prime number
            for (int j = i * 2; j <= MAX; j += i) {
                if (!primeNumbers[j]) {
                    primeNumbers[j] = 1;
                    ++primeNumbers[i];
                }
            }
        }
    }
    int numberOfTestCases, number;
    std::cin >> numberOfTestCases;
    for (int i = 0; i < numberOfTestCases; ++i) {
        std::cin >> number;
        std::cout << primeNumbers[number] + 1 << std::endl;
    }
    return 0;
}

