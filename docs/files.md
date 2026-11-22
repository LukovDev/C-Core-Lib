# Files (`files.c`, `files.h`)

Модуль работы с файлами.

Функции:
- `char* Files_get_cwd(char *buf, size_t size)` - Получить текущую директорию.
- `bool Files_chdir(const char *path)` - Переход к каталогу.
- `char* Files_get_home(void)` - Получить путь домашнего каталога.
- `char* Files_dirname_dup(const char *filepath)` - Получить директорию файла (требуется освободить память).
- `char* Files_path_join(const char *dir, const char *path)` - Склеить пути (требуется освободить память).
- `char* Files_load(const char *file_path, const char *mode)` - Загружаем файл в строку.
- `bool Files_save(const char *file_path, const char *data, const char *mode)` - Сохраняем строку в файл.
- `unsigned char* Files_load_bin(const char *file_path, const char *mode, size_t *out_size)` - Загружаем файл в буфер бинарно.
- `bool Files_save_bin(const char *file_path, const void *data, size_t size, const char *mode)` - Сохраняем буфер в файл бинарно.
