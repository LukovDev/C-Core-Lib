//
// core.h - Ядро. Подключает все модули ядра здесь.
//
// Является независимым пакетом полезных инструментов и функций, для любого приложения на си.
//

// Подключаем:
#include "core.h"


// Локальные переменные:
static bool init = false;


// Инициализация ядра:
bool core_init(void) {
    if (init) return false;
    init = true;
    Info_get_cpu();  // Вызываем 1 раз чтобы кэшировать данные.
    Time_init();     // Время инициализируем первым, потому что остальные модули могут использовать его.
    Logger_init();
    JobSystem_init();

    // Инициализация генератора случайных чисел:
    random_init((uint32_t)(Time_now(nullptr)));

    // Настраиваем пути для OS X:
    #ifdef __APPLE__
        Files_fix_apple_path();
    #endif
    return true;
}


// Уничтожение ядра:
bool core_destroy(void) {
    if (!init) return false;
    JobSystem_destroy();  // Уничтожение работы с задачами (потоками).
    return true;
}


// Получить версию ядра:
const char* core_version(void) {
    return "v1.0.1";
}
