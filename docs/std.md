# STD (`std.h`)

Модуль, импортирующий все минимальные стандартные библиотеки.

Модуль проверяет стандарт языка на то, что он не ниже `C23`

Список подключаемых библиотек:
- `math.h`
- `stdio.h`
- `stdlib.h`
- `string.h`
- `signal.h`
- `stddef.h`
- `stdint.h`
- `inttypes.h`
- `stdckdint.h`
- `stdarg.h`
- `stdatomic.h`
- `errno.h`
- `limits.h`

Все структуры:
- `atomic_float_t { uint32_t bits; }` - Атомарный тип float.

Функции ниже предназначаются для работы с атомарным вещественным типом данных:
- `void atomic_float_store(atomic_float_t *obj, float value)` - Записать данные в float.
- `float atomic_float_load(const atomic_float_t *obj)` - Прочитать данные из float.

