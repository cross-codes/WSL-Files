package main

import (
	"example.com/manipulation"
)

func main() {
	manipulation.CreateNewXLSX("createdsheet.xlsx", "Sheet1")
	manipulation.FillXLSXValues("./spreadsheet.xlsx", "./createdsheet.xlsx", "Sheet1", "Sheet1")
	manipulation.PrintDetails("./createdsheet.xlsx", "Sheet1")
}
