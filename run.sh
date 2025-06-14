#!/bin/bash

if [ $# -eq 0 ]; then
    exit 1
fi

FILE="$1"
EXT="${FILE##*.}"
DIR="$(dirname "$FILE")/"
BASENAME="$(basename "$FILE")"
FILENAME_WITHOUT_EXT="${BASENAME%.*}"

cd "$DIR" || exit 1

if [ "$EXT" == "c" ]; then
    gcc -std=c11 -O2 -pipe -static -s "$BASENAME" -o "$FILENAME_WITHOUT_EXT" -lm
elif [ "$EXT" == "cpp" ]; then
    g++ -std=c++17 -O2 -pipe -static -s "$BASENAME" -o "$FILENAME_WITHOUT_EXT"
else
    exit 1
fi

if [ $? -eq 0 ]; then
    "./$FILENAME_WITHOUT_EXT"
else
    exit 1
fi
