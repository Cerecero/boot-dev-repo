package main

import "errors"

func validateStatus(status string) error {
	if len(status) <= 0{
		err := errors.New("status cannot be empty")
		return err
		/* Or only this
			return errors.New("status cannot be empty")
		*/
	} else if len(status) > 140 {
		err := errors.New("status exceeds 140 characters")
		return err
		/* Or only this
			return errors.New("status exceeds 140 characters")
		*/
	}
	return nil
}

