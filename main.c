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

char cells[ARRAY_SIZE] = { 0 };
char input[INPUT_SIZE] = { 0 };

unsigned pointer = 0;
unsigned num_parens = 0;
unsigned input_index = 0;

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

void increment_pointer()
{
    ++pointer;
}

void decrement_pointer()
{
    --pointer;
}

void increment_value()
{
    ++cells[pointer];
}

void decrement_value()
{
    --cells[pointer];
}

void output_value()
{
    putchar(cells[pointer]);
}

void input_value()
{
    cells[pointer] = getchar();
}

void begin_loop()
{
    num_parens = 1;
    if (cells[pointer] == 0)
    {
        do
        {
            ++input_index;
            if (input[input_index] == BEGIN_LOOP)
            {
                ++num_parens;
            }
            else if (input[input_index] == END_LOOP)
            {
                --num_parens;
            }
        }
        while (num_parens != 0);
    }
}

void end_loop()
{
    num_parens = 0;
    do
    {
        if (input[input_index] == BEGIN_LOOP)
        {
            ++num_parens;
        }
        else if (input[input_index] == END_LOOP)
        {
            --num_parens;
        }
        --input_index;
    }
    while (num_parens != 0);
}

int main()
{
    print_intro_message();
    read_input(input);

    for (input_index = 0; input[input_index] != '\0'; ++input_index)
    {
        switch (input[input_index])
        {
            case INCREMENT_POINTER:
                increment_pointer();
                break;
            case DECREMENT_POINTER:
                decrement_pointer();
                break;
            case INCREMENT_VALUE:
                increment_value();
                break;
            case DECREMENT_VALUE:
                decrement_value();
                break;
            case OUTPUT_VALUE:
                output_value();
                break;
            case INPUT_VALUE:
                input_value();
                break;
            case BEGIN_LOOP:
                begin_loop();
                break;
            case END_LOOP:
                end_loop();
                break;
        }
    }

    return 0;
}
