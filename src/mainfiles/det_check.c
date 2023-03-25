#include "../s21_matrix.h"

int main(void) {
  matrix_t M1;
  int r = 0, c = 0, error = 0;
  double res = 0.;

  scanf("%d%d", &r, &c);
  error = s21_create_matrix(r, c, &M1);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) scanf("%lf", &M1.matrix[i][j]);

  if (!error) {
    s21_print_mtx(&M1);

    error = s21_determinant(&M1, &res);
    if (!error)
      printf("%f\n", res);
    else
      fprintf(stderr, "ERROR: %d\n", error);

    s21_remove_matrix(&M1);
  }

  return 0;
}