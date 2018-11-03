let rec replicate (el, reps) = 
    if reps <= 0 then []
    else el :: replicate (el, reps - 1);;

replicate ("ha", 3);;