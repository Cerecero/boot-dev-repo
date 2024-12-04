package main

import (
	"fmt"
	"io"
	"net/http"
	"encoding/json"
)

	// var issues []Issue
	// if err = json.Unmarshal(data, &issues); err != nil {
	// 	return nil, err
	// }
	// return issues, nil
func getIPAddress(domain string) (string, error) {
	url := fmt.Sprintf("https://cloudflare-dns.com/dns-query?name=%s&type=A", domain)

	req, err := http.NewRequest("GET", url, nil)
	if err != nil {
		return "", fmt.Errorf("error creating request: %w", err)
	}
	req.Header.Set("accept", "application/dns-json")

	client := http.Client{}
	res, err := client.Do(req)
	if err != nil {
		return "", fmt.Errorf("error sending request: %w", err)
	}
	defer res.Body.Close()

	body, err := io.ReadAll(res.Body)
	if err != nil {
		return "", fmt.Errorf("error reading response body: %w", err)
	}
	var dnsRes DNSResponse
	if err = json.Unmarshal(body, &dnsRes); err != nil{
		return "", err
	}

	if len(dnsRes.Answer) > 0{
		return dnsRes.Answer[0].Data, nil
	}

	return "", fmt.Errorf("no ip addresss found")
}

