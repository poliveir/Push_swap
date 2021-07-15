void    show_lists(t_list **stack_a, t_list **stack_b)
{
	t_list  *temp;
         int             *ptr;

         temp = *stack_a;
         printf("-------------PILHA A-------------\n");
         while (temp)
	 {
                 ptr = (int *)temp->content;
                 printf("%d  |  ", *ptr);
                 temp = temp->next;
         }
         printf("\n");
         temp = *stack_b;
         printf("-------------PILHA B-------------\n");
         while (temp)
         {
                 ptr = (int *)temp->content;
                 printf("%d  |  ", *ptr);
                 temp = temp->next;
         }
         printf("\n");
}
