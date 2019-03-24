#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
 
#define custom_count 2
#define produce_count 3

// g++ test.cpp -lpthread  编译命令，生产者和消费者模式
int nNum, nLoop;
int g_count = 0;
 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 
void *consume(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while (g_count == 0)
		{
			printf("consume is waiting: %lu\n", pthread_self());
			pthread_cond_wait(&cond, &mutex);
			//pthread_mutex_unlock(&mutex);
		}
		printf("consume is %lu, g_count is %d\n", pthread_self(), g_count);
		g_count--;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}
 
void *produce(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (g_count >= 10)
		{
			printf("产品太多了，需要休眠1秒\n");
			pthread_mutex_unlock(&mutex);
			sleep(1);
			continue;
		}
		//不需要解锁再上锁，大于10，会解锁，会continue，不会执行下面语句
		printf("start produce the product\n");
		g_count++;
		printf("produce is %lu, g_count is %d\n", pthread_self(), g_count);
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_exit(NULL);
}
 
int main()
{
	int i = 0;
	pthread_t tidCustom[custom_count];
	pthread_t tidProduce[produce_count];
 
	//创建消费者线程
	for (i = 0; i < custom_count; i++)
	{
		pthread_create(&tidCustom[i], NULL, consume, NULL);
	}
	//sleep(3);
	//创建生产者线程
	for (i = 0; i < produce_count; i++)
	{
		pthread_create(&tidProduce[i], NULL, produce, NULL);
	}
	
	//等待消费者线程
	for (i = 0; i < custom_count; i++)
	{
		pthread_join(tidCustom[i], NULL);
	}
 
	//等待生产者线程
	for (i = 0; i < produce_count; i++)
	{
		pthread_join(tidProduce[i], NULL);
	}
	printf("parent exit\n");
	exit(0);
}

