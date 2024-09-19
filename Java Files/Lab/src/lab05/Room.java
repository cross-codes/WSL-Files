package lab05;

public class Room {
  double length, breadth, height;

  Room() {
    this.length = -1D;
    this.breadth = -1D;
    this.height = -1D;
  }

  Room(double l, double b, double h) {
    this.length = l;
    this.breadth = b;
    this.height = h;
  }

  Room(double len) {
    this.length = this.breadth = this.height = len;
  }

  double volume() {
    return this.length * this.breadth * this.height;
  }
}
