#!/bin/bash

## chmod +x ./bash.sh

g++ -o init init.cpp
g++ -o modelo modelo.cpp
g++ -o leitor leitor.cpp

g++ -o merge merge.cpp

if [ $? -eq 0 ]; then
  ./init
else
  echo "Compilation failed."
fi

for i in {1..5}; do
  for file in entradas/*; do
    if [ -f "$file" ]; then
      echo ""
      ./modelo "$file" "$i"
    fi
  done
done

