package main

func findSuggestedFriends(username string, friendships map[string][]string) []string {
	// directFriend, ok := friendships[username]; 
	// if !ok {
	// 	return nil
	// }
	//
	// suggest := make(map[string]bool)
	//
	// directFriendsSet := make(map[string]bool)
	//
	// for _, friend := range directFriend {
	// 	directFriendsSet[friend] = true
	// }
	//
	// for _, friend := range directFriend {
	// 	if friendsOfFriend, ok := friendships[friend]; ok {
	// 		for _, friendOfFriend := range friendsOfFriend {
	// 			if friendOfFriend != username && !directFriendsSet[friendOfFriend] {
	// 				suggest[friendOfFriend] = true
	// 			}
	// 		}
	// 	}
	// }
	//
	// result := []string{}
	// for suggestedFriend := range suggest {
	// 	result = append(result, suggestedFriend)
	// }
	//
	// return result
}

