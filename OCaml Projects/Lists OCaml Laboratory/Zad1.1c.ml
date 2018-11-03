let onec (list, flt) =
	if int_of_float flt > 0 then list
	 else List.rev(list);;

onec ([2.1;1.1;2.2;9.1;1.2], -3.2);;