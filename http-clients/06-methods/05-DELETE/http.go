package main

import (
	// "encoding/json"
	"fmt"
	"net/http"
)

func deleteUser(baseURL, id, apiKey string) error {
	fullURL := baseURL + "/" + id

	req, err := http.NewRequest("DELETE", fullURL, nil)
	if err != nil{
		return err
	}

	req.Header.Set("X-API-KEY", apiKey)
	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return err
	}

	defer res.Body.Close()
	if res.StatusCode > 299 {
		return fmt.Errorf("unsuccessful")
	}
	return nil
}
