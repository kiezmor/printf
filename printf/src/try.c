#include "ft_printf.h"

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

/*-------------------------------------*/

static void		normee(int c, char *tab)
{
	int	len;

	len = 0;
	tab[len++] = 0xFC | (c >> 30);
	tab[len++] = 0x80 | ((c >> 24) & 0x3F);
	tab[len++] = 0x80 | ((c >> 18) & 0x3F);
	tab[len++] = 0x80 | ((c >> 12) & 0x3F);
	tab[len++] = 0x80 | ((c >> 6) & 0x3F);
	tab[len++] = 0x80 | (c & 0x3F);
	tab[len] = 0;
}

static int		t_4byte_char(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x200000)
	{
		tab[len++] = 0xF0 | (c >> 18);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x4000000)
	{
		tab[len++] = 0xF8 | (c >> 24);
		tab[len++] = 0x80 | ((c >> 18) & 0x3F);
		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else
		norme(c, tab);
	tab[len] = 0;
	return (ft_ptf_buff(tab, BUF_WRITE));
}

static int		t_2byte_char(int c, char *tab)
{
	int	len;

	len = 0;
	if (c < 0x80)
		tab[len++] = c;
	else if (c < 0x800)
	{
		tab[len++] = 0xC0 | (c >> 6);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x10000)
	{
		tab[len++] = 0xE0 | (c >> 12);
		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
		tab[len++] = 0x80 | (c & 0x3F);
	}
	tab[len] = 0;
	if (!tab[0])
		return (ft_ptf_buff(tab, BUF_CHAR));
	else
		return (ft_ptf_buff(tab, BUF_WRITE));
}

int			ft_wchar(int c)
{
	char	tab[10];

	if (c < 0x200000)
	{
		printf("%i\n", 2);
		return (t_2byte_char(c, tab));
	}
	else
	{
		printf("%i\n", 4);
		return (t_4byte_char(c, tab));
	}
}
