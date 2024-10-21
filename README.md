# Подготовка среды Windows

Ставим компилятор и окружение:

    https://www.msys2.org/

Параметры -> Система -> О системе -> Дополнительные параметры системы -> Дополнительно -> Переменные среды -> Системные переменные -> Path

Прописываем в PATH пути:

    c:\msys64\mingw64\bin\
    c:\msys64\usr\bin\

Открываем консоль

    c:\msys64\mingw64.exe

Ставим пакеты:

    pacman -S PACKAGE_NAME

Пакеты:

    clang
        mingw-w64-x86_64-clang

    cmake (cmake.exe)
        mingw-w64-x86_64-cmake

    make (mingw32-make.exe)
        mingw-w64-x86_64-make

    ninja
        mingw-w64-x86_64-ninja

# Настройка среды VSCode

Ставим расширения:

    С/С++ [Microsoft]
    С/С++ Extension Pack [Microsoft]
    С/С++ Themes [Microsoft]
    ClangFormat [Seaube]
    CMake [twxs]
    CMake Tools [Microsoft]
    Code Runner [Jun Han]
    Makefile Tools [Microsoft]

Настраиваем расширения

    CMake Tools
        Cmake: Additional Compiler Search Dirs
            c:\msys64\mingw64\bin\
        Cmake: Build Before Run
            true
        Cmake: Build Directory
            ${workspaceFolder}/build
        Cmake: Clear Output Before Build
            true
        Cmake: Cmake Path
            cmake.exe

    Code Runner
        Code-runner: Clear Previous Output
            true
        Code-runner: Preserve Focus
            true
        Code-runner: Run In Terminal
            true

    ClangFormat
        Clang Format › Executable: Default
            clang-format

У вас есть два способа сборки:

    Make
    CMake

Запуск обоих происходит через меню "Запуск и отладка":

    C/C++ Make: Автозапуск с отладкой
    C/C++ CMake: Автозапуск с отладкой

# Make

Make предпочтителен для сборки в стиле ретро-пк, для Dos и старых версий Windows.

Make вызывает дополнительную зависимость от таска "build"

    C/C++ Make: Скомпилировать приложение

Настройки Make берутся из файла Makefile, который лежит в корневом каталоге.

Исходный файл собирается в каталог "bin".

# CMake

CMake это более мощная надстройка над Make и другими сборщиками. CMake является более предпочтительным для сборки современных приложений.

Настройки CMake берутся из файла CMakeLists.txt, который лежит в корневом каталоге.

Для запуска CMake может понадобиться перенастроить сборку. Для этого нужно нажать

    Ctrl + Shift + P

и выбрать

    CMake: Configure

Если будет предложено выбрать компилятор, предпочтение стоит отдать mingw64.

Исходный файл собирается в каталог "build/bin".

# Разработка

В тестовом примере показаны:

    структура файлов проекта
    работа с заголовочными файлами
    пространства имен
    классы
    функции

Файлы проекта должны иметь расширение .cpp, файлы заголовков должны иметь расширение .h

Проект поддерживает дебаг режим.

# Библиотеки

## Conio

Только под Dos/Windows. Подключается и работает по-умолчанию, без проблем.

Файл с примером:

    conio.cpp.test

## Curses

Под Dos/Windows используется pdcurses.

Устанавливается через пакетный менеджер:

    curses/ncurses/pdcurses
        mingw-w64-x86_64-pdcurses

Файл с примером:

    pdcurses.cpp.test

В Makefile нужно прописать флаги:

    LDFLAGS=-lpdcurses

В CMakeLists.txt нужно прописать

после

    add_executable(...)

строку:

    target_link_libraries(${LOCAL_PROJECT_NAME} pdcurses)

Флаги:

    -lpdcurses
    открывает свое окно, которое выглядит как простенькая консоль

    -lpdcurses_wingui -lgdi32 -lwinmm -lcomdlg32
    аналогично pdcurses

    -lpdcurses_vt
    вывод в системную консоль, есть проблемы с работой

    -lpdcurses_wincon -lwinmm
    вывод в системную консоль
