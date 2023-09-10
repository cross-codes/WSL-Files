package models

type CartItem struct {
	ProductId      string `json:"productId"`
	CustomerId     string `json:"customerId"`
	QuantityInCart int    `json:"quantityInCart"`
}
