use std::io;

fn main() {
    println!("Enter the temperature in celsius: ");

    let mut t = String::new();

    io::stdin().read_line(&mut t).expect("Failed to read input");

    let t: f64 = match t.trim().parse() {
        Ok(num) => num,
        Err(_) => 0.0,
    };

    let conv: f64 = (9.0 / 5.0) * t + 32.0;
    println!("Temperature in farenheit: {conv}");
}
