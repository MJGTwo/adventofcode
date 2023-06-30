use crate::util::read_file_to_string;

pub fn run()
{
    ex();
    p1();
    p2();
}

fn find_floor( seq: &str) -> usize {
     seq.matches('(').count() - seq.matches(')').count()
}

fn move_elevator(mv: char) -> i32 {
    match mv {
        '(' => 1,
        ')' => -1,
        _ => 0
    }
}

fn find_basement(seq: &str) -> usize {
    let mut level = 0;
    for (index, letter) in seq.chars().enumerate() {
        level += move_elevator(letter);
        if level == -1 {
            return index + 1;
        }
    }
    return 0;
}

fn ex(){
    let test0 = "))(((((";
    let answer0 = 3;
    let test1 = "(())";
    let answer1 = 0;
    
    println!("{} == {}", find_floor(test0), answer0);
    println!("{} == {}", find_floor(test1), answer1);
}

fn p1(){
    let input = read_file_to_string("./src/d1.txt");
    println!("{}", find_floor(input.as_str()));
}

fn p2(){
    let input = read_file_to_string("./src/d1.txt");
    println!("{}",find_basement(input.as_str()));
}