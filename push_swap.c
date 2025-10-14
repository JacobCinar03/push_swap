#include <stdlib.h>
#include <unistd.h>


typedef struct s_node
{
	int				value; 
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/*
	(top)
1.  VALUE
	İNDEX
	NEXT
	PREV
	
	(top->next)
2. VALUE
	İNDEX
	NEXT
	PREV

	(top->next->next)
3. VALUE
	İNDEX
	NEXT
	PREV


	x = top
	y = top->next

	x->next = y->next
	y->next = x
	x->prev = y
	y->prev = bottom
	top = y

*/ 

void swap(t_stack *stack) //swap şu an çalışıyor
{
	//int temp;
	if (stack->size < 2)
		return;
	t_node *first = stack->top; // İlk düğümü değişkene atadık
	t_node *second = stack->top->next; // İkinci düğümü değişkene atadık
	first->next = second->next; // 1.
	second->next = first;  // 2. aralarındaki bağlantıyı değiştirdik
	first->prev = second; // 1.
	if (stack->size == 2)
		stack->bottom = first;
	second->prev = stack->bottom;// 2. aralarındaki bağlantıyı değişitirdik
	stack->bottom->next = second;
	stack->top = second; 
	first->next->prev = first; // 2 next 3 prev 2	
}
//rotate: top
void rotate(t_stack *stack)
{
	if (stack->size < 2)
		return;
	t_node *first = stack->top;
	t_node *second = stack->top->next;
	stack->top = second;
}

int main(void)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);

	
	
}