#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "selsort.h"


int main(int argc, char** argv){
    struct node* head = NULL;
    struct node* tail = NULL;
	if (argc == 1)	{
		usage(argv[0]);
		return 0;
	}
	int lengthArray = argc;
	int startArray = 1;
	int sort = 0;
	if (!strcmp(argv[1],"-s"))	{
		if (argc == 2)	{
			usage(argv[0]);
			return 0;
		}
		startArray++;
		sort++;
	}
	lengthArray--;	
	tail = new_unconnected_node(atoi(argv[startArray]));
	head = tail;
	for (int i = startArray; i <= lengthArray-1; i++)	{
		connect(tail, new_unconnected_node(atoi(argv[i+1])));
		tail=tail->next;
	}
	print_list(head);
	print_list_reversed(tail);
	if (sort)	{
		struct node* shead = sort_list(head);
		struct node* topshead = shead;
		printf("Srtd:	[ ");
		while(!is_empty(shead))	{
			printf("%d ", shead->value);
			shead = shead->next;
		}
		printf("]\n");
		free_list(topshead);
	}
	else	{
		free_list(head);
	}
	return 0;
}

void usage(char* cmdName)	{
	printf("Usage: %s [-s] <space separated list of numbers>\n", cmdName);
}

bool is_empty(struct node* head)	{
	return (head == NULL);
}

void connect(struct node* prev, struct node* next)	{
	if (!is_empty(prev) && !is_empty(next))	{
		prev->next = next;
		next->prev = prev;
	}
}

void unlink(struct node* n)	{
	if (n!=NULL)	{
		if ((n->next!=NULL) && (n->prev!=NULL))	{
			n->prev->next = n->next;
			n->next->prev = n->prev;
		}
		if ((n->next==NULL) && (n->prev!=NULL))	{
			n->prev->next = NULL;	
		}
		if ((n->next!=NULL) && (n->prev==NULL))	{
			n->next->prev = NULL;
		}
	}
}

struct node* new_unconnected_node(int value)	{
	struct node* n = malloc(sizeof(struct node));
	n->value = value;
	n->prev = NULL;
	n->next = NULL;
	return n; 
}

void print_list(struct node* head)	{
	printf("Frwd:	[ ");
	while(!is_empty(head))	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("]\n");
}

void print_list_reversed(struct node* tail)	{
	printf("Rrsd:	[ ");
		while(!is_empty(tail))	{
			printf("%d ", tail->value);
			tail = tail->prev;
		}
	printf("]\n");
}

struct node* find_minimum(struct node* head)	{
	int min = head->value;
	struct node* ahead = head;
	while(!is_empty(head))	{
		if (head->value < min)	{
			min = head->value;
		}
		head = head->next;
	}
	while(!is_empty(ahead))	{
		if (ahead->value == min)	{
			return ahead;
		}
		ahead = ahead->next;
	}
	return head;
}

struct node* sort_list(struct node* head)	{
	if (is_empty(head))	{
		return head;
	}
	struct node* shead = NULL;
    struct node* stail = NULL;
	struct node* tophead = NULL;
	while (!is_empty(head))	{
		struct node* min = find_minimum(head);
		if (min == head) {
          head = head->next;
        }
		unlink(min);
		if ((shead == NULL) && (stail == NULL)){
            shead = min;
			stail = min;
			tophead = min;
        }
		else	{
			connect(shead, min);
			shead=shead->next;
			stail = min;
		}
	}
	
	return tophead;
}

void free_list(struct node* head) {
    while (head != NULL) {
        struct node* current = head;
        head = head->next;
        free(current);
    }
}
