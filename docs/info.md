# Info (`info.c`, `info.h`)

Модуль получения информации о CPU и RAM.

Перечисления архитектуры:
```c
typedef enum {
    INFO_X86_64,
    INFO_X86,
    INFO_ARM64,
    INFO_ARM,
    INFO_UNKNOWN
} Info_cpu_arch;
```

Структуры:
```c
// Информация о процессоре:
struct CpuInfo {
    char model[64];      // Модель процессора.
    int threads;         // Количество логических ядер (потоков).
    Info_cpu_arch arch;  // Архитектура процессора.
};
```

```c
// Информация о памяти:
struct MemInfo {
    size_t total;  // Всего памяти в байтах.
    size_t free;   // Свободно памяти в байтах.
    size_t used;   // Использовано памяти в байтах.
};
```

Функции:
- `const char* Info_get_cpu_arch_name(Info_cpu_arch arch)` - Получить архитектуру процессора в виде строки.
- `CpuInfo Info_get_cpu(void)` - Функция для получения информации о процессоре.
- `MemInfo Info_get_mem(void)` - Функция для получения ОЗУ (в байтах).
