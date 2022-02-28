#ifndef __MY_PROGRAM_UTIL__
#define __MY_PROGRAM_UTIL__

/**
 * @brief Compares two doubles.
 *
 * If a == b returns 0.
 * If a > b returns 1.
 * if a < b returns -1.
 *
 * @param a
 * @param b
 * @param epsilon
 * @return int
 */
int dblcmp(double a, double b, double epsilon);

/**
 * @brief Sums two nums.
 * @bug There is an intentional bug used to show mock usability.
 *
 * @param a Number to sum.
 * @param b Number to sum.
 * @return double Sum of number a and b.
 */
double sum(double a, double b);

#endif