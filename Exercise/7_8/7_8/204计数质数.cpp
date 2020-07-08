Sieve of EratosthenesÀ„∑®£©
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n + 1, true);
		for (int i = 2; i < n; ++i)
			if (isPrime[i])
				for (int j = 2 * i; j < n; j += i)
					isPrime[j] = false;
		int res = 0;
		for (int i = 2; i < n; ++i)
			if (isPrime[i])
				res++;
		return res;
	}
};
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n + 1, true);
		for (int i = 2; i*i < n; ++i)
			if (isPrime[i])
				for (int j = i * i; j < n; j += i)
					isPrime[j] = false;
		int res = 0;
		for (int i = 2; i < n; ++i)
			if (isPrime[i])
				res++;
		return res;
	}
};
class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n + 1, true);
		int res = 0;
		for (int i = 2; i < n; ++i)
		{
			if (isPrime[i])
			{
				res++;
				for (int j = 2 * i; j < n; j += i)
					isPrime[j] = false;
			}
		}
		return res;
	}
};