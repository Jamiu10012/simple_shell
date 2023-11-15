/**
 * inter_mode - Returns true if the shell is in interactive mode.
 * @disc: Struct address.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int inter_mode(info_t *disc)
{
	if (isatty(STDIN_FILENO) && disc->readfd <= 2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


/**
 * cd_func - Change the current working directory.
 * @disc: Pointer to disc_t structure.
 *
 * Return: Always 0.
 */
int cd_func(disc_t *disc)
{
	char *current_dir, *target_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("TODO: >>getcwd that fail here<<\n");
	if (!disc->argv[1])
	{
		target_dir = _getenv(disc, "HOME=");
		if (!target_dir)
			chdir_ret =
				chdir((target_dir = _getenv(disc, "PWD=")) ? target_dir : "/");
		else
			chdir_ret = chdir(target_dir);
	}
	else if (_strcmp(disc->argv[1], "-") == 0)
	{
		if (!_getenv(disc, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(disc, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((target_dir = _getenv(disc, "OLDPWD=")) ? target_dir : "/");
	}
	else
		chdir_ret = chdir(disc->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(disc, "can't cd to ");
		_eputs(disc->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(disc, "OLDPWD", _getenv(disc, "PWD="));
		_setenv(disc, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help_func - The curr directory of the process
 * @disc: The Structur Used to maintain
 *  Return: 0 Always
 */

int help_func(disc_t *disc)
{
	char **arg_array = disc->argv;

	_puts("The 'help' command called, but the function not implemented.\n");

	if (0)
		_puts(*arg_array);

	return (0);
}

/**
 * remove_alias - Unsets an alias in the information struct.
 * @disc: Pointer to the information struct.
 * @str: The alias string to unset.
 * Return: 0 or 1.
 */

int remove_alias(disc_t *disc, char *str)
{
	char *equals_position;
	char original_char;
	int result;

	equals_position = _strchr(str, '=');

	if (!equals_position)
		return (1);

	original_char = *equals_position;
	*equals_position = '\0';

	result = delete_node_at_index(&(disc->alias),
		get_node_index(disc->alias, node_starts_with(disc->alias, str, -1)));

	*equals_position = original_char;

	return (result);
}
