#include <stdlib.h>
#include <stdio.h>

typedef enum Error {
    E_NO,
    E_INPUT,
    E_INPUT_NOT_EXIST_OPTION,
    E_FORCE_EXIT,
    E_INPUT_ARR_SIZE,
    E_ARR_SIZE_NO_SET,
    E_ARR_NO_SET,
} err_t;
typedef enum Option {
    O_SET_ARR_SIZE = 'a',
    O_FILL_ARR,
    O_PRINT_ARR,
    O_I_LT_K,
    O_Q_MT_K,
    O_S_LT_K,
    O_QUIT
} option_t;

// limits
#define LIM_MAX_ARR_SIZE 10
#define LIM_MIN_ARR_SIZE 0
#define DEFAULT_ARR_SIZE ((LIM_MAX_ARR_SIZE + LIM_MIN_ARR_SIZE)/2)

void print_menu(void);
void print_err(err_t ec);
void cleanup_stdin_line(void);
err_t get_select(option_t *); 
err_t exec_option(option_t *, int *, size_t *);
err_t set_arr_size(size_t *);
err_t get_arr_size(size_t *);
err_t check_arr_size(size_t);
err_t fill_arr(int *, size_t);
err_t print_arr(int *, size_t);
err_t get_arr_elem(int *);
err_t index_lessthan_k(int *, size_t);
err_t get_k(int *);
err_t quantity_morethan_k(int *, size_t);
err_t sum_lessthan_k(int *, size_t);