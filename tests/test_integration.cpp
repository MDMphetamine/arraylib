#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

static bool nearly_equal(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    int data[] = {7, 3, 9, 1, 5, 8, 2, 6, 4};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    // Случай 1: сумма и максимум согласованы
    assert(arr_sum(data, n) == 45);
    assert(arr_max(data, n) == 9);

    // Случай 2: среднее между min и max
    double avg = arr_average(data, n);
    assert(avg >= static_cast<double>(arr_min(data, n)));
    assert(avg <= static_cast<double>(arr_max(data, n)));

    // Случай 3: среднее * n равно сумме, счётчики покрывают весь массив
    assert(nearly_equal(avg * static_cast<double>(n), static_cast<double>(arr_sum(data, n))));
    int mixed[] = {-4, 0, 5, -1, 0, 3};
    const std::size_t m = sizeof(mixed) / sizeof(mixed[0]);
    assert(static_cast<std::size_t>(arr_count_positive(mixed, m) + arr_count_negative(mixed, m)
                                    + arr_count_zero(mixed, m)) == m);

    // Случай 4: медиана отсортированного массива
    int sorted[] = {1, 2, 3, 4, 5, 6, 7};
    assert(nearly_equal(arr_median(sorted, 7), 4.0));

    // Случай 5: медиана лежит между min и max
    double med = arr_median(data, n);
    assert(med >= arr_min(data, n) && med <= arr_max(data, n));

    std::cout << "[integration] All tests passed\n";
    return 0;
}
