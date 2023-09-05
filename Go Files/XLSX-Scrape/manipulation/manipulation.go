// Package manipulation stores functions to open and choose content from the spreadsheet
package manipulation

import (
	"fmt"

	"github.com/tealeg/xlsx/v3"
)

var rbData []string
var students []Student
var departmentMap = map[string]string{
	"A1": "Chemical",
	"A2": "Civil",
	"A3": "EEE",
	"A4": "Mechanical",
	"A5": "Pharmacy",
	"A7": "CSIS",
	"A8": "EnI",
	"AA": "ECE",
	"AB": "Manufacturing",
	"B1": "Biology",
	"B2": "Chemistry",
	"B3": "Economics",
	"B4": "Chemistry",
	"B5": "Physics",
}

type Student struct {
	Name       string
	ID         string
	Email      string
	Department string
}

func refCellDoer(c *xlsx.Cell) error {
	value, err := c.FormattedValue()
	if err != nil {
		fmt.Println(err.Error())
	} else if value != "" {
		rbData = append(rbData, value)
	}
	return err
}

func refRowDoer(r *xlsx.Row) error {
	return r.ForEachCell(refCellDoer)
}

// DisplaySheets will display all available sheets in the file
func DisplaySheets(fileName string) {
	wb, err := xlsx.OpenFile(fileName)
	if err != nil {
		panic(err)
	}

	fmt.Println("Sheets in this file: ")
	for i, sh := range wb.Sheets {
		fmt.Println(i, sh.Name)
	}
	fmt.Println("----")
}

// CreateNewXLSX will create a new .xlsx file
func CreateNewXLSX(fileName string, sheetName string) {
	wb := xlsx.NewFile()

	_, err := wb.AddSheet(sheetName)
	if err != nil {
		panic(err)
	}

	err = wb.Save(fileName)
	if err != nil {
		panic(err)
	}

	fmt.Println(fileName + " created succesfully")
}

// FillXLSXValues will fill in new values inside the spreasheet
func FillXLSXValues(refFileName string, fileName string, refSheetName string, sheetName string) {
	rwb, err := xlsx.OpenFile(refFileName)
	if err != nil {
		panic(err)
	}
	wb, err := xlsx.OpenFile(fileName)
	if err != nil {
		panic(err)
	}

	rsh, ok := rwb.Sheet[refSheetName]
	if !ok {
		fmt.Println(refSheetName + " does not exist")
		return
	}

	sh, ok := wb.Sheet[sheetName]
	if !ok {
		fmt.Println(sheetName + " does not exist")
		return
	}

	rsh.ForEachRow(refRowDoer)

	cell, _ := sh.Cell(0, 0)
	cell.Value = rbData[0]
	cell, _ = sh.Cell(0, 1)
	cell.Value = rbData[1]
	cell, _ = sh.Cell(0, 2)
	cell.Value = "Email"
	cell, _ = sh.Cell(0, 3)
	cell.Value = "Branch"

	rowIndex := 1
	colIndex := 0
	arrCount := 2

	for true {
		if arrCount >= len(rbData) {
			break
		}
		cell, _ = sh.Cell(rowIndex, colIndex)
		if arrCount%2 != 0 {

			cell.Value = rbData[arrCount]
			fullID := rbData[arrCount]
			year := fullID[:4]
			stream := fullID[4:6]
			id := fullID[8:12]
			campus := string(fullID[12])
			email := ""
			if campus == "P" {
				email = "f" + year + id + "@pilani.bits-pilani.ac.in"
			} else if campus == "G" {
				email = "f" + year + id + "@goa.bits-pilani.ac.in"
			} else if campus == "H" {
				email = "f" + year + id + "@hyderabad.bits-pilani.ac.in"
			}
			cell, _ = sh.Cell(rowIndex, colIndex)
			cell.Value = fullID
			colIndex++
			cell, _ = sh.Cell(rowIndex, colIndex)
			cell.Value = email
			colIndex++
			cell, _ = sh.Cell(rowIndex, colIndex)
			cell.Value = departmentMap[stream]
			colIndex++
			rowIndex++
			colIndex = 0
			arrCount++
		} else {
			cell, _ = sh.Cell(rowIndex, colIndex)
			cell.Value = rbData[arrCount]
			colIndex++
			arrCount++
		}
	}

	err = wb.Save(fileName)
	if err != nil {
		panic(err)
	}
}

func (s Student) printDetails() {
	fmt.Println("Name:", s.Name)
	fmt.Println("ID: ", s.ID)
	fmt.Println("Email: ", s.Email)
	fmt.Println("Department: ", s.Department)
}
