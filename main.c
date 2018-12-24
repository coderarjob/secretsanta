#include<stdio.h>
#include<stdlib.h> //for calloc
#include"ss.h"

static void makeGraph(int *graph, int nv);
static int *graph; /* represents a cylic graph. Each element is a vertex. 
					  Vertex v(i) has edge that leaves v(i) and enters v(i+1),
					  and so on.*/

int main()
{
	char **names;
	int length;

	length = readNames(&names);
	printf("Names count: %d\n", length);

	/*
		length+1, because, the graph vector must have palce for the last
		element. The last element is always = first element, as this graph
		vector represents a cyclic graph.
	*/
	graph = calloc(length+1,sizeof(int)); 

	/*
		GRAPH: LOOKS LIKE THIS IN MEMORY

		[0][1][2]...[length-1][length]
		 x  y  z        k        x
		 where x,y,z and k are indexed to names array (represents names)
	*/
	makeGraph(graph,length);

	/*
		As the top structure shows, there is always an item at index 'length'
		that is no matter what the length is, there is always one more. And
		thus if we graph+1 will always point to a valid memory, as long we
		itterate from o to length -1.

		index	   index+1		isExists
		-----      ---------   ---------
		0		   1			true
		1          2            true
		length-1   length       true
	*/
	for(int i = 0; i < length;i++,graph++){
		printf("%s\t->\t%s\n", names[*graph], names[*(graph+1)]);
	}
}

static void makeGraph(int *graph, int nv)
{
	int index;
	int *filled = calloc(nv,sizeof(int));
	random_init();
	
	for(int i = 0; i < nv; i++){
		do{
			index = getRandom() % nv;
		}while(filled[index] != 0);
		filled[index] = 1;
		graph[i] = index;
	}
	// because this is a cyclic graph, the last element is equal to the
	// 1st element in the vector.
	graph[nv] = graph[0];

	free(filled);
}

