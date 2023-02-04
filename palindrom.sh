#!/bin/bash
read -p "Enter a string: " str
len=${#str}
flag=0
for (( i=0; i<len/2; i++ ))
do
  if [ "${str:i:1}" != "${str:len-i-1:1}" ]
  then
    flag=1
    break
  fi
done

if [ $flag -eq 0 ]
then
  echo "The string is a palindrome"
else
  echo "The string is not a palindrome"
fi