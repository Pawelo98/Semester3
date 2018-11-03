let rec pairChange (list) =
	if list= [] then list
	else if List.tl list=[] then List.hd(list) :: pairChange(List.tl(list))
	else List.hd(List.tl list) :: List.hd(list) :: pairChange(List.tl(List.tl(list)));;

pairChange ([0;1;2;3;4]);;