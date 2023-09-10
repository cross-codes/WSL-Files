package models

import "go.mongodb.org/mongo-driver/bson/primitive"

type Product struct {
	Id                primitive.ObjectID `json:"_id,omitempty"`
	ProductName       string             `json:"productName,omitempty" validate:"required"`
	Description       string             `json:"description,omitempty" validate:"required"`
	SellerID          string             `json:"sellerId,omitempty" validate:"required"`
	Brand             string             `json:"brand,omitempty" validate:"required"`
	MaxRetailPrice    int                `json:"maxRetailPrice,omitempty" validate:"required"`
	QuantityAvailable int                `json:"quantityAvailable,omitempty" validate:"required"`
	ProductCategories []string           `json:"productCategories,omitempty" validate:"required"`
	AverageRating     int                `json:"averageRating,omitempty"`
}
