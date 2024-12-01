package main

func getMessageWithRetries(primary, secondary, tertiary string) ([3]string, [3]int) {
	returnedMsg := [3]string{primary, secondary,tertiary}
	returnedInt := [3]int{len(primary), len(primary + secondary), len(primary + secondary + tertiary)}
	return returnedMsg, returnedInt
	// return  [3]string{primary, secondary,tertiary}, [3]int{len(primary), len(primary + secondary), len(primary + secondary + tertiary)}
}

