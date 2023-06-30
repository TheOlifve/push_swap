#!/bin/bash

args=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")

instruction_count=$(./a.out $args | wc -l)
# test_ok=$(./a.out $args)

echo "Number of instructions: $instruction_count
Is sorted?: $test_ok"