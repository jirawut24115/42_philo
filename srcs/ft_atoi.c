
static	int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}
