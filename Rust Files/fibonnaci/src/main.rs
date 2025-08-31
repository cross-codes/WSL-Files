use std::io;

fn main() {
    println!("Enter the value of n: ");

    let mut n = String::new();

    io::stdin().read_line(&mut n).expect("Failed to read input");

    let n: u32 = match n.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };

    if n == 1 {
        println!("0");
    } else if n == 2 {
        println!("1");
    } else {
        let mut back = 0;
        let mut prev = 1;
        let mut curr = 1;

        let mut cnt = 2;
        while cnt < n {
            curr = prev + back;
            back = prev;
            prev = curr;

            cnt += 1;
        }

        println!("The desired fibonnaci number is: {curr}");
    }
}
