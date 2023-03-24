#include "s21_matrix.h"

int main(void) {
  matrix_t M1, M2;
  int r = 0, c = 0, error1 = 0, error2 = 0;

  scanf("%d%d", &r, &c);
  error1 = s21_create_matrix(r, c, &M1);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) scanf("%lf", &M1.matrix[i][j]);

  if (!error1) error2 = s21_inverse_matrix(&M1, &M2);

  if (!error1 && !error2) {
    s21_print_mtx(&M1);
    s21_remove_matrix(&M1);

    s21_print_mtx(&M2);
    s21_remove_matrix(&M2);
  } else {
    printf("%d %d\n", error1, error2);
    if (!error1) s21_remove_matrix(&M1);
  }

  return 0;
}