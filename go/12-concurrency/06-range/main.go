package main

func concurrentFib(n int) []int {
	ch := make(chan int)
	go fibonacci(n, ch)

	var slice []int
	for i := range ch {
		slice = append(slice, i)
	}
	return slice
}

// don't touch below this line

func fibonacci(n int, ch chan int) {
	x, y := 0, 1
	for i := 0; i < n; i++ {
		ch <- x
		x, y = y, x+y
	}
	close(ch)
}