#ifndef GEN_H
#define GEN_H


#include <algorithm>
#include <time.h>


using namespace std;

/**
 * @brief The Gen class holds the random number generator using Mersenne twister
 */
class Gen
{
private:
    /**
     * @brief seed_ Seed of the generator
     */
    static int seed_;
public:
    /**
     * @brief g
    **/
    std::mt19937 g;

    /**
     * @brief Gen Constructor of the Generator
     */
    Gen(): g(static_cast<uint32_t>(seed_))
    {
    }

    /**
     * @brief operator ()
     * @param n Size of the number returned
     * @return a random number
     */
    size_t operator()(size_t n)
    {
        std::uniform_int_distribution<size_t> d(0, n ? n-1 : 0);
        seed_ = (d(g) + seed_) % 32767;
        return d(g);
    }
    
    static void setSeed(int newseed)
    {
        seed_ = newseed;
    }

};

#endif // GEN_H
