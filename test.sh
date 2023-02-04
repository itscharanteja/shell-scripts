echo "enter a num"
read n

temp=$n
sum=0
while [ $temp -gt 0 ]
do
  dig=$((temp % 10))
  len=${#n}
  sum=$((sum + dig ** len))
  temp=$((temp / 10))
done

if [ $sum -eq $n ];then
  echo "$n is an armstrong"
else
  echo "$n is not an armstrong"
fi
