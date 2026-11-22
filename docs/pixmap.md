# Pixmap (`pixmap.c`, `pixmap.h`)

Модуль для работы с растровыми картинками.

Перечисление:
```c
// Количество каналов в пикселе:
typedef enum PixmapFormat {
    PIXMAP_R = 1,
    PIXMAP_RG,
    PIXMAP_RGB,
    PIXMAP_RGBA
} PixmapFormat;
```

Глобальные переменные стандартной картинки:
- `const unsigned char g_Pixmap_default_icon[]`
- `const size_t g_Pixmap_default_icon_size`
- `const int g_Pixmap_default_icon_width`
- `const int g_Pixmap_default_icon_height`

Структура:
```c
struct Pixmap {
    int width;       // Ширина картинки.
    int height;      // Высота картинки.
    int channels;    // Количество байт на пиксель.
    bool from_stbi;  // Флаг, что картинка загружена с помощью stbi.
    bool is_hdr;     // Флаг, что картинка HDR.
    void *data;      // Указатель на блок данных (либо unsigned char* либо float*).
};
```

Функции:
- `Pixmap* Pixmap_create(int width, int height, int channels)` - Создать картинку.
- `void Pixmap_destroy(Pixmap **pixmap)` - Уничтожить картинку.
- `Pixmap* Pixmap_load(const char *filepath, int channels)` - Загрузить картинку.
- `bool Pixmap_save(Pixmap *self, const char *filepath, const char *format)` - Сохранить картинку.
- `Pixmap* Pixmap_copy(const Pixmap *source)` - Копировать картинку в памяти.
- `Pixmap* Pixmap_create_default(void)` - Создать стандартную картинку.
- `size_t Pixmap_get_size(Pixmap *self)` - Получить размер картинки в байтах.
