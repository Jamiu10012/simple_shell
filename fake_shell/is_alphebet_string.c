/**
 *alphabetic - checks for alphabetic character
 *@m: The user input
 *em-sil
 *Return: 1 || 0.
 */

int alphabetic(int m)
{
	int isalp = ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z')) ? 1 : 0;

	return (isalp);
}


/**
 * custom_exit - exit the prompt
 * @disc: discription info
 *  Return: success or fail
 */

int custom_exit(disc_t *disc)
{
	int exitValue;

	if (disc->argv[1])
	{
	exitValue = _erratoi(disc->argv[1]);

	if (exitValue == -1)
	{
	disc->status = 2;
	print_error(disc, "wrong input: ");
		str_puts(disc->argv[1]);
		_eputchar('\n');
		return (1);
	}

	disc->err_num = exitValue;
	return (-2);
	}

	disc->err_num = -1;
	return (-2);
}

/**
 * hist_func - The command hist.
 * @disc: Point to inform struct.
 * Return: Always 0.
 */
int hist_func(disc_t *disc)
{
	if (disc->history != NULL)
	{
		print_list(disc->history);
	}
	else
	{
		printf("Command history is empty.\n");
	}

	return (0);
}

/**
 * own_unset_env - Unsets environment variables.
 * @disc: Pointer to the information struct.
 *
 * Return: 0 on success, 1 on failure.
 */
int own_unset_env(disc_t *disc)
{
	if (disc->argc == 1)
	{
		str_puts("Too few arguments.\n");
		return (1);
	}

	for (int i = 1; i < disc->argc; i++)
	{
		if (!_unsetenv(disc, disc->argv[i]))
		{
			return (1);
		}
	}

	return (0);
}
