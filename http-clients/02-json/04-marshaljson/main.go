package main

import (
	"encoding/json"
)

func marshalAll[T any](items []T) ([][]byte, error) {
	var marshallitems [][]byte
	
	for _, item := range items{
		data, err := json.Marshal(item)
		if err != nil {
			return nil, nil
		}
		marshallitems = append(marshallitems, data)
	}
	
	return marshallitems, nil

	
}

