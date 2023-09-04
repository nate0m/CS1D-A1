#!/bin/bash

# Define the input files you want to test
input_files=("1000_numbers" "10000_numbers" "100000_numbers" "1000000_numbers")

# Define the name of your C++ program
cpp_program="./a1"

# Define the output directory
output_directory="output"

# Create the output directory if it doesn't exist
mkdir -p "$output_directory"

# Loop through the input files
for input in "${input_files[@]}"; do
    echo "Running with input file: $input"
    
    # Loop through the 5 different algorithms (1 to 5)
    for algorithm in {1..5}; do
        echo "Algorithm: $algorithm"
        
        # Construct the output file path
        output_file="$output_directory/output_${input}_algorithm${algorithm}.txt"
        
       # Using Valgrind to check for memory leaks and capture execution time
        {
            valgrind --leak-check=yes "$cpp_program" "/usr/share/CS1D/A1/$input.txt" "$algorithm" &&
            { time -p "$cpp_program" "/usr/share/CS1D/A1/$input.txt" "$algorithm" 2>&1; } 
        } 2>&1 | tee "$output_file" 

        echo "------------------------------------------------------"
    done
done

