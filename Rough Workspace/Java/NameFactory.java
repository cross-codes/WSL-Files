public class NameFactory {
  public Name getName(String entry) {
    int i = entry.indexOf(",");
    if (i > 0) {
      return new LastFirst(entry);
    } else {
      return new FirstFirst(entry);
    }
  }
}

class Name {
  protected String last;
  protected String first;

  public String getFirst() {
    return this.first;
  }

  public String getLast() {
    return this.last;
  }
}

class FirstFirst extends Name {

  public FirstFirst(String s) {
    int i = s.lastIndexOf(" ");
    if (i > 0) {
      this.first = s.substring(0, i).trim();
      this.last = s.substring(i).trim();
    } else {
      this.first = "";
      this.last = s;
    }
  }
}

class LastFirst extends Name {
  public LastFirst(String s) {
    int i = s.lastIndexOf(",");
    if (i > 0) {
      this.last = s.substring(0, i).trim();
      this.first = s.substring(i).trim();
    } else {
      this.last = s;
      this.first = "";
    }
  }
}
