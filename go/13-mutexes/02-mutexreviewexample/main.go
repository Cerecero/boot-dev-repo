package main

import (
	"fmt"
	"sync"
)

func main() {
	m := map[int]int{}

	mu := &sync.Mutex{}

	go writeLoop(m, mu)
	go readLoop(m, mu)

	// stop program from exiting, must be killed
	block := make(chan struct{})
	<-block
}

func writeLoop(m map[int]int, mu *sync.Mutex) {
	for {
		for i := 0; i < 100; i++ {
			mu.Lock()
			m[i] = i
			mu.Unlock()
		}
	}
}

func readLoop(m map[int]int, mu *sync.Mutex) {
	for {
		mu.Lock()
		for k, v := range m {
			fmt.Println(k, "-", v)
		}
		mu.Unlock()
	}
}

// this code below causes a panic of concurrent writing and reading of a map
// package main
//
// import (
// 	"fmt"
// )
//
// func main() {
// 	m := map[int]int{}
// 	go writeLoop(m)
// 	go readLoop(m)
//
// 	// stop program from exiting, must be killed
// 	block := make(chan struct{})
// 	<-block
// }
//
// func writeLoop(m map[int]int) {
// 	for {
// 		for i := 0; i < 100; i++ {
// 			m[i] = i
// 		}
// 	}
// }
//
// func readLoop(m map[int]int) {
// 	for {
// 		for k, v := range m {
// 			fmt.Println(k, "-", v)
// 		}
// 	}
// }
