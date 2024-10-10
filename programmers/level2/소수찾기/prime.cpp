#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> uniqueNumbers;
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            int num = stoi(numbers.substr(0, i));
            uniqueNumbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int primeCount = 0;
    for (int num : uniqueNumbers) {
        if (isPrime(num)) {
            ++primeCount;
        }
    }
    
    return primeCount;
}