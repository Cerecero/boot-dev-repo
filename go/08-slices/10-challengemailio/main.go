package main
/*The formatter parameter is defined without specifying its argument and return types, which causes a compile error.
ORIGINAL func getFormattedMessages(messages []string, formatter func) []string {
*/
func getFormattedMessages(messages []string, formatter func(string) string) []string {
	formattedMessages := []string{}
	for _, message := range messages {
		formattedMessages = append(formattedMessages, formatter(message))
	}
	return formattedMessages
}
