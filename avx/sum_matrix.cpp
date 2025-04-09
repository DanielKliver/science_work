#include <x86intrin.h>
#include <iostream>
#include <vector>

float sum_matrix(const float* a, float result, const size_t size)
{
    float sum {0.0f};
    
    // Создаем AVX вектор для накопления суммы (инициализируем нулями)
    __m256 sum_vec = _mm256_setzero_ps();
    
    size_t i {0};
    // Обрабатываем по 8 элементов за раз (AVX работает с 8 float)
    for (; i + 8 <= size; i += 8) 
    {
        // Загружаем 8 элементов в AVX вектор
        __m256 vec = _mm256_loadu_ps(&a[i]);
        // Добавляем к аккумулятору
        sum_vec = _mm256_add_ps(sum_vec, vec);
    }
        
    // Обрабатываем оставшиеся элементы обычным способом
    for (; i < size; ++i) 
    {
        sum += a[i];
    }
    
    
    // Извлекаем суммы из AVX вектора
    float temp[8]{};
    _mm256_storeu_ps(temp, sum_vec);
    
    // Суммируем 8 значений из AVX вектора
    for (int i = 0; i < 8; ++i) {
        sum += temp[i];
    }

    return sum;

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

    for(size_t i = 0; i<size; i++)
    {
        a[i] = rand();
    }

    float result{};

    clock_t start = clock();
    result = sum_matrix(a, result, size);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The time: %f seconds\n", seconds);

    std::cout<< "result = "<< result <<"\n";

    delete[] a;
    
}