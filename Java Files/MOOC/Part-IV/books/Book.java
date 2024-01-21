public class Book {
  private String title;
  private int pages;
  private int publicationYear;

  public Book(String title, int numPages, int publicationYear) {
    this.title = title;
    this.pages = numPages;
    this.publicationYear = publicationYear;
  }

  public String getTitle() {
    return this.title;
  }

  @Override
  public String toString() {
    return this.title + ", " + this.pages + ", " + this.publicationYear;
  }
}
