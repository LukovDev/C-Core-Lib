//
// core.h - Ядро. Подключает все модули ядра здесь.
//
// Является независимым пакетом полезных инструментов и функций, для любого приложения на си.
//

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Подключаем:
#include "std.h"
#include "array.h"
#include "files.h"
#include "hashtable.h"
#include "info.h"
#include "jobsystem.h"
#include "libs.h"
#include "logger.h"
#include "math.h"
#include "mm.h"
#include "node.h"
#include "noise.h"
#include "pixmap.h"
#include "platform.h"
#include "random.h"
#include "time.h"

// Инициализация ядра:
bool core_init(void);

// Уничтожение ядра:
bool core_destroy(void);

// Получить версию ядра:
const char* core_version(void);

#ifdef __cplusplus
}
#endif
