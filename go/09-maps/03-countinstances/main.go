package main

func getCounts(messagedUsers []string, validUsers map[string]int) {
	for _, usr := range messagedUsers{
		if _, ok := validUsers[usr]; ok{
			validUsers[usr]++
		}
	}
}

