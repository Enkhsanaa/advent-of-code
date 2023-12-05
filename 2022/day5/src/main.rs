use rand::Rng;
use std::cmp::Ordering;
use std::io;

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=100);
    println!("Welcome to the game!");

    loop {
        println!("Please input a number:");
        let mut num = String::new();
        io::stdin()
            .read_line(&mut num)
            .expect("Failed to read the input!");

        let num: u32 = match num.trim().parse() {
            Ok(value) => value,
            Err(_) => {
                println!("Please type a number!");
                continue;
            }
        };
        match num.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}
