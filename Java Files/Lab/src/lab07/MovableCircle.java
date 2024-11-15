package lab07;

public class MovableCircle implements Movable, Comparable<MovableCircle> {
  protected MovablePoint center;
  protected int radius;

  public MovableCircle(int x, int y, int xSpeed, int ySpeed, int radius) {
    this.center = new MovablePoint(x, y, xSpeed, ySpeed);
    this.radius = radius;
  }

  @Override
  public void moveUp() {
    this.center.y -= center.ySpeed;
  }

  @Override
  public void moveDown() {
    this.center.y += center.ySpeed;
  }

  @Override
  public void moveLeft() {
    this.center.x -= center.xSpeed;
  }

  @Override
  public void moveRight() {
    this.center.x += center.xSpeed;
  }

  @Override
  public String toString() {
    return "Circle with radius: " + this.radius + " and center at: " + this.center.x + ", " + this.center.y;
  }

  @Override
  public int compareTo(MovableCircle other) {
    int cmp1 = Integer.compare(this.radius, other.radius);
    if (cmp1 == 0) {
      int cmp2 = Integer.compare(this.center.x, other.center.x);
      if (cmp2 == 0)
        return Integer.compare(this.center.y, other.center.y);
      else
        return cmp2;
    } else
      return cmp1;
  }

}
