/* ==========================================================================*/
/* Copyright 2023 © Moscow, Russian Federaion
 *
 * This file contains Original Code created by
 * Igor Baidikov aka lorenttr.
 *
 * The Original Code and all software developed in the process of
 * participation on learning by experimental programming educational method.
 * The whole methodology was developed and distributed by
 * Autonomous non-profit organization «School 21» (ANO «School 21»).
 *
 * Redistribution and use of this file, its parts, or entire project
 * are permitted by confirmation of its original creators.
 */
/* ==========================================================================*/

#pragma once

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum another_errors {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALCULATION_ERROR = 2,
};

/*      === Constructor and Destructor ===     */
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

/*      === Operations ===     */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

/*      === Determinant ===     */
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

/*      === Helpers ===     */
void s21_print_mtx(const matrix_t *A);
int vldt_mtx(const matrix_t *M);
int vldt_sum(const matrix_t *A, const matrix_t *B, const matrix_t *result);
int vldt_m_mtx(const matrix_t *A, const matrix_t *B, const matrix_t *result);
