#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main()
{
	void *p;
	int i;
	size_t size_of_the_chunk;
	size_t size_of_the_previous_chunk;
	void *chunks[1025];

	for(i=0; i<1025; i++)
	{
		p = malloc(1024 * (i+1));
		chunks[i] = (void *)((char *)p - 0x10);
		printf("%p\n",p);
	}

	free((char*)(chunks[3]) + 0x10);
	free((char*)(chunks[7]) + 0x10);
	for(i = 0; i < 1025 ; i++)
	{
		p = chunks[i];

		size_of_the_chunk = *((size_t *)((char*)p +8))-1;
		printf("malloc[%d]: %p, size = %li \n",
			i,p,size_of_the_chunk);
	}
	return (EXIT_SUCCESS);
}

