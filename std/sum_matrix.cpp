#include <iostream>
#include <time.h>

float sum_matrix(const float* a, float result, const size_t size)
{
    for(size_t i{0}; i<size; i++)
    {
        result += a[i];
    }
    return result;
}

int main(int argc, char** argv)
{
    size_t size{100};
    if(argc!=1)
    {
         size = atoi(argv[1]);
    }
    std::cout<<"Количество элементов: "<<size<<"\n";

    float* a = new float[size]; 

    for(size_t i{0}; i<size; i++)
    {
        a[i] = random();
    }

    float result {0};
    clock_t start = clock();

    result = sum_matrix(a, result, size);

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    std::cout<<"result = "<<result<<"\n";

    delete[] a;

    return 0;
}