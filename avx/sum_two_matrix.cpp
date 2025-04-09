#include <x86intrin.h>
#include <iostream>
#include <time.h>

void add_arrays(const float* a, const float* b, float* result, const size_t size) {
    size_t i;
    
    for (i = 0; i < size / 8 * 8; i += 8) {
        
        __m256 vec_a = _mm256_loadu_ps(&a[i]);
        __m256 vec_b = _mm256_loadu_ps(&b[i]);
        
        
        __m256 vec_result = _mm256_add_ps(vec_a, vec_b);
        
        
        _mm256_storeu_ps(&result[i], vec_result);
    }

    
    for (; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
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
    float* b = new float[size];
    for(size_t i{0}; i<size; i++)
    {
        a[i] = random();
        b[i] = random();
    }

    float* result = new float[size];
    clock_t start = clock();
    add_arrays(a, b, result, size);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    /*
    for (size_t i = 0; i < size; ++i) {
        std::cout << "result[" << i << "] = " << result[i]<<"\n";
    }
    */
    return 0;
}
