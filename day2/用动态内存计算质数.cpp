// Calculating primes using dynamic memory allocation
#include<iostream>
#include <iomanip>
#include <cmath>                                             // For square root function
int main(void)   
{ 
    size_t  max{};
    std::cout << "How many primes would you like? ";
    std::cin >> max;  

    if (max == 0) return 0;                                    // Zero primes: do nothing
    
    auto* primes{new unsigned[max]};

    ssize_t count {1};
    primes[0] =2;

    unsigned trial {3};

    while (count<max)
    {
        bool isprime {true};

        const auto limit=static_cast<unsigned>(std::sqrt(trial));
        for (size_t i = 0; i < limit&isprime; i++)
        {
            isprime=trial%primes[i]>0;
        }
        
        if(isprime)
            primes[count++]=trial;
        
        trial+=2;
    }
    
    for (size_t i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << primes[i];
        if ((i + 1) % 10 == 0)                                   // After every 10th prime...
            std::cout << std::endl;
    }
    std::cout << std::endl;

    delete[] primes;
    primes=nullptr;
    return 0;
}
