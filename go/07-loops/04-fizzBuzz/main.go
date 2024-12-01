package main

import "fmt"


func fizzbuzz() {
	for i := 1; i <= 100; i++{
		if i % 3 == 0{
			if i % 5 == 0 {
				fmt.Println("fizzbuzz")
			}else{
				fmt.Println("fizz")
			}
			
		} else if i % 5 == 0{
			fmt.Println("buzz")
		} else {
		fmt.Println(i)
		}
		/*
		switch{
			case i%15 ==0:
				fizzbuzz
			case i%3 == 0:
				fizz
			case i%5 == 0:
				buzz
			default:
				print i
			}
		*/
	}
}

// don't touch below this line

func main() {
	fizzbuzz()
}

