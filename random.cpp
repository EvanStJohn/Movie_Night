#include "random.h"

Random::Random()
{

}

int Random::getRandom(int max)
{
    srand(time(NULL));
    return rand() % max + 1; // change when finished
}
