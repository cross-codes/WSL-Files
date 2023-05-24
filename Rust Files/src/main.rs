fn main() {
    // Perform some arbitrary operations

    // Calculate the sum of all even numbers from 1 to 100
    let mut sum = 0;
    for i in 1..=100 {
        if i % 2 == 0 {
            sum += i;
        }
    }
    println!("Sum of even numbers from 1 to 100: {}", sum);

    // Generate Fibonacci sequence up to the 15th term
    let mut fib_seq = vec![0, 1];
    for i in 2..15 {
        let next_term = fib_seq[i - 1] + fib_seq[i - 2];
        fib_seq.push(next_term);
    }
    println!("Fibonacci sequence: {:?}", fib_seq);

    // Calculate the factorial of 10
    let mut factorial = 1;
    for i in 1..=10 {
        factorial *= i;
    }
    println!("Factorial of 10: {}", factorial);

    // Generate a multiplication table of numbers from 1 to 10
    for i in 1..=10 {
        for j in 1..=10 {
            print!("{:4} ", i * j);
        }
        println!();
    }

    // Perform some string operations

    // Concatenate strings
    let greeting = "Hello,";
    let name = " Rust!";
    let full_greeting = format!("{}{}", greeting, name);
    println!("{}", full_greeting);

    // Split a string into words
    let sentence = "This is a sample sentence.";
    let words: Vec<&str> = sentence.split_whitespace().collect();
    println!("Words in the sentence: {:?}", words);

    // Reverse a string
    let mut reversed = String::new();
    for c in sentence.chars().rev() {
        reversed.push(c);
    }
    println!("Reversed sentence: {}", reversed);

    // Perform some mathematical operations

    // Calculate the square root of 256
    let sqrt = 256_f64.sqrt();
    println!("Square root of 256: {}", sqrt);

    // Calculate the value of Pi using the Leibniz formula
    let mut pi = 0.0;
    let num_terms = 100000;
    for i in 0..num_terms {
        let term = 1.0 / (2 * i + 1) as f64 * if i % 2 == 0 { 1.0 } else { -1.0 };
        pi += term;
    }
    pi *= 4.0;
    println!("Approximate value of Pi: {}", pi);
}
