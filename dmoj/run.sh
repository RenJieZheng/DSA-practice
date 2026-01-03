#!/usr/bin/env bash
set -e

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <problem-folder>"
    exit 1
fi

PROBLEM_DIR="$1"

if [[ ! -d "$PROBLEM_DIR" ]]; then
    echo "Error: '$PROBLEM_DIR' is not a directory"
    exit 1
fi

SRC="$PROBLEM_DIR/program.cpp"
EXE="$PROBLEM_DIR/program"
TESTS_DIR="$PROBLEM_DIR/tests"

if [[ ! -f "$SRC" ]]; then
    echo "Error: program.cpp not found in $PROBLEM_DIR"
    exit 1
fi


if [[ ! -d "$TESTS_DIR" ]]; then
    echo "Error: tests/ directory not found in $PROBLEM_DIR"
    exit 1
fi

# Compile

g++ -std=c++17 -O0 -g -Wall -Wextra "$SRC" -o "$EXE"

echo "Compiled successfully"
echo

# Run tests

for infile in "$TESTS_DIR"/*.in; do
    test_name=$(basename "$infile" .in)
    outfile="$TESTS_DIR/$test_name.out"

    if [[ ! -f "$outfile" ]]; then
        echo "Missing output file for test '$test_name'"
        exit 1
    fi

    echo "-----------------------------------------------------------"
    echo "Running test: $test_name"

    "$EXE" < "$infile" > "$PROBLEM_DIR/tests/$test_name.actual"

    if diff -u "$outfile" "$PROBLEM_DIR/tests/$test_name.actual"; then
        echo "Passed"
        rm -f "$PROBLEM_DIR/tests/$test_name.actual"
    else
        echo "Failed"
    fi

    echo "-----------------------------------------------------------"
    echo
done
