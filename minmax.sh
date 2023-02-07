#!/bin/bash
echo "Enter numbers"
read -a num
big=${num[0]}
smal=${num[0]}

for i in ${num[@]}
do
  if [[ $i -gt $big ]]
   then 
    big="$i"
   fi

   if [[ $i -lt $smal ]]
   then 
    smal="$i"
   fi
done

echo "big : $big"
echo "small : $smal"
