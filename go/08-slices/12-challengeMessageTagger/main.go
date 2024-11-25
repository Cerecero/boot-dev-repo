package main

import "strings"

type sms struct {
	id      string
	content string
	tags    []string
}

func tagMessages(messages []sms, tagger func(sms) []string) []sms {
	for i := range messages{
		messages[i].tags = []string{}
		messages[i].tags = tagger(messages[i])
	}
	return messages
	
}

func tagger(msg sms) []string {
	tags := []string{}
	lower := strings.ToLower(msg.content)
	if strings.Contains(lower, "urgent") && strings.Contains(lower,"sale"){
		tags = append(tags, "Urgent Promo")
	} else if strings.Contains(lower, "urgent"){
		//TAG HERE FOR URGENT
		tags = append(tags, "Urgent")
	} else if strings.Contains(msg.content, "sale"){
		//TAG HERE FOR PROMO
		tags = append(tags, "Promo")
	}
	return tags
}

