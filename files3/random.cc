#include <functional>
#include <random>
#include <array>

class Rand_double
{
public:
    Rand_double(double low, double high)
    :r(std::bind(std::uniform_real_distribution<>(low,high),std::default_random_engine())){}

    double operator()(){ return r(); }

private:
    std::function<double()> r;
};

#include <iostream>    
int main() {
    // create the random number generator:
    Rand_double rd{0,0.5};

    // print 10 random number between 0 and 0.5
    for (int i=0;i<10;++i){
        std::cout << rd() << ' ';
    }
    return 0;
}
