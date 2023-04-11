#!/bin/bash

#read variables from txt file
filename=data.txt
while IFS= read -r line;
do
echo "$line"
done < "$filename"
