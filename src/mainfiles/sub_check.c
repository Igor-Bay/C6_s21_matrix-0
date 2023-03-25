#include "../s21_matrix.h"

int main(void) {
  matrix_t M1, M2, result, correct_res;
  int err = 0;
  s21_create_matrix(2, 2, &M1);
  s21_create_matrix(2, 2, &M2);
  s21_create_matrix(2, 2, &correct_res);

  M1.matrix[0][0] = 2.2;
  M1.matrix[0][1] = 10;
  M1.matrix[1][0] = 7;
  M1.matrix[1][1] = 14;
  M2.matrix[0][0] = 1;
  M2.matrix[0][1] = 2;
  M2.matrix[1][0] = 3;
  M2.matrix[1][1] = 4;
  correct_res.matrix[0][0] = 1.2;
  correct_res.matrix[0][1] = 8;
  correct_res.matrix[1][0] = 4;
  correct_res.matrix[1][1] = 10;

  err = s21_sub_matrix(&M1, &M2, &result);
  printf("err == SUCCESS = %d\n", err == OK);

  s21_print_mtx(&result);
  s21_print_mtx(&correct_res);

  err = s21_eq_matrix(&result, &correct_res);
  printf("err == SUCCESS = %d\n", err == SUCCESS);

  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);

  return 0;
}

// printf("err == SUCCESS = %d\n", err == SUCCESS);
// printf("err == FAILURE = %d\n", err == FAILURE);