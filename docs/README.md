# Руководство по C-Core-Lib (v1.0.1)

### Описание:

`C-Core-Lib` является базовым набором функционала (пакетом) для разработки программ на языке `C`. В нем реализованы основные, простые, полезные и часто используемые инструменты.

Ядро требует стандарт языка не ниже `C23`

#

### Список модулей ядра:

- [`Array`](array.md) (`array.c`, `array.h`).
- [`core`](core.md) (`core.h`, `core.c`).
- [`Files`](files.md) (`files.c`, `files.h`).
- [`HashTable`](hashtable.md) (`hashtable.c`, `hashtable.h`).
- [`Info`](info.md) (`info.c`, `info.h`).
- [`JobSystem`](jobsystem.md) (`jobsystem.c`, `jobsystem.h`).
- [`libs`](libs.md) (`libs.h`).
- [`Logger`](logger.md) (`logger.c`, `logger.h`).
- [`math`](math.md) (`math.h`).
- [`mm`](mm.md) (`mm.c`, `mm.h`).
- [`Node`](node.md) (`node.c`, `node.h`).
- [`Noise`](noise.md) (`noise.c`, `noise.h`).
- [`Pixmap`](pixmap.md) (`pixmap.c`, `pixmap.h`).
- [`PLATFORM`](platform.md) (`platform.h`).
- [`random`](random.md) (`random.c`, `random.h`).
- [`std`](std.md) (`std.h`).
- [`Time`](time.md) (`time.h`).

#

Ядро является таргетом для компиляции и подключения. Используйте его как пакет который следует скомпилировать и подключить через include.

На данный момент ядро рассчитано на платформы:
- `Windows`
- `MacOS`
- `Linux`

#

### Ссылки:

Репозиторий на [GitHub.](https://github.com/LukovDev/C-Core-Lib)

Посмотреть исходный код визуально можно на [codrift.](https://codrift.lukovdev.ru/?repo=LukovDev/C-Core-Lib&view=api)
