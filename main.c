#include "myarrfunc.h"

int main(void) {
    // init
    err_t erc = E_NO;
    option_t select = O_PRINT_ARR;
    int array[LIM_MAX_ARR_SIZE] = {0};
    size_t arr_size = DEFAULT_ARR_SIZE;
    // mainloop
    while (select != O_QUIT) {
        // menu
        print_menu();
        // input
        erc = get_select(&select);
        cleanup_stdin_line();
        if (erc != E_NO) {
            print_err(erc);
            continue;
        }
        // business
        erc = exec_option(&select, array, &arr_size);
        if (erc == E_FORCE_EXIT) {
            break;
        }
        if (erc != E_NO) {
            print_err(erc);
        }
    }
    // termination
    return EXIT_SUCCESS;
}