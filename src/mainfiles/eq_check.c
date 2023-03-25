#include "../s21_matrix.h"

int main(void) {
  matrix_t M1;
  matrix_t M2;
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  int err = 0;
  err = s21_eq_matrix(&M1, &M2);
  printf("err == SUCCESS = %d\n", err == SUCCESS);
  err = s21_eq_matrix(&M1, NULL);
  printf("err == FAILURE = %d\n", err == FAILURE);

  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);

  s21_create_matrix(2, 2, &M1);
  s21_create_matrix(2, 2, &M2);

  err = s21_eq_matrix(&M1, &M2);
  printf("err == SUCCESS = %d\n", err == SUCCESS);

  err = s21_eq_matrix(NULL, &M2);
  printf("err == FAILURE = %d\n", err == FAILURE);

  M1.matrix[0][0] = 5.00000000011;
  M1.matrix[0][1] = 4.0;
  M1.matrix[1][1] = 3.0;

  M2.matrix[0][0] = 5.00000000012;
  M2.matrix[0][1] = 4.0;
  M2.matrix[1][1] = 3.0;

  err = s21_eq_matrix(&M1, &M2);
  printf("err == FAILURE = %d\n", err == FAILURE);

  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);

  return 0;
}