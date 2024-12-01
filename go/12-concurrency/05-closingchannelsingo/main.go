package main

func countReports(numSentCh chan int) int {
	reports := 0
	for {
		i, ok := <- numSentCh
		if !ok {
			break
		}
		reports += i
	}
	return reports
}

// don't touch below this line

func sendReports(numBatches int, ch chan int) {
	for i := 0; i < numBatches; i++ {
		numReports := i*23 + 32%17
		ch <- numReports
	}
	close(ch)
}

