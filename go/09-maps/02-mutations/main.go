package main

import "errors"

func deleteIfNecessary(users map[string]user, name string) (deleted bool, err error) {
	_, ok := users[name]
	if !ok {
		return false, errors.New("not found")
	}
	if !users[name].scheduledForDeletion{
		return false, nil
	}
	delete(users, name)
	return true, nil
}

type user struct {
	name                 string
	number               int
	scheduledForDeletion bool
}

