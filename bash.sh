#!/bin/bash

## chmod +x ./bash.sh

g++ -o init init.cpp
g++ -o merge merge.cpp
g++ -o quick quick.cpp
g++ -o heap heap.cpp

if [ $? -eq 0 ]; then
  ./init
else
  echo "Compilation failed."
fi

for i in {1..20}; do
  for file in entradas/*; do
    if [ -f "$file" ]; then
      echo ""
      ./merge "$file" "$i"
      echo ""
      ./quick "$file" "$i"
      echo ""
      ./heap "$file" "$i"
    fi
  done
done

