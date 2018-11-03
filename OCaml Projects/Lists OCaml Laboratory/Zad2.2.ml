let podzielPoN(lista, n)=
	let rec helper(lista1, wynik1, wynik2, n, idx)=
	match(lista1, n) with
	([],_)->(List.rev wynik1, List.rev wynik2)
	|(h::t,0)->helper(t, h::wynik1, wynik2, n-1, idx)
	|(h::t,n)->helper(t, wynik1, h::wynik2, n-1, idx)
in helper(lista, [], [], n, 0);;

podzielPoN([1;3;5;7;9], -6);;