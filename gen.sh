#!/bin/bash

echo "sort 3"
count=0
maxmoves=0
for combo in {"1 ","2 ","3 "}{"1 ","2 ","3 "}{"1 ","2 ","3 "};
	do
		str=$(./push_swap $combo)
		seq=$(echo $str | rev | cut -b -5 | rev)
		lines=$(echo $str | rev | cut -b 6- | rev | wc -w)
		(( $lines > $maxmoves )) && maxmoves=$lines
		[[ "1 2 3" == $seq ]] && count=$((count+1))
done
echo success $count
echo max steps $maxmoves

echo "sort 4"
count=0
maxmoves=0
for combo in {"1 ","2 ","3 ","4 "}{"1 ","2 ","3 ","4 "}{"1 ","2 ","3 ","4 "}{"1 ","2 ","3 ","4 "};
	do
		str=$(./push_swap $combo)
		seq=$(echo $str | rev | cut -b -7 | rev)
		lines=$(echo $str | rev | cut -b 8- | rev | wc -w)
		(( $lines > $maxmoves )) && maxmoves=$lines
		[[ "1 2 3 4" == $seq ]] && count=$((count+1))
done
echo success $count
echo max steps $maxmoves

echo "sort 5"
count=0
maxmoves=0
for combo in {"1 ","2 ","3 ","4 ","5 "}{"1 ","2 ","3 ","4 ","5 "}{"1 ","2 ","3 ","4 ","5 "}{"1 ","2 ","3 ","4 ","5 "}{"1 ","2 ","3 ","4 ","5 "};
	do
		str=$(./push_swap $combo)
		seq=$(echo $str | rev | cut -b -9 | rev)
		lines=$(echo $str | rev | cut -b 10- | rev | wc -w)
		(( $lines > $maxmoves )) && maxmoves=$lines
		[[ "1 2 3 4 5" == $seq ]] && count=$((count+1))
done
echo success $count
echo max steps $maxmoves