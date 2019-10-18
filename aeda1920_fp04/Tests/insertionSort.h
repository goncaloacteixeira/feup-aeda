#include <vector>
using namespace std;

template <class T>
void insertionSort(vector<T> &v)
{
    T temp;
    int i, j;
    for(j = 1; j < v.size(); j++)    // Start with 1 (not 0)
    {
        temp = v[j];
        for(i = j - 1; (i >= 0) && (v[i].frequencia <= temp.frequencia); i--)   // Smaller values move up
        {
            if (v[i].frequencia == temp.frequencia && v[i].nome > temp.nome)    // test if name comes after, if true, then put it right to the previous value
                v[i+1] = v[i];
            if (v[i].frequencia != temp.frequencia)
                v[i+1] = v[i];
        }
        v[i+1] = temp;    //Put key into its proper location
    }
}
