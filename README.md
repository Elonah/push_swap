

sortir un algrorithme qui trie des listes de nombres qvec des instruction reduites

Pour 3 values = entre 2 / 3 opérations
Pour 5 values = max 12
Pour 100 values = barème de 1 à 5
  - moins de 700: 5
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1
Pour 500 values = barème de 1 à 5
  - moins de 5500: 5
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1


pour entre 3 et 5 : un melange entre le tri par insertion et le tri par selection
pour les 100 et 500 : radix sort, quicksort, merge sort, shell tri


restriction
-----

Tu a un set d'instruction qui opere comme une stack
sa
sb
ra
rb
rra
rrb

en plus d'operation d'opmisation qui sont :

ss
rr
rrr

creer une interface avec ces operation


ft_swap(stack *stack)
{
	je vais swap des trucs;
}

ft_sa(stack *ma_stack_a)
{
	ft_swap(ma_stack_a)
	ft_putendl("sa");
}

ft_sb(stack *ma_stack_b)
{
	ft_swap(ma_stack_b)
	ft_put endl("sb");
}


ft_insert(stack *a, stack *b, pos a, pos b)

ft_sa(stack *a) > operer sur la stack et output la SA
ft_sb(stack *b) > pareil ma


Optimisation
------
Pour passer en dessous du bareme, mixer les tris, te pencher sur les operations d'optimation, tester plusieurs tri



/*


ETAPE 1
  return (index) ft_min(pile);
  return (index) ft_max(pile);
  return (index) ft_sup(pile, valeur);



