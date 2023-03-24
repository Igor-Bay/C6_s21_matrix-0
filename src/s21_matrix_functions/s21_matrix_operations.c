#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = A->rows == B->rows && A->columns == B->columns;

  if (result)
    for (int i = 0; i < A->rows && result; ++i)
      for (int j = 0; j < A->columns && result; ++j)
        result = (A->matrix)[i][j] == (B->matrix)[i][j];

  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = vldt_sum(A, B, result);

  if (!error) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        (result->matrix)[i][j] = (A->matrix)[i][j] + (B->matrix)[i][j];
  }

  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = vldt_sum(A, B, result);

  if (!error) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        (result->matrix)[i][j] = (A->matrix)[i][j] - (B->matrix)[i][j];
  }

  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = vldt_mtx(A);
  if (!error) error = vldt_res(result);

  if (!error) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        (result->matrix)[i][j] = (A->matrix)[i][j] * number;
  }

  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = vldt_m_mtx(A, B, result);

  if (!error) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows; ++i)
      for (int j = 0; j < result->columns; ++j)
        for (int k = 0; k < A->columns; ++k)
          (result->matrix)[i][j] += (A->matrix)[i][k] * (B->matrix)[k][j];
  }

  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = vldt_mtx(A);
  if (!error) error = vldt_res(result);

  if (!error) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; ++i)
      for (int j = 0; j < A->rows; ++j)
        (result->matrix)[i][j] = (A->matrix)[j][i];
  }
  return error;
}