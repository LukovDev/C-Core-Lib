//
// random.h - Модуль детерминированного рандомайзера, на основе PCG32.
//

#pragma  once


// Подключаем:
#include "std.h"


// Инициализировать рандомайзер:
void random_init(uint64_t init_state);

// Получить случайное число в диапазоне uint32_t:
uint32_t random(void);

// Получить случайное число в диапазоне от 0 до 1:
float randomf(void);

// Получить случайное целое число в диапазоне от min до max включительно:
int32_t random_range(int32_t min, int32_t max);

// Получить случайное вещественное число в диапазоне от min до max:
float random_rangef(float min, float max);
