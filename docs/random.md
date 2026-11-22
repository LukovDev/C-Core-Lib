# Random (`random.c`, `random.h`)

Модуль детерминированного рандомайзера, на основе PCG32.

Функции:
- `void random_init(uint64_t init_state)` - Инициализировать рандомайзер.
- `uint32_t random(void)` - Получить случайное число в диапазоне uint32_t.
- `float randomf(void)` - Получить случайное число в диапазоне от 0 до 1.
- `int32_t random_range(int32_t min, int32_t max)` - Получить случайное целое число в диапазоне от min до max включительно.
- `float random_rangef(float min, float max)` - Получить случайное вещественное число в диапазоне от min до max.
