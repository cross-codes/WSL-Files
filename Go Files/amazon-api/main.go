package main

import (
	"server/db"
	"server/routers"

	"github.com/gin-gonic/gin"
)

func main() {
	router := gin.Default()

	db.ConnectDB()

	routers.UserRoute(router)
	router.Run("localhost:3000")
}
