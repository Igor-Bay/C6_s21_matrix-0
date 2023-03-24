#include "../s21_matrix.h"

void s21_print_mtx(const matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) {
      printf("%.f", A->matrix[i][j]);
      printf("%c", j < A->columns - 1 ? ' ' : '\n');
    }
}

int vldt_mtx(const matrix_t *M) {
  if (M == NULL) return INCORRECT_MATRIX;

  if (M->matrix == NULL || M->rows <= 0 || M->columns <= 0)
    return INCORRECT_MATRIX;

  return OK;
}

int vldt_res(const matrix_t *M) {
  if (M == NULL || M->matrix != NULL) return INCORRECT_MATRIX;

  return OK;
}

int vldt_sum(const matrix_t *A, const matrix_t *B, const matrix_t *result) {
  int res = OK;

  res = vldt_mtx(A);
  if (!res) res = vldt_mtx(B);
  if (!res) res = vldt_res(result);

  if (!res) {
    res = !(A->rows == B->rows && A->columns == B->columns);
    res = res ? CALCULATION_ERROR : OK;
  }

  return res;
}

int vldt_m_mtx(const matrix_t *A, const matrix_t *B, const matrix_t *result) {
  int res = OK;

  res = vldt_mtx(A);
  if (!res) res = vldt_mtx(B);
  if (!res) res = vldt_res(result);

  if (!res) {
    res = !(A->columns == B->rows);
    res = res ? CALCULATION_ERROR : OK;
  }

  return res;
}
