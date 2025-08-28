import math

def get_catalan_number(n):
    """Calculates the nth Catalan number."""
    if n < 0:
        return 0
    # Catalan number C_n = (1 / (n + 1)) * (2n choose n)
    # Using the formula C_n = (2n)! / ((n+1)! * n!)
    # Or C_n = binomial(2n, n) / (n + 1)
    
    # Using math.comb for efficiency and to avoid potential overflow with factorials for large n
    # For n=0, math.comb(0,0) is 1, so 1/(0+1)*1 = 1, which is C0
    return math.comb(2 * n, n) // (n + 1)

def main():
    try:
        n_str = input()
        if not n_str: # Handle empty input gracefully
            print("Invalid input. Please enter an integer.")
            return

        n = int(n_str)
        if n < 0:
            print("Input must be a non-negative integer.")
            return

        catalan_numbers = []
        for i in range(n):
            catalan_numbers.append(get_catalan_number(i))

        # Print the numbers separated by spaces as is common in competitive programming
        print(*catalan_numbers)

    except ValueError:
        print("Invalid input. Please enter an integer.")
    except EOFError: # Catch EOFError specifically for input()
        print("Invalid input. Please enter an integer.")


if __name__ == "__main__":
    main()
