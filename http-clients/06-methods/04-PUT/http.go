package main

import (
	"bytes"
	"encoding/json"
	"net/http"
)

func updateUser(baseURL, id, apiKey string, data User) (User, error) {
	fullURL := baseURL + "/" + id
	// Encode the user data to JSON
	dataJSON, err := json.Marshal(data)
	if err != nil{
		return User{}, err
	}

	//Create a new POST with the json data
	req, err := http.NewRequest("PUT", fullURL, bytes.NewBuffer(dataJSON))
	//Set headers
	req.Header.Set("Content-Type", "application/json")
	req.Header.Set("X-API-KEY", apiKey)

	//Make the request using the default client
	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return User{}, err
	}

	defer res.Body.Close()
	//Decode JSON to User struct
	var newUser User
	if err := json.NewDecoder(res.Body).Decode(&newUser); err != nil{
		return User{}, err
	}

	return newUser, err

}

func getUserById(baseURL, id, apiKey string) (User, error) {
	fullURL := baseURL + "/" + id

	req, err := http.NewRequest("GET", fullURL, nil)
	if err != nil{
		return User{}, err
	}
	req.Header.Set("X-API-KEY", apiKey)

	client := &http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return User{}, nil
	}
	defer res.Body.Close()

	var newUser User
	if err := json.NewDecoder(res.Body).Decode(&newUser); err != nil{
		return User{}, nil
	}
	return newUser, nil
}

