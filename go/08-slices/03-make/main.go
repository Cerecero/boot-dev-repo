package main

func getMessageCosts(messages []string) []float64 {
	msgCost := make([]float64, len(messages))
	// for i := 0; i < len(messages); i++ {
	// 	msgCost[i] = float64(len(messages[i])) * 0.01
	// }
	for i, message := range messages {
		msgCost[i] = float64(len(message)) * 0.01
	}
	return msgCost

}

