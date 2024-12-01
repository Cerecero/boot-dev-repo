package main

func maxMessages(thresh int) int {
	maxMsg := 0
	totalCose := 0
	for i := 1; ;i++{
		fee := i - 1
		messageCost := 100 + fee
		if totalCose+messageCost > thresh{
			break
		}
		totalCose += messageCost
		maxMsg++
	}
	return maxMsg
}
