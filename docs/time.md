# Time (`time.h`)

Модуль кроссплатформенной реализации времени.

Структуры:
```c
// Текущее время:
struct TimeCurrent {
    uint64_t ticks;
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
    uint32_t ms;
};
```

```c
// Смещение пояса UTC:
struct TimeOffsetUTC {
    int32_t offset;
    int32_t hour;
    int32_t min;
};
```

Функции:
- `double Time_now(double *x)` - Возвращает время с начала Unix-эпохи в секундах (double) с точностью до мс.
- `void Time_sleep(double seconds)` - Остановить выполнение кода на определенное время в секундах с дробной частью (малая точность чем у Time_delay).
- `void Time_delay(double seconds)` - Задержать выполнение кода на определенное время в секундах с дробной частью (большая точность чем у Time_sleep).
- `TimeOffsetUTC Time_get_utc_offset(void)` - Узнать у устройства смещение часового пояса.
- `TimeCurrent Time_get_current(bool local_time)` - Получить дату и время.
- `void Time_init(void)` - Инициализация времени. Вызывается при инициализации ядра.
