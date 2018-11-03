let rec listLength l =
  if l = [] then 0 
  else listLength(List.tl l) + 1;;

listLength [1;4;5;2;6];;