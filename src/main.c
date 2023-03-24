// #include <time.h>

#include "s21_matrix.h"

int main(void) {
  // srand(time(NULL));

  matrix_t M1, M2, M3;
  int r = 0, c = 0, error = 0;

  scanf("%d%d", &r, &c);
  error += s21_create_matrix(r, c, &M1);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) scanf("%lf", &M1.matrix[i][j]);

  scanf("%d%d", &r, &c);
  error += s21_create_matrix(r, c, &M2);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) scanf("%lf", &M2.matrix[i][j]);

  // printf("\n");
  // s21_print_mtx(&M1);
  // printf("\n");
  // s21_print_mtx(&M2);
  // printf("\n");

  error = s21_mult_matrix(&M1, &M2, &M3);

  if (!error) {
    s21_print_mtx(&M2);
    s21_remove_matrix(&M1);
    s21_remove_matrix(&M2);
    s21_remove_matrix(&M3);
  } else
    printf("%d\n", error);

  return 0;
}