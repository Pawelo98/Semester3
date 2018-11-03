let rec sqrList l = 
  if l = [] then [] 
  else List.hd l * List.hd l :: sqrList(List.tl l) ;;

sqrList [3;2;5;1;6];;