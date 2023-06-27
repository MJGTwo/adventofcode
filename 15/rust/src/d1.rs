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

}