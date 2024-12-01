package main

func isValidPassword(password string) bool {
	if len(password) < 5 || len(password) > 12{
		return false
	}

	hasUpperCase := false
	hasDigit := false
	
	for _, c := range password {
		if c >= 'A' && c <= 'Z'{
			hasUpperCase = true
		}
		if c >= '0' && c<= '9'{
			hasDigit = true
		}

		if hasDigit && hasUpperCase {
			return true
		}
	}
	return hasUpperCase && hasDigit
}

