# HashTable (`hashtable.c`, `hashtable.h`)

Модуль хэш-таблицы.

Определения:
- `HASHTABLE_DEFAULT_CAPACITY` `1024` - Размер хэш-таблицы по умолчанию.
- `HASHTABLE_MIN_CAPACITY` `1024` - Минимальный размер хэш-таблицы.
- `HASHTABLE_GROWTH_FACTOR` `2.0` - Коэффициент увеличения таблицы.
- `HASHTABLE_SHRINK_FACTOR` `2.0` - Коэффициент сжатия таблицы (формула: cap = len*SHRINK_FACTOR).
- `HASHTABLE_GROWTH_THRESHOLD` `0.66f` - Порог количества заполненности таблицы для расширения (%).
- `HASHTABLE_SHRINK_THRESHOLD` `0.25f` - Порог количества заполненности таблицы для сжатия (%).
- `HASHTABLE_PROBING_COUNT` `64` - Массив записей последних пробирований (аналитика).
- `HASHTABLE_PROBING_LIMIT` `32` - Лимит пробирований при поиске слота.

Перечисление режимов печати:
```c
typedef enum {
    HASHTABLE_PRINT_PTR,
    HASHTABLE_PRINT_HEX,
    HASHTABLE_PRINT_BOOL,
    HASHTABLE_PRINT_CHAR,
    HASHTABLE_PRINT_INT,
    HASHTABLE_PRINT_LONG,
    HASHTABLE_PRINT_LLONG,
    HASHTABLE_PRINT_FLOAT,
    HASHTABLE_PRINT_DOUBLE,
    HASHTABLE_PRINT_STRING,
} HashTablePrintMode;
```

Структуры:
```c
// Структура слота таблицы:
struct HashSlot {
    void  *key;         // Указатель на ключ.
    size_t key_size;    // Размер блока ключа.
    void  *value;       // Указатель на значение.
    size_t value_size;  // Размер блока значения.
    size_t hash;        // Хэш ключа (высчитывается один раз для оптимизации).
    bool   deleted;     // Флаг удаления (нужен для различия удалённых слотов от пустых).
};
```

```c
// Структура хэш-таблицы:
struct HashTable {
    HashSlot *data;      // Таблица слотов.
    size_t  len;         // Длина таблицы (сколько ячеек занято).
    size_t  capacity;    // Всего выделенных ячеек в памяти (вместимость).
    size_t  prob_count[HASHTABLE_PROBING_COUNT];  // Количество пробирований (поиск слота).
    size_t  prob_index;  // Индекс (счетчик) в массиве prob_count.
    size_t (*hash_func)(const void *data, size_t len);  // Функция хэша. Можно сменить.
};
```

Функции:
- `HashTable* HashTable_create(void)` - Создать хэш-таблицу.
- `void HashTable_destroy(HashTable **table, bool free_key, bool free_value)` - Уничтожить хэш-таблицу (не удаляет блоки по указателям).
- `bool HashTable_set(HashTable *table, const void *key, size_t key_size, const void *value, size_t value_size, bool free_value)` - Добавить элемент в хэш-таблицу или обновить его значение.
- `bool HashTable_get(HashTable *table, const void *key, size_t key_size, void **out_value, size_t *out_value_size)` - Получить элемент по ключу. Возвращает true, если ключ найден.
- `HashSlot* HashTable_get_slot(HashTable *table, size_t index)` - Получить слот из таблицы по индексу.
- `bool HashTable_remove(HashTable *table, const void *key, size_t key_size, bool free_key, bool free_value)` - Удалить элемент из таблицы.
- `bool HashTable_has(HashTable *table, const void *key, size_t key_size)` - Возвращает true, если ключ есть в таблице.
- `size_t HashTable_len(HashTable *table)` - Получить длину таблицы.
- `size_t HashTable_capacity(HashTable *table)` - Получить вместимость таблицы.
- `void HashTable_print(HashTable *table, FILE *out, HashTablePrintMode key_mode, HashTablePrintMode value_mode)` - Вывести содержимое таблицы.
- `void HashTable_clear(HashTable *table, bool free_key, bool free_value)` - Очистить таблицу (без освобождения памяти по умолчанию).
