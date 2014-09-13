#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE              30000
#define INPUT_SIZE              1024

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
    puts("Input your brainfuck code below.");
}

void read_input(char input[])
{
    unsigned current_char_index = 0;
    char current_char = EOF;
    while ((current_char = getchar()) != EOF)
    {
        if (current_char_index == INPUT_SIZE - 1)
        {
            puts("Error: Maximum input size exceeded.");
            input[current_char_index] = '\0';
        }
        else
        {
            input[current_char_index++] = current_char;
        }
    }
}

int main()
{
    char cells[ARRAY_SIZE] = { 0 };
    char input[INPUT_SIZE] = { 0 };

    unsigned pointer = 0;

    print_intro_message();
    read_input(input);

    bool in_loop = false;
    unsigned loop_start = 0;

    for (int i = 0; input[i] != '\0'; ++i)
    {
        switch (input[i])
        {
            case INCREMENT_POINTER:
                ++pointer;
                break;
            case DECREMENT_POINTER:
                --pointer;
                break;
            case INCREMENT_VALUE:
                ++cells[pointer];
                break;
            case DECREMENT_VALUE:
                --cells[pointer];
                break;
            case OUTPUT_VALUE:
                putchar(cells[pointer]);
                break;
            case INPUT_VALUE:
                cells[pointer] = getchar();
                break;

            /* NOTE: Nested looping is not supported yet. */
            case BEGIN_LOOP:
                loop_start = i;
                break;
            case END_LOOP:
                i = (cells[pointer] != 0) ? loop_start : i;
                break;
        }
    }

    return 0;
}
