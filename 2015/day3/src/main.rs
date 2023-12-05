use std::collections::HashMap;
use std::collections::HashSet;
use std::fs;

fn part1(instructions: &str) {
    let mut map = HashMap::new();
    let mut set = HashSet::new();

    let mut x = 0;
    let mut y = 0;
    map.insert([x, y], 1);

    for op in instructions.chars() {
        match op {
            '<' => y -= 1,
            '>' => y += 1,
            '^' => x -= 1,
            'v' => x += 1,
            _ => println!("Should we panic?"),
        }
        let house = map.entry([x, y]).or_insert(0);
        *house += 1;
        if *house >= 1 {
            set.insert([x, y]);
        }
    }

    println!(
        "PART 1::Houses that received more than one present: {}",
        set.len()
    )
}

fn part2(instructions: &str) {
    let mut map = HashMap::new();
    let mut set = HashSet::new();

    let mut x = 0;
    let mut y = 0;

    let mut robo_x = 0;
    let mut robo_y = 0;
    map.insert([x, y], 2);

    for (i, op) in instructions.chars().enumerate() {
        let ref_x: &mut i32;
        let ref_y: &mut i32;
        if i & 1 > 0 {
            ref_x = &mut robo_x;
            ref_y = &mut robo_y;
        } else {
            ref_x = &mut x;
            ref_y = &mut y;
        }

        match op {
            '<' => *ref_y -= 1,
            '>' => *ref_y += 1,
            '^' => *ref_x -= 1,
            'v' => *ref_x += 1,
            _ => println!("Should we panic?"),
        }
        let house = map.entry([*ref_x, *ref_y]).or_insert(0);
        *house += 1;
        if *house >= 1 {
            set.insert([*ref_x, *ref_y]);
        }
    }

    println!(
        "PART 2::Houses that received more than one present: {}",
        set.len()
    )
}

fn main() {
    let file_path: String = String::from("data/input.txt");
    let contents = fs::read_to_string(file_path).expect("Should have been able to read the file");
    part1(&contents[..]);
    part2(&contents[..]);
}
