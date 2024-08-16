void sieve(int n)
{
  std::vector<bool> isprime(n + 1, true);
  for (ll i = 0; i <= n; ++i)
  {
    if (isprime[i])
    {
      prime.pb(i);
      for (int j = i * i; j <= n ; j = j + i)
      {
        isprime[j] = false;
      }
    }
  }
}