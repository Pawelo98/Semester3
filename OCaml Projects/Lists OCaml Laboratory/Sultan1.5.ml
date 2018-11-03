let palindrome l = 
  if l = List.rev l then true else false;;

palindrome [1;4;2;5;6];;