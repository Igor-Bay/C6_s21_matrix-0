#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  error = rows <= 0 || columns <= 0;
  if (!error) error = result == NULL;

  if (!error) {
    result->rows = rows;
    result->columns = columns;

    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL)
      for (int i = 0; i < rows; ++i) {
        (result->matrix)[i] = (double *)calloc(columns, sizeof(double));
        if ((result->matrix)[i] == NULL) exit(1);
      }
    else
      exit(1);
  }

  return error;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; ++i) free(A->matrix[i]);
  free(A->matrix);

  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  result = A->rows == B->rows && A->columns == B->columns;

  if (result)
    for (int i = 0; i < A->rows && result; ++i)
      for (int j = 0; j < A->columns && result; ++j)
        result = (A->matrix)[i][j] == (B->matrix)[i][j];

  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = A == NULL || B == NULL || result == NULL;
  if (!res) res = !(A->rows == B->rows && A->columns == B->columns);

  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          (result->matrix)[i][j] = (A->matrix)[i][j] + (B->matrix)[i][j];
    }
  }

  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = A == NULL || B == NULL || result == NULL;
  if (!res) res = !(A->rows == B->rows && A->columns == B->columns);

  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          (result->matrix)[i][j] = (A->matrix)[i][j] - (B->matrix)[i][j];
    }
  }

  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = A == NULL || result == NULL;

  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (!res) {
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          (result->matrix)[i][j] = (A->matrix)[i][j] * number;
    }
  }

  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = A == NULL || B == NULL || result == NULL;
  if (!res) res = !(A->columns == B->rows);

  if (!res) {
    res = s21_create_matrix(A->rows, B->columns, result);
    if (!res) {
      for (int i = 0; i < result->rows; ++i)
        for (int j = 0; j < result->columns; ++j)
          for (int k = 0; k < A->columns; ++k)
            (result->matrix)[i][j] += (A->matrix)[i][k] * (B->matrix)[k][j];
    }
  }

  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = A == NULL || result == NULL;

  if (!res) {
    res = s21_create_matrix(A->columns, A->rows, result);
    if (!res) {
      for (int i = 0; i < A->columns; ++i)
        for (int j = 0; j < A->rows; ++j)
          (result->matrix)[i][j] = (A->matrix)[j][i];
    }
  }
  return res;
}

void s21_print_mtx(const matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) {
      printf("%.f", A->matrix[i][j]);
      printf("%c", j < A->columns - 1 ? ' ' : '\n');
    }
}