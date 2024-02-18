public class Book {
  private String author;
  private String title;
  private int pageCount;

  public Book(String author, String name, int pages) {
    this.author = author;
    this.title = name;
    this.pageCount = pages;
  }

  public String getAuthor() {
    return this.author;
  }

  public String getName() {
    return this.title;
  }

  public int getPages() {
    return this.pageCount;
  }

  @Override
  public String toString() {
    return this.author + ", " + this.title + ", " + this.pageCount;
  }
}
