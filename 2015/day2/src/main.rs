use std::fs;

fn main() {
    let file_path: String = String::from("data/input.txt");
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");

    let mut total_area = 0;
    let mut total_ribbon = 0;
    for line in contents.lines() {
        let mut dimensions: Vec<i32> = line.split("x").map(|k| k.parse().unwrap()).collect();
        dimensions.sort();

        // Wrap
        let mut area = 0;
        for i in 0..3 {
            for j in (i + 1)..3 {
                area += 2 * dimensions[i] * dimensions[j];
            }
        }
        area += dimensions[0] * dimensions[1];
        total_area += area;

        // Ribbon
        let ribbon = 2 * dimensions[0] + 2 * dimensions[1];
        let bow = dimensions[0] * dimensions[1] * dimensions[2];
        total_ribbon += ribbon + bow;
    }
    println!("Total area: {total_area}");
    println!("Total ribbon: {total_ribbon}");
}
