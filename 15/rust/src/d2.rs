use crate::util::read_file_to_string;

pub fn run()
{
    ex();
    p1();
    p2();
}

fn wrapping_paper_area(dimensions: &str) -> i32 {
    let three_sides = parse_dimensions(dimensions);
    let side1 = three_sides[0] * three_sides[1];
    let side2 = three_sides[1] * three_sides[2];
    let side3 = three_sides[2] * three_sides[0];
    2 * side1 +
        2 * side2 +
        2 * side3
        + std::cmp::min(std::cmp::min(side1, side2), side3)
}

fn parse_dimensions(dimensions: &str) -> Vec<i32> {
    dimensions.split('x').map(|n| {
        n.parse::<i32>().unwrap()
    }).collect()
}

fn ribbon_feet(dimensions: &str) -> i32 {
    let three_sides = parse_dimensions(dimensions);
    let volumne = three_sides[0] * three_sides[1] * three_sides[2];
    let length: i32 =  2 * (three_sides.iter().sum::<i32>() - three_sides.iter().max().unwrap());
    return volumne + length;
}

fn ex(){
    let test0 = "2x3x4";
    let answer0 = 58;
    let answer02 = 34;
    let test1 = "1x1x10";
    let answer1 = 43;
    let answer12 = 14;
    
    println!("{} == {}", wrapping_paper_area(test0), answer0);
    println!("{} == {}", wrapping_paper_area(test1), answer1);
    println!("{} == {}", ribbon_feet(test0), answer02);
    println!("{} == {}", ribbon_feet(test1), answer12);
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
    let input = read_file_to_string("./src/d2.txt");
    let total_paper: i32 = input.split('\n').map( |gift| {
        if gift.len() > 0 {
            ribbon_feet(gift)
        } else {
            0
        }
    }).sum();
    println!("{}", total_paper);
}