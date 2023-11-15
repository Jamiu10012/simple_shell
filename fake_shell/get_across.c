/**
 * find_environment - Retrieves the value of an environment variable.
 * @disc: Pointer to the information struct.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: NULL.
 */

char *find_environment(disc_t *disc, const char *name)
{
	list_t *node = disc->env;

	while (node)
	{
		char *value = starts_with(node->str, name);

		if (value && *value)
			return (value);

		node = node->next;
	}

	return (NULL);
}
