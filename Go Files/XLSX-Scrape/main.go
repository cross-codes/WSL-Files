package main

import (
	"example.com/manipulation"
)

func main() {
	manipulation.DisplaySheets("./spreadsheet.xlsx")
	manipulation.CreateNewXLSX("createdsheet.xlsx", "Sheet1")
	manipulation.FillXLSXValues("./spreadsheet.xlsx", "./createdsheet.xlsx", "Sheet1", "Sheet1")
}
