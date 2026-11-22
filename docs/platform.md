# Platform (`platform.h`)

Модуль, определяющий платформу, на которой компилируется код.

Определяет удобные макросы в зависимости от платформы во время компиляции кода:
- define `PLATFORM_WINDOWS` `1` - Для `_WIN32` и `_WIN64`.
- define `PLATFORM_MACOS` `1` - Для `__APPLE__` и `__MACH__`.
- define `PLATFORM_LINUX` `1` - Для `__linux__`.
- define `PLATFORM_NAME` - Название платформы:
  - `"Windows"`
  - `"MacOS"`
  - `"Linux"`
  - `"Unknown"`

Если платформа не определена, то все макросы будут равны `0` а `PLATFORM_NAME` будет равен `"Unknown"`
