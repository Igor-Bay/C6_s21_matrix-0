#include "../s21_matrix.h"

#define minus1_pow(x) ((x) % 2 ? -1 : 1)
#define EPS 1e-7

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = vldt_comp(A, result);

  if (!error) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t mtx_min;
        double det = 0.;

        minor(A, i, j, &mtx_min);
        s21_determinant(&mtx_min, &det);
        result->matrix[i][j] = det * minus1_pow(i + j);
        s21_remove_matrix(&mtx_min);
      }
    }
  }

  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = vldt_det(A, result);

  if (!error) {
    *result = 0.;

    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      for (size_t i = 0; i < (size_t)A->rows; ++i) {
        matrix_t mtx_min;
        double det_min = 0.;

        minor(A, 0, i, &mtx_min);
        s21_determinant(&mtx_min, &det_min);
        *result += A->matrix[0][i] * det_min * minus1_pow(i);
        s21_remove_matrix(&mtx_min);
      }
    }
  }

  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = vldt_comp(A, result);

  if (!error) {
    double det = 0.;
    s21_determinant(A, &det);
    if (fabs(det) < EPS) error = CALCULATION_ERROR;

    if (!error) {
      matrix_t mtx_comp;
      matrix_t mtx_comp_trans;

      det = 1. / det;

      s21_calc_complements(A, &mtx_comp);
      s21_transpose(&mtx_comp, &mtx_comp_trans);
      s21_mult_number(&mtx_comp_trans, det, result);
      s21_remove_matrix(&mtx_comp_trans);
      s21_remove_matrix(&mtx_comp);
    }
  }

  return error;
}

void minor(const matrix_t *A, const size_t a_i, const size_t a_j,
           matrix_t *res) {
  vldt_minor(A, a_i, a_j, res);

  // if (A->rows > 1) {
  s21_create_matrix(A->rows - 1, A->columns - 1, res);

  for (size_t i = 0; i < (size_t)A->rows; ++i) {
    if (i == a_i) continue;

    for (size_t j = 0; j < (size_t)A->columns; ++j) {
      if (j == a_j) continue;

      res->matrix[i - (i > a_i)][j - (j > a_j)] = A->matrix[i][j];
    }
  }
  // } else {
  //   s21_create_matrix(A->rows, A->columns, res);
  //   res->matrix[0][0] = A->matrix[0][0];
  // }
}