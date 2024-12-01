package main

import "time"

func processMessages(messages []string) []string {
	resultsChan := make(chan string, len(messages))
	
	// Process each message concurrently
	for _, msg := range messages {
		go func(message string) {
			resultsChan <- process(message)
		}(msg)
	}
	
	// Collect processed messages
	var results []string
	for i := 0; i < len(messages); i++ {
		results = append(results, <-resultsChan)
	}
	
	return results
}

// don't touch below this line

func process(message string) string {
	time.Sleep(1 * time.Second)
	return message + "-processed"
}

