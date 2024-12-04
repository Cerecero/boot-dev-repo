package main

import (
	"net/url"
)

func getDomainNameFromURL(rawURL string) (string, error) {
	url, err := url.Parse(rawURL)
	if err != nil {
		return "", err
	}
	return url.Hostname(), nil
}

