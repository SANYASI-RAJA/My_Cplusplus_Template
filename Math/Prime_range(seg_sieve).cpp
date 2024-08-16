// Prime number in a range l .... r

#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
vector<int>prime_range;
void sieve(int n)
{
	std::vector<bool> isprime(n + 1, true);
	for (long long i = 2; i <= n; ++i)
	{
		if (isprime[i])
		{
			prime.push_back(i);
			for (int j = i * i; j <= n ; j = j + i)
			{
				isprime[j] = false;
			}
		}
	}
}

void segsieve(int l, int h)
{

	long long sq = sqrt(h);
	sieve(sq);

	std::vector<bool> isprime(h - l + 1, true);
	for (long long p : prime)
	{
		long long sm = (l / p) * p;
		if (sm < l)
			sm += p;
		if (sm == p)sm += p;
		for (long long j =  sm  ; j <= h; j = j + p)
		{
			isprime[j - l] = false;

		}

	}
	for (int i = l; i <= h; ++i)
	{
		if (i > 1 && isprime[i - l] == true)
			prime_range.push_back(i);
	}
}



signed main()
{
	int t; cin >> t;
	while (t--)
	{
		int l, r; cin >> l >> r;
		prime.clear();
		prime_range.clear();
		segsieve(l, r);
		for (int i = 0; i < prime_range.size(); ++i)
		{
			cout << prime_range[i] << " ";
		}
		cout <<  endl;
	}

}