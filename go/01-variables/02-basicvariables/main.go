package main
import "fmt"

func main(){
	var smsSendingLimit int
	smsSendingLimit = 23
	var costPerSMS float64
	costPerSMS = 2.45
	var hasPermission bool
	hasPermission = true
	var username string
	username = "Test User"

	fmt.Printf("%v %.2f %v %q\n", smsSendingLimit, costPerSMS, hasPermission, username)
}
