package main

func sum(nums ...int) int {
	sum := 0
	for _, i := range nums{
		sum += i
	}
	return sum
}

