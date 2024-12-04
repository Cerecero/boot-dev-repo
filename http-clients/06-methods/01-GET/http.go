package main

import (
	"encoding/json"
	"net/http"
)

func getUsers(url string) ([]User, error) {
	resp, err := http.Get(url)
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()

	var user []User
	if err = json.NewDecoder(resp.Body).Decode(&user); err != nil{
		return nil, err
	}
	return user, nil
}

