let rec getN (list, n) =
	if list= [] then raise (Failure "ujemny argument")
	else if n=0 then List.hd(list)
	else getN(List.tl list, n - 1);;

getN ([0;1;2;3;4], 5);;