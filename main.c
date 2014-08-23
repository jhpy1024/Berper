#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE              30000
#define INITIAL_CELL_VALUE      0

#define INCREMENT_POINTER       '>'
#define DECREMENT_POINTER       '<'
#define INCREMENT_VALUE         '+'
#define DECREMENT_VALUE         '-'
#define OUTPUT_VALUE            '.'
#define INPUT_VALUE             ','
#define BEGIN_LOOP              '['
#define END_LOOP                ']'

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
