package lab07;

public class MovablePoint implements Movable, Comparable<MovablePoint> {
  protected int x, y, xSpeed, ySpeed;

  public MovablePoint(int x, int y, int xSpeed, int ySpeed) {
    this.x = x;
    this.y = y;
    this.xSpeed = xSpeed;
    this.ySpeed = ySpeed;
  }

  @Override
  public String toString() {
    return "Point at (" + x + ", " + y + ")";
  }

  @Override
  public void moveUp() {
    this.y -= this.ySpeed;
  }

  @Override
  public void moveDown() {
    this.y += this.ySpeed;
  }

  @Override
  public void moveLeft() {
    this.x -= this.xSpeed;
  }

  @Override
  public void moveRight() {
    this.x += this.xSpeed;
  }

  @Override
  public int compareTo(MovablePoint other) {
    int cmp1 = Integer.compare(this.x, other.x);
    if (cmp1 == 0)
      return Integer.compare(this.y, other.y);
    else
      return cmp1;
  }
}
