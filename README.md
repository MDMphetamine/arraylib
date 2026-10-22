# arraylib

Динамическая библиотека операций над массивом целых чисел (калькулятор).
Лабораторная работа 2 по дисциплине «Основы программирования».

Функции: arr_sum, arr_max, arr_min, arr_average, arr_count_positive,
arr_count_negative, arr_count_zero, arr_product, arr_median.

## Сборка

```
mkdir build && cd build
cmake ..
cmake --build . -j
./app
```

## Тесты

```
ctest --output-on-failure
```
