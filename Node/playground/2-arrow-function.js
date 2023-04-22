/* const square = (x) => x * x; */

/* console.log(square(2)); */

const party = {
  name: "Birthday Party",
  guestList: ["Akshaj", "Childe", "Scaramouche"],
  printGuestList() {
    console.log("Guest list for " + this.name);
    this.guestList.forEach((guest) => {
      console.log(guest + " is attending " + this.name);
    });
  },
};

party.printGuestList();
