#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{	
	int	x;
	pthread_mutex_t	lock;
}	t_data;

void	increment(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	pthread_mutex_lock(&(data->lock));
	data->x++;
	pthread_mutex_unlock(&(data->lock));
}

void	*routine1(void *arg)
{
	printf("From Thread 1\n");
	for (int i = 0; i < 1000000; i++)
		increment(arg);
}

void	*routine2(void *arg)
{
	printf("From Thread 2\n");
	for (int i = 0; i < 1000000; i++)
		increment(arg);
}

int	main(void)
{
	t_data	*data;
	pthread_t	p1;
	pthread_t	p2;

	data = malloc(sizeof(t_data));
	data->x = 0;
	if (pthread_mutex_init(&(data->lock), NULL) < 0)
	{
		printf("mutex error\n");
		return (1);
	}
	printf("%d\n", data->x);
	pthread_create(&p1, NULL, routine1, (void *)data);
	pthread_create(&p2, NULL, routine2, (void *)data);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("x = %d\n", data->x);
	pthread_mutex_destroy(&(data->lock));
}