#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    int value;
} Variable;

Variable variables[100];
int var_count = 0;

int get_variable_value(char *name)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0)
        {
            return variables[i].value;
        }
    }
    return 0;
}

void set_variable_value(char *name, int value)
{
    for (int i = 0; i < var_count; i++)
    {
        if (strcmp(variables[i].name, name) == 0)
        {
            variables[i].value = value;
            return;
        }
    }
    strcpy(variables[var_count].name, name);
    variables[var_count].value = value;
    var_count++;
}

void execute_line(char *line)
{
    char var_name[100];
    char op;
    int value;
    if (sscanf(line, "%s = %d", var_name, &value) == 2)
    {
        set_variable_value(var_name, value);
    }
    else if (sscanf(line, "%s = %s %c %d", var_name, var_name, &op, &value) == 4)
    {
        int var_value = get_variable_value(var_name);
        if (op == '+')
        {
            set_variable_value(var_name, var_value + value);
        }
        else if (op == '-')
        {
            set_variable_value(var_name, var_value - value);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <archivo.nieto>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *ext = strrchr(filename, '.');
    if (!ext || strcmp(ext, ".nieto") != 0)
    {
        fprintf(stderr, "Error: El archivo debe tener la extensión .nieto\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        execute_line(line);
    }

    fclose(file);
    return 0;
}
