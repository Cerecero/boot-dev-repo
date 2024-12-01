package main

type cost struct {
	day   int
	value float64
}

func getCostsByDay(costs []cost) []float64 {
	totalCost := []float64{}
	for _, c := range costs{
		for len(totalCost) <= c.day{
			totalCost = append(totalCost, 0.0)
		}
		totalCost[c.day] += c.value
	}
	return totalCost
}

