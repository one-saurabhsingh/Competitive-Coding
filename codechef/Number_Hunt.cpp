#include <iostream>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

int find_product_of_primes(int X)
{
    // Find the first prime >= X
    int prime1 = X;
    while (!is_prime(prime1))
    {
        prime1++;
    }

    // Find the next prime >= prime1
    int prime2 = prime1 + 1;
    while (!is_prime(prime2))
    {
        prime2++;
    }

    // Return the product of these two primes
    return prime1 * prime2;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int X;
        cin >> X;
        cout << find_product_of_primes(X) << endl;
    }
    return 0;
}
