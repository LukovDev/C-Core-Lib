# Logger (`logger.c`, `logger.h`)

Модуль логгера событий.

Функции:
- `void Logger_init(void)` - Инициализация логгера. Вызывается при инициализации ядра.
- `void Logger_enable(void)` - Включить логгер.
- `void Logger_disable(void)` - Выключить логгер.
- `void log_msg(const char *fmt, ...)` - Вывод сообщения в лог-файл и в консоль.
