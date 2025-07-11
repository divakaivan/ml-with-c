#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0}, // y = 2x
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};
#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}

float cost(float w)
{
    float result = 0.0f;
    size_t n = train_count;
    for (size_t i = 0; i < n; ++i) {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= n;
    return result;
}

float dcost(float w)
{
    float result = 0.0f;
    size_t n = train_count;
    for (size_t i = 0; i < n; ++i) {
        float x = train[i][0];
        float y = train[i][1];
        result += 2*(x*w - y)*x;
    }
    result /= n;
    return result;
}

int main()
{
    srand(2025);
    float w = rand_float()*10.0f;

    float learning_rate = 1e-1;

    printf("cost = %f, w = %f\n", cost(w), w);
    for (size_t i = 0; i < 50; ++i) {
#if 0
        float eps = 1e-3;
        float c = cost(w);
        float dw = (cost(w + eps) - c)/eps;;
#else
        float dw = dcost(w);
#endif
        w -= learning_rate * dw;
        printf("cost = %f, w = %f\n", cost(w), w);
    }

    printf("------------------------------\n");
    printf("w = %f\n", w);

    return 0;
}




