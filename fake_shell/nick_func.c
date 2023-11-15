
/**
 * add_alias - add or updat alias in the inform.
 * @disc: The information struct.
 * @str: alia to set or update.
 * Return: 0 or 1.
 */
int add_alias(disc_t *disc, char *str)
{
	char *equals_position;

	equals_position = _strchr(str, '=');

	if (!equals_position)
		return (1);

	if (!*++equals_position)
		return (remove_alias(disc, str));

	remove_alias(disc, str);

	return (add_node_end(&(disc->alias), str, 0) == NULL);
}

/**
 * list_env - Environment list in the information struct.
 * @disc: information struct.
 * silent and emech
 * Return: 0 or 1.
 */
int list_env(disc_t *disc)
{
	list_t *node = NULL;

	for (size_t j = 0; environ[j]; j++)
	{
		if (add_node_end(&node, environ[j], 0) == NULL)
		{
			printf("Handle memory allocation failure\n")
			return (1);
		}
	}

	disc->env = node;
	return (0);
}


/**
 * str_puts - Prints a string to standard error.
 * @str: The string to print.
 */
void str_puts(char *str)
{
	if (str == NULL)
	return;

	for (int i = 0; str[i] != '\0'; i++)
	{
		_eputchar(str[i]);
	}
}
