package main

func bulkSend(numMessages int) float64 {
	totalCost := 0.0
	for i := 1; i<= numMessages; i++{
		fee := 0.01 * float64(i-1) // Calculate the additional fee for each message
		totalCost += 1.0 + fee   
	}
	return totalCost
}

