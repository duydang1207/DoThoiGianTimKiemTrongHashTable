#include "dataStructure.h"


int HashFunction(string url, int prime)
{
    int hashValue = 0;
    for (int i = 0; i < url.length(); i++)
        hashValue += url[i]*i;
    return hashValue % prime;
}
