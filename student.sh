#!/bin/bash
echo "Enter student number:"
read snum

echo "Enter student name:"
read sname

echo "Enter marks in 5 subjects:"
read m1 m2 m3 m4 m5

total=$((m1 + m2 + m3 + m4 + m5))
avg=$((total/5))

if [ $avg -ge 80 ]
then
    grade="A"
elif [ $avg -ge 70 ]
then
    grade="B"
elif [ $avg -ge 60 ]
then
    grade="C"
elif [ $avg -ge 50 ]
then
    grade="D"
elif [ $avg -ge 40 ]
then
    grade="E"
else
    grade="F"
fi

echo "Student number: $snum"
echo "Student name: $sname"
echo "Total marks: $total"
echo "Average: $avg"
echo "Grade: $grade"
