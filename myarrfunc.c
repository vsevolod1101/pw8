#include "myarrfunc.h"


void print_menu(void) {
    printf(
        "%c Задать размер массива\n"
        "%c Заполнить массив\n"
        "%c Представление массива (значения, адреса)\n"
        "%c Определение индексов элементов, значения которых ниже заданного k\n"
        "%c Определение количества элементов массива по значению выше введенного k\n"
        "%c Определение суммы элементов массива по значению ниже введенного k\n"
        "%c Выход\n",
        O_SET_ARR_SIZE,
        O_FILL_ARR, 
        O_PRINT_ARR,
        O_I_LT_K,
        O_Q_MT_K,
        O_S_LT_K,
        O_QUIT
    );
}

err_t get_select(option_t *select) {
    int rc = scanf("%c", select);
    if (rc == 0) return E_INPUT;
    if (rc == EOF) *select = O_QUIT;
    return E_NO;
}

void print_err(err_t ec) {
    switch (ec) {
        case E_INPUT:
            puts("E_INPUT");
            break;
        case E_INPUT_NOT_EXIST_OPTION:
            puts("E_INPUT_NOT_EXIST_OPTION");
            break;
        case E_ARR_NO_SET:
            puts("E_ARR_NO_SET");
            break;
        case E_ARR_SIZE_NO_SET:
            puts("E_ARR_SIZE_NO_SET");
            break;
        case E_FORCE_EXIT:
            puts("E_FORCE_EXIT");
            break;
        case E_INPUT_ARR_SIZE:
            puts("E_INPUT_ARR_SIZE");
            break;
    }
}

void cleanup_stdin_line(void) {
    int c;
    while (((c = getchar()) != '\n') && (c != EOF)) continue;
}

err_t exec_option(option_t *select, int *array, size_t *arr_size) {
    err_t erc = E_NO;
    switch (*select) {
        case O_SET_ARR_SIZE:
            erc = set_arr_size(arr_size);
            cleanup_stdin_line();
            break;
        case O_FILL_ARR:
            erc = fill_arr(array, *arr_size);
            cleanup_stdin_line();
            break;
        case O_PRINT_ARR:
            erc = print_arr(array, *arr_size);
            break;
        case O_I_LT_K:
            erc = index_lessthan_k(array, *arr_size);
            cleanup_stdin_line();
            break;
        case O_Q_MT_K:
            erc = quantity_morethan_k(array, *arr_size);
            cleanup_stdin_line();
            break;
        case O_S_LT_K:
            erc = sum_lessthan_k(array, *arr_size);
            cleanup_stdin_line();
            break;
        case O_QUIT:
            break;
        default:
            return E_INPUT_NOT_EXIST_OPTION;
    }
    return erc;
}

err_t set_arr_size(size_t *arr_size) {
    err_t erc = E_NO;
    printf("array[%d<?(int)<%d]\n", LIM_MIN_ARR_SIZE, LIM_MAX_ARR_SIZE);
    size_t old_arr_size = *arr_size;
    int rc = scanf("%d", arr_size);
    if (rc == 0) return E_INPUT;
    if (rc == EOF) return E_FORCE_EXIT;
    erc = check_arr_size(*arr_size);
    if (erc != E_NO) 
        *arr_size = old_arr_size;
    return erc;
}


err_t check_arr_size(size_t arr_size) {
    return (arr_size > LIM_MIN_ARR_SIZE && arr_size < LIM_MAX_ARR_SIZE) ? E_NO : E_INPUT_ARR_SIZE;
}

err_t fill_arr(int *array, size_t arr_size) {
    int elem;
    err_t erc = E_NO;
    for (int i = 0; i < arr_size; ++i) {
        printf("array[%d] = ?(int)\n", i);
        erc = get_arr_elem(&elem);
        if (erc != E_NO) return erc;
        array[i] = elem;
    }
    return erc;
}

err_t get_arr_elem(int *elem) {
    int rc = scanf("%d", elem);
    if (rc == 0) return E_INPUT;
    if (rc == EOF) return E_FORCE_EXIT;
    return E_NO;
}

err_t print_arr(int *array, size_t arr_size) {
    for (int i = 0; i < arr_size; ++i) {
        printf("array[%d] = %d; %p\n", i, array[i], &(array[i]));
    }
    return E_NO;
}

err_t index_lessthan_k(int *array, size_t arr_size) {
    int k;
    err_t erc = E_NO;
    erc = get_k(&k);
    if (erc != E_NO)
        return erc;
    if (array[0] < k) 
        printf(" %d", 0);
    for(int i = 1; i < arr_size; ++i) {
        if (array[i] < k) 
            printf(" %d", i);
    }
    putchar('\n');
    return erc;
}

err_t quantity_morethan_k(int *array, size_t arr_size) {
    int k;
    err_t erc = E_NO;
    erc = get_k(&k);
    if (erc != E_NO)
        return erc;
    int q = 0;
    for(int i = 0; i < arr_size; ++i) {
        if (array[i] > k)
            q += 1;
    }
    printf("%d\n", q);
    return erc;
}

err_t sum_lessthan_k(int *array, size_t arr_size) {
    int k;
    err_t erc = E_NO;
    erc = get_k(&k);
    if (erc != E_NO)
        return erc;
    int sum = 0;
    for(int i = 0; i < arr_size; ++i) {
        if (array[i] < k) 
            sum += array[i];
    }
    printf("%d\n", sum);
    return erc;
}

err_t get_k(int *k) {
    int rc = scanf("%d", k);
    if (rc == 0) return E_INPUT;
    if (rc == EOF) return E_FORCE_EXIT;
    return E_NO;
}