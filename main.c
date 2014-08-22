#include <stdio.h>
#include <stdlib.h>

const unsigned ARRAY_SIZE     = 30000;
const char INITIAL_CELL_VALUE = 0;

const char INCREMENT_POINTER = '>';
const char DECREMENT_POINTER = '<';
const char INCREMENT_VALUE   = '+';
const char DECREMENT_VALUE   = '-';
const char OUTPUT_VALUE      = '.';
const char INPUT_VALUE       = ',';
const char BEGIN_LOOP        = '[';
const char END_LOOP          = ']';

void print_intro_message()
{
    puts("Input your brainfuck code below and hit the enter key when done:");
}

void initialize_cells(char cells[])
{
    for (unsigned i = 0; i < ARRAY_SIZE; ++i)
    {
        cells[i] = INITIAL_CELL_VALUE;
    }
}

void parse_input(char cells[])
{
    char current_char = EOF;
    while ((current_char = getchar()) != EOF)
    {
    }
}

int main()
{
    char cells[ARRAY_SIZE];

    print_intro_message();
    initialize_cells(cells);
    parse_input(cells);

    return EXIT_SUCCESS;
}
