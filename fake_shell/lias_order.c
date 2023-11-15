/**
 * display_alias - Display alias.
 * @node: Node containing the alias.
 * Return: 0 or 1.
 */
int display_alias(list_t *node)
{
	if (node == NULL)
		return (1);

	char *equals_position = _strchr(node->str, '=');

	if (!equals_position)
		return (1);

	for (char *char_ptr = node->str; char_ptr <= equals_position; char_ptr++)
		_putchar(*char_ptr);

	_putchar('\'');
	_puts(equals_position + 1);
	_puts("'\n");

	return (0);
}

/**
 * env_print - Environment list.
 * @disc: Struct.
 * silent and mount
 * Return: 0 or  1.
 */
int env_print(disc_t *disc)
{
	if (disc->env == NULL)
	{
		printf("Environment list is empty.\n");
		return (1);
	}

	print_list_str(disc->env);

	return (0);
}
