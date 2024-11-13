#!/bin/bash

## chmod +x ./bash.sh

g++ -o init init.cpp
g++ -o merge merge.cpp

if [ $? -eq 0 ]; then
  ./init
else
  echo "Compilation failed."
fi

for i in {1..1}; do
  for file in entradas/*; do
    if [ -f "$file" ]; then
      echo ""
      ./merge "$file" "$i"
    fi
  done
done

