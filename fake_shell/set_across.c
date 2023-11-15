/**
 * own_set_env - Sets an environment variable.
 * @disc: Pointer to the information struct.
 * sil
 * Return: 0 or 1.
 */
int own_set_env(disc_t *disc)
{
	if (disc->argc != 3)
	{
		str_puts("Incorrect number of arguments\n");
		return (1);
	}

	int success = _setenv(disc, disc->argv[1], disc->argv[2]);

	return (success ? 0 : 1);
}


/**
 * char_put - Writes a character to standard error.
 * @m: The character to write.
 *
 * Return: 1 on success, -1 on failure.
 */
int char_put(char m)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (m == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
	ssize_t bytes_written = write(2, buf, j);

	if (bytes_written == -1)
		return (-1);

		j = 0;
	}

	if (m != BUF_FLUSH)
		buff[j++] = m;

	return (1);
}
