#pragma once

#include "../s21_matrix.h"

/*      === Helpers ===     */
int vldt_mtx(const matrix_t *M);
int vldt_ABr(const matrix_t *A, const matrix_t *B, const matrix_t *result);
int vldt_sum(const matrix_t *A, const matrix_t *B, const matrix_t *result);
int vldt_m_mtx(const matrix_t *A, const matrix_t *B, const matrix_t *result);

int vldt_det(const matrix_t *A, const double *result);

void minor_mtx(const matrix_t *A, const size_t a_i, const size_t a_j,
               matrix_t *res);
int vldt_comp(const matrix_t *A, const matrix_t *result);

/*      === Debugging Helpers ===     */
/*
void vldt_minor(const matrix_t *A, const size_t a_i, const size_t a_j,
                const matrix_t *res);
void s21_print_mtx(const matrix_t *A);
*/