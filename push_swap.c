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

//rotate: yer değişmiyor sadece top bottom ygösterilen
void rotate(t_stack *stack)
{
	if (stack->size < 2)
		return;
	t_node *first = stack->top;
	t_node *second = stack->top->next;
	stack->top = second;
	stack->bottom = first;
}

//rrotate: yer değişmiyor sadece top bottom gösterilen
void rrotate(t_stack *stack)
{
	if (stack->size < 2)
		return;
	t_node *first = stack->bottom;
	t_node *second = stack->bottom->prev;
	stack->top = first;
	stack->bottom = second;
}

//push verilen stack_a dan stack_b'ye ilk düğümü taşıyor
void push(t_stack *stack_a, t_stack *stack_b)
{
	if(stack_a->size < 1)
		return ;
	else if(stack_a->size == 1)
	
	t_node *first = stack_a->top; // stack_a atılacak node ele alındı
	stack_a->top = first->next; // top 2. node verildi
	stack_a->top->prev = stack_a->bottom; // topdan bottoma bağlantı
	stack_a->bottom->next = stack_a->top; // bottomdan topa bağlantı
	// stack_a düzeldilti sıra stack_b'de
	t_node *second = stack_b->top; // stack_b baş node'u alındı
	stack_b->top = first; // top first olarak ayarlandı
	second->prev = first; // 2. nodedan firste bağlantı prev kuruldu
	stack_b->bottom->next = first; // bottomdan topa nağlantı ayarlandı
	first->next = second; // firsten gelen gidiş bağlantısı 
	first->prev = stack_b->bottom; //fitsten gelen geliş bağlantısı 

	stack_a->size--;
	stack_b->size++;
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