package main

import "errors"

func getUserMap(names []string, phoneNumbers []int) (map[string]user, error) {
	// check to see if names and phoneNumbers slices are not equal
	if len(names) != len(phoneNumbers){
		return nil, errors.New("invalid sizes")
	}
	// create a map of string(key)->value(user structs)
	userMap := make(map[string]user)
	// create a usr struct
	var usr user

	for i, n := range names{
		usr.name = n
		usr.phoneNumber = phoneNumbers[i]
		userMap[n] = usr
	}
	return userMap, nil
}

type user struct {
	name        string
	phoneNumber int
}

