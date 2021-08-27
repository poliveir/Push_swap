#!/bin/bash

MAX=0
ITERATIONS=0
SUM=0

for i in {1..10000}
do
		export ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
		if ./push_swap $ARG | grep -q "Error"
		then
			echo "Error!"
			echo $ARG
			break
		fi
		NUMBER="$(./push_swap $ARG | wc -l | sed 's/ //g')"
		if [ "$NUMBER" -gt "$MAX" ]
			then
			MAX=$NUMBER;
		fi
		echo $i ":" $NUMBER
		let SUM+=$NUMBER;
		let ITERATIONS+=1
done

echo "AVG: $(($SUM / $ITERATIONS))"
echo "MAX: " $MAX
