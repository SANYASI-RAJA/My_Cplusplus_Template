vector<int>spf(1e6 + 5);
vector<int>mobius(1e6 + 5);

//  spf[i]=smallest primefactor of i.
//  Time : O(NlogN) , Space : O(N).

void primefactorsieve()
{

	for (int i = 2; i <= 1e6; i++)
		spf[i] = i;
	for (int i = 2; i <= 1e6; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i + i; j <= 1e6; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

// 		      | 0 : if any prime factor is more than one.
// mobius[i]= | 1 : if number of prime factor is even.
// 		      |-1 : if number of prime factor is odd.
//  Time : O(N) , Space : O(N).

void Mobius()
{
	for (int i = 1; i <= 1e6; ++i)
	{
		if (i == 1)mobius[i] = 1;
		else
		{
			if (spf[i / spf[i]] == spf[i])mobius[i] = 0;
			else mobius[i] = -1 * mobius[i / spf[i]];
		}
	}
}
