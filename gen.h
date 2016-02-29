#ifndef GEN_H
#define GEN_H


#include <algorithm>
#include <time.h>


using namespace std;

/**
 * @brief The Gen class Generator of random number whith Mersenne twister
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
};

#endif // GEN_H

/*
#ifndef GEN_H
#define GEN_H


#include <algorithm>
#include <time.h>

#include "iostream"

using namespace std;

class Gen
{
private:
    static Gen* singleton;
    std::mt19937 g;

    Gen(): g(static_cast<uint32_t>(time(0)))
    {
        cout << "constructeur" << endl;
    }

    Gen(int seed): g(static_cast<uint32_t>(seed))
    {
        cout << "constructeur avec seed" << endl;
    }

    //Empecher la copie
    Gen(const Gen&);
    void operator=(const Gen&);

public:

    static Gen *get()
    {
        if(!singleton)
            singleton = new Gen;
        return singleton;
    }

    size_t operator()(size_t n)
    {
        std::uniform_int_distribution<size_t> d(0, n ? n-1 : 0);
        cout << d(g) << endl;
        return d(g);
    }
};

#endif // GEN_H
*/
