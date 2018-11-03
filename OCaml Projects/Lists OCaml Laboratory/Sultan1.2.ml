let rec count (el, lst) =
	if lst = [] then 0
	else (if List.hd lst = el then 1 else 0) + count(el, List.tl lst);;

count ('a', ['a';'b';'a';'v';'a']);;
