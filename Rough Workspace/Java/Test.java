class Box {
  private double width;
  private double depth;
  private double height;

  public Box(Box obj) {
    this.width = obj.width;
    this.height = obj.height;
    this.depth = obj.depth;
  }

  public Box(double w, double h, double d) {
    this.width = w;
    this.height = h;
    this.depth = d;
  }

  public double volume() {
    return this.width * this.height * this.depth;
  }
}

class BoxWeight extends Box {
  double weight;

  BoxWeight(BoxWeight obj) {
    super(obj);
    this.weight = obj.weight;
  }

  BoxWeight(double w, double h, double d, double m) {
    super(w, d, h);
    weight = m;
  }
}

public class Test {
  public static void main(String[] args) {
    BoxWeight weightBox = new BoxWeight(1D, 2D, 2D, 3D);
    System.out.println(weightBox.volume());
  }
}
