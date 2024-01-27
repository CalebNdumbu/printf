/**
 * _strlen - Custom strlen function
 * @str: String
 *
 * Return: Length of the string
 */
int _strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;

    return len;
}