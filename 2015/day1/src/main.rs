use std::fs;

fn main() {
    let file_path: String = String::from("data/input.txt");
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");

    let mut floor: i32 = 0;
    let mut idx_at_basement: i32 = -1;
    for (i, c) in contents.chars().enumerate() {
        match c {
            ')' => floor -= 1,
            '(' => floor += 1,
            _ => println!("Found something strage: {c}"),
        }
        if floor == -1 && idx_at_basement == -1 {
            idx_at_basement = (i + 1) as i32;
        }
    }
    println!("Floor: {floor}");
    println!("First time in basement: {idx_at_basement}");
}
