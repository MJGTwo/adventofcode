use std::{hash::Hash, hash::Hasher};

use crate::util::read_file_to_string;

pub fn run()
{
    ex();
    p1();
    p2();
}

// fn wrapping_paper_area(dimensions: &str) -> i32 {
//     let three_sides = parse_dimensions(dimensions);
//     let side1 = three_sides[0] * three_sides[1];
//     let side2 = three_sides[1] * three_sides[2];
//     let side3 = three_sides[2] * three_sides[0];
//     2 * side1 +
//         2 * side2 +
//         2 * side3
//         + std::cmp::min(std::cmp::min(side1, side2), side3)
// }

// fn parse_dimensions(dimensions: &str) -> Vec<i32> {
//     dimensions.split('x').map(|n| {
//         n.parse::<i32>().unwrap()
//     }).collect()
// }

// fn ribbon_feet(dimensions: &str) -> i32 {
//     let three_sides = parse_dimensions(dimensions);
//     let volumne = three_sides[0] * three_sides[1] * three_sides[2];
//     let length: i32 =  2 * (three_sides.iter().sum::<i32>() - three_sides.iter().max().unwrap());
//     return volumne + length;
// }^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.

struct Position {
    x: i32,
    y: i32
}

impl std::fmt::Display for Position {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f,"(x: {}, y: {})", self.x, self.y)
    }
}

impl PartialEq for Position {
    fn eq(&self, other: &Self)-> bool{
        self.x == other.x && self.y == other.y
    }
}

trait Eq: PartialEq<Self> {}

impl Hash for Position {
    fn hash<H: Hasher>(&self, hasher: *mut H){
        self.x.hash(hasher);
        self.y.hash(hasher);
    }
}

fn move_parser(pos: &mut Position, movement: u8){
    match movement {
        b'^' => pos.y += 1,
        b'v' => pos.y += -1,
        b'>' => pos.x += 1,
        b'<' => pos.x += -1,
        _ => todo!(),
    }
}

fn move_santa(pos: &mut Position, moves: &str){
    println!("{}", pos);
    let house_hash: std::collections::HashMap<Position, i32> = std::collections::HashMap::new();
    house_hash.insert(*pos.clone(), 1);
    moves.as_bytes().iter().map(|step|{
        move_parser(pos, *step);
        println!("{}", pos);
    });
}


fn ex(){
    let test0 = ">";
    let answer0 = 2;
    let test1 = "^>v<";
    let answer1 = 4;
    let test2 = "^v^v^v^v^v";
    let answer2 = 2;

    let mut pos = Position {x: 0, y: 0};
    move_santa(&mut pos, test0);
    print!("-----\n");
    let mut pos = Position {x: 0, y: 0};
    move_santa(&mut pos, test1);
    print!("-----\n");

    let mut pos = Position {x: 0, y: 0};
    move_santa(&mut pos, test2);
 
    // println!("{} == {}", wrapping_paper_area(test0), answer0);
    // println!("{} == {}", wrapping_paper_area(test1), answer1);
}

fn p1(){
    // let input = read_file_to_string("./src/d2.txt");
    // let total_paper: i32 = input.split('\n').map( |gift| {
    //     if gift.len() > 0 {
    //         wrapping_paper_area(gift)
    //     } else {
    //         0
    //     }
    // }).sum();
    // println!("{}", total_paper);
}

fn p2(){
    // let input = read_file_to_string("./src/d2.txt");
    // let total_paper: i32 = input.split('\n').map( |gift| {
    //     if gift.len() > 0 {
    //         ribbon_feet(gift)
    //     } else {
    //         0
    //     }
    // }).sum();
    // println!("{}", total_paper);
}