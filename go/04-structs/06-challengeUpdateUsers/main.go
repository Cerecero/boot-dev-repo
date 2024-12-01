package main

type User struct {
	Name string
	Membership
}

type Membership struct {
	Type string
	MessageCharLimit int
}

func newUser(name string, membershipType string) User {
	var user User
	user.Name = name
	if membershipType == "premium"{
		user.Type = "premium"
		user.MessageCharLimit = 1000
		return user
	}
	user.Type = "standard"
	user.MessageCharLimit = 100
	return user
}

