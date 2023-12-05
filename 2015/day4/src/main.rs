use std::fs;
use std::io::{stdout, Write};
fn solver(data: &str, leading_zeros: usize) -> i32 {
    let zeros = std::iter::repeat("0")
        .take(leading_zeros)
        .collect::<String>();
    for i in 1600000000.. {
        let attempt = String::new() + data + &i.to_string();
        let digest = &format!("{:x}", md5::compute(attempt.clone()))[..5];
        print!("\rProcessing {}...", attempt);
        if digest == zeros {
            return i;
        }
        stdout().flush().unwrap();
    }
    return -1;
}

fn main() {
    let file_path: String = String::from("data/input.txt");
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");
    // println!("{contents}")
    // println!("Found the decimal: {}", solver(&contents, 5));
    println!("Found the decimal: {}", solver(&contents, 6));
}
