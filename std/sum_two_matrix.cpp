#include <iostream>

void add_arrays(const float* a, const float* b, float* result, const size_t size) {
    size_t i;
    
    for (i = 0; i < size; i++) 
    {
        result[i] = a[i]+b[i];
    }

}

int main() {
    const size_t size = 600000000; 
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