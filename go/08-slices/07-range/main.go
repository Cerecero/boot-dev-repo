package main

func indexOfFirstBadWord(msg []string, badWords []string) int {
	for i, m := range msg{
		for _, bw := range badWords{
			if m == bw{
				return i
			}
		}
	}
	return -1
}
