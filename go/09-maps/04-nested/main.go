package main

func getNameCounts(names []string) map[rune]map[string]int {

	nameCount := make(map[rune]map[string]int)

	for _, n := range names{
		if len(n) == 0{
			continue
		}
						// rune(n[0]) could assign it to a variable like first character
		if _, exists := nameCount[rune(n[0])]; !exists{ // Create a map if it dosent exist
			nameCount[rune(n[0])] = make(map[string]int)
		}
		nameCount[rune(n[0])][n]++
	}
	return nameCount
}

