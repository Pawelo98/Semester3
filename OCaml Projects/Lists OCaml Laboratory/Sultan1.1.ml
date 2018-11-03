let rec flatten lst = 
  if lst = [] then [] 
  else List.hd lst :: flatten (List.tl lst);;

flatten [[1;4;5;2];[4;5;6;2];[1;1;3;3]];;