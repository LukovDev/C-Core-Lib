//
// random.c - Модуль детерминированного рандомайзера, на основе PCG32.
//


// Подключаем:
#include "std.h"
#include "random.h"


// Состояние генератора:
static uint64_t pcg_state = 0x853c49e6748fea9bULL;
static uint64_t pcg_inc   = 0xda3e39cb94b95bdbULL;


// Инициализировать рандомайзер:
void random_init(uint64_t init_state) {
    pcg_state = 0U;
    pcg_state = pcg_state * 6364136223846793005ULL + pcg_inc;
    pcg_state += init_state;
    pcg_state = pcg_state * 6364136223846793005ULL + pcg_inc;
}


// Получить случайное число в диапазоне uint32_t:
uint32_t random(void) {
    uint64_t old_state = pcg_state;
    pcg_state = old_state * 6364136223846793005ULL + pcg_inc;
    uint32_t xorshifted = ((old_state >> 18u) ^ old_state) >> 27u;
    uint32_t rot = old_state >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}


// Получить случайное число в диапазоне от 0 до 1:
float randomf(void) {
    uint32_t x = random();
    union { uint32_t u; float f; } pun = { .u = (x >> 9) | 0x3f800000u };
    return pun.f - 1.0f;
}


// Получить случайное целое число в диапазоне от min до max включительно:
int32_t random_range(int32_t min, int32_t max) {
    if (min > max) {
        int32_t temp = min;
        min = max;
        max = temp;
    }
    uint32_t range = (uint32_t)(max - min) + 1U;
    return min + (int32_t)(random() % range);
}

// Получить случайное вещественное число в диапазоне от min до max:
float random_rangef(float min, float max) {
    return min + randomf() * (max - min);
}
