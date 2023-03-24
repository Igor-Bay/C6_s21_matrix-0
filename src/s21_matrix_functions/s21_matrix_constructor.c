#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = rows <= 0 || columns <= 0;
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
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; ++i) {
      if (A->matrix[i] != NULL)
        free(A->matrix[i]);
      else
        exit(1);
    }
    free(A->matrix);
  } else
    exit(1);

  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}