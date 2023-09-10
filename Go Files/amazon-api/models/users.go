package models

import "go.mongodb.org/mongo-driver/bson/primitive"

type User struct {
	Id           primitive.ObjectID `json:"_id,omitempty"`
	FirstName    string             `json:"firstName,omitempty" validate:"required"`
	LastName     string             `json:"lastName,omitempty" validate:"required"`
	Email        string             `json:"email,omitempty" validate:"required"`
	Password     string             `json:"password,omitempty" validate:"required"`
	MobileNumber string             `json:"mobileNumber,omitempty" validate:"required"`
	DateOfBirth  string             `json:"dateOfBirth,omitempty" validate:"required"`
	CartItems    []CartItem         `json:"cartItems"`
	Role         string             `json:"role"`
}
