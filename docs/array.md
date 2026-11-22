# Array (`array.c`, `array.h`)

Модуль динамического массива.

Определения:
- `ARRAY_DEFAULT_CAPACITY` `1024` - Размер массива по умолчанию.
- `ARRAY_GROWTH_FACTOR` `2.0` - Коэффициент расширения массива.
- `ARRAY_SHRINK_FACTOR` `0.25` - Коэффициент сжатия массива.

Перечисление режимов печати:
```c
typedef enum {
    ARRAY_PRINT_PTR,
    ARRAY_PRINT_HEX,
    ARRAY_PRINT_BOOL,
    ARRAY_PRINT_CHAR,
    ARRAY_PRINT_INT,
    ARRAY_PRINT_LONG,
    ARRAY_PRINT_LLONG,
    ARRAY_PRINT_FLOAT,
    ARRAY_PRINT_DOUBLE,
    ARRAY_PRINT_STRING,
} ArrayPrintMode;
```

Структура массива:
```c
struct Array {
    void *data;        // Базовый адрес блока элементов.
    size_t item_size;  // Размер одного элемента.
    size_t len;        // Длина массива (сколько ячеек занято).
    size_t capacity;   // Всего выделенных ячеек в памяти (вместимость).
    size_t init_cap;   // Размер массива по умолчанию.
};
```

Функции:
- `Array* Array_create(size_t item_size, size_t initial_capacity)` - Создать массив с заданным размером.
- `void Array_destroy(Array **arr)` - Уничтожить массив.
- `void Array_growth(Array *arr, double factor)` - Расширяем массив.
- `void Array_shrink(Array *arr, double factor)` - Сжимаем массив.
- `void Array_push(Array *arr, const void *element)` - Добавить элемент в массив (передайте указатель на данные, которые надо скопировать внутрь массива).
- `void Array_set(Array *arr, size_t index, const void *element)` - Перезаписать элемент в массиве.
- `void* Array_get(Array *arr, size_t index)` - Получение элемента по индексу (адрес ячейки в памяти).
- `void* Array_get_ptr(Array *arr, size_t index)` - Получение элемента по индексу (сам указатель).
- `void* Array_get_round(Array *arr, int64_t index)` - Получение элемента по индексу по кругу (индексация замкнута, включая отрицательные индексы).
- `void Array_insert(Array *arr, size_t index, const void *element)` - Вставка элемента по индексу со сдвигом.
- `void Array_reverse(Array *arr)` - Переворот массива.
- `void Array_fill(Array *arr, const void *element, size_t count)` - Заполнить массив элементами.
- `size_t Array_find(Array *arr, const void *element)` - Найти элемент и вернуть его индекс + 1 (счет не с нуля). 0 = нет такого элемента.
- `void Array_copy(Array *dst, Array *src)` - Копировать массив.
- `void Array_remove(Array *arr, size_t index, void *out)` - Удаление элемента со сдвигом.
- `void Array_remove_swap(Array *arr, size_t index, void *out)` - Удаление элемента без сдвига, заменяем удаляемый, последним элементом (порядок нарушается, зато быстро).
- `void Array_pop(Array *arr, void *out)` - Получить и удалить последний элемент из массива (без alloc).
- `void* Array_pop_copy(Array *arr)` - Получить и удалить последний элемент из массива (alloc с копированием).
- `void Array_print(Array *arr, FILE *out, ArrayPrintMode mode)` - Печать содержимого массива.
- `size_t Array_len(Array *arr)` - Получить длину массива.
- `size_t Array_capacity(Array *arr)` - Получить размер массива.
- `void Array_clear(Array *arr, bool free_data)` - Очистка массива.
