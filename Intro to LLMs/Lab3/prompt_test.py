import unittest
import subprocess
import sys
import io
import os

# Define the path to the script to be tested
SCRIPT_TO_TEST = "prompt_output.py"

# --- Test Helper Function ---
def run_script_with_input(input_data):
    """
    Runs the prompt_output.py script with the given input and captures its output.
    Returns a tuple: (stdout_output_string, stderr_output_string)
    """
    # Use subprocess to run the script and capture its output
    process = subprocess.Popen(
        [sys.executable, SCRIPT_TO_TEST],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,  # Decode stdin/stdout/stderr as text
        encoding='utf-8' # Specify encoding for consistency
    )
    stdout, stderr = process.communicate(input=str(input_data))
    return stdout.strip(), stderr.strip()

# --- Test Cases ---
def run_tests():
    test_cases = [
        # (input, expected_output_string)
        (0, ""),  # n=0, no numbers should be printed
        (1, "1"), # C_0
        (2, "1 1"), # C_0, C_1
        (3, "1 1 2"), # C_0, C_1, C_2
        (4, "1 1 2 5"), # C_0, C_1, C_2, C_3
        (5, "1 1 2 5 14"), # C_0, C_1, C_2, C_3, C_4
        (6, "1 1 2 5 14 42"), # C_0, C_1, C_2, C_3, C_4, C_5
        (7, "1 1 2 5 14 42 132"),
        (8, "1 1 2 5 14 42 132 429"),
        (9, "1 1 2 5 14 42 132 429 1430"),
        (10, "1 1 2 5 14 42 132 429 1430 4862"),
        (11, "1 1 2 5 14 42 132 429 1430 4862 16796"),
        (12, "1 1 2 5 14 42 132 429 1430 4862 16796 58786"),
        (13, "1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012"),
        (14, "1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900"),
        (15, "1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440"),
        # Edge cases and error handling
        (-1, "Input must be a non-negative integer."), # Negative input
        ("-5", "Input must be a non-negative integer."), # Negative string input
        ("abc", "Invalid input. Please enter an integer."), # Non-integer input
        ("1.5", "Invalid input. Please enter an integer."), # Float string input
        ("", "Invalid input. Please enter an integer."), # Empty input
        (" ", "Invalid input. Please enter an integer."), # Whitespace input
        (" 10 ", "1 1 2 5 14 42 132 429 1430 4862"), # Input with leading/trailing spaces
    ]

    for i, (input_val, expected_output) in enumerate(test_cases):
        actual_output, actual_stderr = run_script_with_input(input_val)

        # Check for stderr, which indicates a serious error in the script itself (e.g., traceback)
        # This is generally not expected for correctly handled user inputs.
        if actual_stderr:
            print(f"test failed (input: {repr(input_val)})")
            print(f"  Unexpected stderr: {actual_stderr}")
            continue

        # For valid inputs, actual_output should match expected_output
        if actual_output != expected_output:
            print(f"test failed (input: {repr(input_val)})")
            print(f"  Expected: '{expected_output}'")
            print(f"  Got:      '{actual_output}'")

if __name__ == "__main__":
    # Create a dummy prompt_output.py if it doesn't exist for the test harness to run.
    # In a real scenario, this script would be in the same directory as prompt_output.py.
    if not os.path.exists(SCRIPT_TO_TEST):
        print(f"Error: '{SCRIPT_TO_TEST}' not found in the current directory.")
        print("Please ensure the file to be tested is present.")
        sys.exit(1)

    run_tests()