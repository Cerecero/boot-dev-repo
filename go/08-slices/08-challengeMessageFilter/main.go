package main

type Message interface {
	Type() string
}

type TextMessage struct {
	Sender  string
	Content string
}

func (tm TextMessage) Type() string {
	return "text"
}

type MediaMessage struct {
	Sender    string
	MediaType string
	Content   string
}

func (mm MediaMessage) Type() string {
	return "media"
}

type LinkMessage struct {
	Sender  string
	URL     string
	Content string
}

func (lm LinkMessage) Type() string {
	return "link"
}

// Don't touch above this line

func filterMessages(messages []Message, filterType string) []Message {
	// linkmsg := []Message{}
	// textmsg := []Message{}
	// mediamsg := []Message{}
	//
	// for _, m := range messages{
	// 	if m.Type() == "link"{
	// 		linkmsg = append(linkmsg, m)
	// 	} else if m.Type() == "media"{
	// 		mediamsg = append(mediamsg, m)
	// 	} else {
	// 		textmsg = append(textmsg, m)
	// 	}
	// }
	// if filterType == "link"{
	// 	return linkmsg
	// } else if filterType == "media"{
	// 	return mediamsg
	// } else {
	// 	return textmsg
	// }
	var filtered []Message

	for _, msg := range messages {
		if msg.Type() == filterType {
			filtered = append(filtered, msg)
		}
	}

	return filtered
}

