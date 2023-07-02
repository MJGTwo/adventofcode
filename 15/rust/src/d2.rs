use crate::util::read_file_to_string;

pub fn run()
{
    ex();
    p1();
    p2();
}

fn wrapping_paper_area(dimensions: &str) -> i32 {
    let three_sides: Vec<i32> = dimensions.split('x').map(|n| {
        n.parse::<i32>().unwrap()
    }).collect();
    let side1 = three_sides[0] * three_sides[1];
    let side2 = three_sides[1] * three_sides[2];
    let side3 = three_sides[2] * three_sides[0];
    return 2 * side1 +
        2 * side2 +
        2 * side3
        + std::cmp::min(std::cmp::min(side1, side2), side3);


}

fn ex(){
    let test0 = "2x3x4";
    let answer0 = 58;
    let test1 = "1x1x10";
    let answer1 = 43;
    
    println!("{} == {}", wrapping_paper_area(test0), answer0);
    println!("{} == {}", wrapping_paper_area(test1), answer1);
}

fn p1(){
    let input = read_file_to_string("./src/d2.txt");
    let total_paper: i32 = input.split('\n').map( |gift| {
        if gift.len() > 0 {
            wrapping_paper_area(gift)
        } else {
            0
        }
    }).sum();
    println!("{}", total_paper);
}

fn p2(){
    // let input = read_file_to_string("./src/d1.txt");
    // println!("{}",find_basement(input.as_str()));
}