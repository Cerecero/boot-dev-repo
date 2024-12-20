package main

import "fmt"

func fetchTasks(baseURL, availability string) []Issue {
	var limit int
	switch availability {
	case "Low":
		limit = 1
	case "Medium":
		limit = 3
	case "High":
		limit = 5
	default:
		limit = 0
	}

	fullURL := fmt.Sprintf("%s?sort=estimate&limit=%d", baseURL, limit)
	return getIssues(fullURL)
}
