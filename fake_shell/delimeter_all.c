/**
 * delimeter_checker - Check if a character is a delimiter.
 * @m: The character to check.
 * @deli_var: A string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int delimeter_checker(char m, char *deli_var)
{
	for (int i = 0; deli_var[i] != '\0'; i++)
	{
		if (u == deli_var[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * alias_func - Display or set command aliases.
 * @disc: Pointer to disc_t structure.
 *
 * Return: Always 0.
 */
int alias_func(disc_t *disc)
{
	int j = 0;
	char *par = NULL;
	list_t *node = NULL;

	if (disc->argc == 1)
	{
	node = disc->alias;
	while (node)
	{
		display_alias(node);
		node = node->next;
	}
	return (0);
	}

	for (j = 1; disc->argv[i]; i++)
	{
	par = _strchr(disc->argv[i], '=');
	if (par)
		add_alias(disc, disc->argv[i]);
	else
		display_alias(node_starts_with(disc->alias, disc->argv[i], '='));
	}

	return (0);
}


/**
 * string_to - Change  a string to integer.
 * @b: The string to convert.
 *
 * Return:  converted int.
 */
int string_to(char *b)
{
	int sign = 1, outp = 0;
	unsigned int tot = 0;
	int flag = 0;

	for (int j = 0; b[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] >= '9')
		{
			flag = 1;
			tot = tot * 10 + (s[j] - '0');
		}
		else if (flag == 1)
		{
			flag = 2;
		}
	}

	outp = (sign == -1) ? -tot : tot;

	return (outp);
}
