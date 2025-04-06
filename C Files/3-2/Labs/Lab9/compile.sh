#!/bin/bash

C_FILE="BST.c"
OUTPUT_FILE="a.out"

while true; do
    gcc "$C_FILE" -o "$OUTPUT_FILE"
    echo "----------"
    sleep 10
done
