#include "s21_matrix_helpers.h"

#include "../s21_matrix.h"

int vldt_mtx(const matrix_t *M) {
  if (M == NULL) return INCORRECT_MATRIX;

  if (M->matrix == NULL || M->rows <= 0 || M->columns <= 0)
    return INCORRECT_MATRIX;

  return OK;
}

int vldt_ABr(const matrix_t *A, const matrix_t *B, const matrix_t *result) {
  int error = result == NULL;
  if (!error) error = vldt_mtx(A);
  if (!error) error = vldt_mtx(B);

  return error;
}

int vldt_sum(const matrix_t *A, const matrix_t *B, const matrix_t *result) {
  int error = vldt_ABr(A, B, result);

  if (!error && (A->rows != B->rows || A->columns != B->columns))
    error = CALCULATION_ERROR;

  return error;
}

int vldt_m_mtx(const matrix_t *A, const matrix_t *B, const matrix_t *result) {
  int error = vldt_ABr(A, B, result);

  if (!error && A->columns != B->rows) error = CALCULATION_ERROR;

  return error;
}

int vldt_det(const matrix_t *A, const double *result) {
  int error = result == NULL;
  if (!error) error = vldt_mtx(A);
  if (!error && A->rows != A->columns) error = CALCULATION_ERROR;

  return error;
}

int vldt_comp(const matrix_t *A, const matrix_t *result) {
  const double dummy = 0.;
  int error = result == NULL;
  if (!error) error = vldt_det(A, &dummy);

  return error;
}

/*      === Debugging Helpers ===     */
/*
void vldt_minor(const matrix_t *A, const size_t a_i, const size_t a_j,
                const matrix_t *res) {
  if (a_i >= (size_t)A->rows || a_j >= (size_t)A->columns) {
    fprintf(stderr, "\nminor(...): A_I AND/OR A_J ARE OUT OF RANGE\nEXIT\n");
    exit(1);
  }

  if (vldt_mtx(A)) {
    fprintf(stderr, "\nminor(...): INPUT MATRIX IS INVALID\nEXIT\n");
    exit(1);
  }

  if (vldt_res(res)) {
    fprintf(stderr, "\nminor(...): RES MATRIX IS INVALID\nEXIT\n");
    exit(1);
  }
}

void s21_print_mtx(const matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) {
      printf("%.2f", A->matrix[i][j]);
      printf("%c", j < A->columns - 1 ? ' ' : '\n');
    }
}
*/