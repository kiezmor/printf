char	*ft_itoa(int32_t n, char *buffer, int base)
{
	int		i;
	char	str[4 * 8 + 2];
	int32_t	tmp;

	tmp = 0;

	ft_bzero(str, 4 * 8 + 2);
	i = 0;
	while (n / base)
	{
		tmp = (n % base > 0) ? (n % base) : -(n % base);
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		n = n / base;
	}
	tmp = (n % base > 0) ? (n % base) : (-n % base);
	str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)(s++) = 0;
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strrev(char *s)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
