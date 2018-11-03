let nTy(lista, n)=
	if lista= [] then raise (Failure "niepoprawny argument")
	else let rec helper(lista1, n)=
	match(lista1, n) with
	([],_)->raise(Failure "niepoprawny argument")
	|(h::_,0)-> h
	|(_::t,n)->helper(t, n-1)
in helper(lista, n);;

nTy ([1;3;5;7], -1);;